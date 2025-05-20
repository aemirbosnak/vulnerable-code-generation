//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char key[20];
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char* str) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->key, str);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, Node* newNode) {
    if (root == NULL) {
        root = newNode;
    } else if (strcmp(newNode->key, root->key) < 0) {
        root->left = insert(root->left, newNode);
    } else {
        root->right = insert(root->right, newNode);
    }
    return root;
}

bool search(Node* root, char* key) {
    if (root == NULL) {
        return false;
    } else if (strcmp(root->key, key) == 0) {
        return true;
    } else if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* minValueNode(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, char* key) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(key, root->key) < 0) {
        root->left = deleteNode(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        root->right = deleteNode(root->right, key);
    } else {
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
        strcpy(root->key, temp->key);
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, newNode("apple"));
    root = insert(root, newNode("banana"));
    root = insert(root, newNode("cherry"));
    root = insert(root, newNode("orange"));
    root = insert(root, newNode("kiwi"));

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    bool found = search(root, "banana");
    if (found) {
        printf("Found: %s\n", "banana");
    } else {
        printf("Not found: %s\n", "banana");
    }

    root = deleteNode(root, "banana");

    printf("Inorder traversal after deleting 'banana': ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}