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

};
#endif
