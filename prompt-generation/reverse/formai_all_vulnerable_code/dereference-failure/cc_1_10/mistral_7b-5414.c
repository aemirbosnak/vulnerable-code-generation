//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define HEIGHT 20
#define WIDTH 35

typedef struct FractalTreeNode {
    int depth;
    double x, y;
    struct FractalTreeNode *left, *right;
} FractalTreeNode;

void print_tree(FractalTreeNode *node, int level) {
    char symbol = (level % 2 == 0) ? '^' : 'v';
    int pos_x = round(node->x * WIDTH);
    int pos_y = round(node->y * HEIGHT);

    if (node != NULL) {
        printf("\033[%d;%dH%c", pos_y, pos_x, symbol);
        fflush(stdout);

        print_tree(node->left, level + 1);
        print_tree(node->right, level + 1);
    }
}

void generate_tree(FractalTreeNode **node, int depth) {
    if (*node == NULL) {
        *node = (FractalTreeNode *) malloc(sizeof(FractalTreeNode));
        (*node)->depth = depth;
        (*node)->x = pow(0.5, depth);
        (*node)->y = (depth % 2 == 0) ? pow(0.5, depth) : -pow(0.5, depth);
        (*node)->left = NULL;
        (*node)->right = NULL;
    } else {
        generate_tree(&((*node)->left), depth + 1);
        generate_tree(&((*node)->right), depth + 1);
    }
}

int main() {
    FractalTreeNode *root = NULL;

    generate_tree(&root, 0);

    system("clear"); // or "cls" for Windows

    print_tree(root, 0);

    free(root);

    return 0;
}