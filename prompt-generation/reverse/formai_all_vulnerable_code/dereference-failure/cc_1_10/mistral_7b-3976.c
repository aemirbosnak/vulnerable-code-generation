//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        root = newNode(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}

int main() {
    srand(time(NULL));
    int size, i;
    printf("Enter the size of binary search tree: ");
    scanf("%d", &size);

    Node* root = NULL;

    printf("Generating random keys for binary search tree...\n");
    for (i = 0; i < size; i++) {
        root = insert(root, rand() % 100);
    }

    printf("\nCreated binary search tree with %d elements:\n", size);
    inorderTraversal(root);
    printf("\n");

    return 0;
}