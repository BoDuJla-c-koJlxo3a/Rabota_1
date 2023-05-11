#ifndef DATA_H
#define DATA_H

typedef struct Complex {
	float Re;
	float Im;
} complex;

typedef struct Vector {
	void *x;
	void *y;
	void *z;
} vector;

complex intToComplex(int);

complex floatToComplex(float );

vector* vecNew();

int getXi(vector*);

int getYi(vector*);

int getZi(vector*);

float getXf(vector*);

float getYf(vector*);

float getZf(vector*);

complex getXc(vector*);

complex getYc(vector*);

complex getZc(vector*);

void vecSetInt(vector*, int, int, int);

void vecSetFloat(vector*, float, float, float);

void vecSetComplex(vector*, complex, complex, complex);

#endif 
