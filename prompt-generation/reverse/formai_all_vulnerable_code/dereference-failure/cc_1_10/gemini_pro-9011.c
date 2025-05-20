//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a node for a linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node with the given data and next pointer
node *create_node(int data, node *next) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

// Insert a new node into a linked list at the given index
void insert_node(node **head, int index, int data) {
    if (index == 0) {
        *head = create_node(data, *head);
    } else {
        node *current = *head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next = create_node(data, current->next);
    }
}

// Delete a node from a linked list at the given index
void delete_node(node **head, int index) {
    if (index == 0) {
        *head = (*head)->next;
    } else {
        node *current = *head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
    }
}

// Print a linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Create a new binary tree node with the given data and left and right pointers
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

// Create a new binary tree node with the given data
tree_node *create_tree_node(int data) {
    tree_node *new_node = malloc(sizeof(tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into a binary tree with the given data
void insert_tree_node(tree_node **root, int data) {
    if (*root == NULL) {
        *root = create_tree_node(data);
    } else {
        if (data < (*root)->data) {
            insert_tree_node(&(*root)->left, data);
        } else {
            insert_tree_node(&(*root)->right, data);
        }
    }
}

// Print a binary tree in pre-order (root, left, right)
void print_tree_pre_order(tree_node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_tree_pre_order(root->left);
        print_tree_pre_order(root->right);
    }
}

// Print a binary tree in in-order (left, root, right)
void print_tree_in_order(tree_node *root) {
    if (root != NULL) {
        print_tree_in_order(root->left);
        printf("%d ", root->data);
        print_tree_in_order(root->right);
    }
}

// Print a binary tree in post-order (left, right, root)
void print_tree_post_order(tree_node *root) {
    if (root != NULL) {
        print_tree_post_order(root->left);
        print_tree_post_order(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    // Create a linked list
    node *head = NULL;
    insert_node(&head, 0, 1);
    insert_node(&head, 1, 2);
    insert_node(&head, 2, 3);
    insert_node(&head, 3, 4);
    insert_node(&head, 4, 5);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Delete a node from the linked list
    delete_node(&head, 2);

    // Print the linked list again
    printf("Linked list after deleting node at index 2: ");
    print_list(head);

    // Create a binary tree
    tree_node *root = NULL;
    insert_tree_node(&root, 10);
    insert_tree_node(&root, 5);
    insert_tree_node(&root, 15);
    insert_tree_node(&root, 2);
    insert_tree_node(&root, 7);
    insert_tree_node(&root, 12);
    insert_tree_node(&root, 20);

    // Print the binary tree in pre-order
    printf("Binary tree in pre-order: ");
    print_tree_pre_order(root);

    // Print the binary tree in in-order
    printf("\nBinary tree in in-order: ");
    print_tree_in_order(root);

    // Print the binary tree in post-order
    printf("\nBinary tree in post-order: ");
    print_tree_post_order(root);

    return 0;
}