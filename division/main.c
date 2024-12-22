#include <stdio.h>
#include <stdlib.h>

int division(int a, int b) {
    // 1. Проверка деления на ноль
    if (b == 0) {
        fprintf(stderr, "Error: division by zero!\n");
        exit(EXIT_FAILURE);
    }

    // Случай a >= 0, b > 0
    if (a >= 0 && b > 0) {
        int count = 0;
        int temp = a;
        while (temp >= b) {
            temp = temp - b;
            count = count + 1;
        }
        return count;
    }

    // Случай a >= 0, b < 0
    if (a >= 0 && b < 0) {
        int count = 0;
        int temp = a;
        int b_abs = (b < 0) ? -b : b;
        while (temp >= b_abs) {
            temp = temp - b_abs;
            count = count + 1;
        }
        return -count;
    }

    // Случай a < 0, b > 0
    if (a < 0 && b > 0) {
        int count = 0;
        int a_abs = -a;
        int temp = a_abs;
        while (temp >= b) {
            temp = temp - b;
            count = count + 1;
        }
        if (temp > 0) {
            count = count + 1;
        }
        return -count;
    }

    // Случай a < 0, b < 0
    if (a < 0 && b < 0) {
        int count = 0;
        int a_abs = -a;
        int b_abs = -b;
        int temp = a_abs;
        while (temp >= b_abs) {
            temp = temp - b_abs;
            count = count + 1;
        }
        if (temp > 0) {
            count = count + 1;
        }
        return count;
    }

    return 0;
}

int main(void) {
    int a, b;

    a = 5;
    b = 2;
    printf("5 / 2 = %d\n", division(a,b));     //  2
    a = 5;
    b = -2;
    printf("5 / -2 = %d\n", division(a,b));    // -2
    a = -5;
    b = 2;
    printf("-5 / 2 = %d\n", division(a,b));    // -3
    a = -5;
    b = -2;
    printf("-5 / -2 = %d\n", division(a,b));   //  3

    return 0;
}