#include <algorithm>
#include <cstdio>
#include <utility>
#include "population.h"

Population::Population(){
    best_order.clear();
    generation_number = 0;
    best_of_all_value = 2000000000;
}
Population::~Population(){
    for(Individual* individual : population) delete(individual);
    population.clear();
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
    int* indOrder = new int[POPULATION];
    build_permutation(indOrder,POPULATION);
    for(int i = 0; i<POPULATION/2; i++){
        //pii random = random_pair(POPULATION);
        Individual* n = cross(population[indOrder[2*i]],population[indOrder[2*i+1]]);
        count_individual_value(n);
        population.push_back(n);
    }
    generation_number++;
    sort_population();
    eliminate_weakest();
    
    delete(indOrder);
}
void Population::mutate_population(){
    REP(i,0,MUTATION_SIZE) population[random_int(POPULATION)]->mutate(); 
}
void Population::populate(){            
    REP(i,0,POPULATION) population.push_back(Individual::create_random_individual()); 
    REP(i,0,POPULATION) count_individual_value(i);
}

void Population::sort_population(){
    int k = population.size();
    REP(i,0,k) count_individual_value(i); 

    sort(population.begin(),population.end(),compare);
    save_best();
}
void Population::save_best(){
    if(population[0]->value < best_of_all_value){
        best_of_all_value = population[0]->value;
        best_order.clear();
        REP(i,0,N) best_order.push_back(population[0]->order[i]);
    }
}
void Population::eliminate_weakest(){
    sort_population();
    for(auto i = population.begin()+(3*POPULATION)/2; i != population.end(); i++) delete(*i);
    population.resize(POPULATION);
}

void Population::print_best_of_all(){ printf("BEST OF ALL: %d\n",best_of_all_value); }
void Population::print_best_order(){ 
    printf("BEST ORDER: ");
    for(int v : best_order) printf("%d ",v);
    printf("\n");
}

void Population::read_distances(){  REP(i,0,N) REP(j,0,N) scanf("%d", &distances[i][j]); }
void Population::print_distances(){ REP(i,0,N) REP(j,0,N) printf("%d ", distances[i][j]); }

void Population::print_best(){ printf("After %d generations: %d Best of all: %d\n", generation_number,population[0]->value,best_of_all_value); }
void Population::print_population(){ for(Individual* individual : population) individual->print(); }

int Population::count_individual_value(Individual* in){
    int v = 0;
    REP(i,0,N) v += distances[in->order[i]-1][in->order[(i+1)%N]-1];
    in->value = v;
    return v;   
}
