#include "population.h"
int main(){

	Population* population = new Population();
	population->init();
	population->print_population();
		
	for(int i = 0; i < GENERATIONS; i++){
        population->make_new_generation();
        population->eliminate_weakest();
        population->mutate_population();
		population->print_best();
    }
	
	return 0;
}
