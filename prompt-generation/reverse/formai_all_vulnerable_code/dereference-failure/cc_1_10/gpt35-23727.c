//FormAI DATASET v1.0 Category: Binary search trees ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNewNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = createNewNode(data);
        return newNode;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            Node* minRight = root->right;
            while (minRight->left != NULL) {
                minRight = minRight->left;
            }

            root->data = minRight->data;
            root->right = deleteNode(root->right, minRight->data);
        }
    }

    return root;
}

Node* findNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return findNode(root->left, data);
    }
    else {
        return findNode(root->right, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    Node* root = NULL;

    // insert some nodes
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 13);
    root = insertNode(root, 18);

    // search for a node
    Node* foundNode = findNode(root, 5);
    if (foundNode != NULL) {
        printf("Found node with value %d\n", foundNode->data);
    }
    else {
        printf("Node not found\n");
    }

    // delete a node
    root = deleteNode(root, 15);

    // print out in order traversal of the tree
    printf("In order traversal: ");
    inOrderTraversal(root);

    return 0;
}