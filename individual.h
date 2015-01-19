#ifndef OSOBNIK_H
#define OSOBNIK_H
#include "utilities.h"
class Individual{
    public:
        int value;
        int order[N];
        Individual();
		void mutate();
        void give_identity(int*);
        void fill_identity();
        bool operator < (const Individual& a) const;
		
		void print()const;
        
		static Individual* create_random_individual(){
			Individual* new_ind = new Individual();
			build_permutation(new_ind->order,N);
			return new_ind;
		}
};
#endif
