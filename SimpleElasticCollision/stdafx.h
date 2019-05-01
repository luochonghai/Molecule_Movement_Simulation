#pragma once
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<random>
#include<string>
#include<fstream>
#include<list>
#include"cv.h"

/*NOTICE: the system_parameters are set in SI units by default.
Ohterwise it would be declared.*/
#define HALF_SCALE 200.0		//the half length of cube space where flies interact 
#define ColHalfScale 195.0	//the colliding half scale
#define SIZE 500			//number of flies
#define DELTA_T 1.0			//length of one time step
#define LIFE 5000.0			//the lifetime of system
#define LEN_FLY 3.0			//body length of fly
#define V_BAR 0.46			//mean velocity of fly
#define V_STA_DIV 0.03		//standard deviation of fly's velocity
#define COLLIDE_DIST 5.0		//colliding distance
#define sqrt2 sqrt(2.0)
#define ts_cos_theta -1.0/sqrt2
#define sqrt3 sqrt(3.0)
