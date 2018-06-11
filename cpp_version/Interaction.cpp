#include"stdafx.h"
#include"Interaction.h"
using namespace std;
	Interaction::Interaction() = default;
	Interaction::Interaction(int Sample_size, double Interval, double K_index, double Length_dro, double Length_box, double Terminal) :
		sample_size(Sample_size), interval(Interval), K(K_index), length_dro(Length_dro), length_box(Length_box), terminal(Terminal) {}
	void Interaction::Py_evaluation_expdata(const char* file_name, const char* module_name)
	{
		py_evaluation(file_name, module_name);
	}
	bool Interaction::py_evaluation(const char* file_name, const char* module_name)
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
		//PyEval_CallObject(pFunc, NULL);

		//finish the invoking process
		//Py_Finalize();

		/*test ok*/
		//PyRun_SimpleString("import sys; sys.path.append('.')");
		//PyRun_SimpleString("import mytest;");
		//PyRun_SimpleString("print(mytest.myabs(-2.0))");
		//Py_Finalize();
		return 0;
	}