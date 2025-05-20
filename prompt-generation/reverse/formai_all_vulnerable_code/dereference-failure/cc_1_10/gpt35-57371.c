//FormAI DATASET v1.0 Category: Binary search trees ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int data) {
    if (node == NULL) return createNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

Node* delete(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) root->left = delete(root->left, data);
    else if (data > root->data) root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) return root;
    else if (root->data < data) return search(root->right, data);
    return search(root->left, data);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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
    printf("Initial inorder traversal: ");
    inorder(root);
    printf("\nDeleting 20...\n");
    root = delete(root, 20);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\nSearching for 60...\n");
    Node* temp = search(root, 60);
    if (temp != NULL) printf("Found 60!\n");
    else printf("Could not find 60.\n");
    return 0;
}