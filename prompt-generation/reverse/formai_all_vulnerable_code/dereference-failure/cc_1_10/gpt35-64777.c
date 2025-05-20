//FormAI DATASET v1.0 Category: Binary search trees ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} Node;

void insert(Node *root, int val) {
    Node **curr = &root;
    while (*curr != NULL) {
        if (val < (*curr)->val) {
            curr = &(*curr)->left;
        } else {
            curr = &(*curr)->right;
        }
    }
    *curr = malloc(sizeof(Node));
    (*curr)->val = val;
    (*curr)->left = NULL;
    (*curr)->right = NULL;
}

bool search(Node *root, int val) {
    while (root != NULL) {
        if (val == root->val) {
            return true;
        } else if (val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}

void print(Node *root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d ", root->val);
    print(root->right);
}

int main(void) {
    Node *root = NULL;
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 9);
    printf("Tree: ");
    print(root);
    printf("\n");
    printf("Searching for 7: %s\n", search(root, 7) ? "Found" : "Not found");
    printf("Searching for 8: %s\n", search(root, 8) ? "Found" : "Not found");
    return 0;
}