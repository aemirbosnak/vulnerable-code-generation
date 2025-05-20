//FormAI DATASET v1.0 Category: Binary search trees ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

//Defining the structure of the Binary Search Tree
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//Function to create a new node in the Binary Search Tree
struct node* newNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//Function to insert a new node in the Binary Search Tree
struct node* insert(struct node* root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

//Function to search for a node in the Binary Search Tree
struct node* search(struct node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(root->data < data){
        return search(root->right, data);
    }
    return search(root->left, data);
}

//Function to delete a node in the Binary Search Tree
struct node* delete(struct node* root, int data){
    if(root == NULL){
        return root;
    }
    if(data < root->data){
        root->left = delete(root->left, data);
    }
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else{
        //Case when the node has only one child or no child
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        //Case when the node has two children
        struct node* temp = root->right;
        while(temp && temp->left != NULL){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

//Function to print the Binary Search Tree in an in-order traversal
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//Main function
int main(){
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the Binary Search Tree: \n");
    inorder(root);

    printf("\nDeleting the node with data 20: \n");
    root = delete(root, 20);
    printf("In-order traversal of the modified Binary Search Tree: \n");
    inorder(root);

    printf("\nDeleting the node with data 30: \n");
    root = delete(root, 30);
    printf("In-order traversal of the modified Binary Search Tree: \n");
    inorder(root);

    printf("\nDeleting the node with data 50: \n");
    root = delete(root, 50);
    printf("In-order traversal of the modified Binary Search Tree: \n");
    inorder(root);

    return 0;
}