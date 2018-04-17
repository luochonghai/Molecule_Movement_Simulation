#include"stdafx.h"

#define HALF_SCALE 60
#define SIZE 100
#define DELTA_T 0.1
#define PARA_1 5
#define PARA_2 58.8
#define PARA_3 0.00196
#define PARA_4 60
#define PARA_5 2
#define PARA_6 1.008
#define LIFE 10

using namespace std;

static int timer;

class Fly
{
public:
	Fly() = default;
	Fly (bool sex_fly,double weight_fly,double initial_cor[3]) :
		sex(sex_fly),m(weight_fly),cor(),vel(),acv()
	{
		for (int i = 0; i < 3; ++i)
			cor[i] = initial_cor[i];
	}
	double* original_state()//print the coordinate of node
	{
		return cor;
	}
	void refresh_A()//to refresh the accelerated velocity of node to be zero
	{
		for (int i = 0; i < 3; ++i)
		{
			acv[i] = 0;
		}
	}
	void transfer(double another_node[3],int timer)//to change the accelerated velocity of Fly
	{
		transfer_A(another_node,timer);
	}
	double* transfer()//when the accelerated velocity has been calculated, calculate the new coordinate
	{
		return transfer_state();
	}
private:
	bool sex;
	//the fly's weight
	double m;
	//the fly's coordinate(x,y,z)
	double cor[3];
	//the fly's speed
	double vel[3];
	//the fly's accelerated velocity
	double acv[3];

	void transfer_A(double another_node[3],int timer)
	{
		double delta_cor[3], force[3];
		for (int i = 0; i < 3; ++i)
		{
			delta_cor[i] = cor[i] - another_node[i];
		}
		double distance = sqrt(delta_cor[0] * delta_cor[0] + delta_cor[1] * delta_cor[1] + delta_cor[2] * delta_cor[2]);
		double temp_f = PARA_3 / distance / distance / distance;
		double force_pair = temp_f*temp_f+PARA_2*temp_f*distance-1/ distance;
		//double time_descend = 1 / (1+pow(PARA_6,-timer+LIFE/2));
		//time_descend = 1 - time_descend;
		force_pair *= PARA_4;
		//force_pair *= time_descend;
		for (int j = 0; j < 3; ++j)
		{
			force[j] = force_pair * delta_cor[j]/distance;
		}

		for (int i = 0; i < 3; ++i)
		{
			acv[i] += force[i] / m;
		}
	}

	double *transfer_state()
	{
		for (int i = 0; i < 3; ++i)
		{
			cor[i] += (vel[i] + acv[i] * DELTA_T / 2)*DELTA_T;
			vel[i] += acv[i] * DELTA_T;
		}
		return cor;
	}
};

class Interaction
{
public:
	Interaction() = default;
	Interaction(int Sample_size,double Interval,double K_index,double Length_dro,double Length_box,double Terminal):
	sample_size(Sample_size),interval(Interval),K(K_index),length_dro(Length_dro),length_box(Length_box),terminal(Terminal){}
	void Py_evaluation_expdata(const char* file_name, const char* module_name)
	{
		py_evaluation(file_name,module_name);
	}
private:
	int sample_size;
	double interval;
	double K;
	double length_dro;
	double length_box;
	double terminal;
	bool py_evaluation(const char* file_name, const char* module_name)
	{
		//Py_Initialize();

		//to state the variable(s)
		PyObject *pModule = NULL;
		PyObject *pFunc = NULL;

		//IMPORTANT!!change the current_file_path
		PyRun_SimpleString("import sys;sys.path.append('./')");

		//define invoking file's name
		PyObject* moduleName = PyUnicode_FromString(file_name);
		pModule = PyImport_Import(moduleName);
		if (!pModule)
		{
			cout << "[ERROR]:Python get module failed." << endl;
			return 0;
		}
		cout << "[INFO]Python get module succeed." << endl;
		//pModule = PyImport_ImportModule("random_index_cal");


		//define the invoking function's name
		pFunc = PyObject_GetAttrString(pModule, module_name);

		//invoke the function
		PyEval_CallObject(pFunc, NULL);

		//finish the invoking process
		//Py_Finalize();

		/*test ok*/
		//PyRun_SimpleString("import sys; sys.path.append('.')");
		//PyRun_SimpleString("import mytest;");
		//PyRun_SimpleString("print(mytest.myabs(-2.0))");
		//Py_Finalize();
		return 0;
	}
};

int main()
{
	Py_Initialize();
	//to initialize the py_interaction_mode
	Interaction inter_py(SIZE,DELTA_T,1,1,HALF_SCALE,LIFE);
	inter_py.Py_evaluation_expdata("random_index_cal","cpp_invoke");

	//to store the coordinate of simulation_model

	//double **Cx = new double*[SIZE];
	//double **Cy = new double*[SIZE];
	//double **Cz = new double*[SIZE];
	//for (int i = 0; i < SIZE; ++i)
	//{
	//	Cx[i] = new double[LIFE / DELTA_T];
	//	Cy[i] = new double[LIFE / DELTA_T];
	//	Cz[i] = new double[LIFE / DELTA_T];
	//}
	
	timer = 0;
	srand(unsigned(time(NULL)));
	Fly *groups = new Fly[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		double initial_cor[3];
		for (int m = 0; m < 3; ++m)
		{
			initial_cor[m] = (rand() % (2 * HALF_SCALE)) - HALF_SCALE;
		}
		groups[i] = Fly(rand()%2,(rand()%SIZE)/SIZE+1, initial_cor);
	}

	system("DEL /f D:\\FDU\\Template\\CS\\数学建模\\coordinate.txt");
	ofstream coordi;
	coordi.open("D:\\FDU\\Template\\CS\\数学建模\\coordinate.txt",ios::out|ios::app);
	for (timer = 0; timer*DELTA_T < LIFE; ++timer)
	{
		if (!timer)
		{
			for (int r = 0; r < SIZE; ++r)
			{
				coordi << r << " ";
				for (int u = 0; u < 3; ++u)
				{
					auto cor_num = groups[r].original_state()[u];
					coordi << " " << cor_num << " ";
					//if (u == 0)
					//	Cx[r][0] = cor_num;
					//else if (u == 1)
					//	Cy[r][0] = cor_num;
					//else
					//	Cz[r][0] = cor_num;
				}
				coordi << endl;
			}
		}
		for (int j = 0; j < SIZE; ++j)
		{
			groups[j].refresh_A();
			for (int k = 0; k < SIZE; ++k)
			{
				if (k != j)
				{
					groups[j].transfer(groups[k].original_state(),timer);
				}
			}
			groups[j].transfer();
			coordi << j << " ";
			for (int u = 0; u < 3; ++u)
			{
				auto temp_num = groups[j].original_state()[u];
				coordi  << " " << temp_num << " ";
				//if (u == 0)
				//	Cx[j][timer] = temp_num;
				//else if (u == 1)
				//	Cy[j][timer] = temp_num;
				//else
				//	Cz[j][timer] = temp_num;
			}
			coordi << endl;
		}
	}
	coordi.close();

	inter_py.Py_evaluation_expdata("read_cordinate_text", "model_evaluation");
	//for (int i = 0; i < SIZE; ++i)
	//{
	//	delete Cx[i];
	//	delete Cy[i];
	//	delete Cz[i];
	//}
	//delete Cx;
	//delete Cy;
	//delete Cz;
	Py_Finalize();
    return 0;
}

