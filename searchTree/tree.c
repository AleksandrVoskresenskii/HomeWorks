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

NodeTree* createTree(void) {
    NodeTree* root = malloc(sizeof(NodeTree*));
    root = NULL;
    return root;
}

NodeTree* addElement(char value, int key, NodeTree* root) {
    if (root == NULL) {
        return createNode(value, key);
    }

    if (key < root->key) {
        root->left = addElement(value, key, root->left);
    } else if (key > root->key) {
        root->right = addElement(value, key, root->right);
    } else {
        // Если ключ совпадает
        (*root).value = value;
    }

    return root;
}
