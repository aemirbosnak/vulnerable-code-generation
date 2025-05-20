//FormAI DATASET v1.0 Category: Binary search trees ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define the BST node with left and right children
struct bstnode
{
    int data;
    struct bstnode *left, *right;
};

// Create a new node and set left and right children to NULL
struct bstnode* createNewNode(int data)
{
    struct bstnode* newNode = (struct bstnode*)malloc(sizeof(struct bstnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node into the BST
struct bstnode* insert(struct bstnode* root, int data)
{
    if(root == NULL) // If the BST is empty, create and return the new node
        return createNewNode(data);
    
    if(data < root->data) // If data is less than root's data then insert into left subtree
        root->left = insert(root->left, data);
    else if(data > root->data) // If data is greater than root's data then insert into right subtree
        root->right = insert(root->right, data);
    
    // Return the current node pointer after insertion
    return root;
}

// Search for a node in the BST
struct bstnode* search(struct bstnode *root, int data)
{
    if(root == NULL || root->data == data) // If root is NULL or the root node matches data
        return root;
    
    if(data < root->data) // If data is less than root's data search in left subtree
        return search(root->left, data);
    else // If data is greater than root's data search in right subtree
        return search(root->right, data);
}

// Print the BST in-order
void printInorder(struct bstnode* root)
{
    if(root != NULL)
    {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// Delete a node from the BST
struct bstnode* delete(struct bstnode *root, int data)
{
    if(root == NULL) // If the tree is empty, return NULL
        return root;
    
    if(data < root->data) // If data is less than root's data then search in left subtree
        root->left = delete(root->left, data);
    else if(data > root->data) // If data is greater than root's data then search in right subtree
        root->right = delete(root->right, data);
    else // If data matches the current node
    {
        if(root->left == NULL) // If the node has only one child or no child
        {
            struct bstnode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) // If the node has only one child or no child
        {
            struct bstnode *temp = root->left;
            free(root);
            return temp;
        }
        // If the node has two children, get the inorder successor (smallest in the right subtree)
        struct bstnode *temp = root->right;
        while(temp->left != NULL)
            temp = temp->left;
        // Copy the inorder successor's data to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Driver function to test the BST implementation
int main()
{
    struct bstnode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 70);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal of the BST: ");
    printInorder(root);
    printf("\n");

    int searchKey = 60;
    struct bstnode* searchResult = search(root, searchKey);
    if(searchResult != NULL)
        printf("Found the node with data=%d in the BST\n", searchKey);
    else
        printf("Could not find the node with data=%d in the BST\n", searchKey);

    int deleteKey = 20;
    root = delete(root, deleteKey);
    printf("In-order traversal of the BST after deleting node with data=%d: ", deleteKey);
    printInorder(root);
    printf("\n");
    
    return 0;
}