//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/* This program generates a visualization of a binary tree with randomly generated nodes */

/* Define the structure of each node in our binary tree */
typedef struct Node {
    int data;
    struct Node* left_child;
    struct Node* right_child;
} Node;

/* Function to generate a new node with random data */
Node* new_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

/* Function to insert a new node into our binary tree */
void insert_node(Node** root, Node* node) {
    if (*root == NULL) {
        *root = node;
    } else if (node->data < (*root)->data) {
        insert_node(&((*root)->left_child), node);
    } else {
        insert_node(&((*root)->right_child), node);
    }
}

/* Function to generate a random integer from 1 to 100 */
int random_int() {
    return (rand() % 100) + 1;
}

/* Function to traverse the binary tree in-order and print each node */
void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left_child);
        printf("%d ", root->data);
        inorder_traversal(root->right_child);
    }
}

/* Function to traverse the binary tree pre-order and print each node */
void preorder_traversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left_child);
        preorder_traversal(root->right_child);
    }
}

/* Function to traverse the binary tree post-order and print each node */
void postorder_traversal(Node* root) {
    if (root != NULL) {
        postorder_traversal(root->left_child);
        postorder_traversal(root->right_child);
        printf("%d ", root->data);
    }
}

/* Main function */
int main() {
    Node* root = NULL;
    int num_nodes;

    printf("How many nodes should our binary tree have? ");
    scanf("%d", &num_nodes);

    /* Generate and insert a random node for each specified node */
    for (int i = 0; i < num_nodes; i++) {
        insert_node(&root, new_node(random_int()));
    }

    /* Print the binary tree in order */
    printf("\nIn-order traversal:\n");
    inorder_traversal(root);

    /* Print the binary tree pre-order */
    printf("\n\nPre-order traversal:\n");
    preorder_traversal(root);

    /* Print the binary tree post-order */
    printf("\n\nPost-order traversal:\n");
    postorder_traversal(root);

    return 0;
}