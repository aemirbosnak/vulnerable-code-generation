//FormAI DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a node in the tree */
struct node {
    int value;
    struct node *left;
    struct node *right;
};

/* Function to create a new node */
struct node* new_node(int value) {
    struct node* temp_node = (struct node*) malloc(sizeof(struct node));
    temp_node->value = value;
    temp_node->left = NULL;
    temp_node->right = NULL;
    return temp_node;
}

/* Function to insert a node into the tree */
struct node* insert_node(struct node* node, int value) {
    /* If the tree is empty, create a new node */
    if (node == NULL) return new_node(value);

    /* Otherwise, recur down the tree */
    if (value < node->value)
        node->left  = insert_node(node->left, value);
    else if (value > node->value)
        node->right = insert_node(node->right, value);

    /* Return the node pointer */
    return node;
}

/* Function to search for a node in the tree */
struct node* search_node(struct node* node, int value) {
    /* Base Cases: root is null or value is present at root */
    if (node == NULL || node->value == value)
       return node;

    /* Value is greater than root's value */
    if (node->value < value)
       return search_node(node->right, value);

    /* Value is smaller than root's value */
    return search_node(node->left, value);
}

/* Function to perform in-order traversal of the tree */
void inorder(struct node* node) {
    if (node == NULL) return;

    inorder(node->left);
    printf("%d ", node->value);
    inorder(node->right);
}

int main() {
    /* Create an empty tree */
    struct node* root = NULL;

    /* Insert some nodes into the tree */
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    /* Search for a node in the tree */
    struct node* search_result = search_node(root, 60);
    if (search_result != NULL) {
        printf("Found node with value %d!\n", search_result->value);
    } else {
        printf("Node not found!\n");
    }

    /* Perform in-order traversal of the tree */
    inorder(root);
    printf("\n");

    /* Free the memory allocated for the tree */
    free(root);

    return 0;
}