//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a node in the tree
typedef struct Node {
    int key;
    char name[20];
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* newNode(int key, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform the binary search
Node* search(Node* root, int key) {
    if (root == NULL) {
        printf("Error: Tree is empty!\n");
        return NULL;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        printf("Congratulations! You've found %s with key %d!\n", root->name, root->key);
        return root;
    }
}

// Function to insert a new node into the tree
Node* insert(Node* root, int key, char* name) {
    if (root == NULL) {
        return newNode(key, name);
    }

    if (key < root->key) {
        root->left = insert(root->left, key, name);
    } else if (key > root->key) {
        root->right = insert(root->right, key, name);
    } else {
        printf("Error: Key already exists in the tree!\n");
        free(name);
    }

    return root;
}

// Function to display the contents of the tree in order
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s with key %d\n", root->name, root->key);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 50, "Thor");
    root = insert(root, 30, "Loki");
    root = insert(root, 40, "Odin");
    root = insert(root, 70, "Freyja");
    root = insert(root, 60, "Balder");

    printf("The Magnificent Quest for the Splendid Data begins!\n");

    int key;
    char name[20];

    while (1) {
        printf("\nEnter a name to search for (or type 'exit' to quit): ");
        scanf("%s", name);
        name[strcspn(name, "\n")] = '\0';

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter the key for %s: ", name);
        scanf("%d", &key);

        search(root, key);
    }

    printf("\nThe Magnificent Quest for the Splendid Data ends! ");
    printf("Your tree contains:\n");
    inOrderTraversal(root);

    return 0;
}