//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_DEPTH 5
#define MAX_WIDTH 10
#define MAX_HEIGHT 10

typedef struct node {
    int x;
    int y;
    int z;
    char value;
    struct node *left;
    struct node *right;
} node_t;

node_t* search(node_t* root, int x, int y, int z) {
    if (root == NULL) {
        return NULL;
    }

    int diff_x = abs(x - root->x);
    int diff_y = abs(y - root->y);
    int diff_z = abs(z - root->z);

    if (diff_x > diff_y && diff_x > diff_z) {
        if (x < root->x) {
            return search(root->left, x, y, z);
        } else {
            return search(root->right, x, y, z);
        }
    } else if (diff_y > diff_x && diff_y > diff_z) {
        if (y < root->y) {
            return search(root->left, x, y, z);
        } else {
            return search(root->right, x, y, z);
        }
    } else {
        if (z < root->z) {
            return search(root->left, x, y, z);
        } else {
            return search(root->right, x, y, z);
        }
    }
}

int main() {
    node_t* root = NULL;

    srand(time(NULL));

    int num_nodes = 10;
    int node_size = 3;

    for (int i = 0; i < num_nodes; i++) {
        int x = rand() % (MAX_WIDTH - 1) + 1;
        int y = rand() % (MAX_HEIGHT - 1) + 1;
        int z = rand() % (MAX_DEPTH - 1) + 1;

        node_t* new_node = malloc(sizeof(node_t));
        new_node->x = x;
        new_node->y = y;
        new_node->z = z;
        new_node->value = 'A' + (rand() % 26);

        if (i == 0) {
            root = new_node;
        } else {
            root->left = new_node;
            root = new_node;
        }

        if (i % 2 == 0) {
            new_node->left = NULL;
        } else {
            new_node->right = NULL;
        }
    }

    int search_x = 5;
    int search_y = 5;
    int search_z = 5;

    node_t* found = search(root, search_x, search_y, search_z);

    if (found != NULL) {
        printf("Found node at (%d, %d, %d) with value %c\n", found->x, found->y, found->z, found->value);
    } else {
        printf("Not found\n");
    }

    return 0;
}