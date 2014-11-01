#include "population.h"
int main(){

	Population* population = new Population();
	population->read_distances();
	population->populate();
	for(int i = 0; i < GENERATIONS; i++){
        population->make_new_generation();
        population->sort_population();
        population->eliminate_weakest();
        population->mutate_population();
	population->print_best();
    }
	return 0;
}
