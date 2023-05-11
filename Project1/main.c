#include <stdlib.h>
#include "vector.h"
#include "element.h"
#include "cycle.h"
#include <windows.h>


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector* arr = NULL;
	size_t l = 0;
	cycle(&arr, &l);
	for (int i = 0; i < l; i++) {
		vecDel(arr[i]);
	}
	free(arr);
	return 0;
}