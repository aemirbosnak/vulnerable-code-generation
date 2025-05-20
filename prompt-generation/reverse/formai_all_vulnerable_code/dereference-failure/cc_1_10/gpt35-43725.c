//FormAI DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Creating the node structure of BST
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Creating a function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Creating a function to insert a new node
struct node* insert(struct node* root, int data) {
    if(root == NULL) {
        return newNode(data);
    } else {
        if(data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Creating a function to search for a node in the BST
struct node* search(struct node* root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }

    if(data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

// Function to find the minimum element in the BST
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    while(current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from BST
struct node* deleteNode(struct node* root, int data) {
    if(root == NULL) {
        return root;
    }

    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if(root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the BST inorder traversal
void inorderTraversal(struct node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    int n, data, i;
    struct node* root = NULL;

    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("Enter the node to be searched: ");
    scanf("%d", &data);

    struct node* temp = search(root, data);
    if(temp) {
        printf("The node %d is found in the BST\n", data);
    } else {
        printf("The node %d is not found in the BST\n", data);
    }

    printf("Enter the node to be deleted: ");
    scanf("%d", &data);

    root = deleteNode(root, data);

    printf("Inorder traversal of the BST after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}