#define _CRT_SECURE_NO_WARNINGS
#include "interaction.h"
#include <stdio.h>

int init(vector** a, size_t* l) {
    int r = 0, n = 0, t = 0, num = 0;
    float numf = 0;
    while ((r != 1) || (n < 0)) {
        printf("Введите количество элементов массива:\n>");
        r = scanf("%d", &n);
        if (r == EOF) {
            return 1;
        }
        while (getchar() != '\n');
    }
    (*a) = realloc((*a), n * sizeof(vector));
    if ((*a) == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    *l = n;
    for (int i = 0; i < n; i++) {
        (*a)[i] = vecNew();
    }
    printf("Введите %d векторов:\n", n);
    r = 0;
    for (int i = 0; i < *l; i++) {
        while ((r != 1) || (n < 1)) {
            printf("Введите размерность вектора %d\n>", i + 1);
            r = scanf("%d", &n);
            if (r == EOF) {
                return 1;
            }
            while (getchar() != '\n');
        }
        r = 0;
        (*a)[i].len = 0;
        for (int j = 0; j < n; j++) {
            number* adr = malloc(sizeof(number));
            *adr = numNew();
            while ((r != 1) || (t < 1) || (t > 3)) {
                printf("Введите 1 - целое число, 2 - рациональное, 3 - комплексное\n>");
                r = scanf("%d", &t);
                if (r == EOF) {
                    return 1;
                }
                while (getchar() != '\n');
            }
            r = 0;
            switch (t) {
            case 1:
                while (r != 1) {
                    printf("Введите %d координату\n>", j+1);
                    r = scanf("%d", &num);
                    if (r == EOF) {
                        return 1;
                    }
                    while (getchar() != '\n');
                }
                r = 0;
                adr->type = 1;
                adr->Re = num;
                adr->Im = 0;
                vecAddDim((*a) + i, adr);
                break;
            case 2:
                while (r != 1) {
                    printf("Введите %d координату\n>", j + 1);
                    r = scanf("%f", &numf);
                    if (r == EOF) {
                        return 1;
                    }
                    while (getchar() != '\n');
                }
                r = 0;
                adr->type = 2;
                adr->Re = numf;
                adr->Im = 0;
                vecAddDim((*a) + i, adr);
                break;
            case 3:
                while (r != 1) {
                    printf("Введите действительную часть\n>");
                    r = scanf("%f", &numf);
                    if (r == EOF) {
                        return 1;
                    }
                    while (getchar() != '\n');
                }
                r = 0;
                adr->type = 3;
                adr->Re = numf;
                while (r != 1) {
                    printf("Введите мнимую часть\n>");
                    r = scanf("%f", &numf);
                    if (r == EOF) {
                        return 1;
                    }
                    while (getchar() != '\n');
                }
                r = 0;
                adr->Im = numf;
                vecAddDim((*a) + i, adr);
                break;
            }
        }
    }
    return 0;
}

int insert(vector** a, size_t* l, size_t n, vector vec) {
    (*a) = realloc(*a, (*l + 1) * sizeof(vector));
    if ((*a) == NULL) {
        return 1;
    }
    if (n >= *l) {
        n = *l;
    }
    else {
        for (int i = (*l); i > n; i--) {
            (*a)[i] = (*a)[i - 1];
        }
    }
    *l = *l + 1;
    (*a)[n] = vec;
    return 0;
}

int insertU(vector** a, size_t* l) {
    int r = 0, num = 0, d = 0, t = 0;
    size_t n = 0;
    vector vec = vecNew();
    float numf = 0;
    while ((r != 1) || (n < 0)) {
        printf("Введите индекс элемента (куда вставлять вектор)\n");
        r = scanf("%d", &n);
        if (r == EOF) {
            return 1;
        }
        while (getchar() != '\n');
    }
    r = 0;
    while ((r != 1) || (d < 1)) {
        printf("Введите размерность вектора\n>");
        r = scanf("%d", &d);
        if (r == EOF) {
            return 1;
        }
        while (getchar() != '\n');
    }
    r = 0;
    for (int j = 0; j < d; j++) {
        number* adr = malloc(sizeof(number));
        *adr = numNew();
        while ((r != 1) || (t < 1) || (t > 3)) {
            printf("Выберете: 1 - целое число, 2 - рациональное, 3 - комплексное\n>");
            r = scanf("%d", &t);
            if (r == EOF) {
                return 1;
            }
            while (getchar() != '\n');
        }
        r = 0;
        switch (t) {
        case 1:
            while (r != 1) {
                printf("Введите %d координату\n>", j + 1);
                r = scanf("%d", &num);
                if (r == EOF) {
                    return 1;
                }
                while (getchar() != '\n');
            }
            r = 0;
            adr->type = 1;
            adr->Re = num;
            adr->Im = 0;
            vecAddDim(&vec, adr);
            break;
        case 2:
            while (r != 1) {
                printf("Введите %d координату\n>", j + 1);
                r = scanf("%f", &numf);
                if (r == EOF) {
                    return 1;
                }
                while (getchar() != '\n');
            }
            r = 0;
            adr->type = 2;
            adr->Re = numf;
            adr->Im = 0;
            vecAddDim(&vec, adr);
            break;
        case 3:
            while (r != 1) {
                printf("Введите действительную часть\n>");
                r = scanf("%f", &numf);
                if (r == EOF) {
                    return 1;
                }
                while (getchar() != '\n');
            }
            r = 0;
            adr->type = 3;
            adr->Re = numf;
            while (r != 1) {
                printf("Введите мнимую часть\n>");
                r = scanf("%f", &numf);
                if (r == EOF) {
                    return 1;
                }
                while (getchar() != '\n');
            }
            r = 0;
            adr->Im = numf;
            vecAddDim(&vec, adr);
            break;
        }
    }
    if (insert(a, l, n, vec)) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    return 0;
}

int del(vector** a, size_t* l, int n) {
    if (*l > 0) {
        vecDel((*a)[n]);
        for (int i = (n); i < (*l - 1); i++) {
            (*a)[i] = (*a)[i + 1];
        }
        *l = *l - 1;
        (*a) = (int*)realloc(*a, (*l) * sizeof(vector));
        if ((*a) == NULL) {
            return 1;
        }
    }
    else {
        return 2;
    }
    return 0;
}


int delU(vector** a, size_t* l) {
    int r = 0, n = 0;
    while ((r != 1) || (n < 0) || (n > (*l - 1))) {
        printf("Введите номер вектора под удаление - число большее или равное 0, меньшее или равное %lu\n", (*l - 1));
        r = scanf("%d", &n);
        if (r == EOF) {
            return 1;
        }
        while (getchar() != '\n');
    }
    r = del(a, l, n);
    if (r == 1) {
        printf("Ошибка перевыделения памяти!\n");
        return 1;
    }
    if (r == 2) {
        printf("Нечего удалять!\n");
        return 0;
    }
}

int vecSumU(vector** a, size_t* l) {
    int r = 0, n1 = 0, n2 = 0;
    while ((r != 1) || (n1 < 0) || (n1 > (*l - 1))) {
        printf("Введите номер первого вектора-слагаемого - число большее или равное 0, меньшее или равное %lu\n", (*l - 1));
        r = scanf("%d", &n1);
        if (r == EOF) {
            return 1;
        }
        while (getchar() != '\n');
    }
    r = 0;
    while ((r != 1) || (n2 < 0) || (n2 > (*l - 1))) {
        printf("Введите номер второго вектора-слагаемого - число большее или равное 0, меньшее или равное %lu\n", (*l - 1));
        r = scanf("%d", &n2);
        if (r == EOF) {
            return 1;
        }
        while (getchar() != '\n');
    }
    vector vec = vecSum((*a) + n1, (*a) + n2);
    if (insert(a, l, *l, vec)) {
        return 1;
    }
    return 0;
}

int vecMultNumU(vector** a, size_t* l) {
    int r = 0, n1 = 0, t = 0, num;
    float numf = 0;
    number numm = numNew();
    while ((r != 1) || (n1 < 0) || (n1 > (*l - 1))) {
        printf("Введите номер вектора, который будет умножен на число - (0 - %lu)\n>", (*l - 1));
        r = scanf("%d", &n1);
        if (r == EOF) {
            return 1;
        }
        while (getchar() != '\n');
    }
    while ((r != 1) || (t < 1) || (t > 3)) {
        printf("Выберете: 1 - целое число, 2 - рациональное, 3 - комплексное\n>");
        r = scanf("%d", &t);
        if (r == EOF) {
            return 1;
        }
        while (getchar() != '\n');
    }
    r = 0;
    switch (t) {
    case 1:
        while (r != 1) {
            printf("Введите число\n>");
            r = scanf("%d", &num);
            if (r == EOF) {
                return 1;
            }
            while (getchar() != '\n');
        }
        r = 0;
        numm.Re = num;
        break;
    case 2:
        while (r != 1) {
            printf("Введите число\n>");
            r = scanf("%f", &numf);
            if (r == EOF) {
                return 1;
            }
            while (getchar() != '\n');
        }
        r = 0;
        numm.Re = numf;
        break;
    case 3:
        while (r != 1) {
            printf("Введите действительную часть\n>");
            r = scanf("%f", &numf);
            if (r == EOF) {
                return 1;
            }
            while (getchar() != '\n');
        }
        r = 0;
        numm.Re = numf;
        while (r != 1) {
            printf("Введите мнимую часть\n>");
            r = scanf("%f", &numf);
            if (r == EOF) {
                return 1;
            }
            while (getchar() != '\n');
        }
        r = 0;
        numm.Im = numf;
        break;
    }
    vector vec = vecMultNum((*a)[n1], numm);
    if (insert(a, l, l, vec)) {
        return 1;
    }
    return 0;
}

number vecScalarMultU(vector** a, size_t* l) {
    int r = 0, n1 = 0, n2 = 0;
    number num = numNew();
    while ((r != 1) || (n1 < 0) || (n1 > (*l - 1))) {
        printf("Введите номер первого вектора-множителя - число большее или равное 0, меньшее или равное %lu\n", (*l - 1));
        r = scanf("%d", &n1);
        if (r == EOF) {
            return num;
        }
        while (getchar() != '\n');
    }
    r = 0;
    while ((r != 1) || (n2 < 0) || (n2 > (*l - 1))) {
        printf("Введите номер второго вектора-множителя - число большее или равное 0, меньшее или равное %lu\n", (*l - 1));
        r = scanf("%d", &n2);
        if (r == EOF) {
            return num;
        }
        while (getchar() != '\n');
    }
    num = vecScalarMult((*a)[n1], (*a)[n2]);
    return num;
}

void printfVec(vector v) {
    printf("(");
    for (int i = 0; i < v.len; i++) {
        printfnumber((v.array)[i]);
    }
    printf(")\n");
}

void printarr(vector* a, size_t l) {
    for (int i = 0; i < l; i++) {
        printf("Вектор %d: ", i);
        printfVec(a[i]);
    }
}
