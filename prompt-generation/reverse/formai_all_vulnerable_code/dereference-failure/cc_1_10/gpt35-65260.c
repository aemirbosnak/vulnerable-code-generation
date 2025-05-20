//FormAI DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

/* Basic structure of node in a BST */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Function to create a new node */
struct Node* newNode(int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

/* Recursive function to insert element in BST */
struct Node* insert(struct Node* node, int val) {
    if (node == NULL) return newNode(val);
    if (val < node->data) node->left = insert(node->left, val);
    else if (val > node->data) node->right = insert(node->right, val);
    return node;
}

/* Recursive function to search element in BST */
struct Node* search(struct Node* node, int val) {
    if (node == NULL || node->data == val) return node;
    if (node->data < val) return search(node->right, val);
    return search(node->left, val);
}

/* Function to print inorder traversal of BST */
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

/* Main function to perform BST operations */
int main() {
    printf("Oh my goodness, I am surprised to see you here!\n");
    printf("Let's create a Binary Search Tree!\n");

    /* Creating root node */
    int val;
    printf("Enter value of root node: ");
    scanf("%d", &val);
    struct Node* root = newNode(val);

    /* Inserting new nodes */
    printf("Do you want to insert more nodes? (y/n): ");
    char choice;
    scanf("%s", &choice);
    while (choice == 'y' || choice == 'Y') {
        printf("Enter value of new node: ");
        scanf("%d", &val);
        insert(root, val);
        printf("Do you want to insert more nodes? (y/n): ");
        scanf("%s", &choice);
    }

    /* Searching for a specific node */
    printf("Do you want to search for a specific node? (y/n): ");
    scanf("%s", &choice);
    while (choice == 'y' || choice == 'Y') {
        printf("Enter value of node to search: ");
        scanf("%d", &val);
        struct Node* result = search(root, val);
        if (result != NULL) printf("Node found!\n");
        else printf("Node not found!\n");
        printf("Do you want to search for more nodes? (y/n): ");
        scanf("%s", &choice);
    }

    /* Printing inorder traversal */
    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");

    return 0;
}