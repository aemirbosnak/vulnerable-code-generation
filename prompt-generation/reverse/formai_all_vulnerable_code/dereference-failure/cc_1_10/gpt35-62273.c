//FormAI DATASET v1.0 Category: Binary search trees ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

//structure for node
struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

//inserting a new node into the binary search tree
struct node *insert(struct node *root, int data)
{
    if(root == NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data = data;
        root->leftChild = NULL;
        root->rightChild = NULL;
    }
    else if(data <= root->data)
    {
        root->leftChild = insert(root->leftChild, data);
    }
    else
    {
        root->rightChild = insert(root->rightChild, data);
    }
    return root;
}

//function to check if a given node exists in the BST
int exists(struct node *root, int data)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->data == data)
    {
        return 1;
    }
    else if(data < root->data)
    {
        return exists(root->leftChild, data);
    }
    else
    {
        return exists(root->rightChild, data);
    }
}

//function to find minimum value in the BST
int findMin(struct node *root)
{
    if(root == NULL)
    {
        printf("Error: The tree is empty\n");
        return -1;
    }
    while(root->leftChild != NULL)
    {
        root = root->leftChild;
    }
    return root->data;
}

//function to find maximum value in the BST
int findMax(struct node *root)
{
    if(root == NULL)
    {
        printf("Error: The tree is empty\n");
        return -1;
    }
    while(root->rightChild != NULL)
    {
        root = root->rightChild;
    }
    return root->data;
}

//function to traverse in inorder (left,root,right)
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->leftChild);
        printf("%d ", root->data);
        inorder(root->rightChild);
    }
}

//function to traverse in preorder (root,left,right)
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

//function to traverse in postorder (left,right,root)
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d ", root->data);
    }
}

//main function to call all the above functions
int main()
{
    struct node *root = NULL;
    
    //inserting elements into the BST
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 10);
    root = insert(root, 18);
    root = insert(root, 22);
    root = insert(root, 30);
    
    //traversing in inorder
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    //traversing in preorder
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    //traversing in postorder
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    
    //checking if a given element exists in the BST
    int number = 25;
    if(exists(root, number) == 1)
    {
        printf("%d exists in the BST\n", number);
    }
    else
    {
        printf("%d does not exist in the BST\n", number);
    }
    
    //finding the minimum element in the BST
    int min = findMin(root);
    printf("Minimum element in the BST: %d\n", min);
    
    //finding the maximum element in the BST
    int max = findMax(root);
    printf("Maximum element in the BST: %d\n", max);
    
    return 0;
}