#pragma once

#include"stdafx.h"

//two-vector multiplication
double v2_multi(double*, double*, int);

//calculate vector-2-cos
double v2_cos(double *, double*, int);

//normalize the vector,to store the result in res
void norm_vec(double*, double* , int );

//calculate the distance of 2 nodes
double cal_dist(double*, double*);

//check whether a node is in a box
bool CheckNodeInBox(double *,double*);

//calculate the target node's coordinate
void RefSolu(double*B, double* C, double *NormalVec, double *D);

//tell which plane of the index_cube can AC intersect: 0,1--left,right 2,3--front,back 4,5--up,down
void CalLinePlane(double *A, double* C, double *NormalVec, double *B,double wall_value);