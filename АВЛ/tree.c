#include <stdio.h>


typedef struct NodeTree {
    int height;
    int key;
    const char *value;
    NodeTree *left;
    NodeTree *right;
} NodeTree;

NodeTree* createTree(void) {
    NodeTree* root = malloc(sizeof(NodeTree*));
    root = NULL;
    return root;
}

NodeTree* createNode(char* value, int key) {
    NodeTree* node = (NodeTree*)malloc(sizeof(NodeTree));
    char* str = (char*)malloc(strlen(value) + 1);
    strcpy(str, value);
    node->key = key;
    node->value = str;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
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

    // добавить баланс

    return root;
}

