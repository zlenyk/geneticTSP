#ifndef UTILITIES_H
#define UTILITIES_H
#include "configuration.h"
#include <time.h>
#include <utility>
struct Triple{
	int s1,s2,max;
	Triple(int,int,int);
};

Triple lcs(const int* a,const int* b);

//	returns pair of random,distinct integers not higher than n
pii random_pair(int);
//	given array of permutation and it's size, permutates it
void permutate(int*);
//	fills array with random permutation 1...N
void build_permutation(int*);
//	returns random int not higher than argument
int random_int(int);
#endif
