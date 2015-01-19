#ifndef POPULATION_H
#define POPULATION_H
#include "individual.h"
#include <vector>
class Population{
    public:
    std::vector<Individual*> population;
    int best_of_all_value,generation_number,distances[N][N];
    std::vector<int> best_order;
    
    void init();
    void read_distances();
    void print_distances();
    int count_individual_value(Individual* in); 
    Population();
    ~Population();  
    //  Run once, at the beginning. Fills vector population with random individuals
    void populate();
    
    //  creates new individual from two given, using algorithm spicified in utilities
    Individual* cross(const Individual*,const Individual*);
        
    //  picks random individuals and mutates them
    void mutate_population();
    
    //  create new generation of individuals, crosses existing individuals. Size of new generation: half existing one.
    void make_new_generation();
    
    //  sorts individuals according to their value
    void sort_population();
    
    //  eliminatest weakest individuals
    void eliminate_weakest();
    
    //FILL
    void print_best();

    //  prints every individual
    void print_population();
    
    //FILL!
    void save_best();
    void print_best_order();
    void print_best_of_all();

    static bool compare(const Individual* a,const Individual* b){
        return a->value < b->value;
    }
};
#endif
