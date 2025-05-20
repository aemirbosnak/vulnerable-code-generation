//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* rootNode, int data){
    if(rootNode == NULL){
        rootNode = createNode(data);
    }
    else if(data < rootNode->data){
        rootNode->left = insertNode(rootNode->left, data);
    }
    else if(data > rootNode->data){
        rootNode->right = insertNode(rootNode->right, data);
    }
    return rootNode;
}

void printInorder(Node* rootNode){
    if(rootNode != NULL){
        printInorder(rootNode->left);
        printf("%d ", rootNode->data);
        printInorder(rootNode->right);
    }
}

Node* search(Node* rootNode, int data){
    if(rootNode == NULL || rootNode->data == data){
        return rootNode;
    }
    else if(data < rootNode->data){
        return search(rootNode->left, data);
    }
    else{
        return search(rootNode->right, data);
    }
}

Node* minBST(Node* rootNode){
    Node* current = rootNode;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* rootNode, int data){
    if(rootNode == NULL){
        return rootNode;
    }
    else if(data < rootNode->data){
        rootNode->left = deleteNode(rootNode->left, data);
    }
    else if(data > rootNode->data){
        rootNode->right = deleteNode(rootNode->right, data);
    }
    else{          
        if(rootNode->left == NULL){           
            Node* temp = rootNode->right;
            free(rootNode);
            return temp;
        }
        else if(rootNode->right == NULL){
            Node* temp = rootNode->left;
            free(rootNode);
            return temp;
        }
        
        Node* temp = minBST(rootNode->right);
        rootNode->data = temp->data;
        rootNode->right = deleteNode(rootNode->right, temp->data);
    }
    return rootNode;
}

int main(){
    Node* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 6);
    root = insertNode(root, 23);
    root = insertNode(root, 4);
    root = insertNode(root, 12);
    root = insertNode(root, 10);
    root = insertNode(root, 13);
    root = insertNode(root, 71);
    root = insertNode(root, 50);
    root = insertNode(root, 96);

    printf("Binary search tree inorder traversal: ");
    printInorder(root);
    
    int num = 12;
    Node* searchedNode = search(root, num);
    if(searchedNode != NULL){
        printf("\n%d found in Binary search tree", num);
    }
    else{
        printf("\n%d not found in Binary search tree", num);
    }
    
    num = 55;
    searchedNode = search(root, num);
    if(searchedNode != NULL){
        printf("\n%d found in Binary search tree", num);
    }
    else{
        printf("\n%d not found in Binary search tree", num);
    }

    num = 4;
    root = deleteNode(root, num);
    printf("\nBinary search tree inorder traversal after deleting %d: ", num);
    printInorder(root);

    num = 15;
    root = deleteNode(root, num);
    printf("\nBinary search tree inorder traversal after deleting %d: ", num);
    printInorder(root);
    
    return 0;
}