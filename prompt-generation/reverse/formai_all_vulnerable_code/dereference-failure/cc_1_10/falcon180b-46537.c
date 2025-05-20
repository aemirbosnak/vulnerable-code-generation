//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into the tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to search for a node with the given data
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Function to print the tree inorder
void printInorder(struct node* root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    struct node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Inorder traversal\n4. Exit");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                struct node* result = search(root, data);

                if (result == NULL)
                    printf("%d not found in the tree\n", data);
                else
                    printf("%d found in the tree\n", data);
                break;

            case 3:
                printf("Inorder traversal of the tree:\n");
                printInorder(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}