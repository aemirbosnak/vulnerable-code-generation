//FormAI DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

// Define the struct for the BST node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node* newnode(int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Function to insert a node into BST
node* insert(node *root, int data) {
    if (root == NULL) 
        return newnode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to check if a node is present in BST
int search(node *root, int data) {
    if (root == NULL) 
        return 0;
    if (root->data == data) 
        return 1;
    if (data < root->data)
        return search(root->left, data);
    else if (data > root->data)
        return search(root->right, data);
}

// Function to print the inorder traversal of the BST
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    node *root = NULL;
    int n, data, choice, ans;
    while (1) {
        // Ask the user for a choice
        printf("\n1) Insert into BST\n2) Search in BST\n3) Print inorder traversal\n4) Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                // Ask the user for data to insert
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                // Ask the user for data to search
                printf("Enter the data to search: ");
                scanf("%d", &data);
                ans = search(root, data);
                if (ans == 1)
                    printf("%d is present in the BST\n", data);
                else
                    printf("%d is not present in the BST\n", data);
                break;
            case 3:
                // Print the inorder traversal of the BST
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                // Exit the program
                exit(0);
            default:
                // Invalid choice
                printf("Invalid Choice\n");
        }
    }
    return 0;
}