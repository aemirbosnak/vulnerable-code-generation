//FormAI DATASET v1.0 Category: Binary search trees ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d -> ", root->data);
        inOrder(root->right);
    }
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
       return root;
    
    if (root->data < key)
       return search(root->right, key);

    return search(root->left, key);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of BST: \n");
    inOrder(root);

    int key = 60;
    struct Node* result = search(root, key);
    if (result == NULL)
        printf("\n%d is not found in the BST\n", key);
    else
        printf("\n%d is found in the BST\n", key);

    key = 100;
    result = search(root, key);
    if (result == NULL)
        printf("%d is not found in the BST\n", key);
    else
        printf("%d is found in the BST\n", key);

    return 0;
}