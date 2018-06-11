#pragma once
#include"stdafx.h"

using namespace std;
class Interaction
{
public:
	Interaction();
	Interaction(int, double, double, double, double, double);

	void Py_evaluation_expdata(const char*, const char*);
private:
	int sample_size;
	double interval;
	double K;
	double length_dro;
	double length_box;
	double terminal;
	bool py_evaluation(const char*, const char*);
};