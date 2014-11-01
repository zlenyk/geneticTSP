#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include "population.h"

Population::Population(){
	best_order = NULL;
	generation_number = 0;
	best_of_all_value = 2000000000;
}
Individual* Population::cross(const Individual* mother,const Individual* father){
    Individual* new_ind = new Individual();
	Triple data = lcs(mother->order,father->order);
    int start = (data.s1+data.s2)/2;
    for(int k = 0; k<data.max; k++){
        new_ind->order[start+k] = mother->order[data.s1+k];
    }
    new_ind->fill_identity();
    return new_ind;
}
void Population::make_new_generation(){
    for(int i = 0; i<POPULATION; i++){
		int mother = rand()%POPULATION;
        int father;
        while((father = rand()%POPULATION) == mother);
        Individual* n = cross(population[mother],population[father]);
		population.push_back(n);
    }
	generation_number++;
}
void Population::mutate_population(){
    for(int i = 0; i<MUTATION_SIZE; i++){
        int index = rand() % POPULATION;
        population[index]->mutate();
    }
}
void Population::populate(){
    for(int i = 0; i<POPULATION; i++){
        Individual* new_individual = new Individual();
		permutate();
        new_individual->give_identity(permutation);
        population.push_back(new_individual);
    }
}
void Population::sort_population(){
    int k = 0;
	for(auto i = population.begin();i!=population.end();i++){
		count_individual_value(k++);
	}
	sort(population.begin(),population.end());
	if(population[0]->value > best_of_all_value){
		best_of_all_value = population[0]->value;
		if(best_order == NULL) delete(best_order);
		best_order = new int(N);
		for(int i = 0;i<N;i++) best_order[i] = population[0]->order[i];
	}
}
void Population::eliminate_weakest(){
	for(auto i = population.begin()+POPULATION; i != population.end(); i++) delete(*i);
    population.erase(population.begin()+POPULATION,population.end());
}
void Population::print_best(){
    printf("After %d generations: %d\n", generation_number,population[0]->value);
}
int Population::give_best_of_all(){
    return best_of_all_value;
}
int* Population::give_best_array(){
    return best_order;
}
void Population::print_population(){
    for(auto it = population.begin(); it!=population.end(); it++){
        printf("OSOBNIK: %d",(*it)->value);
        for(int i = 0; i<N;i++)
            printf("%d ", (*it)->order[i]);
        printf("\n");
    }
}

void Population::read_distances(){
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            scanf("%d", &distances[i][j]);
}
void Population::print_distances(){
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            printf("%d ", distances[i][j]);
}
void Population::build_permutation(){
	for(int i = 0; i<N;i++)
		permutation[i] = i+1;
}
void Population::permutate(){
	srand(time(NULL));
	for(int k=N;k>=2;k--){
		int l = rand() % k;
		std::swap(permutation[l],permutation[k-1]);
	}
}
int Population::count_individual_value(int index){
	Individual* in = population[index];
    int v = 0;
    for(int i = 0; i<N-1; i++)
	v += distances[in->order[i]-1][in->order[i+1]-1];
    v += distances[in->order[N-1]-1][in->order[0]-1];
    in->value = v;
    return v;
	
}
