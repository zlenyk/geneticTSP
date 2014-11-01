#ifndef POPULATION_H
#define POPULATION_H
#include "individual.h"
#include <vector>
class Population{
	public:
	std::vector<Individual*> population;
	int best_of_all_value;
	int generation_number;
	int* best_order;
	int distances[N][N];
	int permutation[N];

	void build_permutation();
	void read_distances();
	void print_distances();
	void permutate();
	int count_individual_value(int);	
	Population();
	//	Run once, at the beginning. Fills vector population with random individuals
	void populate();
	
	//	creates new individual from two given, using algorithm spicified in utilities
	Individual* cross(const Individual*,const Individual*);
		
	//	picks random individuals and mutates them
	void mutate_population();
	
	//	create new generation of individuals, crosses existing individuals. Size of new generation: half existing one.
	void make_new_generation();
	
	//	sorts individuals according to their value
	void sort_population();
	
	//	eliminatest weakest individuals
	void eliminate_weakest();
	
	//FILL
	void print_best();

	//FILL!	
	void print_population();
	
	//FILL!
	void save_best();
	int* give_best_array();
	int give_best_of_all();

};
#endif
