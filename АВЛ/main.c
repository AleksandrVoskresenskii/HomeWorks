#include "tree.h"

int main(void) {
    NodeTree *tree = createTree();
    tree = addElement("a", 123, tree);
    tree = addElement("b", 124, tree);
    tree = addElement("c", 125, tree);
    tree = addElement("d", 126, tree);
    tree = addElement("e", 127, tree);
    tree = addElement("f", 128, tree);
    return 0;
}