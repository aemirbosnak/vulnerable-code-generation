//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 10
#define MAX_PATH 30

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node_t;

node_t* create_node(int value) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void traverse(node_t* root) {
    if (root == NULL) {
        return;
    }

    printf("Exploring node with value %d\n", root->value);

    traverse(root->left);
    traverse(root->right);
}

node_t* search(node_t* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->value == target) {
        return root;
    }

    if (root->left != NULL) {
        node_t* result = search(root->left, target);
        if (result != NULL) {
            return result;
        }
    }

    if (root->right != NULL) {
        node_t* result = search(root->right, target);
        if (result != NULL) {
            return result;
        }
    }

    return NULL;
}

int main() {
    node_t* root = create_node(5);
    root->left = create_node(2);
    root->right = create_node(8);
    root->left->left = create_node(1);
    root->left->right = create_node(3);
    root->right->left = create_node(6);
    root->right->right = create_node(9);

    traverse(root);

    int target = 7;
    node_t* result = search(root, target);
    if (result != NULL) {
        printf("Found value %d\n", result->value);
    } else {
        printf("Value not found\n");
    }

    return 0;
}