//FormAI DATASET v1.0 Category: Binary search trees ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int value;
  struct Node* left;
  struct Node* right;
}Node;
Node* root = NULL;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* insert(Node* root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value < root -> value){
        root -> left = insert(root -> left, value);
    }else if(value > root -> value){
        root -> right = insert(root -> right, value);
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root -> left);
    printf("%d ",root -> value);
    inorderTraversal(root -> right);
}

Node* search(Node* root,int value){
    if(root == NULL || root -> value == value){
        return root;
    }
    if(root -> value > value){
        return search(root -> left, value);
    }
    return search(root -> right, value);
}

Node* minValueNode(Node* node){
    Node* current = node;
    while(current -> left != NULL){
        current = current -> left;
    }
    return current;
}

Node* delete(Node* root, int value){
    if(root == NULL){
        return root;
    }
    if(value < root -> value){
        root -> left = delete(root -> left, value);
    }else if(value > root -> value){
        root -> right = delete(root -> right, value);
    }else{
        if(root -> left == NULL){
            Node* temp = root -> right;
            free(root);
            return temp;
        }else if(root -> right == NULL){
            Node* temp = root -> left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root -> right);
        root -> value = temp -> value;
        root -> right = delete(root -> right, temp -> value);
    }
    return root;
}

int main(){
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("Inorder traversal of the binary search tree:\n");
    inorderTraversal(root);

    printf("\n\nDeleting 20 from the binary search tree:\n");
    root = delete(root, 20);
    printf("Inorder traversal of the modified binary search tree:\n");
    inorderTraversal(root);

    printf("\n\nSearching for 30 in the binary search tree:\n");
    Node* searchedNode = search(root, 30);
    if(searchedNode != NULL){
        printf("Searched element 30 found in the binary search tree\n");
    }else{
        printf("Searched element 30 not present in the binary search tree\n");
    }

    printf("\n\nSearching for 100 in the binary search tree:\n");
    searchedNode = search(root, 100);
    if(searchedNode != NULL){
        printf("Searched element 100 found in the binary search tree\n");
    }else{
        printf("Searched element 100 not present in the binary search tree\n");
    }
    return 0;
}