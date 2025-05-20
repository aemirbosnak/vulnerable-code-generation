//FormAI DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

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

void insert(Node** root, int newData){
    if(*root == NULL){
        *root = createNode(newData);
    }
    else if(newData <= (*root)->data){
        insert(&((*root)->left), newData);
    }
    else{
        insert(&((*root)->right), newData);
    }
}

int search(Node* root, int searchData){
    if(root == NULL){
        return 0;
    }
    else if(root->data == searchData){
        return 1;
    }
    else if(searchData < root->data){
        return search(root->left, searchData);
    }
    else{
        return search(root->right, searchData);
    }
}

Node* findMinimum(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int dataToDelete){
    if(root == NULL){
        return root;
    }
    else if(dataToDelete < root->data){
        root->left = delete(root->left, dataToDelete);
    }
    else if(dataToDelete > root->data){
        root->right = delete(root->right, dataToDelete);
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
            Node* minRightSubtree = findMinimum(root->right);
            root->data = minRightSubtree->data;
            root->right = delete(root->right, minRightSubtree->data);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    Node* root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("\nInorder traversal of the binary search tree: ");
    inorder(root);  // 20 30 40 50 60 70 80

    printf("\n\nDeleting node 20 from the binary search tree...\n");
    root = delete(root, 20);

    printf("\nInorder traversal of the modified binary search tree: ");
    inorder(root);  // 30 40 50 60 70 80

    printf("\n\nSearching for the value 60 in the binary search tree...\n");
    if(search(root, 60)){
        printf("Value found!\n");
    }
    else{
        printf("Value not found.\n");
    }

    printf("\nSearching for the value 90 in the binary search tree...\n");
    if(search(root, 90)){
        printf("Value found!\n");
    }
    else{
        printf("Value not found.\n");
    }

    return 0;
}