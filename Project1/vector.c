#include "vector.h"
#include "element.h"
#include <stdio.h>

vector vecNew() {                                   //—Œ«ƒ¿Õ»≈ ¬≈ “Œ–¿
	vector vec;
	vec.array = NULL;
	vec.len = 0;
	return vec;
}

void vecDel(vector vec) {
	for (int i = 0; i < vec.len; i++) {
		free(vec.array[i]);
	}
	free(vec.array);
}

void vecAddDim(vector *vec, void* n) {           //«¿œ»’»¬¿≈Ã ¬ ¬≈ “Œ– ≈Ÿ≈ ŒƒÕ”  ŒŒ–ƒ»Õ¿“”
	size_t len = vec -> len + 1;
	vec -> len = len;
	vec -> array = realloc(vec -> array, len*sizeof(void*));
	vec -> array[len - 1] = n;
}

int getInt(vector vec, size_t n) {
	int* adr = (vec.array)[n];
	return *adr;
}

vector vecSum(vector *v1, vector *v2) {
	while (v1->len < v2->len || (v1->len == 0 && v2->len == 0)) {
		number* adr = malloc(sizeof(number));
		*adr = numNew();
		vecAddDim(v1, adr);
	}
	while (v1->len > v2->len) {
		number* adr = malloc(sizeof(number));
		*adr = numNew();
		vecAddDim(v2, adr);
	}
	vector v3;
	v3.len = 0;
	v3.array = NULL;
	for (int i = 0; i < v1->len; i++) {
		number* adr = malloc(sizeof(number));
		*adr = sum(*(v1->array + i), *(v2->array + i));
		vecAddDim(&v3, adr);
	}
	return v3;
}

vector vecMultNum(vector vec, number n) {
	vector v3;
	v3.len = 0;
	v3.array = NULL;
	for (int i = 0; i < vec.len; i++) {
		number* adr = malloc(sizeof(number));
		*adr = mult(*(vec.array + i), &n);
		vecAddDim(&v3, adr);
	}
	return v3;
}

number vecScalarMult(vector a, vector b) {
	number c = numNew();
	number d = numNew();
	for (int i = 0; (i < a.len) && (i < b.len); i++) {
		d = mult(*(a.array + i), *(b.array + i));
		c = sum(&c, &d);
	}
	return c;
}