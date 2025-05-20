//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

/* Define the structure of a node in the binary search tree */
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

/* Create a new node with the given data */
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* Insert a new node with the given data into the binary search tree */
Node* insert_node(Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

/* Search for a node with the given data in the binary search tree */
Node* search_node(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

/* Print the binary search tree in a visually appealing way */
void print_tree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;
    print_tree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    print_tree(root->left, space);
}

/* Main function */
int main() {
    Node* root = NULL;

    /* Insert nodes into the binary search tree */
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    /* Print the binary search tree */
    printf("Binary Search Tree:\n");
    print_tree(root, 0);

    return 0;
}