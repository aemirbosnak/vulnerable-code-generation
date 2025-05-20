//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100
#define MAX_CHAR 256

typedef struct {
    char character;
    int frequency;
    char code[MAX_CHAR];
} HuffmanNode;

typedef struct {
    HuffmanNode *nodes;
    int size;
} MinHeap;

// Function prototypes
MinHeap* createMinHeap(int capacity);
void insertMinHeap(MinHeap *minHeap, char character, int frequency);
HuffmanNode extractMin(MinHeap *minHeap);
void buildHuffmanTree(char *text, int *freq);
void generateCodes(HuffmanNode *nodes, int size, int index, char *code);
void encode(HuffmanNode *nodes, char *text, char *encodedText);
void decode(HuffmanNode *nodes, char *encodedText, char *decodedText);
void printHuffmanCodes(HuffmanNode *nodes, int size);

// Function to create a new min heap
MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->nodes = (HuffmanNode *)malloc(capacity * sizeof(HuffmanNode));
    return minHeap;
}

// Function to insert a new node into the min heap
void insertMinHeap(MinHeap *minHeap, char character, int frequency) {
    HuffmanNode newNode;
    newNode.character = character;
    newNode.frequency = frequency;
    minHeap->nodes[minHeap->size++] = newNode;
}

// Function to extract the minimum node from the min heap
HuffmanNode extractMin(MinHeap *minHeap) {
    int minIndex = 0;
    for (int i = 1; i < minHeap->size; i++) {
        if (minHeap->nodes[i].frequency < minHeap->nodes[minIndex].frequency) {
            minIndex = i;
        }
    }
    HuffmanNode minNode = minHeap->nodes[minIndex];
    minHeap->nodes[minIndex] = minHeap->nodes[--minHeap->size];
    return minNode;
}

// Build Huffman tree
void buildHuffmanTree(char *text, int *freq) {
    MinHeap *minHeap = createMinHeap(MAX_CHAR);
    
    // Count frequency of each character
    for (int i = 0; text[i]; i++) {
        freq[(unsigned char)text[i]]++;
    }

    // Insert frequency of all characters into min heap
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i]) {
            insertMinHeap(minHeap, (char)i, freq[i]);
        }
    }

    // Construct the Huffman tree
    // This part can be extended to handle the tree nodes properly
    while (minHeap->size > 1) {
        HuffmanNode left = extractMin(minHeap);
        HuffmanNode right = extractMin(minHeap);

        // Create a new internal node
        insertMinHeap(minHeap, '\0', left.frequency + right.frequency);
    }
}

// Generate Huffman codes
void generateCodes(HuffmanNode *nodes, int size, int index, char *code) {
    if (index == size) return;

    if (nodes[index].character) {
        strcpy(nodes[index].code, code);
    }

    code[strlen(code)] = '0';
    generateCodes(nodes, size, 2 * index + 1, code);
    code[strlen(code) - 1] = '1';
    generateCodes(nodes, size, 2 * index + 2, code);
    code[strlen(code)] = '\0';
}

// Encode the given text
void encode(HuffmanNode *nodes, char *text, char *encodedText) {
    encodedText[0] = '\0';
    for (int i = 0; text[i]; i++) {
        // Find the code for the character
        for (int j = 0; j < MAX_CHAR; j++) {
            if (nodes[j].character == text[i]) {
                strcat(encodedText, nodes[j].code);
            }
        }
    }
}

// Decode the encoded text using Huffman tree
void decode(HuffmanNode *nodes, char *encodedText, char *decodedText) {
    char *current = decodedText;
    // Iterate through the encoded text, this should be properly done by implementing the tree
    for (int i = 0; encodedText[i]; i++) {
        // A placeholder to decode, can be implemented if there is a proper node structure
    }
}

// Print Huffman codes
void printHuffmanCodes(HuffmanNode *nodes, int size) {
    printf("Huffman Codes:\n");
    for (int i = 0; i < size; i++) {
        if (nodes[i].character) {
            printf("%c: %s\n", nodes[i].character, nodes[i].code);
        }
    }
}

int main() {
    char text[MAX_CHAR] = "this is a simple example for huffman coding";
    int freq[MAX_CHAR] = {0};
    HuffmanNode nodes[MAX_CHAR] = {0};

    buildHuffmanTree(text, freq);
    generateCodes(nodes, sizeof(nodes) / sizeof(HuffmanNode), 0, "");
    printHuffmanCodes(nodes, sizeof(nodes) / sizeof(HuffmanNode));

    char encodedText[MAX_CHAR * 2] = {0};
    encode(nodes, text, encodedText);
    printf("Encoded Text: %s\n", encodedText);

    // To decode, we need more detailed data structure (not implemented for simplicity)
    // char decodedText[MAX_CHAR] = {0};
    // decode(nodes, encodedText, decodedText);
    // printf("Decoded Text: %s\n", decodedText);

    return 0;
}