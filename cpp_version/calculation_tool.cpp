#include"stdafx.h"
using namespace std;

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