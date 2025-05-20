//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void displayTree(Node* node, int space) {
    if (node == NULL)
        return;

    space += 10;

    displayTree(node->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", node->data);

    displayTree(node->left, space);
}

int main() {
    srand(time(NULL));

    Node* root = NULL;

    for (int i = 0; i < 15; i++) {
        root = insertNode(root, rand() % 50 + 1);
    }

    printf("Binary Search Tree:\n");
    displayTree(root, 0);

    int target;
    printf("\nEnter a number to search: ");
    scanf("%d", &target);

    Node* result = searchNode(root, target);

    if (result != NULL) {
        printf("\nFound %d in the tree.\n", result->data);
    } else {
        printf("\n%d not found in the tree.\n", target);
    }

    int deleteData;
    printf("\nEnter a number to delete: ");
    scanf("%d", &deleteData);

    root = deleteNode(root, deleteData);

    printf("\nBinary Search Tree after deleting %d:\n", deleteData);
    displayTree(root, 0);

    return 0;
}