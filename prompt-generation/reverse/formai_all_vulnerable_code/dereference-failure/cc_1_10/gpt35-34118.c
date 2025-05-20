//FormAI DATASET v1.0 Category: Binary search trees ; Style: careful
#include<stdio.h>
#include<stdlib.h>

// Tree Node Structure
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

// Create a new node
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the tree
Node* insert(Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }

    return root;
}

// Search for a node in the tree
Node* search(Node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    else if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

// Find the minimum value in a tree
Node* findMinimum(Node* root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    else{
        return findMinimum(root->left);
    }
}

// Delete a node from the tree
Node* delete(Node* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(data < root->data){
        root->left = delete(root->left, data);
    }
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else{
        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if(root->left == NULL || root->right == NULL){
            Node* temp;
            if(root->left == NULL){
                temp = root->right;
            }
            else{
                temp = root->left;
            }
            free(root);
            return temp;
        }
        // Case 3: Two children
        else{
            Node* temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    return root;
}

// Preorder traversal of tree
void preorder(Node* root){
    if(root == NULL){
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main function
int main(){
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    // Search for a node
    Node* searchedNode = search(root, 6);
    if(searchedNode != NULL){
        printf("Node found: %d\n", searchedNode->data);
    }
    else{
        printf("Node not found.\n");
    }

    // Delete a node
    root = delete(root, 3);
    printf("After deleting 3: ");
    preorder(root);

    return 0;
}