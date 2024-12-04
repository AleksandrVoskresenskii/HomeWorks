#ifndef LIST_H
#define LIST_H

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList();

void addToList(List* list, const char* key);

Node* findInList(List* list, const char* key);

int getListLength(List* list);

void freeList(List* list);

#endif