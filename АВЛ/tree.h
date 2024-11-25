#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Узел дерева
typedef struct NodeTree NodeTree;

// Функция создания пустого дерева, возвращает указатель на дерево
NodeTree* createTree(void);

// Добавляет узел по значению ключа key в дерево root
NodeTree* addElement(char* value, int key, NodeTree* root);

// Функция создания узла дерева
NodeTree* createNode(char* value, int key, NodeTree *root);

// Возвращает максимальный из двух элементов
int max(int a, int b);

// Пересчитывает высоту узла по указателю
int newHeit(NodeTree *root);

// Делает правый поворот АВЛ дерева
NodeTree *rightRotate(NodeTree *root);

// Делает левый поворот АВЛ дерева
NodeTree *leftRotate(NodeTree *root);

#endif