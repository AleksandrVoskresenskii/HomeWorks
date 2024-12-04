#include <stdio.h>
#include <stdlib.h>

#include "sorted.h"

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* addNode(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = addNode(root->left, key);
    } else {
        root->right = addNode(root->right, key);
    }

    return root;
}

void treeTraversal(Node* root, int* array, int* index) {
    if (root == NULL) {
        return;
    }

    treeTraversal(root->left, array, index);
    array[(*index)++] = root->key;
    treeTraversal(root->right, array, index);
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void treeSort(int* array, int sizeArray) {
    Node* root = NULL;

    // Строим дерево
    for (int i = 0; i < sizeArray; i++) {
        root = addNode(root, array[i]);
    }

    int index = 0;
    treeTraversal(root, array, &index);

    freeTree(root);
}