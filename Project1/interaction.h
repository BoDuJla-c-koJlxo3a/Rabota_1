#ifndef INTERACTION_H
#define INTERACTION_H
#include "vector.h"

int init(vector**, size_t*);

int insertU(vector**, size_t*);

int delU(vector**, size_t*);

int vecSumU(vector**, size_t*);

int vecMultNumU(vector**, size_t*);

number vecScalarMultU(vector**, size_t*);

void printarr(vector* a, size_t l);

#endif
