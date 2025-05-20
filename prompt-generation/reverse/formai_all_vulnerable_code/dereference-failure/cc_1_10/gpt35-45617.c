//FormAI DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node_t;

// Function to create a new node
node_t* create_node(int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if(new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node
node_t* insert_node(node_t* root, int data) {
    if(root == NULL) {
        root = create_node(data);
    } else if(data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to search for a node
node_t* search_node(node_t* root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }
    if(root->data < data) {
        return search_node(root->right, data);
    }
    return search_node(root->left, data);
}

// Function to delete a node
node_t* delete_node(node_t* root, int data) {
    if(root == NULL) {
        return NULL;
    } else if(data < root->data) {
        root->left = delete_node(root->left, data);
    } else if(data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        // Check if node has at most one child
        if(root->left == NULL) {
            node_t* new_root = root->right;
            free(root);
            return new_root;
        } else if(root->right == NULL) {
            node_t* new_root = root->left;
            free(root);
            return new_root;
        }
        // Node has two children
        node_t* min_node = root->right;
        while(min_node->left != NULL) {
            min_node = min_node->left;
        }
        root->data = min_node->data;
        root->right = delete_node(root->right, root->data);
    }
    return root;
}

// Function to print the tree in-order
void print_tree(node_t* root) {
    if(root != NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

int main() {
    node_t* root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 80);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 60);
    root = insert_node(root, 90);
    root = insert_node(root, 20);
    root = insert_node(root, 70);
    printf("Tree in-order: ");
    print_tree(root);
    printf("\n");
    root = delete_node(root, 40);
    printf("Tree in-order after deleting 40: ");
    print_tree(root);
    printf("\n");
    node_t* search = search_node(root, 60);
    if(search != NULL) {
        printf("Node found: %d\n", search->data);
    } else {
        printf("Node not found!\n");
    }
    return 0;
}