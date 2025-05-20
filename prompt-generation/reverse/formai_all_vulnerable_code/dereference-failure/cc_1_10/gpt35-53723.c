//FormAI DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        printf("Woah, new node created with value %d\n", value);
        return new_node;
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
        printf("Inserted %d in the left subtree of %d\n", value, root->value);
    } else {
        root->right = insert(root->right, value);
        printf("Inserted %d in the right subtree of %d\n", value, root->value);
    }
    return root;
}

struct node* search(struct node* root, int value) {
    if (root == NULL) {
        printf("Sorry, %d not found in the tree\n", value);
        return NULL;
    }
    if (root->value == value) {
        printf("%d found in the tree\n", value);
        return root;
    }
    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void traverse(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Values in the tree: ");
    if (root->left != NULL) {
        traverse(root->left);
    }
    printf("%d ", root->value);
    if (root->right != NULL) {
        traverse(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    traverse(root);

    struct node* result = search(root, 4);
    if (result != NULL) {
        printf("Deleted %d from the tree\n", result->value);
        free(result);
    }

    traverse(root);

    return 0;
}