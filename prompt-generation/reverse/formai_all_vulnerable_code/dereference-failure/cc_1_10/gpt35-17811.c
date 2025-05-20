//FormAI DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

/* Definition of Binary Tree Node */
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

/* Function to create a new node with given data */
Node* createNode(int data){

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a new node into the BST */
Node* insertNode(Node* root, int data){

    if(root == NULL){
        return createNode(data);
    }

    if(data < root->data){
        root->left = insertNode(root->left, data);
    }else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

/* Function to perform a pre-order traversal of the BST */
void preOrderTraversal(Node* root){

    if(root != NULL){
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

/* Function to perform a post-order traversal of the BST */
void postOrderTraversal(Node* root){

    if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

/* Function to perform an in-order traversal of the BST */
void inOrderTraversal(Node* root){

    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

/* Function to find the minimum value in the BST */
Node* findMinimum(Node* root){

    if(root == NULL || root->left == NULL){
        return root;
    }

    return findMinimum(root->left);
}

/* Function to delete a node from the BST */
Node* deleteNode(Node* root, int data){

    if(root == NULL){
        return root;
    }

    if(root->data > data){
        root->left = deleteNode(root->left, data);
    }else if(root->data < data){
        root->right = deleteNode(root->right, data);
    }else{

        /* Case 1: No child */
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        /* Case 2: One child */
        else if(root->left == NULL || root->right == NULL){
            Node* temp = (root->left == NULL) ? root->right : root->left;
            free(root);
            return temp;
        }else{
            /* Case 3: Two children */
            Node* temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

/* Main Function */
int main(){

    Node* root = NULL;
    int choice, data;
    printf("Enter your choice: \n");
    printf("1. Insert Node \n");
    printf("2. Delete Node \n");
    printf("3. Pre-order Traversal \n");
    printf("4. Post-order Traversal \n");
    printf("5. In-order Traversal \n");

    do{
        printf("\nEnter your choice (0 to exit): ");
        scanf("%d", &choice);

        switch(choice){

            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                preOrderTraversal(root);
                break;
            case 4:
                postOrderTraversal(root);
                break;
            case 5:
                inOrderTraversal(root);
                break;
            default:
                printf("Invalid Choice!");
                break;
        }

    }while(choice != 0);

    return 0;
}