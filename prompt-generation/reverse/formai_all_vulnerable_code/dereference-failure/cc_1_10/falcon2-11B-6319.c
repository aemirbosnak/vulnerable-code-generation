//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
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
    int data;

    while (1) {
        printf("Enter data (0 to quit): ");
        scanf("%d", &data);

        if (data == 0) {
            break;
        }

        root = insert(root, data);
    }

    print_tree(root);

    return 0;
}