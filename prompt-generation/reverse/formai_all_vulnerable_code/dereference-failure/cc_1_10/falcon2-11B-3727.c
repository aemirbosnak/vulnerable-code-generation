//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(Node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        insert_node(root->left, data);
    } else {
        insert_node(root->right, data);
    }
}

void print_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    Node* root = NULL;

    insert_node(root, 4);
    insert_node(root, 2);
    insert_node(root, 6);
    insert_node(root, 1);
    insert_node(root, 3);
    insert_node(root, 5);

    print_tree(root);

    return 0;
}