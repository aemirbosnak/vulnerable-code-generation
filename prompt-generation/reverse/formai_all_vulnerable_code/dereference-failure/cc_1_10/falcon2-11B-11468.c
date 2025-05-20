//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// A node in the binary search tree
struct node {
    int value;
    struct node* left;
    struct node* right;
};

// Inserts a new node into the binary search tree
void insert(struct node* root, int value) {
    if (root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else if (value < root->value) {
        insert(root->left, value);
    } else if (value > root->value) {
        insert(root->right, value);
    }
}

// Performs an inorder traversal of the binary search tree and prints out the values of all the nodes
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Searches for a value in the binary search tree and returns a pointer to the node containing the value, if it exists, or NULL otherwise
struct node* search(struct node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    } else if (root->value < value) {
        return search(root->right, value);
    } else {
        return search(root->left, value);
    }
}

int main() {
    struct node* root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the tree:\n");
    inorder(root);

    printf("\nSearching for values in the tree:\n");
    struct node* node1 = search(root, 50);
    printf("Value 50 found at node %p\n", node1);
    struct node* node2 = search(root, 30);
    printf("Value 30 found at node %p\n", node2);
    struct node* node3 = search(root, 40);
    printf("Value 40 found at node %p\n", node3);
    struct node* node4 = search(root, 70);
    printf("Value 70 found at node %p\n", node4);
    struct node* node5 = search(root, 80);
    printf("Value 80 found at node %p\n", node5);
    struct node* node6 = search(root, 90);
    printf("Value 90 not found in the tree\n");

    return 0;
}