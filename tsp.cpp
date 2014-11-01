/*
    problem komiwojażera za pomocą algorytmu genetycznego.
    osobnikiem jest trasa komiwojażera(pewna permutacja).
    krzyżowanie polega na wybraniu najdłuższego wspólnego podciągu dwóch osobników i wsadzeniu go
    pomiędzy miejsc jego występowania u rodziców.
    stworzymy w każdej generacji tylu potomków, aby liczebność populacji się podwoiła
    następnie populacja będzie obcinana do połowy najlepszych pod względem zysku osobników
*/
#include "population.h"
#include <ctime>
#include <cstdio>
#include <cstdlib>
int main(){
    clock_t begin = clock();
    srand(time(NULL));
    build_permutation();
    read_distances();
    populate();
    for(int i = 0; i < GENERATIONS; i++){
        make_new_generation();
        sort_population();
        eliminate_weakest();
//        print_best(i);
        save_best();
        mutate_population();
    }
    printf("BEST OF ALL: %d\n", give_best_of_all());
    int *b = give_best_array();
    for(int i = 0; i<N; i++)
        printf("%d ", b[i]);
    clock_t end = clock();
    printf("TIME: %f\n", double(end-begin)/CLOCKS_PER_SEC);
}

