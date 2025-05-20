//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(root->data < data){
        return search(root->right, data);
    }
    return search(root->left, data);
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while(current && current->left!= NULL){
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int data){
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
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the given tree\n");
    inorder(root);
    printf("\n");
    printf("Search for 40\n");
    struct Node* res = search(root, 40);
    if(res!= NULL){
        printf("Found\n");
    }
    else{
        printf("Not found\n");
    }
    printf("\n");
    printf("Search for 90\n");
    res = search(root, 90);
    if(res!= NULL){
        printf("Found\n");
    }
    else{
        printf("Not found\n");
    }
    printf("\n");
    printf("Delete 20\n");
    root = deleteNode(root, 20);
    inorder(root);
    printf("\n");
    printf("Delete 30\n");
    root = deleteNode(root, 30);
    inorder(root);
    printf("\n");
    printf("Delete 50\n");
    root = deleteNode(root, 50);
    inorder(root);
    printf("\n");
    return 0;
}