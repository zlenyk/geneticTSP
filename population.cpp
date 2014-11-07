#include <algorithm>
#include <cstdio>
#include <utility>
#include "population.h"

Population::Population(){
	best_order = NULL;
	generation_number = 0;
	best_of_all_value = 2000000000;
}
void Population::init(){
	read_distances();
	populate();
	srand(time(NULL));
}
Individual* Population::cross(const Individual* mother,const Individual* father){
    Individual* new_ind = new Individual();
	Triple data = lcs(mother->order,father->order);
    int start = (data.s1+data.s2)/2;
    REP(k,0,data.max)  new_ind->order[start+k] = mother->order[data.s1+k];

    new_ind->fill_identity();
    return new_ind;
}
void Population::make_new_generation(){
    for(int i = 0; i<POPULATION; i++){
        pii random = random_pair(POPULATION);
		Individual* n = cross(population[random.first],population[random.second]);
		population.push_back(n);
		count_individual_value(population.size()-1);
    }
	generation_number++;
}
void Population::mutate_population(){ 	REP(i,0,MUTATION_SIZE) population[random_int(POPULATION)]->mutate(); }
void Population::populate(){ 			REP(i,0,POPULATION) population.push_back(Individual::create_random_individual()); }

void Population::sort_population(){
	int k = population.size();
	REP(i,0,k) count_individual_value(i); 

	sort(population.begin(),population.end());
	save_best();
}
void Population::save_best(){
	if(population[0]->value < best_of_all_value){
		best_of_all_value = population[0]->value;
		if(best_order != NULL) delete(best_order);
		best_order = new int(N);
		REP(i,0,N) best_order[i] = population[0]->order[i];
	}
}
void Population::eliminate_weakest(){
	sort_population();
	for(auto i = population.begin()+POPULATION; i != population.end(); i++) delete(*i);
    population.erase(population.begin()+POPULATION,population.end());
	population.resize(POPULATION);
}

int Population::give_best_of_all(){ return best_of_all_value; }
int* Population::give_best_array(){ return best_order; }

void Population::read_distances(){	REP(i,0,N) REP(j,0,N) scanf("%d", &distances[i][j]); }
void Population::print_distances(){ REP(i,0,N) REP(j,0,N) printf("%d ", distances[i][j]); }

void Population::print_best(){ printf("After %d generations: %d\n", generation_number,population[0]->value); }
void Population::print_population(){ for(auto individual : population) individual->print(); }

int Population::count_individual_value(int index){
	Individual* in = population[index];
    int v = 0;
    REP(i,0,N) v += distances[in->order[i]-1][in->order[(i+1)%N]-1];
    in->value = v;
    return v;	
}
