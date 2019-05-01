#pragma once
#include "stdafx.h"
using namespace std;

class Fly
{
public:
	Fly();
	Fly(double initial_cor[3],double initial_vel[3]);
	double* original_state();//print the coordinate of node
	double* original_vel();  //print the velocity of node
	bool transfer(double[3],double[3]);//to change the velocity and coordinate of Fly
	double* transfer();		//when the accelerated velocity has been calculated, calculate the new coordinate
	bool pinball();			//to check& change the direction of velocity when the node meets the wall: return true when collision happens
	void updateCol();
	void ModAnoVel(double *);//to modify another node's velocity if necessary

private:
	double m;
	//the fly's coordinate(x,y,z)
	double cor[3];
	//the fly's speed
	double vel[3];
	double next_cor[3];//used specifically for collision
	double next_vel[3];//used specifically for collision

	bool collide_node(double[3],double[3]);
	void Colli1Time(int, double *);
	void Colli2Time(int, double *);
	void Colli3Time(int, double *);
	double *transfer_coordinate();
	void after_col();
	void ModifyAnoVel(double *);//to modify another node's velocity if necessary
};
