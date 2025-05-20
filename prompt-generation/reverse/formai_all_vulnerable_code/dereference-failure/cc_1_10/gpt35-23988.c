//FormAI DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
// This program visualizes a simple binary tree data structure using randomly generated
// values for the nodes. The binary tree structure is as follows:
//
//      root
//       / \
//      /   \
//     /     \
//  left   right
//
// The program generates nodes with randomly assigned values and inserts them into the tree.
// The tree is then displayed in a graphical text format for a visual representation of the
// tree structure.
//
// By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

void insert(struct Node **node, int value) {
    if (*node == NULL) {
        *node = malloc(sizeof(struct Node));
        (*node)->value = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
    } else {
        if (value < ((*node)->value)) {
            insert(&(*node)->left, value);
        } else {
            insert(&(*node)->right, value);
        }
    }
}

void print_tree(struct Node *node, int depth) {
    if (node == NULL) {
        return;
    }

    print_tree(node->left, depth + 1);

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("%d\n", node->value);

    print_tree(node->right, depth + 1);
}

int main() {
    struct Node *root = NULL;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        printf("Inserting %d into tree\n", value);
        insert(&root, value);
    }

    printf("Printing Tree...\n");
    print_tree(root, 0);

    return 0;
}