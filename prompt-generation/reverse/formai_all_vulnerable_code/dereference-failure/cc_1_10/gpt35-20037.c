//FormAI DATASET v1.0 Category: Binary search trees ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

// Data structure to represent a binary search tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node for the tree
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return (newNode);
}

// Insert a node to the tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root -> data) {
        root -> left = insert(root -> left, data);
    }
    else if (data > root -> data) {
        root -> right = insert(root -> right, data);
    }
    return root;
}

// Search for a node in the tree
struct node* search(struct node* root, int data) {
    if (root == NULL || root -> data == data) {
        return root;
    }

    if (root -> data < data) {
        return search(root -> right, data);
    }
    return search(root -> left, data);
}

// Traverse the binary search tree in in-order fashion
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root -> left);
        printf("%d ", root -> data);
        inorderTraversal(root -> right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, num;

    while (1) {
        printf("Enter your choice: \n");
        printf("1. Insert a node\n");
        printf("2. Search a node\n");
        printf("3. Traverse the tree in in-order\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &num);
                root = insert(root, num);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &num);
                if (search(root, num) != NULL) {
                    printf("Data found in the tree!\n");
                }
                else {
                    printf("Data not found in the tree!\n");
                }
                break;
            case 3:
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}