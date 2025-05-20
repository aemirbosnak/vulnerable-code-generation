//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void create_binary_tree(struct Node** root) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = 5;
    new_node->left = NULL;
    new_node->right = NULL;

    *root = new_node;

    struct Node* left_node = (struct Node*)malloc(sizeof(struct Node));
    left_node->data = 3;
    left_node->left = NULL;
    left_node->right = NULL;

    struct Node* right_node = (struct Node*)malloc(sizeof(struct Node));
    right_node->data = 7;
    right_node->left = NULL;
    right_node->right = NULL;

    new_node->left = left_node;
    new_node->right = right_node;

    struct Node* left_left_node = (struct Node*)malloc(sizeof(struct Node));
    left_left_node->data = 1;
    left_left_node->left = NULL;
    left_left_node->right = NULL;

    struct Node* left_right_node = (struct Node*)malloc(sizeof(struct Node));
    left_right_node->data = 2;
    left_right_node->left = NULL;
    left_right_node->right = NULL;

    struct Node* right_left_node = (struct Node*)malloc(sizeof(struct Node));
    right_left_node->data = 4;
    right_left_node->left = NULL;
    right_left_node->right = NULL;

    struct Node* right_right_node = (struct Node*)malloc(sizeof(struct Node));
    right_right_node->data = 6;
    right_right_node->left = NULL;
    right_right_node->right = NULL;

    left_node->left = left_left_node;
    left_node->right = left_right_node;

    right_node->left = right_left_node;
    right_node->right = right_right_node;
}

void print_binary_tree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    print_binary_tree(root->left);
    printf("%d ", root->data);
    print_binary_tree(root->right);
}

int main() {
    struct Node* root = NULL;
    create_binary_tree(&root);
    print_binary_tree(root);
    return 0;
}