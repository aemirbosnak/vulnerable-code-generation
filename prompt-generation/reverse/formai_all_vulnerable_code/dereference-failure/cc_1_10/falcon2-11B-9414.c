//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: secure
#include <stdio.h>

// Define a struct to represent each node of the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to insert a new value into the BST
void insert(struct Node* root, int data) {
    // If the root is NULL, create a new node with the given value
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return;
    }

    // Otherwise, traverse the tree until we find the correct position for the new node
    // based on the comparison of the new value with the values in the existing nodes
    if (data < root->data) {
        insert(root->left, data);
    } else if (data > root->data) {
        insert(root->right, data);
    }
}

// Function to display the BST in pre-order traversal
void preOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Function to display the BST in in-order traversal
void inOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Function to display the BST in post-order traversal
void postOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Function to search for a given value in the BST
int search(struct Node* root, int data) {
    if (root == NULL) {
        return -1;
    }

    if (root->data == data) {
        return 0;
    }

    int leftResult = search(root->left, data);
    if (leftResult!= -1) {
        return leftResult;
    }

    int rightResult = search(root->right, data);
    if (rightResult!= -1) {
        return rightResult;
    }

    return -1;
}

// Function to delete a node from the BST
void deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return;
    }

    // If the node to be deleted has no children, simply remove it from the tree
    if (root->left == NULL && root->right == NULL) {
        free(root);
        root = NULL;
        return;
    }

    // Otherwise, find the in-order successor of the node to be deleted
    struct Node* successor = NULL;
    struct Node* current = root;

    while (current->left!= NULL) {
        successor = current;
        current = current->left;
    }

    // If the node to be deleted has a single child, replace it with the in-order successor
    if (successor == NULL) {
        successor = root;
        if (root->right!= NULL) {
            successor = root->right;
        }

        if (successor!= NULL) {
            root->data = successor->data;
            free(successor);
        }

        return;
    }

    // If the node to be deleted has two children, replace it with the in-order successor
    // and then delete the in-order successor from the tree
    struct Node* temp = successor->right;
    deleteNode(temp, successor->data);
    free(successor);
}

// Function to display the BST in pre-order traversal
void displayBST() {
    struct Node* root = NULL;

    // Create a binary search tree
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 1);
    insert(root, 7);
    insert(root, 12);
    insert(root, 3);
    insert(root, 6);
    insert(root, 14);
    insert(root, 17);
    insert(root, 4);
    insert(root, 8);
    insert(root, 11);
    insert(root, 13);
    insert(root, 16);
    insert(root, 9);

    // Display the binary search tree in pre-order traversal
    printf("Pre-order traversal: ");
    preOrder(root);

    // Display the binary search tree in in-order traversal
    printf("\nIn-order traversal: ");
    inOrder(root);

    // Display the binary search tree in post-order traversal
    printf("\nPost-order traversal: ");
    postOrder(root);

    // Search for a value in the binary search tree
    int result = search(root, 13);
    if (result == 0) {
        printf("\n%d found in the binary search tree.\n", 13);
    } else {
        printf("\n%d not found in the binary search tree.\n", 13);
    }

    // Delete a node from the binary search tree
    deleteNode(root, 11);

    // Display the binary search tree after deleting a node
    printf("\nPre-order traversal after deleting a node: ");
    preOrder(root);

    // Display the binary search tree in in-order traversal after deleting a node
    printf("\nIn-order traversal after deleting a node: ");
    inOrder(root);

    // Display the binary search tree in post-order traversal after deleting a node
    printf("\nPost-order traversal after deleting a node: ");
    postOrder(root);
}

int main() {
    displayBST();
    return 0;
}