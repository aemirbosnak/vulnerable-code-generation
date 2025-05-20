//FormAI DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/* Structure definition for binary search tree node */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Creating a new node */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Inserting a node into the binary search tree */
struct node* insertNode(struct node* node, int data) {
    /* If the tree is empty, create a new node and return */
    if (node == NULL)
        return newNode(data);
    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    /* Return the (unchanged) node pointer */
    return node;
}

/* Inorder traversal of BST */
void inorderTraversal(struct node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

/* Finding the minimum value in the BST */
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

/* Deleting a node from BST */
struct node* deleteNode(struct node* root, int data) {
    /* Base case */
    if (root == NULL)
        return root;
    /* If the data to be deleted is smaller than the root's data, then
       it lies in left subtree */
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    /* If the data to be deleted is greater than the root's data, then
       it lies in right subtree */
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    /* If data is same as root's data, then this is the node to be deleted */
    else {
        /* node with only one child or no child */
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        /* node with two children: Get the inorder successor (smallest
           in the right subtree) */
        struct node* temp = minValueNode(root->right);
        /* Copy the inorder successor's content to this node */
        root->data = temp->data;
        /* Delete the inorder successor */
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* Driver program */
int main() {
    int key;
    struct node* root = NULL;
    /* Inserting nodes into the BST */
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    /* Displaying the BST */
    printf("Inorder traversal of initial BST: ");
    inorderTraversal(root);
    /* Deleting a node */
    printf("\n\nEnter a number to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);
    /* Displaying the updated BST */
    printf("\nInorder traversal of updated BST: ");
    inorderTraversal(root);
    return 0;
}