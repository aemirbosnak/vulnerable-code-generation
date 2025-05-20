//FormAI DATASET v1.0 Category: Binary search trees ; Style: random
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to insert a new node
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        struct Node* root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else {
        node->right = insert(node->right, data);
    }

    return node;
}

// Function to search for a key in the tree
struct Node* search(struct Node* node, int key) {
    if (node == NULL || node->data == key) {
        return node;
    }

    if (key < node->data) {
        return search(node->left, key);
    }

    return search(node->right, key);
}

// Function to find the minimum value in the tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // copy the inorder successor's content to this node
        root->data = temp->data;

        // delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the tree in-order
void printInorder(struct Node* node) {
    if (node != NULL) {
        printInorder(node->left);
        printf("%d ", node->data);
        printInorder(node->right);
    }
}

// Driver program to test above functions
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given tree : ");
    printInorder(root);

    printf("\nDeleting key 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree : ");
    printInorder(root);

    printf("\nDeleting key 70\n");
    root = deleteNode(root, 70);
    printf("Inorder traversal of the modified tree : ");
    printInorder(root);

    return 0;
}