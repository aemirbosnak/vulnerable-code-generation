//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    double log_height;
    struct Node* left;
    struct Node* right;
} Node;

Node* new_node(int key) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->log_height = log2(1);
    return new_node;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        root = new_node(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    root->log_height = log2(1 + (root->left == NULL ? 0 : height(root->left) + 1) + (root->right == NULL ? 0 : height(root->right) + 1));
    return root;
}

int height(Node* node) {
    if (node == NULL) {
        return -1;
    }
    return node->log_height;
}

bool is_leaf(Node* node) {
    return node->left == NULL && node->right == NULL;
}

Node* find_min_value_node(Node* node) {
    if (is_leaf(node)) {
        return node;
    }
    return find_min_value_node(node->left);
}

Node* delete_min_value_node(Node* root) {
    if (root->left == NULL) {
        Node* temp = root;
        root = root->right;
        free(temp);
    } else {
        root->left = delete_min_value_node(root->left);
    }
    root->log_height = log2(1 + (root->left == NULL ? 0 : height(root->left) + 1) + (root->right == NULL ? 0 : height(root->right) + 1));
    return root;
}

void inorder_traversal(Node* node, int* array, int* size) {
    if (node == NULL) {
        return;
    }

    inorder_traversal(node->left, array, size);
    array[*size] = node->key;
    (*size)++;
    inorder_traversal(node->right, array, size);
}

int main() {
    int array[] = {5, 3, 7, 1, 8, 4, 9, 6};
    int size = sizeof(array) / sizeof(array[0]);

    Node* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert(root, array[i]);
    }

    int result[size];
    int result_size = 0;

    inorder_traversal(root, result, &result_size);

    for (int i = 0; i < result_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    Node* node_to_delete = find_min_value_node(root);
    root = delete_min_value_node(root);

    printf("Deleted minimum value: %d\n", node_to_delete->key);

    free(node_to_delete);

    return 0;
}