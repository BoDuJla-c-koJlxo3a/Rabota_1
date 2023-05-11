#ifndef ELEMENT_H
#define ELEMENT_H
#include <stdlib.h>
typedef struct Number {
	size_t type;
	float Re;
	float Im;
} number;

number numNew();

number sum(number*, number*);

number mult(number*, number*);

void printfnumber(number*);

#endif
