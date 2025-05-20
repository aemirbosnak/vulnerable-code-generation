//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold syntax tree node
typedef struct _Node {
    char* token;
    struct _Node* next;
} Node;

// Function to create a new node
Node* createNode(char* token) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->token = token;
    newNode->next = NULL;
    return newNode;
}

// Function to parse the syntax tree recursively
void parse(Node* root, char* input) {
    if (*input == '\0') {
        // Base case: reached end of input
        return;
    }
    Node* newNode = createNode(*input);
    root->next = newNode;
    parse(newNode, input + 1);
}

// Function to print the syntax tree
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%s ", root->token);
    printTree(root->next);
}

int main() {
    // Sample input string
    char input[] = "Hello world!";

    // Create root node
    Node* root = createNode("root");

    // Parse the syntax tree
    parse(root, input);

    // Print the syntax tree
    printf("Syntax tree:\n");
    printTree(root);

    return 0;
}