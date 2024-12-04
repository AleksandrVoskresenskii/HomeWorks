#ifndef SORTED_H
#define SORTED_H

// Структура узла дерева
typedef struct Node Node;

// Функция создания нового узла
Node* createNode(int key);

// Функция для добавления узла в дерево
Node* addNode(Node* root, int key);

// Функция для очистки дерева
void freeTree(Node* root);

// Функция сортировки
void treeSort(int* array, int size);

// Обход дерева в порядке возрастания и запись элементов в массив
void treeTraversal(Node* root, int* array, int* index);

#endif