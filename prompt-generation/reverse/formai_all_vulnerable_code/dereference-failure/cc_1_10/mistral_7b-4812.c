//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory error\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(Node* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (data == root->data) {
        return true;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void print_tree(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < level; ++i) {
        printf("  ");
    }
    printf("%d\n", root->data);
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

int main() {
    Node* root = NULL;
    int numbers[] = {5, 3, 7, 1, 8, 6, 4};

    for (int i = 0; i < sizeof(numbers) / sizeof(int); ++i) {
        root = insert(root, numbers[i]);
    }

    printf("Binary Search Tree:\n");
    print_tree(root, 0);

    int search_number = 6;
    bool found = search(root, search_number);

    if (found) {
        printf("%d found in tree.\n", search_number);
    } else {
        printf("%d not found in tree.\n", search_number);
    }

    return EXIT_SUCCESS;
}