#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "tree.h"

typedef struct NodeTree {
    char* value;
    int key;
    struct NodeTree* left;
    struct NodeTree* right;
} NodeTree;

NodeTree* createNode(char* value, int key) {
    NodeTree* node = (NodeTree*)malloc(sizeof(NodeTree));
    char* str = (char*)malloc(strlen(value) + 1);
    strcpy(str, value);
    node->key = key;
    node->value = str;
    node->left = NULL;
    node->right = NULL;
    return node;
}

NodeTree* createTree(void) {
    NodeTree* root = malloc(sizeof(NodeTree*));
    root = NULL;
    return root;
}

NodeTree* addElement(char* value, int key, NodeTree* root) {
    if (root == NULL) {
        return createNode(value, key);
    }

    if (key < root->key) {
        root->left = addElement(value, key, root->left);
    } else if (key > root->key) {
        root->right = addElement(value, key, root->right);
    } else {
        // Если ключ совпадает
        free(root->value);
        char* str = (char*)malloc(strlen(value) + 1);
        strcpy(str, value);
        root->value = str;
    }

    return root;
}

bool isHaveKey(int key, NodeTree* root) {
    if (root->key == key) {
        return true;
    } else if ((root->key > key) && (root->left != NULL)) {
        return isHaveKey(key, root->left);
    } else if ((root->key < key) && (root->right != NULL)) {
        return isHaveKey(key, root->right);
    } else {
        return false;
    }
}

char* getValueKey(int key, NodeTree* root) {
    if (root->key == key) {
        return root->value;
    } else if ((root->key > key) && (root->left != NULL)) {
        return getValueKey(key, root->left);
    } else if ((root->key < key) && (root->right != NULL)) {
        return getValueKey(key, root->right);
    } else {
        return NULL;
    }
}

NodeTree* searchFatherMinChild(NodeTree* root) {
    if ((*root).left == NULL) {
        // Возвращаем NULL, если элемент и так минимальный
        return NULL;
    }
    if (root->left->left == NULL) {
        // Если следуюший - корень минимального, возвращаем указатель на него
        return root->left;
    } else {
        // проходим дальше по рекурсии
        return searchFatherMinChild(root->left);
    }
}

NodeTree* deleteElement(int key, NodeTree* root) {
    if (!isHaveKey(key, root)) {
        return root;
    }

    // если элемент единственный
    if ((root->right == NULL) && (root->left == NULL)) {
        free(root->value);
        free(root);
        return NULL;
    }

    // Если удаляемый элемент - лист
    if ((root->right->key == key) && (root->right->left == NULL) && (root->right->right == NULL)){
        // Если лист справа
        free(root->right->value);
        free(root->right);
        root->right = NULL;
        return root;
    } else if ((root->left->key == key) && (root->left->left == NULL) && (root->left->right == NULL)){
        // Если лист слева
        free(root->left->value);
        free(root->left);
        root->left = NULL;
        return root;
    }

    if ((root->key == key) && (searchFatherMinChild(root->right) != NULL)) {
        free(root->value);
        void* left = root->left;
        // копирую минимального правого в root
        *root = *(searchFatherMinChild(root->right)->left);
        root->left = left;
        // Удаляю минимального правого
        free(searchFatherMinChild(root->right)->left);
        searchFatherMinChild(root->right)->left = NULL;
        return root;
    } else if ((root->key == key) && (root->right != NULL)) {
        // Если правый минимальный
        free(root->value);
        void* left = root->left;
        *root = *(root->right);
        root->left = left;
        free(root->right);
        return root;
    } else if ((root->key == key) && (root->left != NULL)) {
        // Если правого нет
        free(root->value);
        *root = *(root->left);
        return root;
    } else if (root->key > key) {
        root->left = deleteElement(key, root->left);
        return root;
    } else if (root->key < key) {
        root->right = deleteElement(key, root->right);
        return root;
    }

    return root;
}