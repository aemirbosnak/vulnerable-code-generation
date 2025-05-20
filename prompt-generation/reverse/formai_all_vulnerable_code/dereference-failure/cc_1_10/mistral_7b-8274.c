//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

void print_tree(TreeNode *root, int height) {
    int i;

    if (root == NULL) {
        printf("\n");
        return;
    }

    print_tree(root->right, height + 1);

    for (i = height; i < 2 * height + 1; i++)
        printf(" ");

    printf("(%d)\n", root->data);

    print_tree(root->left, height + 1);
}

void create_node(TreeNode **tree, int data) {
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    *tree = new_node;
}

void insert(TreeNode **tree, int data) {
    if (*tree == NULL) {
        create_node(tree, data);
        return;
    }

    if (data < (*tree)->data)
        insert(&(*tree)->left, data);
    else
        insert(&(*tree)->right, data);
}

void draw_branch(int length) {
    int i;

    for (i = length; i > 0; i--)
        putchar('\\');
    putchar('/');
}

void draw_tree(int height, TreeNode *tree) {
    int i;

    if (tree == NULL) {
        for (i = 0; i < height; i++)
            putchar(' ');
        putchar('^');
        putchar('\n');
        return;
    }

    draw_tree(height + 1, tree->right);

    for (i = 2 * height; i > 2 * height - 2; i--)
        putchar(' ');

    if (tree->left != NULL)
        putchar('|');
    else
        putchar(' ');

    putchar('O');

    if (tree->right != NULL)
        putchar('|');
    else
        putchar(' ');

    printf("%d\n", tree->data);

    draw_tree(height + 1, tree->left);
}

int main() {
    TreeNode *tree = NULL;

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        insert(&tree, rand() % 20);

    print_tree(tree, 0);

    printf("\n");

    int height = 0;
    draw_tree(height, tree);

    return 0;
}