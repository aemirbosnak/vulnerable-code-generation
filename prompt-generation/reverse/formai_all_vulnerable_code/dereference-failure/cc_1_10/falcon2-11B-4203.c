//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int x, y;
    struct node *left, *right;
};

struct node *create_node(int x, int y) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->x = x;
    node->y = y;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_maze(struct node *root) {
    if (root == NULL)
        return;
    printf(" ");
    printf("%d %d\n", root->x, root->y);
    print_maze(root->left);
    print_maze(root->right);
}

void add_edges(struct node *root) {
    if (root->left!= NULL)
        root->left->right = root;
    if (root->right!= NULL)
        root->right->left = root;
}

int main() {
    struct node *root = NULL;
    int x, y;
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        x = rand() % 20 + 1;
        y = rand() % 20 + 1;

        root = create_node(x, y);
        add_edges(root);

        printf("Adding edge from (%d, %d) to (%d, %d):\n", x, y, root->x, root->y);
        print_maze(root);
    }

    printf("\nFinal maze:\n");
    print_maze(root);

    return 0;
}