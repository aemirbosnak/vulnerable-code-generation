//FormAI DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048
#define CODE_SIZE 8

// Structure to hold variable length codes for characters
struct HuffmanCode {
    int frequency;
    char *code;
};

// Structure to hold node in the Huffman tree
struct Node {
    char letter;
    int frequency;
    struct Node *left;
    struct Node *right;
};

// Function to compare two nodes based on frequency
int compareNodes(const void *a, const void *b) {
    struct Node **nodeA = (struct Node **) a;
    struct Node **nodeB = (struct Node **) b;
    if ((*nodeA)->frequency < (*nodeB)->frequency) {
        return -1;
    } else if ((*nodeA)->frequency > (*nodeB)->frequency) {
        return 1;
    } else {
        return 0;
    }
}

// Recursive function to traverse the Huffman tree and generate codes for each character
void generateHuffmanCodes(struct Node *node, char *code, int size, struct HuffmanCode *huffmanCodes) {
    if (node->left != NULL) {
        // Traverse left node if it exists
        code[size] = '0';
        generateHuffmanCodes(node->left, code, size + 1, huffmanCodes);
    }
    if (node->right != NULL) {
        // Traverse right node if it exists
        code[size] = '1';
        generateHuffmanCodes(node->right, code, size + 1, huffmanCodes);
    }
    if (node->left == NULL && node->right == NULL) {
        // Leaf node, so store Huffman code for character
        huffmanCodes[node->letter].frequency = node->frequency;
        huffmanCodes[node->letter].code = malloc((size + 1) * sizeof(char));
        strncpy(huffmanCodes[node->letter].code, code, size);
        huffmanCodes[node->letter].code[size] = '\0';
    }
}

// Function to build the Huffman tree and generate codes for each character
struct HuffmanCode *buildHuffmanTree(char *inputString) {
    // Array to hold frequency for each ASCII character
    int frequencyArray[128] = {0};
    int inputStringLength = strlen(inputString);
    for (int i = 0; i < inputStringLength; i++) {
        frequencyArray[(int) inputString[i]]++;
    }
    // Array to hold pointers to tree nodes
    struct Node **nodeArray = malloc(128 * sizeof(struct Node *));
    int nodeCount = 0;
    // Create a leaf node for each character that appears in the input string
    for (int i = 0; i < 128; i++) {
        if (frequencyArray[i] > 0) {
            struct Node *node = malloc(sizeof(struct Node));
            node->letter = (char) i;
            node->frequency = frequencyArray[i];
            node->left = NULL;
            node->right = NULL;
            nodeArray[nodeCount] = node;
            nodeCount++;
        }
    }
    // Build Huffman tree by repeatedly combining the two nodes with lowest frequency until only one node remains
    while (nodeCount > 1) {
        qsort(nodeArray, nodeCount, sizeof(struct Node *), compareNodes);
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->letter = '\0';
        newNode->frequency = nodeArray[0]->frequency + nodeArray[1]->frequency;
        newNode->left = nodeArray[0];
        newNode->right = nodeArray[1];
        for (int i = 2; i < nodeCount; i++) {
            nodeArray[i - 2] = nodeArray[i];
        }
        nodeArray[nodeCount - 2] = newNode;
        nodeCount--;
    }
    // Huffman tree now complete, so generate Huffman codes for each character
    struct HuffmanCode *huffmanCodes = malloc(128 * sizeof(struct HuffmanCode));
    char code[BUFFER_SIZE] = {'\0'};
    generateHuffmanCodes(nodeArray[0], code, 0, huffmanCodes);
    free(nodeArray);
    return huffmanCodes;
}

// Function to compress the input string using the Huffman codes
char *compress(char *inputString, struct HuffmanCode *huffmanCodes) {
    char *compressedString = malloc(BUFFER_SIZE * sizeof(char));
    int inputStringLength = strlen(inputString);
    int outputIndex = 0;
    for (int i = 0; i < inputStringLength; i++) {
        // Find Huffman code for character and append it to compressed string
        char *code = huffmanCodes[(int) inputString[i]].code;
        int codeLength = strlen(code);
        for (int j = 0; j < codeLength; j++) {
            if (outputIndex % CODE_SIZE == 0) {
                compressedString[outputIndex / CODE_SIZE] = 0;
            }
            compressedString[outputIndex / CODE_SIZE] = compressedString[outputIndex / CODE_SIZE] << 1;
            if (code[j] == '1') {
                compressedString[outputIndex / CODE_SIZE] |= 1;
            }
            outputIndex++;
        }
    }
    // Add padding bits to ensure final byte is fully occupied
    int paddingBits = outputIndex % CODE_SIZE;
    if (paddingBits != 0) {
        paddingBits = CODE_SIZE - paddingBits;
        compressedString[outputIndex / CODE_SIZE] = compressedString[outputIndex / CODE_SIZE] << paddingBits;
    }
    compressedString[(outputIndex + paddingBits) / CODE_SIZE] = '\0';
    return compressedString;
}

int main() {
    char *inputString = "this is a test string";
    printf("Input string: %s\n", inputString);
    struct HuffmanCode *huffmanCodes = buildHuffmanTree(inputString);
    printf("Huffman codes:\n");
    for (int i = 0; i < 128; i++) {
        if (huffmanCodes[i].frequency > 0) {
            printf("%c: %s\n", (char) i, huffmanCodes[i].code);
        }
    }
    char *compressedString = compress(inputString, huffmanCodes);
    printf("Compressed string: %s\n", compressedString);
    return 0;
}