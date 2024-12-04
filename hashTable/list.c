#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void addToList(List* list, const char* key) {
    Node* node = findInList(list, key);
    if (node) {
        node->value++;
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = strdup(key);
        newNode->value = 1;
        newNode->next = list->head;
        list->head = newNode;
    }
}

Node* findInList(List* list, const char* key) {
    Node* current = list->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int getListLength(List* list) {
    int length = 0;
    Node* current = list->head;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

void freeList(List* list) {
    Node* current = list->head;
    while (current) {
        Node* temp = current;
        free(current->key);
        current = current->next;
        free(temp);
    }
    free(list);
}