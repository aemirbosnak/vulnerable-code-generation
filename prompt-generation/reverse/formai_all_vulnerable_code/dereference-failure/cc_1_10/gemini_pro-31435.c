//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of a Huffman tree
typedef struct HuffmanNode {
    int frequency;
    char character;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// Comparison function for sorting nodes in a min-heap
int compareHuffmanNodes(const void *a, const void *b) {
    HuffmanNode *node1 = (HuffmanNode *)a;
    HuffmanNode *node2 = (HuffmanNode *)b;
    return node1->frequency - node2->frequency;
}

// Build a Huffman tree from a given array of characters and their frequencies
HuffmanNode *buildHuffmanTree(char *characters, int *frequencies, int size) {
    // Create a min-heap of Huffman nodes
    HuffmanNode **minHeap = (HuffmanNode **)malloc(sizeof(HuffmanNode *) * size);
    for (int i = 0; i < size; i++) {
        minHeap[i] = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        minHeap[i]->frequency = frequencies[i];
        minHeap[i]->character = characters[i];
        minHeap[i]->left = NULL;
        minHeap[i]->right = NULL;
    }

    // Build the Huffman tree
    while (size > 1) {
        // Extract the two nodes with the minimum frequencies
        HuffmanNode *node1 = minHeap[0];
        HuffmanNode *node2 = minHeap[1];
        minHeap[0] = minHeap[size - 1];
        size--;
        qsort(minHeap, size, sizeof(HuffmanNode *), compareHuffmanNodes);

        // Create a new node with the combined frequency of the two extracted nodes
        HuffmanNode *parentNode = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        parentNode->frequency = node1->frequency + node2->frequency;
        parentNode->character = '\0';
        parentNode->left = node1;
        parentNode->right = node2;

        // Insert the new node into the min-heap
        minHeap[0] = parentNode;
        qsort(minHeap, size, sizeof(HuffmanNode *), compareHuffmanNodes);
    }

    // Return the root of the Huffman tree
    return minHeap[0];
}

// Generate the Huffman codes for all the characters in the tree
void generateHuffmanCodes(HuffmanNode *root, char *codes, char *currentCode, int currentCodeLength) {
    if (root->left == NULL && root->right == NULL) {
        codes[root->character] = currentCode;
    } else {
        // Traverse the left subtree
        currentCode[currentCodeLength] = '0';
        generateHuffmanCodes(root->left, codes, currentCode, currentCodeLength + 1);

        // Traverse the right subtree
        currentCode[currentCodeLength] = '1';
        generateHuffmanCodes(root->right, codes, currentCode, currentCodeLength + 1);
    }
}

// Encode a given string using the Huffman codes
char *encodeHuffman(char *string, char *codes) {
    int encodedStringLength = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        encodedStringLength += strlen(codes[string[i]]);
    }

    char *encodedString = (char *)malloc(sizeof(char) * (encodedStringLength + 1));
    int currentPosition = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        strcat(encodedString, codes[string[i]]);
        currentPosition += strlen(codes[string[i]]);
    }

    encodedString[currentPosition] = '\0';
    return encodedString;
}

// Decode a given string using the Huffman codes
char *decodeHuffman(char *encodedString, HuffmanNode *root) {
    int decodedStringLength = 0;
    HuffmanNode *currentNode = root;
    for (int i = 0; encodedString[i] != '\0'; i++) {
        if (encodedString[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (currentNode->left == NULL && currentNode->right == NULL) {
            decodedStringLength++;
            currentNode = root;
        }
    }

    char *decodedString = (char *)malloc(sizeof(char) * (decodedStringLength + 1));
    int currentPosition = 0;
    currentNode = root;
    for (int i = 0; encodedString[i] != '\0'; i++) {
        if (encodedString[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (currentNode->left == NULL && currentNode->right == NULL) {
            decodedString[currentPosition] = currentNode->character;
            currentPosition++;
            currentNode = root;
        }
    }

    decodedString[currentPosition] = '\0';
    return decodedString;
}

// Driver code to test the Huffman coding
int main() {
    // Create an array of characters and their frequencies
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(characters) / sizeof(characters[0]);

    // Build the Huffman tree
    HuffmanNode *root = buildHuffmanTree(characters, frequencies, size);

    // Generate the Huffman codes for all the characters
    char codes[256];
    char currentCode[256];
    generateHuffmanCodes(root, codes, currentCode, 0);

    // Encode a given string using the Huffman codes
    char *string = "abracadabra";
    char *encodedString = encodeHuffman(string, codes);
    printf("Encoded string: %s\n", encodedString);

    // Decode the encoded string using the Huffman codes
    char *decodedString = decodeHuffman(encodedString, root);
    printf("Decoded string: %s\n", decodedString);

    return 0;
}