//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEPTH 10
#define MAX_PATH 100

typedef struct node {
    int depth;
    int path;
    struct node *left;
    struct node *right;
} node_t;

node_t* search(node_t* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->depth == target) {
        return root;
    }

    node_t* left = search(root->left, target);
    node_t* right = search(root->right, target);

    if (left != NULL && right != NULL) {
        return root;
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    node_t* root = NULL;

    for (int i = 0; i < MAX_DEPTH; i++) {
        int depth = rand() % MAX_DEPTH;
        int path = rand() % MAX_PATH;

        node_t* node = malloc(sizeof(node_t));
        node->depth = depth;
        node->path = path;
        node->left = NULL;
        node->right = NULL;

        if (i == 0) {
            root = node;
        } else {
            root->left = node;
        }
    }

    node_t* result = search(root, 5);

    if (result != NULL) {
        printf("Found node with depth %d and path %d\n", result->depth, result->path);
    } else {
        printf("No node found\n");
    }

    return 0;
}