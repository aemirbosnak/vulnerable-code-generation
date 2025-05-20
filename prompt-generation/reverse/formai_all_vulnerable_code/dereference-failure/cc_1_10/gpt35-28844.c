//FormAI DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a function to create a new node
struct node* create_new_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Create a function to insert a new node into the tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return create_new_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("The value %d already exists in the binary search tree.\n", data);
    }
    return root;
}

// Create a function to search for a value in the tree
struct node* search(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Create a function to find the minimum value in the tree
struct node* find_minimum(struct node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_minimum(root->left);
    }
}

// Create a function to delete a node from the tree
struct node* delete(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) { // Case 1: No child
            free(root);
            root = NULL;
        } else if (root->left == NULL) { // Case 2: One child
            struct node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) { // Case 2: One child
            struct node* temp = root;
            root = root->left;
            free(temp);
        } else { // Case 3: Two children
            struct node* temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Create a function to traverse the tree in preorder
void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Create a function to traverse the tree in inorder
void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Create a function to traverse the tree in postorder
void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Create the main function
int main() {
    struct node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 12);
    insert(root, 18);
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    root = delete(root, 15);
    printf("Inorder traversal after deleting 15: ");
    inorder(root);
    printf("\n");
    struct node* search_result = search(root, 10);
    printf("The value 10 is present in the binary search tree.\n");
    return 0;
}