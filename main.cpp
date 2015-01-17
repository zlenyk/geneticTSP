#include "population.h"
#include <cstdio>
#include <algorithm>
int main(){
    srand(time(NULL));
	Population* population = new Population();
	population->init();
    population->print_population();
	for(int i = 0; i < GENERATIONS; i++){
        population->make_new_generation();
		population->print_best();
        population->mutate_population();
    }
    population->print_best_of_all();
    population->print_best_order();
    delete population;	
	return 0;
}
