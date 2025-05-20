//FormAI DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

/* Structure for Binary Search Tree */
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};

/* Function to create new node */
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

/* Function to insert node */
struct node* insert_node(struct node* node, int data) {
    if (node == NULL) {
        return create_node(data);
    }

    if (data < node->data) {
        node->left_child = insert_node(node->left_child, data);
    } else if (data > node->data) {
        node->right_child = insert_node(node->right_child, data);
    }

    return node;
}

/* Function to find minimum value node */
struct node* min_value_node(struct node* node) {
    struct node* current = node;
    while (current && current->left_child != NULL) {
        current = current->left_child;
    }
    return current;
}

/* Function to delete node */
struct node* delete_node(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left_child = delete_node(root->left_child, data);
    } else if (data > root->data) {
        root->right_child = delete_node(root->right_child, data);
    } else {
        if (root->left_child == NULL) {
            struct node* temp = root->right_child;
            free(root);
            return temp;
        } else if (root->right_child == NULL) {
            struct node* temp = root->left_child;
            free(root);
            return temp;
        }

        struct node* temp = min_value_node(root->right_child);
        root->data = temp->data;
        root->right_child = delete_node(root->right_child, temp->data);
    }

    return root;
}

/* Function to display nodes */
void display_nodes(struct node* node) {
    if (node != NULL) {
        printf("%d\n", node->data);
        display_nodes(node->left_child);
        display_nodes(node->right_child);
    }
}

/* Main function */
int main() {
    struct node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("Initial BST:\n");
    display_nodes(root);

    root = delete_node(root, 20);
    printf("BST after 20 was deleted:\n");
    display_nodes(root);

    root = delete_node(root, 30);
    printf("BST after 30 was deleted:\n");
    display_nodes(root);

    root = delete_node(root, 50);
    printf("BST after 50 was deleted:\n");
    display_nodes(root);

    return 0;
}