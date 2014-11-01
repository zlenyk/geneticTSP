#ifndef UTILITIES_H
#define UTILITIES_H
#include "configuration.h"

struct Triple{
	int s1,s2,max;
	Triple(int,int,int);
};

Triple lcs(const int* a,const int* b);
#endif
