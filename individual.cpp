#include "individual.h"
#include <cstdio>
#include <algorithm>
#include <set>

Individual::Individual(){
    for(int i = 0; i<N; i++)
        order[i] = 0;
}
void Individual::mutate(){
    for(int i = 0; i<MUTATION_SIZE; i++){
		int v1 = rand() % (N-1) + 1;
		int v2;
		while((v2 = rand() % (N-1) + 1) == v1);
		std::swap(order[v1],order[v2]);
    }
}
void Individual::give_identity(int* permutation){
    for(int i=0;i<N;i++)
		order[i] = permutation[i];
}
void Individual::fill_identity(){
    std::set <int> S;
    for(int i = 1; i<=N; i++)
	S.insert(i);
    for(int i = 0; i<N; i++)
	if(order[i] > 0)
	    S.erase(order[i]);
    for(int i = 0; i<N; i++){
		if(order[i] == 0){
	    	int s = S.size();
	    	auto it = S.begin();
	    	int ran = rand() % s;
	   		advance(it,ran);
	    	order[i] = *(it);
	    	S.erase(order[i]);
		}
    }
}
bool Individual::operator < (const Individual& a) const{
    return value < a.value;
}

