#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

// Узел дерева
typedef struct NodeTree NodeTree;

// Функция создания узла дерева
NodeTree* createNode(char* value, int key);

// Функция создания пустого дерева, возвращает указатель на дерево
NodeTree* createTree(void);

// Добавляет узел по значению ключа key в дерево root
NodeTree* addElement(char* value, int key, NodeTree* root);

#endif