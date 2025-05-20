//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return (Node*) malloc(sizeof(Node));
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void print_tree(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    Node* root = NULL;

    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);

    printf("Binary Search Tree\n");
    print_tree(root);

    return 0;
}