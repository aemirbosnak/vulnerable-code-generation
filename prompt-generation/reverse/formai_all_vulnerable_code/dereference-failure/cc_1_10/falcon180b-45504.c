//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_STR_LEN 100

// Node structure definition
typedef struct node {
    char data[MAX_STR_LEN];
    int count;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given data
Node* newNode(char* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new word into the tree
void insert(Node* root, char* word) {
    if (root == NULL) {
        root = newNode(word);
    } else if (strcmp(root->data, word) == 0) {
        root->count++;
    } else if (strcmp(word, root->data) < 0) {
        insert(root->left, word);
    } else {
        insert(root->right, word);
    }
}

// Function to search for a word in the tree
bool search(Node* root, char* word) {
    if (root == NULL) {
        return false;
    } else if (strcmp(root->data, word) == 0) {
        return true;
    } else if (strcmp(word, root->data) < 0) {
        return search(root->left, word);
    } else {
        return search(root->right, word);
    }
}

// Function to print the tree in alphabetical order
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%s (%d)\n", root->data, root->count);
    printTree(root->right);
}

int main() {
    Node* root = NULL;
    char word[MAX_STR_LEN];

    // Insert some words into the tree
    insert(root, "apple");
    insert(root, "banana");
    insert(root, "cherry");
    insert(root, "date");
    insert(root, "elderberry");
    insert(root, "fig");
    insert(root, "grape");
    insert(root, "honeydew");

    // Print the tree
    printf("Alphabetical list of fruits:\n");
    printTree(root);

    // Search for a word in the tree
    char searchWord[MAX_STR_LEN];
    printf("\nEnter a fruit to search for: ");
    scanf("%s", searchWord);
    if (search(root, searchWord)) {
        printf("%s found in the tree.\n", searchWord);
    } else {
        printf("%s not found in the tree.\n", searchWord);
    }

    return 0;
}