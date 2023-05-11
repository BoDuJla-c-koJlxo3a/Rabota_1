#include "element.h"
#include <stdio.h>

number numNew() {
	number num;
	num.type = 1;
	num.Re = 0;
	num.Im = 0;
	return num;
}

number sum(number* a, number* b) {
	number c = numNew();
	if (!a || !b) {
		return c;
	}
	switch (a->type) {
	case 1:
		switch (b->type) {
		case 1:
			c.type = 1;
			c.Re = (int)(a->Re) + (int)(b->Re);
			break;
		case 2:
			c.type = 2;
			c.Re = (int)(a->Re) + b->Re;
			break;
		case 3:
			c.type = 3;
			c.Im = b->Im;
			c.Re = b->Re + (int)(a->Re);
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (b->type) {
		case 1:
			c.type = 2;
			c.Re = a->Re + (int)(b->Re);
			break;
		case 2:
			c.type = 2;
			c.Re = a->Re + b->Re;
			break;
		case 3:
			c.type = 3;
			c.Im = b->Im;
			c.Re = b->Re + a->Re;
			break;
		default:
			break;
		}
		break;
	case 3:
		switch (b->type) {
		case 1:
			c.type = 3;
			c.Im = a->Im;
			c.Re = a->Re + (int)(b->Re);
			break;
		case 2:
			c.type = 3;
			c.Im = a->Im;
			c.Re = a->Re + b->Re;
			break;
		case 3:
			c.type = 3;
			c.Im = a->Im + b->Im;
			c.Re = a->Re + b->Re;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return c;
}

number mult(number* a, number* b) {
	number c = numNew();
	if (!a || !b) {
		return c;
	}
	switch (a->type) {
	case 1:
		switch (b->type) {
		case 1:
			c.type = 1;
			c.Re = (int)(a->Re) * (int)(b->Re);
			break;
		case 2:
			c.type = 2;
			c.Re = (int)(a->Re) * b->Re;
			break;
		case 3:
			c.type = 3;
			c.Im = b->Im * (int)(a->Re);
			c.Re = b->Re * (int)(a->Re);
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (b->type) {
		case 1:
			c.type = 2;
			c.Re = a->Re * (int)(b->Re);
			break;
		case 2:
			c.type = 2;
			c.Re = a->Re * b->Re;
			break;
		case 3:
			c.type = 3;
			c.Im = b->Im * a->Re;
			c.Re = b->Re * a->Re;
			break;
		default:
			break;
		}
		break;
	case 3:
		switch (b->type) {
		case 1:
			c.type = 3;
			c.Im = a->Im * (int)(b->Re);
			c.Re = a->Re * (int)(b->Re);
			break;
		case 2:
			c.type = 3;
			c.Im = a->Im * b->Re;
			c.Re = a->Re * b->Re;
			break;
		case 3:
			c.type = 3;
			c.Im = (a->Re * b->Im) + (a->Im * b->Re);
			c.Re = (a->Re * b->Re) - (a->Im * b->Im);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return c;
}

void printfnumber(number* n) {
	switch (n->type) {
	case 1:
		printf("%d", (int)(n->Re));
		break;
	case 2:
		printf("%f", n->Re);
		break;
	case 3:
		printf("{%f; %f}", n->Re, n->Im);
		break;
	default:
		break;
	}
	printf(" ");
}