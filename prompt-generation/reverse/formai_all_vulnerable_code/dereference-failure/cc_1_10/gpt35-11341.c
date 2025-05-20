//FormAI DATASET v1.0 Category: Binary search trees ; Style: genious
#include <stdio.h>
#include <stdlib.h>

/* Define a node structure for the binary search tree */
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

/* Function prototypes for the binary search tree */
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* delete(Node* root, int data);
Node* search(Node* root, int data);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);

/* Main function to test the binary search tree */
int main() {
    Node* root = NULL;

    /* Insert some numbers into the tree */
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 4);

    /* Print the tree in three ways */
    printf("In-order traversal:\n");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal:\n");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal:\n");
    postOrder(root);
    printf("\n");

    /* Search for some numbers in the tree */
    if (search(root, 4) != NULL) {
        printf("Found 4 in the tree.\n");
    } else {
        printf("Could not find 4 in the tree.\n");
    }

    if (search(root, 8) != NULL) {
        printf("Found 8 in the tree.\n");
    } else {
        printf("Could not find 8 in the tree.\n");
    }

    /* Delete some numbers from the tree */
    root = delete(root, 1);
    root = delete(root, 3);
    root = delete(root, 9);

    /* Print the tree in three ways again */
    printf("In-order traversal after deleting some nodes:\n");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal after deleting some nodes:\n");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal after deleting some nodes:\n");
    postOrder(root);
    printf("\n");

    return 0;
}

/* Function to create a node with the given data */
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a node with the given data into the binary search tree */
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

/* Function to delete a node with the given data from the binary search tree */
Node* delete(Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

/* Function to search for a node with the given data in the binary search tree */
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

/* Function to print the binary search tree in-order */
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

/* Function to print the binary search tree pre-order */
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Function to print the binary search tree post-order */
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}