//FormAI DATASET v1.0 Category: Binary search trees ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        root = createNode(data);
    }
    else if(data <= root->data){
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
    else if(data <= root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

Node* minNode(Node* root){
    Node* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

Node* delete(Node* root, int data){
    if(root == NULL){
        return root;
    }
    else if(data < root->data){
        root->left = delete(root->left, data);
    }
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        else{
            Node* temp = minNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);

    printf("\nDeleting node 20 from the binary search tree\n");
    root = delete(root, 20);
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);

    printf("\nDeleting node 30 from the binary search tree\n");
    root = delete(root, 30);
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);

    printf("\nDeleting node 50 from the binary search tree\n");
    root = delete(root, 50);
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);

    printf("\n");
    return 0;
}