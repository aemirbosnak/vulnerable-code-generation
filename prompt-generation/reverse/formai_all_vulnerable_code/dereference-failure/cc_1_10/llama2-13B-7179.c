//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with a given value
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the tree
void insert(struct node** root, int value) {
    if (*root == NULL) {
        *root = newNode(value);
        return;
    }

    if (value < (*root)->data) {
        if ((*root)->left == NULL) {
            (*root)->left = newNode(value);
        } else {
            insert((*root)->left, value);
        }
    } else {
        if ((*root)->right == NULL) {
            (*root)->right = newNode(value);
        } else {
            insert((*root)->right, value);
        }
    }
}

// Function to search for a value in the tree
struct node* search(struct node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else if (value > root->data) {
        return search(root->right, value);
    } else {
        return root;
    }
}

// Function to grant a wish
void grantWish(struct node* root, int value) {
    struct node* node = search(root, value);
    if (node != NULL) {
        printf("Granting wish: %d\n", node->data);
        // Do something magical here!
    } else {
        printf("Wish not granted :(");
    }
}

int main() {
    struct node* root = NULL;

    // Insert some values into the tree
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 6);
    insert(&root, 1);

    // Grant some wishes
    grantWish(root, 5);
    grantWish(root, 2);
    grantWish(root, 8);
    grantWish(root, 3);
    grantWish(root, 6);
    grantWish(root, 1);

    return 0;
}