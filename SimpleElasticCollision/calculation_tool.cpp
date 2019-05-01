#include"stdafx.h"
using namespace std;
using namespace cv;

//two-vector multiplication
double v2_multi(double*a, double*b, int len)
{
	double res = 0.0;
	for (int i = 0; i < len; ++i)
		res += a[i] * b[i];
	return res;
}

//calculate vector-2-cos
double v2_cos(double *a, double*b, int len)
{
	return v2_multi(a, b, len) / (sqrt(v2_multi(a, a, len)*v2_multi(b, b, len)));
}

//normalize the vector,to store the result in res
void norm_vec(double*a, double* res, int len)
{
	double v_len = sqrt(v2_multi(a, a, len));
	for (int i = 0; i < len; ++i)
		res[i] = a[i] / v_len;
}

//calculate the distance of 2 nodes
double cal_dist(double *n1, double *n2)
{
	double dist = 0;
	for (int i = 0; i < 3; ++i)
	{
		dist += (n1[i] - n2[i])*(n1[i] - n2[i]);
	}
	return sqrt(dist);
}

//check whether a node is in a box: true means in(the func is used to judge whether the node collides with the wall)
bool CheckNodeInBox(double *node_cor, double*box_scale)
{
	bool signal = true;
	for (int i = 0; i < 3; ++i)
	{
		if (node_cor[i] <= box_scale[i * 2] || node_cor[i] >= box_scale[i * 2 + 1])
		{
			signal = false;
			break;
		}
	}
	return signal;
}

//use opencv to solve equation(useful!!!)
void gaussin(double a[3][3], double b[3], double x[3])
{
	Mat A = Mat(3,3,CV_64F,a).clone(), B = Mat_<double>(3, 1),X;
	//memcpy(A.data,a,sizeof(double)*9);
	memcpy(B.data, b, sizeof(double) * 3);
	double det_val = determinant(A);
	cout << det_val << endl;
	while (det_val == 0)
	{
		for (int i = 0; i < 3; ++i)
			a[i][i] += 0.01;
		A = Mat(3, 3, CV_64F, a).clone();
	}
	solve(A, B, X, CV_LU);
	memcpy(x,X.data,sizeof(double)*3);
}

//calculate the crossover point between straight_line AC(not segment_line!!!) and plane P, the result is stored at B
void CalLinePlane(double *A, double* C, double *NormalVec, double *B,double wall_v)
{
	double SumA = 0, SumC = 0;
	for (int i = 0; i < 3; ++i)
	{
		SumC += NormalVec[i] * C[i];
		SumA += NormalVec[i] * A[i];
	}
	double Vec_t = (wall_v-SumC) / (SumA-SumC);
	if (Vec_t < 0 || Vec_t > 1)
		Vec_t = (-wall_v - SumC) / (SumA - SumC);
	for (int i = 0; i < 3; ++i)
		B[i] = Vec_t * (A[i] - C[i]) + C[i];
}

//the basic package in this system, to calculate the very node's coordinate via 1 reflection
void RefSolu(double*B, double* C, double *NormalVec,double *D)
{
	double CB[3];
	for (int i = 0; i < 3; ++i)
		CB[i] = B[i] - C[i];
	double CB_Np = v2_multi(CB,NormalVec,3);
	for (int i = 0; i < 3; ++i)
		D[i] = 2 * CB_Np*NormalVec[i] + C[i];
}
