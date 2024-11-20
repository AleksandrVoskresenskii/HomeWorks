#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

typedef struct NodeTree {
    char* value;
    int key;
    struct NodeTree* left;
    struct NodeTree* right;
} NodeTree;

NodeTree* createNode(char value, int key) {
    NodeTree* node = (NodeTree*)malloc(sizeof(NodeTree));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}