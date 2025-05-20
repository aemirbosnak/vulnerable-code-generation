//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for comparison of nodes (used in sorting)
int compare(const void* a, const void* b) {
    return ((Node*)a)->frequency - ((Node*)b)->frequency;
}

// Function to create Huffman Coding
void generateHuffmanTree(Node** nodes, int size) {
    while (size > 1) {
        // Sort the nodes based on frequency
        qsort(nodes, size, sizeof(Node*), compare);

        // Create a new internal node
        Node* left = nodes[0];
        Node* right = nodes[1];
        Node* newNode = createNode('\0', left->frequency + right->frequency);

        newNode->left = left;
        newNode->right = right;

        // Replace two smallest nodes with new node
        nodes[0] = newNode;
        memmove(nodes + 1, nodes + 2, (size - 2) * sizeof(Node*));
        size--;
    }
}

// Function to print the codes
void printCodes(Node* root, char* code, int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    // Leaf node
    if (!root->left && !root->right) {
        printf("%c: %s\n", root->character, code);
    }
}

// Function to free the nodes
void freeHuffmanTree(Node* root) {
    if (root) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

int main() {
    // Sample input
    const char* text = "hello huffman";
    int frequency[256] = {0};
    int size = 0;

    // Calculate frequency of each character
    for (int i = 0; text[i] != '\0'; i++) {
        frequency[(unsigned char)text[i]]++;
    }

    // Create an array of nodes
    Node* nodes[256] = {NULL};
    for (int i = 0; i < 256; i++) {
        if (frequency[i]) {
            nodes[size++] = createNode((char)i, frequency[i]);
        }
    }

    // Generate Huffman Tree
    generateHuffmanTree(nodes, size);

    // Prepare to store codes
    char code[256];
    printCodes(nodes[0], code, 0); // The root of the tree

    // Clean up
    freeHuffmanTree(nodes[0]);

    return 0;
}