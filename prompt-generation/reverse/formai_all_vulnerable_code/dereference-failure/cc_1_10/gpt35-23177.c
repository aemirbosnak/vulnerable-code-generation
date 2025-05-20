//FormAI DATASET v1.0 Category: Binary search trees ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

// Define the structure of the binary search tree node
struct bstnode{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

// Create a new node of a binary search tree
struct bstnode* newNode(int data){
    struct bstnode* node = (struct bstnode*) malloc(sizeof(struct bstnode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Insert a new node in the binary search tree
struct bstnode* insertNode(struct bstnode* node, int data){
    if (node == NULL) return(newNode(data));
    else{
        if (data <= node->data) node->left = insertNode(node->left, data);
        else node->right = insertNode(node->right, data);
        return(node);
    }
}

// Traverse the binary search tree in inorder
void inorderTraversal(struct bstnode* node){
    if (node == NULL) return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

// Main function to execute
int main(){
    int treeSize, element;
    struct bstnode *root = NULL;

    // Read the size of the binary search tree
    printf("Enter the size of the binary search tree: ");
    scanf("%d", &treeSize);

    // Read the elements of the binary search tree
    printf("\nEnter the elements of the binary search tree: \n");
    for(int i=0; i<treeSize; i++){
        scanf("%d", &element);
        root = insertNode(root, element);
    }

    // Traverse the binary search tree in inorder
    printf("\nInorder traversal of the binary search tree: ");
    inorderTraversal(root);

    return 0;
}