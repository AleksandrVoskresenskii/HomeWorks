#include <stdlib.h>

#ifndef HASH_H
#define HASH_H

// Структура узла списка
typedef struct listNode {
    char* data;
    struct listNode* next;
} listNode;

// Создает узел списка и выводит указатель на него
listNode* createNode(listNode* list, char* data);

#endif