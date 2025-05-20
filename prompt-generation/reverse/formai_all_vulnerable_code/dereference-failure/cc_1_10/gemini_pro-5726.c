//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the tree node structure
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node into a linked list
void insert_node(node_t **head, node_t *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Print a linked list
void print_linked_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Create a new tree node
tree_node_t *create_tree_node(int data) {
    tree_node_t *new_node = (tree_node_t *)malloc(sizeof(tree_node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a tree
void insert_tree_node(tree_node_t **root, tree_node_t *new_node) {
    if (*root == NULL) {
        *root = new_node;
    } else {
        if (new_node->data < (*root)->data) {
            insert_tree_node(&(*root)->left, new_node);
        } else {
            insert_tree_node(&(*root)->right, new_node);
        }
    }
}

// Print a tree
void print_tree(tree_node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

// Main function
int main() {
    // Create a linked list
    node_t *head = NULL;
    insert_node(&head, create_node(1));
    insert_node(&head, create_node(2));
    insert_node(&head, create_node(3));
    insert_node(&head, create_node(4));
    insert_node(&head, create_node(5));

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Create a tree
    tree_node_t *root = NULL;
    insert_tree_node(&root, create_tree_node(10));
    insert_tree_node(&root, create_tree_node(5));
    insert_tree_node(&root, create_tree_node(15));
    insert_tree_node(&root, create_tree_node(2));
    insert_tree_node(&root, create_tree_node(7));
    insert_tree_node(&root, create_tree_node(12));
    insert_tree_node(&root, create_tree_node(20));

    // Print the tree
    printf("Tree: ");
    print_tree(root);

    return 0;
}