//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODE_SIZE 100
#define MAGIC_NUMBER 42

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

void init_tree(struct tree *t) {
    int i, j;
    for (i = 0; i < 100; i++) {
        struct node *n = malloc(sizeof(struct node));
        n->data = i % 2 ? i : -i;
        n->left = (i % 2) ? NULL : &t->root;
        n->right = (i % 2) ? &t->root : NULL;
        t->root = n;
    }
}

int search(struct tree *t, int key) {
    int i, j;
    struct node *n = t->root;
    if (n == NULL) return -1;
    for (i = 0; i < 100; i++) {
        if (n->data == key) return i;
        if (key < n->data) n = n->left;
        else n = n->right;
    }
    return -1;
}

int main() {
    struct tree t;
    srand(time(NULL));
    init_tree(&t);
    for (int i = 0; i < 100; i++) {
        int key = rand() % 100;
        int found = search(&t, key);
        if (found != -1) {
            printf("Found key %d at index %d\n", key, found);
        } else {
            printf("Key %d not found\n", key);
        }
    }
    return 0;
}