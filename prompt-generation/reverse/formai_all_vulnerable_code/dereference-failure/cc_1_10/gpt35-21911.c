//FormAI DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int data){
    if(node == NULL){
        return createNode(data);
    }
    
    if(data < node->data){
        node->left = insert(node->left, data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }
    
    return node;
}

Node* search(Node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    
    if(data < root->data){
        return search(root->left, data);
    }
    
    return search(root->right, data);
}

Node* minValueNode(Node* node){
    Node* current = node;
    
    while(current->left != NULL){
        current = current->left;
    }
    
    return current;
}

Node* deleteNode(Node* root, int data){
    if(root == NULL){
        return root;
    }
    
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = minValueNode(root->right);
        
        root->data = temp->data;
        
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

void inorderTraversal(Node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main(){
    Node* root = NULL;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    
    printf("\n\nDeleting 20 from the binary search tree.\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the binary search tree after deletion: ");
    inorderTraversal(root);
    
    printf("\n\nSearching for 50 in the binary search tree...\n");
    Node* result = search(root, 50);
    
    if(result != NULL){
        printf("%d was found in the binary search tree.\n", result->data);
    }
    else{
        printf("50 was not found in the binary search tree.\n");
    }
    
    printf("\nSearching for 10 in the binary search tree...\n");
    result = search(root, 10);
    
    if(result != NULL){
        printf("%d was found in the binary search tree.\n", result->data);
    }
    else{
        printf("10 was not found in the binary search tree.\n");
    }
    
    return 0;
}