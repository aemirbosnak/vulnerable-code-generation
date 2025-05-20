//FormAI DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

Node* search(Node* node, int key) {
    if (node == NULL || node->data == key)
        return node;
    if (node->data < key)
        return search(node->right, key);
    return search(node->left, key);
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

    printf("Inorder traversal:\n");
    inorder(root);

    int searchKey = 60;
    Node* searchNode = search(root, searchKey);
    if (searchNode != NULL)
        printf("\n%d is present in the tree.", searchKey);
    else
        printf("\n%d is not present in the tree.", searchKey);

    return 0;
}