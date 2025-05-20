//FormAI DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

/*
 * Create a new node and initialize its values
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/*
 * Insert a node into the binary search tree
 */
Node* insert(Node* root, int data) {
    if (root == NULL) { // create a new node if tree is empty
        return createNode(data);
    }
    if (data < root->data) { // traverse left if data is less than root node value
        root->left = insert(root->left, data);
    } else if (data > root->data) { // traverse right if data is greater than root node value
        root->right = insert(root->right, data);
    }

    return root;
}

/*
 * Find the minimum value in the tree (the leftmost node)
 */
Node* findMin(Node* root) {
    if (root == NULL) { // return NULL if tree is empty
        return NULL;
    }
    if (root->left == NULL) { // return the leftmost node if it is the minimum value
        return root;
    }

    return findMin(root->left); // recursively search the left subtree
}

/*
 * Find a node in the tree with the given value
 */
Node* find(Node* root, int data) {
    if (root == NULL) { // return NULL if tree is empty or desired node is not found
        return NULL;
    }
    if (root->data == data) { // return node if the desired value is found
        return root;
    } else if (data < root->data) { // traverse left if desired value is less than root node value
        return find(root->left, data);
    } else { // traverse right if desired value is greater than root node value
        return find(root->right, data);
    }
}

/*
 * Delete a node from the tree with the given value
 */
Node* delete(Node* root, int data) {
    if (root == NULL) { // return NULL if tree is empty or desired node is not found
        return NULL;
    } else if (data < root->data) { // traverse left if desired value is less than root node value
        root->left = delete(root->left, data);
    } else if (data > root->data) { // traverse right if desired value is greater than root node value
        root->right = delete(root->right, data);
    } else { // the desired value has been found
        if (root->left == NULL && root->right == NULL) { // case where the node has no children
            free(root);
            root = NULL;
        } else if (root->left == NULL) { // case where the node has one child (right child)
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) { // case where the node has one child (left child)
            Node* temp = root;
            root = root->left;
            free(temp);
        } else { // case where the node has two children
            Node* temp = findMin(root->right); // find the minimum value in the right subtree
            root->data = temp->data; // replace the node's data with that of the minimum value
            root->right = delete(root->right, temp->data); // delete the minimum value node from the right subtree
        }
    }

    return root;
}

/*
 * Traverse the tree in-order and print the node values
 */
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the binary search tree: ");
    inorder(root);
    printf("\n\n");

    Node* nodeToDelete = find(root, 30);
    printf("Deleting node with value 30...\n\n");
    root = delete(root, nodeToDelete->data);

    printf("In-order traversal of the binary search tree after deletion: ");
    inorder(root);
    printf("\n\n");

    return 0;
}