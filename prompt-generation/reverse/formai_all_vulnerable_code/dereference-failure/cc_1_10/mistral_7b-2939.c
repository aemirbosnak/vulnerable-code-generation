//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(Node* root, char* style) {
    if (root == NULL) {
        printf("%s Nothing to display!\n", style);
        return;
    }

    inorderTraversal(root->left, "Cracking the code, left branch...");
    printf("%s %d\n", style, root->data);
    inorderTraversal(root->right, "Racing through the right branch...");
}

int main() {
    srand(time(NULL));

    Node* root = NULL;

    for (int i = 0; i < 10; i++) {
        root = insert(root, rand() % 20 + 1);
    }

    printf("Inserted 10 random numbers, let's see them!\n");
    inorderTraversal(root, "In an energetic inorder traversal style...");

    return 0;
}