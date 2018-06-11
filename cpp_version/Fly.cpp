#include"stdafx.h"
#include"Fly.h"
#include"calculation_tool.h"
using namespace std;

Fly::Fly() = default;
	
Fly::Fly(bool sex_fly, double weight_fly, double initial_cor[3]) :
		sex(sex_fly), m(weight_fly), cor(), vel(), acv(), cur_radius(0)
	{
		for (int i = 0; i < 3; ++i)
			rec_fie_cen[i] = cor[i] = initial_cor[i];
	}
	
double* Fly::original_state()//print the coordinate of node
	{
		return cor;
	}

double Fly::show_cur_radius()
	{
		return cur_radius;
	}

void Fly::refresh_A()//to refresh the accelerated velocity of node to be zero
	{
		for (int i = 0; i < 3; ++i)
			acv[i] = 0;
	}
	
void Fly::transfer(double another_node[3], int timer)//to change the accelerated velocity of Fly
	{
		transfer_A(another_node, timer);
	}
	
double* Fly::transfer()//when the accelerated velocity has been calculated, calculate the new coordinate
	{
		return transfer_state();
	}

double Fly::Force_func(double distance)
{
	return PARA_4*(PARA_2 / pow(distance, 3) - PARA_3 / pow(distance,1));
}

/*180610: now we add reception field to the model, so it's necessary to check whether fly-k
	can influence fly-j or not first. We use cos(Vj,Vk)&Radius(Reception)-D(i,j) to check it.
	Then it seemed to be wrong since the flies cannot cluster again because no fly would
	drive them back to the central point when they dissipate.
	So I took another method: use a ball to depict the reception field of the fly,while the center
	isn't the fly's coordiante--instead, both the fly's coordinate and velocity_direction determine
	the centre of the ball.*/
void Fly::transfer_A(double another_node[3], int timer)
	{
		double delta_cor[3], force[3];
		for (int i = 0; i < 3; ++i)
		{
			delta_cor[i] = cor[i] - another_node[i];
		}
		double distance = sqrt(v2_multi(delta_cor, delta_cor, 3));

		//check first
		/*one way to check:
		if (distance > R_FIELD_LEN)//condition 2 isn't satisfied
		return;
		else
		{
		double vel_len = sqrt(v2_multi(vel,vel,3));
		double cos_vec_multi = -v2_cos(vel,delta_cor,3);
		if (cos_vec_multi <= ts_cos_theta)
		return;
		}
		*/

		/*another way to check:change the reception field, introduce a sign to show
		where the other fly is*/
		double delta_dis[3];
		double locate_sign = 1;
		for (int di = 0; di < 3; ++di)
			delta_dis[di] = another_node[di] - rec_fie_cen[di];
		if (sqrt(v2_multi(delta_dis, delta_dis, 3)) > R_FIELD_LEN)
		{
			//not in the reception field,but in the backward field(where fly can just feel it strongly)
			if (distance <= R_FIELD_LEN)
				locate_sign = 0.9;
			//else //too far away from the fly, hardly can they influence each other
			//	locate_sign = 0;
		}

		double force_pair = Force_func(distance)*locate_sign;

		/*I don't know what's wrong with my code, but the simulation of molecule seems wrong!
		Now I got the bug:
		1.the system bug:
		I calculated the coordinate of each modecule before a round is over, which would
		influence the remaining modecules' coordinate to be wrong.
		2.the parameter-set bug:
		Since the calculating ability of computer,especially our PC, is limited,
		When the distance of two modecules is very small, and the force function
		is quite accurate,such as 1/s^5, then you would fall into cases when the 2
		modecules are quite close, their repulsive force would be extremely large
		with errors we cannot ignore!*/
		for (int j = 0; j < 3; ++j)
		{
			force[j] = force_pair * delta_cor[j] / distance;
			acv[j] += force[j] / m;
		}

	}

double* Fly::transfer_state()
	{
		double vec_dir[3];
		norm_vec(vel, vec_dir, 3);
		for (int i = 0; i < 3; ++i)
		{
			rec_fie_cen[i] = cor[i] + R_FIELD_LEN / 2 * vec_dir[i];
			cor[i] += (vel[i] + acv[i] * DELTA_T / 2.0)*DELTA_T;
			vel[i] += acv[i] * DELTA_T;
		}

		double force[3];

		for (int j = 0; j < 3; ++j)
		{
			force[j] = acv[j] * m;
		}
		//to calculate the curvature radius and the velocity_radial / V via one point's coordinate
		double v_2norm = sqrt(v2_multi(vel, vel, 3));
		double f_2norm = sqrt(v2_multi(force, force, 3));
		double force_tangential = (v2_multi(force, vel, 3) / v_2norm);
		double force_radial = sqrt(f_2norm*f_2norm - force_tangential * force_tangential);
		cur_radius = (m*v_2norm*v_2norm + 3 * force_tangential*v_2norm*DELTA_T) / force_radial;

		return cor;
	}
