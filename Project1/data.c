#include "data.h"
#include <stdlib.h>

complex intToComplex(int n) {
	complex c;
	c.Re = (float)n;
	c.Im = 0;
}

complex floatToComplex(float n) {
	complex c;
	c.Re = n;
	c.Im = 0;
}

vector *vecNew() {
	vector *vec = calloc(1, sizeof(vector));
	if (!vec) {
		return NULL;
	}
	return vec;
}

void vecDel(vector *vec) {
	if (vec) {
		if (vec -> x) {
			free(vec->x);
		}
		if (vec->y) {
			free(vec->y);
		}
		if (vec->z) {
			free(vec->z);
		}
		free(vec);
	}
}

int getXi(vector *vec) {
	if (!vec) {
		return 0;
	}
	int *adr = vec->x;
	return *adr;
}

int getYi(vector* vec) {
	if (!vec) {
		return 0;
	}
	int *adr = vec->y;
	return *adr;
}

int getZi(vector* vec) {
	if (!vec) {
		return 0;
	}
	int *adr = vec->z;
	return *adr;
}

float getXf(vector* vec) {
	if (!vec) {
		return 0;
	}
	float *adr = vec->x;
	return *adr;
}

float getYf(vector* vec) {
	if (!vec) {
		return 0;
	}
	float* adr = vec->y;
	return *adr;
}

float getZf(vector* vec) {
	if (!vec) {
		return 0;
	}
	float* adr = vec->z;
	return *adr;
}

complex getXc(vector* vec) {
	if (!vec) {
		return intToComplex(0);
	}
	complex* adr = vec->x;
	return *adr;
}

complex getYc(vector* vec) {
	if (!vec) {
		return intToComplex(0);
	}
	complex* adr = vec->y;
	return *adr;
}

complex getZc(vector* vec) {
	if (!vec) {
		return intToComplex(0);
	}
	complex* adr = vec->z;
	return *adr;
}


void vecSetInt(vector* vec, int x, int y, int z) {
	if (!vec) {
		return;
	}
	if (vec->x) {
		free(vec->x);
	}
	if (vec->y) {
		free(vec->y);
	}
	if (vec->z) {
		free(vec->z);
	}
	vec->x = malloc(sizeof(int));
	vec->y = malloc(sizeof(int));
	vec->z = malloc(sizeof(int));
	int *adr = vec->x;
	*adr = x;
	adr = vec->y;
	*adr = y;
	adr = vec->z;
	*adr = z;
}

void vecSetFloat(vector* vec, float x, float y, float z) {
	if (!vec) {
		return;
	}
	if (vec->x) {
		free(vec->x);
	}
	if (vec->y) {
		free(vec->y);
	}
	if (vec->z) {
		free(vec->z);
	}
	vec->x = malloc(sizeof(float));
	vec->y = malloc(sizeof(float));
	vec->z = malloc(sizeof(float));
	float *adr = vec->x;
	*adr = x;
	adr = vec->y;
	*adr = y;
	adr = vec->z;
	*adr = z;
}

void vecSetComplex(vector* vec, complex x, complex y, complex z) {
	if (!vec) {
		return;
	}
	if (vec->x) {
		free(vec->x);
	}
	if (vec->y) {
		free(vec->y);
	}
	if (vec->z) {
		free(vec->z);
	}
	vec->x = malloc(sizeof(complex));
	vec->y = malloc(sizeof(complex));
	vec->z = malloc(sizeof(complex));
	complex *adr = vec->x;
	*adr = x;
	adr = vec->y;
	*adr = y;
	adr = vec->z;
	*adr = z;
}
