//FormAI DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *node, int data) {
    if (node == NULL) {
        return create_node(data);
    }
    if (data < node->data) {
        node->left = insert_node(node->left, data);
    } else if (data > node->data) {
        node->right = insert_node(node->right, data);
    }
    return node;
}

bool search_tree(Node *node, int data) {
    if (node == NULL) {
        return false;
    }
    if (data == node->data) {
        return true;
    } else if (data < node->data) {
        return search_tree(node->left, data);
    } else {
        return search_tree(node->right, data);
    }
}

void print_in_order(Node *node) {
    if (node != NULL) {
        print_in_order(node->left);
        printf("%d ", node->data);
        print_in_order(node->right);
    }
}

int main() {
    Node *root = NULL;
    printf("My happy binary search tree program!\n");
    printf("Inserting data into the tree...\n");
    root = insert_node(root, 5);
    insert_node(root, 4);
    insert_node(root, 6);
    insert_node(root, 2);
    insert_node(root, 8);
    insert_node(root, 1);
    insert_node(root, 3);
    insert_node(root, 7);
    printf("Data successfully inserted!\n");

    printf("Printing the tree in order...\n");
    print_in_order(root);
    printf("\n");

    printf("Searching for data in the tree...\n");
    if (search_tree(root, 6)) {
        printf("Found data in the tree!\n");
    } else {
        printf("Data not found in the tree :(\n");
    }

    return 0;
}