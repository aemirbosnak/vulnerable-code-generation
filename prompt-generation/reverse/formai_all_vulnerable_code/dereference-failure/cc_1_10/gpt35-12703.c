//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left_child;
    struct node* right_child;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

void insert(Node* root, int data) {
    if (data < root->data) {
        if (root->left_child != NULL) {
            insert(root->left_child, data);
        } else {
            root->left_child = create_node(data);
        }
    } else if (data > root->data) {
        if (root->right_child != NULL) {
            insert(root->right_child, data);
        } else {
            root->right_child = create_node(data);
        }
    }
}

void print_tree(Node* node, int level) {
    if (node == NULL) {
        return;
    }
    print_tree(node->right_child, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", node->data);
    print_tree(node->left_child, level + 1);
}

int main() {
    Node* root = create_node(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    print_tree(root, 0);
    return 0;
}