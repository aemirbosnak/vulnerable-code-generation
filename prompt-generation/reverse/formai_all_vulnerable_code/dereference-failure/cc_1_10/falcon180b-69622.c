//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: genious
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

Node* search(Node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

Node* minValueNode(Node* node){
    Node* current = node;
    while(current && current->left!= NULL){
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

void inorder(Node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root!= NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root!= NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
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

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    Node* searchNode = search(root, 40);
    if(searchNode!= NULL){
        printf("Found %d\n", searchNode->data);
    }
    else{
        printf("Not found\n");
    }

    root = deleteNode(root, 20);

    printf("Inorder traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    return 0;
}