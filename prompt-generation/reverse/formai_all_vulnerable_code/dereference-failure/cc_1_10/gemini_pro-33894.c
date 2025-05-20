//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256

// Symbol structure
typedef struct {
    char character;
    int frequency;
    char *code;
} Symbol;

// Node structure
typedef struct node {
    Symbol symbol;
    struct node *left;
    struct node *right;
} Node;

// Comparison function for sorting symbols by frequency
int compareSymbols(const void *a, const void *b) {
    Symbol *symbol1 = (Symbol *)a;
    Symbol *symbol2 = (Symbol *)b;
    return symbol1->frequency - symbol2->frequency;
}

// Create a new node
Node *createNode(Symbol symbol) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->symbol = symbol;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build the Huffman tree
Node *buildHuffmanTree(Symbol symbols[], int size) {
    // Create a priority queue of nodes
    Node *queue[size];
    for (int i = 0; i < size; i++) {
        queue[i] = createNode(symbols[i]);
    }

    // Sort the queue by frequency
    qsort(queue, size, sizeof(Node *), compareSymbols);

    // While there are more than one node in the queue
    while (size > 1) {
        // Remove the two nodes with the lowest frequencies
        Node *node1 = queue[0];
        Node *node2 = queue[1];
        queue[0] = queue[size - 1];
        size--;
        queue[1] = queue[size - 1];
        size--;

        // Create a new node for the parent
        Node *parentNode = createNode((Symbol){'\0', node1->symbol.frequency + node2->symbol.frequency, NULL});

        // Set the left and right children of the parent node
        parentNode->left = node1;
        parentNode->right = node2;

        // Insert the parent node into the queue
        queue[size++] = parentNode;

        // Sort the queue by frequency
        qsort(queue, size, sizeof(Node *), compareSymbols);
    }

    // Return the root of the Huffman tree
    return queue[0];
}

// Generate the Huffman codes for each symbol
void generateHuffmanCodes(Node *root, char *code, int length) {
    if (root->symbol.character != '\0') {
        // If the node is a leaf node, assign the code to the symbol
        root->symbol.code = malloc(length + 1);
        strcpy(root->symbol.code, code);
    } else {
        // If the node is an internal node, generate the codes for its children
        generateHuffmanCodes(root->left, strcat(code, "0"), length + 1);
        generateHuffmanCodes(root->right, strcat(code, "1"), length + 1);
    }
}

// Encode a string using the Huffman tree
char *encodeString(Node *root, char *string) {
    int length = strlen(string);
    char *encodedString = malloc(length * 8 + 1);
    int index = 0;

    for (int i = 0; i < length; i++) {
        char character = string[i];
        Node *node = root;

        // Find the node corresponding to the character
        while (node->symbol.character != character && node->left != NULL && node->right != NULL) {
            if (character < node->symbol.character) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        // Append the code for the character to the encoded string
        strcat(encodedString, node->symbol.code);
        index += strlen(node->symbol.code);
    }

    encodedString[index] = '\0';
    return encodedString;
}

// Decode a string using the Huffman tree
char *decodeString(Node *root, char *encodedString) {
    int length = strlen(encodedString);
    char *decodedString = malloc(length + 1);
    int index = 0;

    Node *node = root;

    for (int i = 0; i < length; i++) {
        char bit = encodedString[i];

        // Follow the path in the Huffman tree corresponding to the bit
        if (bit == '0') {
            node = node->left;
        } else if (bit == '1') {
            node = node->right;
        }

        // If the node is a leaf node, append the character to the decoded string
        if (node->symbol.character != '\0') {
            decodedString[index++] = node->symbol.character;
            node = root;
        }
    }

    decodedString[index] = '\0';
    return decodedString;
}

// Free the memory allocated for the Huffman tree
void freeHuffmanTree(Node *root) {
    if (root != NULL) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

// Print the Huffman codes for each symbol
void printHuffmanCodes(Symbol symbols[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c: %s\n", symbols[i].character, symbols[i].code);
    }
}

int main() {
    // Define the symbols and their frequencies
    Symbol symbols[] = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 4},
    };

    int size = sizeof(symbols) / sizeof(symbols[0]);

    // Build the Huffman tree
    Node *root = buildHuffmanTree(symbols, size);

    // Generate the Huffman codes for each symbol
    generateHuffmanCodes(root, "", 0);

    // Print the Huffman codes
    printHuffmanCodes(symbols, size);

    // Encode the string "abcabc"
    char *string = "abcabc";
    char *encodedString = encodeString(root, string);

    // Decode the encoded string back to the original string
    char *decodedString = decodeString(root, encodedString);

    // Print the encoded and decoded strings
    printf("Encoded string: %s\n", encodedString);
    printf("Decoded string: %s\n", decodedString);

    // Free the memory allocated for the Huffman tree
    freeHuffmanTree(root);

    return 0;
}