//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// Define a structure for the nodes of the binary search tree
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct Node *left;
    struct Node *right;
} Node;

// Function prototypes
Node* createNode(const char* word);
Node* insert(Node* root, const char* word);
void printInOrder(Node* root);
void freeTree(Node* root);
void toLowerCase(char* str);
void processFile(const char* filename);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    processFile(argv[1]);
    return 0;
}

// Function to create a new node
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a word into the BST
Node* insert(Node* root, const char* word) {
    if (root == NULL) {
        return createNode(word);
    }
    if (strcmp(word, root->word) < 0) {
        root->left = insert(root->left, word);
    } else if (strcmp(word, root->word) > 0) {
        root->right = insert(root->right, word);
    } else {
        root->count++;
    }
    return root;
}

// Function to perform an in-order traversal and print the words and their counts
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%s: %d\n", root->word, root->count);
        printInOrder(root->right);
    }
}

// Function to free the tree nodes
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to process the input file
void processFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    Node* root = NULL;
    char word[MAX_WORD_LENGTH];

    // Read words from the file
    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word);
        root = insert(root, word);
    }

    fclose(file);
    
    printf("Word Frequency Count:\n");
    printInOrder(root);
    
    freeTree(root);
}