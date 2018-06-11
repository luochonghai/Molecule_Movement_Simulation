#pragma once
#include "stdafx.h"
using namespace std;

class Fly
{
public:
	Fly();
	Fly(bool sex_fly, double weight_fly, double initial_cor[3]);
	double* original_state();//print the coordinate of node

	double show_cur_radius();

	void refresh_A();//to refresh the accelerated velocity of node to be zero
	void transfer(double[3], int);//to change the accelerated velocity of Fly
	double* transfer();//when the accelerated velocity has been calculated, calculate the new coordinate

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
	//the fly's radius of curvature
	double cur_radius;
	//center of the reception field
	double rec_fie_cen[3];

	/*180610: now we add reception field to the model, so it's necessary to check whether fly-k
	can influence fly-j or not first. We use cos(Vj,Vk)&Radius(Reception)-D(i,j) to check it.
	Then it seemed to be wrong since the flies cannot cluster again because no fly would
	drive them back to the central point when they dissipate.
	So I took another method: use a ball to depict the reception field of the fly,while the center
	isn't the fly's coordiante--instead, both the fly's coordinate and velocity_direction determine
	the centre of the ball.*/
	double Force_func(double distance);
	void transfer_A(double[3], int);
	double *transfer_state();
};
