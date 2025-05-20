//LLAMA2-13B DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define K (100)
#define L (256)
#define M (8)
#define N (4)

struct Tree {
    int x;
    int y;
    struct Tree *left;
    struct Tree *right;
};

void init(struct Tree *root) {
    root->x = 0;
    root->y = 0;
    root->left = NULL;
    root->right = NULL;
}

void insert(struct Tree *root, int key) {
    if (root->x > key) {
        if (root->left == NULL) {
            root->left = malloc(sizeof(struct Tree));
            init(root->left);
            root->left->x = key;
        } else {
            insert(root->left, key);
        }
    } else if (root->x < key) {
        if (root->right == NULL) {
            root->right = malloc(sizeof(struct Tree));
            init(root->right);
            root->right->x = key;
        } else {
            insert(root->right, key);
        }
    }
}

void traverse(struct Tree *root) {
    if (root != NULL) {
        printf("%d ", root->x);
        traverse(root->left);
        traverse(root->right);
    }
}

int main() {
    struct Tree *root = malloc(sizeof(struct Tree));
    init(root);
    for (int i = 0; i < K; i++) {
        insert(root, L * (i + 1) % M);
    }
    traverse(root);
    return 0;
}