#define _CRT_SECURE_NO_WARNINGS
#include "cycle.h"
#include "interaction.h"
#include <stdio.h>

int menu() {
    int d = 0, r = 0;
    while ((r != 1) || (d > 8) || (d < 1)) {
        printf("Введите номер действия:\n1)Инициализировать массив векторов\n2)Добавить вектор в массив\n3)Удалить вектор из массива\n4)Сложить вектора\n5)Умножить вектор на число\n6)Скалярное произведение\n7)Вывод массива\n8)Выход\n>");
        r = scanf("%d", &d);
        if (r == EOF) {
            return 0;
        }
        while (getchar() != '\n');
    }
    return d;
}


int cycle(vector **arr, size_t *l) {
    int inic = 1;
    int r = 1;
    if (!r) {
        return 1;
    }
    while (1) {
        r = menu();
        if (!r) {
            return 1;
        }
        switch (r) {
        case 1:
            if (inic) {
                inic = init(arr, l);
                if (inic) {
                    return 1;
                }
            }
            else {
                printf("Массив уже инициализирован!!!\n");
            }
            break;

        case 2:
            if (inic) {
                printf("Массив не инициализирован!!!\n");
            }
            else {
                if (insertU(arr, l)) {
                    return 1;
                }
            }
            break;
        case 3:
            if (inic) {
                printf("Массив не инициализирован!!!\n");
            }
            else {
                if (delU(arr, l)) {
                    return 1;
                }
            }
            break;
        case 4:
            if (*l <= 0) {
                printf("Массив пуст!!!\n");
            }
            else {
                if (vecSumU(arr, l)) {
                    return 1;
                }
            }
            break;
        case 5:
            if (*l <= 0) {
                printf("Массив пуст!!!\n");
            }
            else {
                if (vecMultNumU(arr, l)) {
                    return 1;
                }
            }
            break;
        case 6:
            if (*l <= 0) {
                printf("Массив пуст!!!\n");
            }
            else {
                number s = vecScalarMultU(arr, l);
                printf("Скалярное произведение: ");
                printfnumber(&s);
                printf("\n");
            }
            break;
        case 7:
            if (*l <= 0) {
                printf("Массив пуст!!!\n");
            }
            else {
                printf("Ваш массив (%lu):\n", (*l));
                printarr((*arr), (*l));
            }
            break;
        case 8:
            printf("ВЫХОД\n");
            return 0;
            break;
        }
    }

}