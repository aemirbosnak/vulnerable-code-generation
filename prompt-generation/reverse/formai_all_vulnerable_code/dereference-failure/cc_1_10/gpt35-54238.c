//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

//Defining the structure of the binary search tree node
typedef struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}TreeNode;

//Function to create a new node for the binary search tree
TreeNode* createNode(int data){
    TreeNode *newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert a node into the binary search tree
TreeNode* insert(TreeNode *root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

//Function to find the minimum value node in the binary search tree
TreeNode* findMin(TreeNode *root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

//Function to delete a node from the binary search tree
TreeNode* delete(TreeNode *root, int data){
    if(root == NULL)
        return root;
    else if(data < root->data)
        root->left = delete(root->left, data);
    else if(data > root->data)
        root->right = delete(root->right, data);
    else{ //If the node to be deleted is found
        //Case 1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //Case 2: One child
        else if(root->left == NULL){
            TreeNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            TreeNode *temp = root;
            root = root->left;
            free(temp);
        }
        //Case 3: Two children
        else{
            TreeNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

//Function to print the binary search tree in in-order traversal
void inOrder(TreeNode *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

//Main Function to test the binary search tree
int main(){
    //Initializing the root node as NULL
    TreeNode *root = NULL;

    //Inserting values into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    //Printing the binary search tree
    printf("In-Order Traversal of the Binary Search Tree: ");
    inOrder(root);

    //Deleting nodes from the binary search tree
    root = delete(root, 20);
    root = delete(root, 40);
    root = delete(root, 70);

    //Printing the binary search tree after deletion
    printf("\nIn-Order Traversal of the Binary Search Tree after Deletion: ");
    inOrder(root);

    return 0;
}