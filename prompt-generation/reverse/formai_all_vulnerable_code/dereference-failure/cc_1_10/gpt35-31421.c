//FormAI DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Create a new node */
struct node* new_node(int value) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

/* Insert a value into the binary search tree */
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return new_node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

/* Search for a value in the binary search tree */
struct node* search(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

/* Traverse the binary search tree in-order */
void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

/* Delete a node from the binary search tree */
struct node* delete(struct node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = delete(root->left, value);
    } else if (value > root->data) {
        root->right = delete(root->right, value);
    } else {
        /* Case 1: No child */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;

        /* Case 2: One child */
        } else if (root->left == NULL) {
            struct node* temp = root;
            root = root->right;
            free(temp);

        } else if (root->right == NULL) {
            struct node* temp = root;
            root = root->left;
            free(temp);

        /* Case 3: Two children */
        } else {
            struct node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    return root;
}

/* Driver program */
int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Deleting value 20: ");
    root = delete(root, 20);
    inorder_traversal(root);
    printf("\n");

    printf("Deleting value 30: ");
    root = delete(root, 30);
    inorder_traversal(root);
    printf("\n");

    printf("Searching for value 70: ");
    if (search(root, 70) != NULL) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    return 0;
}