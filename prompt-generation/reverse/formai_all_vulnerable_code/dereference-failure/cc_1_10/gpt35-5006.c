//FormAI DATASET v1.0 Category: Binary search trees ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// function prototypes
Node *newNode(int val);
Node *insert(Node *root, int val);
Node *search(Node *root, int val);
void printTree(Node *root);
Node *minValue(Node *root);
Node *deleteNode(Node *root, int val);

int main() {
    Node *root = NULL;
    
    // insert some values into the BST
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);

    printf("Initial tree:\n");
    printTree(root);

    // search for a node with a value of 7
    Node *searchResult = search(root, 7);
    if (searchResult != NULL) {
        printf("Found node with value 7.\n");
    } else {
        printf("Could not find node with value 7.\n");
    }

    // delete node with value 3
    root = deleteNode(root, 3);
    printf("Tree after deleting node with value 3:\n");
    printTree(root);

    // delete node with value 10
    root = deleteNode(root, 10);
    printf("Tree after deleting node with value 10:\n");
    printTree(root);

    return 0;
}

/*
 * Helper function to create a new Node with the given value
 */
Node *newNode(int val) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

/*
 * Recursive function to insert a Node with the given value
 * into the BST rooted at 'root'
 */
Node *insert(Node *root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    } else {
        // value already exists, do nothing
        return root;
    }
    return root;
}

/*
 * Recursive function to search for a Node with the given value
 * in the BST rooted at 'root'
 */
Node *search(Node *root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }
    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

/*
 * Helper function that returns the Node with the minimum value
 * in the BST rooted at 'root'
 */
Node *minValue(Node *root) {
    Node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

/*
 * Recursive function to delete a Node with the given value
 * in the BST rooted at 'root'
 */
Node *deleteNode(Node *root, int val) {
    // base case
    if (root == NULL) {
        return root;
    }
    // if val is smaller than root's data, then it lies in left subtree
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    // if val is greater than root's data, then it lies in right subtree
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    // if val is same as root's data, then this is the Node to be deleted
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: get the inorder successor (smallest
        // in the right subtree)
        Node *temp = minValue(root->right);
        // copy the inorder successor's content to this Node
        root->data = temp->data;
        // delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/*
 * Helper function to print the unbalanced BST
 * using in-order traversal.
 */
void printTree(Node *root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}