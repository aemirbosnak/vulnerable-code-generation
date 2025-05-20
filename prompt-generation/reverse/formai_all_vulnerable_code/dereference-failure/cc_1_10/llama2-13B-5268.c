//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 1000

struct node {
    int data;
    struct node *left, *right;
};

struct node* create_tree(void) {
    struct node* root = malloc(sizeof(struct node));
    root->data = 0;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void insert(struct node** root_ptr, int data) {
    struct node* root = *root_ptr;
    if (!root) {
        root = create_tree();
        *root_ptr = root;
    }

    if (data < root->data) {
        if (!root->left) {
            root->left = create_tree();
        }
        insert(&root->left, data);
    } else if (data > root->data) {
        if (!root->right) {
            root->right = create_tree();
        }
        insert(&root->right, data);
    } else {
        root->data = data;
    }
}

void print(struct node* root) {
    if (!root) {
        return;
    }

    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

int main() {
    struct node* root = NULL;

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int data = rand() % 100;
        insert(&root, data);
    }

    print(root);

    return 0;
}