#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sorted.h"

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

void testCreateNode() {
    Node* node = createNode(10);
    assert(node != NULL);
    assert(node->key == 10);
    assert(node->left == NULL);
    assert(node->right == NULL);
    free(node);
}

void testAddNode() {
    Node* root = NULL;
    root = addNode(root, 10);
    root = addNode(root, 5);
    root = addNode(root, 15);

    assert(root != NULL);
    assert(root->key == 10);
    assert(root->left != NULL && root->left->key == 5);
    assert(root->right != NULL && root->right->key == 15);

    freeTree(root);
}

void testTreeTraversal() {
    Node* root = NULL;
    root = addNode(root, 10);
    root = addNode(root, 5);
    root = addNode(root, 15);

    int array[3];
    int index = 0;
    treeTraversal(root, array, &index);

    assert(array[0] == 5);
    assert(array[1] == 10);
    assert(array[2] == 15);

    freeTree(root);
}

void testTreeSort() {
    int array[] = {5, 2, 8, 1, 3};
    int expected[] = {1, 2, 3, 5, 8};
    int size = sizeof(array) / sizeof(array[0]);

    treeSort(array, size);

    for (int i = 0; i < size; i++) {
        assert(array[i] == expected[i]);
    }
}

void testFreeTree() {
    Node* root = NULL;
    root = addNode(root, 10);
    root = addNode(root, 5);
    root = addNode(root, 15);

    freeTree(root);
}

void tests(void){
    testCreateNode();
    testAddNode();
    testTreeTraversal();
    testTreeSort();
    testFreeTree();
}

int main(void) {

    tests();

    int array[] = {5, 397, 34, 3, 537, 2, 1, 325, 90, 55, 55};
    int sizeTree = sizeof(array) / sizeof(array[0]);

    treeSort(array, sizeTree);

    for(int i = 0; i < sizeTree; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}