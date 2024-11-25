#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NodeTree {

    int height;
    int key;
    char *value;

    struct NodeTree *father;
    struct NodeTree *left;
    struct NodeTree *right;
} NodeTree;

int max(int a, int b) {
    return (a > b) ? a : b;
}

NodeTree* createTree(void) {
    NodeTree* root = malloc(sizeof(NodeTree*));
    root = NULL;
    return root;
}

NodeTree* createNode(char* value, int key, NodeTree *root) {
    // Выделение памяти на value
    NodeTree* node = (NodeTree*)malloc(sizeof(NodeTree));
    char* str = (char*)malloc(strlen(value) + 1);
    strcpy(str, value);

    // Копирование ключа и значения в новый узел
    node->key = key;
    node->value = str;

    node->height = 1;

    // Присваивание указателей новому узлу
    node->father = root;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int newHeit(NodeTree *root) {
    if ((root->right != NULL) && (root->left != NULL)) {
        return max(root->left->height, root->right->height) + 1;
    } else if (root->left != 0) {
        return root->left->height + 1;
    } else if (root->right != 0) {
        return root->right->height + 1;
    } else {
        return 1;
    }
}

NodeTree *rightRotate(NodeTree *root) {
    void *leftSubtree = root->left;
    void *leftRightSudtree = root->left->right;

    if (root->father == NULL) {
        // Если это корень всего дерева
        root->father = leftSubtree;
        root->left->father = NULL;

        root->left->right = root;
        root->left = leftRightSudtree;
    } else if (root->father->left == root) {
        root->father->left = leftSubtree;

        root->left->father = root->father;
        root->father = leftSubtree;

        root->left->right = root;
        root->left = leftRightSudtree;
    } else if (root->father->right == root) {
        root->father->right = leftSubtree;

        root->left->father = root->father;
        root->father = leftSubtree;

        root->left->right = root;
        root->left = leftRightSudtree;
    }

    root = leftSubtree;
    root->left->height = newHeit(root->left);
    root->right->height = newHeit(root->right);
    root->height = newHeit(root);

    return root;
}

NodeTree *leftRotate(NodeTree *root) {
    void *rightSubtree = root->right;
    void *rightLeftSudtree = root->right->left;

    if (root->father == NULL) {
        // Если это корень всего дерева
        root->father = rightSubtree;
        root->right->father = NULL;

        root->right->left = root;
        root->right = rightLeftSudtree;
    } else if (root->father->left == root) {
        root->father->left = rightSubtree;

        root->right->father = root->father;
        root->father = rightSubtree;

        root->right->left = root;
        root->right = rightLeftSudtree;
    } else if (root->father->right == root) {
        root->father->right = rightLeftSudtree;

        root->right->father = root->father;
        root->father = rightSubtree;

        root->right->left = root;
        root->right = rightLeftSudtree;
    }

    root = rightSubtree;
    root->left->height = newHeit(root->left);
    root->right->height = newHeit(root->right);
    root->height = newHeit(root);

    return root;
}

NodeTree* addElement(char* value, int key, NodeTree* root) {
    if (root == NULL) {
        return createNode(value, key, root);
    }

    int rotate = 0; // -1 если вставка была в левом поддереве, 1, если в правом

    if (key < root->key) {
        root->left = addElement(value, key, root->left);
        rotate = -1;
        root->height = newHeit(root);
    } else if (key > root->key) {
        root->right = addElement(value, key, root->right);
        rotate = 1;
        root->height = newHeit(root);
    } else {
        // Если ключ совпадает
        free(root->value);
        char* str = (char*)malloc(strlen(value) + 1);
        strcpy(str, value);
        root->value = str;
        return root;
    }

    // Балансировка
    int leftHeight = 0;
    int rightHeight = 0;

    if (root->left == NULL) {
        leftHeight = 0;
    } else {
        leftHeight = root->left->height;
    }

    if (root->right == NULL) {
        rightHeight = 0;
    } else {
        rightHeight = root->right->height;
    }

    int balance = rightHeight - rightHeight;

    if ((balance > 1) && (root->left->right->height > root->left->left->height)) {
        leftRotate(root->left);
        root = rightRotate(root);
    } else if ((balance < -1) && (root->right->left->height > root->right->right->height)) {
        rightRotate(root->right);
        root = leftRotate(root);
    } else if ((balance < -1) && (rotate == 1)) {
        root = leftRotate(root);
    } else if ((balance > 1) && (rotate == -1)) {
        root = rightRotate(root);
    }

    return root;
}

