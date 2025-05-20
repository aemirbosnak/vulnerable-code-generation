//FormAI DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create new nodes
struct node* create(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert nodes
struct node* insert(struct node* root, int val) {
    if(root == NULL)
        return create(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    else
        printf("You are trying to insert the same value again! Try again with a different value.\n");
    return root;
}

// Function to find the minimum value in the tree
struct node* min(struct node* root) {
    struct node* current = root;
    while(current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete nodes
struct node* delete(struct node* root, int val) {
    if(root == NULL)
        return root;
    if(val < root->data)
        root->left = delete(root->left, val);
    else if(val > root->data)
        root->right = delete(root->right, val);
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if(root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct node* temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Function to search nodes
struct node* search(struct node* root, int val) {
    if(root == NULL || root->data == val)
        return root;
    if(val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

// Function to traverse the tree in inorder
void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    else
        return;
}

// Main function
int main() {
    struct node* root = NULL;
    int choice, val;
    do {
        printf("\n\n-- Surrealist Binary Search Tree --\n\n");
        printf("1. Insert a value\n");
        printf("2. Delete a value\n");
        printf("3. Search for a value\n");
        printf("4. Traverse in inorder\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("\nEnter value to delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;
            case 3:
                printf("\nEnter value to search: ");
                scanf("%d", &val);
                if(search(root, val) == NULL)
                    printf("\nValue not found\n");
                else
                    printf("\nValue found\n");
                break;
            case 4:
                printf("\nInorder traversal: ");
                inorder(root);
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while(1);
    return 0;
}