//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_VAL 100

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* minValueNode(Node* root) {
    Node* current = root;

    while (current->left!= NULL) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
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
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main() {
    srand(time(NULL));

    Node* root = NULL;

    for (int i = 0; i < MAX_NODES; i++) {
        root = insert(root, rand() % MAX_VAL);
    }

    printf("Inorder traversal:\n");
    inorderTraversal(root);

    printf("\n");

    for (int i = 0; i < MAX_NODES; i++) {
        root = deleteNode(root, rand() % MAX_VAL);
    }

    printf("Inorder traversal after deletion:\n");
    inorderTraversal(root);

    return 0;
}