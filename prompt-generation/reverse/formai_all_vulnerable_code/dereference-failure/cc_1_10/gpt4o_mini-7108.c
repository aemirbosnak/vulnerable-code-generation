//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

int search(Node* root, int key, char* path, int level) {
    if (root == NULL) {
        return 0; // Value not found
    }

    path[level] = root->data + '0'; // Convert int to char
    level++;

    if (root->data == key) {
        path[level] = '\0'; // Null terminate the path string
        printf("Found %d at path: %s\n", key, path);
        return 1; // Value found
    }

    // Search in left subtree
    if (search(root->left, key, path, level)) {
        return 1;
    }

    // Search in right subtree
    return search(root->right, key, path, level);
}

int main() {
    Node* root = NULL;
    int numbers[] = {10, 5, 20, 3, 7, 15, 30};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    
    for (int i = 0; i < n; i++) {
        insert(&root, numbers[i]);
    }

    int key;
    char path[100]; // Array to store the path

    printf("Enter the number you want to search for: ");
    scanf("%d", &key);

    if (!search(root, key, path, 0)) {
        printf("Number %d not found in the tree.\n", key);
    }

    // Free the allocated memory (not implemented here for brevity)
    // In a full implementation, ensure to free memory for each node

    return 0;
}