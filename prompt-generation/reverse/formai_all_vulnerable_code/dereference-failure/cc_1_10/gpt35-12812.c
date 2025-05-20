//FormAI DATASET v1.0 Category: Binary search trees ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

//structure to represent a node in BST
struct node{
    int data;
    struct node *left;
    struct node *right;
};

//function to allocate memory for new node
struct node *newNode(int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//function to insert a new node in BST
struct node *insert(struct node *root, int key){
    if(root == NULL){
        return newNode(key);
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    }else if(key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}

//function to search for a node in BST
struct node *search(struct node *root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(root->data < key){
        return search(root->right, key);
    }
    return search(root->left, key);
}

//function to find the minimum value node in BST
struct node *minValueNode(struct node *node){
    struct node *current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

//function to delete a node from BST
struct node *deleteNode(struct node *root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//function to traverse the BST in in-order manner
void inorderTraversal(struct node *root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main(){
    struct node *root = NULL;
    printf("******** Binary Search Tree *********\n\n");
    printf("Inserting Values: 5 2 8 1 3 7 9\n");
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 9);
    printf("Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n\nSearching for the value 3 in the BST...\n");
    struct node *searchNode = search(root, 3);
    if(searchNode == NULL){
        printf("Value not found in the BST.\n");
    }else{
        printf("Value %d found in the BST.\n", searchNode->data);
    }
    printf("\nDeleting the value 7 from the BST...\n");
    root = deleteNode(root, 7);
    printf("Traversal of the BST after deletion: ");
    inorderTraversal(root);
    return 0;
}