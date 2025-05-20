//FormAI DATASET v1.0 Category: Memory management ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

/* 
  This C program demonstrates the use of a recursive function for allocating and deallocating memory 
  dynamically. The program creates a binary tree of nodes, each containing an integer value
  and two child pointers (left and right). The program allocates and deallocates memory 
  dynamically using recursion.
*/

struct node {
    int value;
    struct node* left_child;
    struct node* right_child;
};

/* Function to allocate memory dynamically for a new node */
struct node* new_node(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->value = value;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}

/* Function to insert a new node in the binary tree */
struct node* insert_node(struct node* root, int value) {
    if (root == NULL) {
        return new_node(value);
    }

    if (value < root->value) {
        root->left_child = insert_node(root->left_child, value);
    } else {
        root->right_child = insert_node(root->right_child, value);
    }

    return root;
}

/* Function to deallocate memory of all nodes in the binary tree recursively */
void deallocate_memory(struct node* root) {
    if (root != NULL) {
        deallocate_memory(root->left_child);
        deallocate_memory(root->right_child);
        free(root);
    }
}

int main() {
    struct node* root = NULL;
    int n, value;

    // Inserting nodes in the binary tree
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for (int i=0; i<n; i++) {
        scanf("%d", &value);
        root = insert_node(root, value);
    }

    // Deallocating memory of all nodes in the binary tree
    deallocate_memory(root);

    return 0;
}