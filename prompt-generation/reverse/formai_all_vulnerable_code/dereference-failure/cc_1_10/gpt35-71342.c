//FormAI DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
       return root;
     
    if (root->key < key)
       return search(root->right, key);
 
    return search(root->left, key);
}

void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    struct Node* root = NULL;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    
    printf("Inorder traversal of binary search tree: ");
    inorder(root);
    printf("\n");
    
    int key = 30;
    struct Node* temp = search(root, key);
    if (temp != NULL)
        printf("Key %d is found in the binary search tree\n", key);
    else
        printf("Key %d is not found in the binary search tree\n", key);

    return 0;
}