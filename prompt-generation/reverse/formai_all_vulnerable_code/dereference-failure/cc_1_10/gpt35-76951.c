//FormAI DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

//Creating Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
 
//Function to create a new Node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}
 
//Function to print inorder traversal
void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
 
//Function to insert a new Node with the given data
struct Node* insert(struct Node* node, int data) {
    if(node == NULL) return newNode(data);
    if(data < node->data) node->left = insert(node->left, data);
    else if(data > node->data) node->right = insert(node->right, data);
    return node;
}
 
//Function to find minimum element in a BST
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
 
//Function to delete a Node with the given data
struct Node* deleteNode(struct Node* root, int data) {
    if(root == NULL) return root;
    if(data < root->data) root->left = deleteNode(root->left, data);
    else if(data > root->data) root->right = deleteNode(root->right, data);
    else {
        if(root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
 
int main() {
    struct Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Deleting node with value 10...\n");
    root = deleteNode(root, 10);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}