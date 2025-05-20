//FormAI DATASET v1.0 Category: Binary search trees ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

// structure for storing BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create a new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

// function for inserting node in BST
struct Node* insert(struct Node* root, int key) {
    if(root == NULL) {
        return newNode(key);
    }
    if(key < root->data) {
        root->left = insert(root->left,key);
    } else if(key > root->data) {
        root->right = insert(root->right,key);
    }
    return root;
}

// function for searching a node in BST
struct Node* search(struct Node* root, int key) {
    if(root == NULL || root->data == key) {
        return root;
    }
    if(key < root->data) {
        return search(root->left,key);
    }
    return search(root->right,key);
}

// function for finding minimum value node in BST
struct Node* minValueNode(struct Node* node) {
    struct Node* currNode = node;
    while(currNode && currNode->left != NULL) {
        currNode = currNode->left;
    }
    return currNode;
}

// function for deleting a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if(root == NULL) {
        return root;
    }
    if(key < root->data) {
        root->left = deleteNode(root->left,key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right,key);
    } else {
        if(root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

// function for inorder traversal of BST
void inorder(struct Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

// main function
int main() {
    struct Node* root = NULL;
    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,70);
    root = insert(root,60);
    root = insert(root,80);
    printf("Inorder traversal of the BST : ");
    inorder(root);
    printf("\nDelete 20 from BST\n");
    root = deleteNode(root,20);
    printf("Inorder traversal of the modified BST : ");
    inorder(root);
    printf("\nDelete 30 from BST\n");
    root = deleteNode(root,30);
    printf("Inorder traversal of the modified BST : ");
    inorder(root);
    printf("\nDelete 50 from BST\n");
    root = deleteNode(root,50);
    printf("Inorder traversal of the modified BST : ");
    inorder(root);
    return 0;
}