#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include "element.h"

typedef struct Vector {
	void** array;
	size_t len;
} vector;

vector vecNew();

void vecDel(vector);

void vecAddDim(vector*, void*);

vector vecSum(vector*, vector*);

vector vecMultNum(vector, number);

number vecScalarMult(vector, vector);

#endif