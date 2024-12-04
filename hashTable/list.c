#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    char* data;
    struct listNode* next;
} listNode;

listNode* createNode(listNode* list, char* data) {
    listNode* node = malloc(sizeof(listNode));

    node->data = data;
    node->next = NULL;

    return node;
}