//FormAI DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h> 

struct TreeNode { 
    int data; 
    struct TreeNode* left; 
    struct TreeNode* right; 
}; 

struct TreeNode* createNode(int data) 
{ 
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    
    new_node->data = data; 
    new_node->left = NULL; 
    new_node->right = NULL; 
    
    return new_node; 
}

struct TreeNode* insertNode(struct TreeNode* root, int data) 
{ 
    if (root == NULL) 
        return createNode(data); 
    
    if (data < root->data) 
        root->left = insertNode(root->left, data); 
    
    else if (data > root->data) 
        root->right = insertNode(root->right, data); 
    
    return root; 
} 

struct TreeNode* searchNode(struct TreeNode* root, int data) 
{ 
    if (root == NULL || root->data == data) 
        return root; 
    
    if (root->data < data) 
        return searchNode(root->right, data); 
    
    else if (root->data > data) 
        return searchNode(root->left, data); 
}

void inorderTraversal(struct TreeNode* root) 
{ 
    if (root != NULL) { 
        inorderTraversal(root->left); 
        printf("%d ", root->data); 
        inorderTraversal(root->right); 
    } 
} 

int main() 
{ 
    struct TreeNode* root = NULL; 
    root = insertNode(root, 10); 
    insertNode(root, 5); 
    insertNode(root, 15); 
    insertNode(root, 3); 
    insertNode(root, 8); 
    insertNode(root, 12); 
    insertNode(root, 18);
    
    printf("Inorder Traversal of the Binary Search Tree: ");
    inorderTraversal(root); 

    int search_key = 5;
    struct TreeNode* search_node = searchNode(root, search_key);
    if(search_node == NULL){
        printf("\n%d not found in the Binary Search Tree.", search_key);
    }
    else{
        printf("\n%d found in the Binary Search Tree.", search_key);
    }
    
    search_key = 20;
    search_node = searchNode(root, search_key);
    if(search_node == NULL){
        printf("%d not found in Binary Search Tree.", search_key);
    }
    else{
        printf("%d found in Binary Search Tree.", search_key);
    }

    return 0; 
}