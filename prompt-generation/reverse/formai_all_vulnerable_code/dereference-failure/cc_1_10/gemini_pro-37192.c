//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of the Huffman tree
struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(char character, int frequency) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to compare two nodes based on their frequency
int compareNodes(const void *a, const void *b) {
    struct Node **node1 = (struct Node **)a;
    struct Node **node2 = (struct Node **)b;
    return (*node1)->frequency - (*node2)->frequency;
}

// Function to build a Huffman tree
struct Node *buildHuffmanTree(char *characters, int *frequencies, int size) {
    // Create a priority queue of nodes
    struct Node **nodes = (struct Node **)malloc(sizeof(struct Node *) * size);
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(characters[i], frequencies[i]);
    }
    qsort(nodes, size, sizeof(struct Node *), compareNodes);

    // Build the Huffman tree
    while (size > 1) {
        // Get the two nodes with the lowest frequency
        struct Node *node1 = nodes[0];
        struct Node *node2 = nodes[1];

        // Create a new node with the combined frequency
        struct Node *parentNode = createNode('\0', node1->frequency + node2->frequency);
        parentNode->left = node1;
        parentNode->right = node2;

        // Remove the two nodes with the lowest frequency
        nodes[0] = nodes[size - 1];
        size--;

        // Insert the new node into the priority queue
        qsort(nodes, size, sizeof(struct Node *), compareNodes);
    }

    // Return the root of the Huffman tree
    return nodes[0];
}

// Function to generate a Huffman code for a character
char *generateHuffmanCode(struct Node *root, char character) {
    if (root == NULL) {
        return NULL;
    }

    if (root->character == character) {
        return "";
    }

    char *leftCode = generateHuffmanCode(root->left, character);
    if (leftCode != NULL) {
        return strcat("0", leftCode);
    }

    char *rightCode = generateHuffmanCode(root->right, character);
    if (rightCode != NULL) {
        return strcat("1", rightCode);
    }

    return NULL;
}

// Function to encode a string using Huffman coding
char *encodeHuffman(char *string, struct Node *root) {
    char *encodedString = (char *)malloc(1000);
    int index = 0;
    for (int i = 0; i < strlen(string); i++) {
        char *code = generateHuffmanCode(root, string[i]);
        strcat(encodedString, code);
        index += strlen(code);
    }
    return encodedString;
}

// Function to decode a string using Huffman coding
char *decodeHuffman(char *encodedString, struct Node *root) {
    char *decodedString = (char *)malloc(strlen(encodedString));
    int index = 0;
    struct Node *currentNode = root;
    for (int i = 0; i < strlen(encodedString); i++) {
        if (encodedString[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (currentNode->character != '\0') {
            decodedString[index++] = currentNode->character;
            currentNode = root;
        }
    }
    return decodedString;
}

// Driver code
int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 4};
    int size = sizeof(characters) / sizeof(characters[0]);

    // Build the Huffman tree
    struct Node *root = buildHuffmanTree(characters, frequencies, size);

    // Generate the Huffman codes
    char *codes[size];
    for (int i = 0; i < size; i++) {
        codes[i] = generateHuffmanCode(root, characters[i]);
        printf("%c: %s\n", characters[i], codes[i]);
    }

    // Encode a string
    char *string = "abcdef";
    char *encodedString = encodeHuffman(string, root);
    printf("Encoded string: %s\n", encodedString);

    // Decode the encoded string
    char *decodedString = decodeHuffman(encodedString, root);
    printf("Decoded string: %s\n", decodedString);

    return 0;
}