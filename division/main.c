#include <stdio.h>
#include <stdlib.h>

int division(int a, int b) {
    // Проверка на деление на ноль
    if (b == 0) {
        fprintf(stderr, "Error: division by zero\n");
        exit(1);
    }

    // Определяем знак результата
    int sign = 1;
    if (a < 0) {
        sign = -sign;
        a = -a;
    }
    if (b < 0) {
        sign = -sign;
        b = -b;
    }

    int divResult = 0;
    int sum = 0;

    // Прибавляем b пока sum <= a
    while (sum + b <= a) {
        sum = sum + b;
        divResult = divResult + 1;
    }

    divResult *= sign;

    return divResult;
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
    printf("-5 / 2 = %d\n", division(a,b));    // -2
    a = -5;
    b = -2;
    printf("-5 / -2 = %d\n", division(a,b));   //  2

    return 0;
}