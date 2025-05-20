//FormAI DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>

/* Node definition for Binary Search Tree */
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node_t;

/* Create and return new node */
node_t* create_node(int key) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

/* Insert new node in BST */
node_t* insert_node(node_t* node, int key) {
    
    /* If the tree is empty, return a new node */
    if (node == NULL) {
        return(create_node(key));
    } else {

        /* Otherwise, recur down the tree */
        if (key < node->key) {
            node->left = insert_node(node->left, key);
        } else if (key > node->key) {
            node->right = insert_node(node->right, key);
        }

        /* return the (unchanged) node pointer */
        return(node);
    }
}

/* Search for a given key in the BST*/
node_t* search_key(node_t* node, int key) {
    /* If the tree is empty or key is present at root */
    if (node == NULL || node->key == key) {
        return node;
    }

    /* Key is greater than root's key */
    if (node->key < key) {
        return search_key(node->right, key);
    }

    /* Key is smaller than root's key */
    return search_key(node->left, key);
}

/* Inorder traversal of BST*/
void inorder_traversal(node_t *root) {
    if(root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

/* Main function to test Binary Search Tree */
int main() {
    node_t* root = NULL;
    node_t* search_result = NULL;

    /* Insert 50, 30, 20, 40, 70, 60, 80 */
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    /* Search for key 60 in the BST */
    search_result = search_key(root, 60);
    if (search_result != NULL) {
        printf("\n%d is present in the BST\n", search_result->key);
    } else {
        printf("\n%d is not present in the BST\n", 60);
    }

    /* Inorder traversal of BST */
    printf("\nInorder traversal of the BST is: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}