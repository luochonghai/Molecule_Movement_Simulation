#pragma once
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include <Python.h>
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<list>

/*NOTICE: the system_parameters are set in SI units by default.
Ohterwise it would be declared.*/
#define HALF_SCALE 30//cm
#define SIZE 100
#define DELTA_T 0.1
#define PARA_2 40.0*1000
#define PARA_3 0.025*10
#define PARA_4 60.0//the order of force(mainly used to control the fast&active the system is operating)
#define LIFE 1000
#define STABLE_RATIO 0.5//the ratio is used to count when to start calculating the collapse of flies
#define LEN_FLY 5.0/10//cm
#define R_FIELD_LEN 40 //receptive field radius(cm)
#define C_FIELD_TIME 3  //colliding field radius
//right now the solution of Force(x) = 0 is 0.129, we regard it as the 5 times of length of fly
#define sqrt2 sqrt(2.0)
#define ts_cos_theta -1.0/sqrt2