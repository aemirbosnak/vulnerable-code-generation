//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A poetic dance of compression
// Inspired by the whisper of bits and bytes

// Node structure for linked list
typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

// Utility function to create a new node
Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to compare nodes for sorting purposes
int compare(const void* a, const void* b) {
    return ((Node*)a)->frequency - ((Node*)b)->frequency;
}

// Function to build the Huffman tree
Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    Node **nodes = (Node**)malloc(sizeof(Node*) * size);
    
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(characters[i], frequencies[i]);
    }

    qsort(nodes, size, sizeof(Node*), compare);

    while (size > 1) {
        Node *left = nodes[0];
        Node *right = nodes[1];

        Node *combined = createNode('$', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;

        nodes[1] = combined;  // Place combined node in second position
        size--;

        // Shift nodes back to keep them sorted
        for (int i = 0; i < size; i++) {
            nodes[i] = nodes[i + 1];
        }
        
        qsort(nodes, size, sizeof(Node*), compare);
    }

    Node* root = nodes[0];
    free(nodes);
    return root;
}

// Function to print the Huffman codes recursively
void printHuffmanCodes(Node* root, char* code, int depth) {
    if (root->left) {
        code[depth] = '0';
        printHuffmanCodes(root->left, code, depth + 1);
    }

    if (root->right) {
        code[depth] = '1';
        printHuffmanCodes(root->right, code, depth + 1);
    }

    if (!root->left && !root->right) {  // Leaf node
        code[depth] = '\0';
        printf("Character: %c, Code: %s\n", root->character, code);
    }
}

// Function to perform Huffman compression
void huffmanCompress(char* input) {
    int frequencies[256] = {0};
    char characters[256];
    int uniqueChars = 0;

    // Calculate frequency of each character in the input
    for (int i = 0; input[i]; i++) {
        if (frequencies[(unsigned char)input[i]] == 0) {
            characters[uniqueChars++] = input[i];  // Store unique characters
        }
        frequencies[(unsigned char)input[i]]++;
    }

    Node* root = buildHuffmanTree(characters, frequencies, uniqueChars);
    
    // Now, we will print the Huffman codes
    char code[256];
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, 0);
}

// Function to free the tree
void freeHuffmanTree(Node* root) {
    if (root) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

// Main function to initiate compression
int main() {
    char input[256];
    
    // An artistic prompt for the user
    printf("Compose a melody of characters to compress (max 255 chars):\n");
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character from input
    input[strcspn(input, "\n")] = 0;

    // Perform compression on provided input
    huffmanCompress(input);
    
    return 0;
}