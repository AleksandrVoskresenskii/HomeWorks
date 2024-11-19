#include "tree.h"

typedef struct NodeTree {
    char op; // '+', '-', '*', '/' или '\0'
    int value; // Значение для числа
    struct NodeTree* left;
    struct NodeTree* right;
} NodeTree;

NodeTree* createNode(char op, int value) {
    NodeTree* node = (NodeTree*)malloc(sizeof(NodeTree));
    node->op = op;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

NodeTree* parseExpression(FILE* file) {
    int ch = fgetc(file);
    
    // Пропускаем пробелы
    while (isspace(ch)) {
        ch = fgetc(file);
    }

    if (ch == '(') {
        // Читаем операцию
        char op = fgetc(file);
        NodeTree* node = createNode(op, 0);

        // Рекурсивно разбираем левый и правый операнды
        node->left = parseExpression(file);
        node->right = parseExpression(file);

        // Ожидаем закрывающую скобку
        ch = fgetc(file);
        if (ch != ')') {
            printf("Error: Expected ')'\n");
            exit;
        }

        return node;
    } else {
        // Возвращаем символ в поток и читаем число
        ungetc(ch, file);
        int value;
        if (fscanf(file, "%d", &value) != 1) {
            printf("Error: Expected number\n");
            exit;
        }
        return createNode('\0', value);
    }
}

void printTree(NodeTree* root) {

}