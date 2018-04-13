#include"stdafx.h"

#define HALF_SCALE 60
#define SIZE 100
#define DELTA_T 0.1
#define PARA_1 5
#define PARA_2 10000
#define LIFE 6

using namespace std;

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
	double* original_state()
	{
		return cor;
	}
	void refresh_A()
	{
		for (int i = 0; i < 3; ++i)
		{
			acv[i] = 0;
		}
	}
	void transfer(double another_node[3])//to change the accelerated velocity of Fly
	{
		transfer_A(another_node);
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
	void transfer_A(double another_node[3])
	{
		double delta_cor[3], force[3];
		for (int i = 0; i < 3; ++i)
		{
			delta_cor[i] = cor[i] - another_node[i];
		}
		double distance = sqrt(delta_cor[0] * delta_cor[0] + delta_cor[1] * delta_cor[1] + delta_cor[2] * delta_cor[2]);
		double force_pair = PARA_2*(PARA_1 / distance - 1) / distance / distance;
		for (int j = 0; j < 3; ++j)
		{
			delta_cor[j] /= distance;
			force[j] = force_pair * delta_cor[j];
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
			vel[i] += acv[i] * DELTA_T;
			cor[i] += (vel[i] + acv[i] * DELTA_T / 2)*DELTA_T;
		}
		return cor;
	}
};

int main()
{
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
	for (int i = 0; double(i)*DELTA_T < LIFE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			groups[j].refresh_A();
			for (int k = 0; k < SIZE; ++k)
			{
				if (k != j)
				{
					groups[j].transfer(groups[k].original_state());
				}
			}
			groups[j].transfer();
			for (int u = 0; u < 3; ++u)
				cout << j <<","<<u+1<<":"<<groups[j].original_state()[u] <<" ";
			cout << endl;
		}
	}
    return 0;
}

