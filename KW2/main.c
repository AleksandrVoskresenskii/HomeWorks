#include <stdio.h>

#include "sorted.h"

int main(void) {
    int array[] = {5, 397, 34, 3, 537, 2, 1, 325, 90, 55, 55};
    int sizeTree = sizeof(array) / sizeof(array[0]);

    treeSort(array, sizeTree);

    for(int i = 0; i < sizeTree; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}