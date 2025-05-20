//FormAI DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Struct for storing a character and its frequency
typedef struct {
    char ch;
    int freq;
} CharFreq;

// Array of CharFreq objects for each character in the file
CharFreq charCounts[256] = {0};
// Length of the input file
long long inputFileLength = 0;

// Function to calculate the frequency of each character in the input file
void calculateCharacterFrequencies(FILE* inputFile) {
    int ch;
    // Iterate through each character in the file
    while ((ch = fgetc(inputFile)) != EOF) {
        // Increment the frequency of the corresponding CharFreq object
        charCounts[ch].freq++;
        // Increment the length of the input file
        inputFileLength++;
    }
}

// Struct for representing a node in the Huffman tree
typedef struct Node {
    CharFreq data;
    struct Node *left;
    struct Node *right;
} Node;

// Array of Huffman tree nodes for each character in the file
Node nodes[256];
// Index of the next available Huffman tree node
int nextNodeIndex = 0;

// Function to initialize the Huffman tree nodes based on the character frequencies
void initializeHuffmanTreeNodes() {
    // Iterate through each character in the file
    for (int i = 0; i < 256; i++) {
        // If the character has a nonzero frequency, create a Huffman tree node for it
        if (charCounts[i].freq != 0) {
            nodes[nextNodeIndex].data = charCounts[i];
            nodes[nextNodeIndex].left = NULL;
            nodes[nextNodeIndex].right = NULL;
            nextNodeIndex++;
        }
    }
}

// Function to compare two Huffman tree nodes by frequency
int compareNodesByFrequency(const void *a, const void *b) {
    Node *nodeA = (Node *)a;
    Node *nodeB = (Node *)b;
    return (nodeA->data.freq - nodeB->data.freq);
}

// Function to build the Huffman tree
Node* buildHuffmanTree() {
    // Sort the Huffman tree nodes by frequency
    qsort(nodes, nextNodeIndex, sizeof(Node), compareNodesByFrequency);
    // Iterate through the sorted node array, combining pairs of nodes into a parent node
    for (int i = 0; i < nextNodeIndex - 1; i++) {
        Node *parentNode = (Node *)malloc(sizeof(Node));
        parentNode->left = &nodes[i];
        parentNode->right = &nodes[i+1];
        // Set the frequency of the parent node to the sum of its child nodes' frequencies
        parentNode->data.freq = nodes[i].data.freq + nodes[i+1].data.freq;
        // Add the parent node to the array of nodes
        nodes[nextNodeIndex] = *parentNode;
        nextNodeIndex++;
        // Sort the node array again to ensure that the nodes are still sorted by frequency
        qsort(nodes + i + 1, nextNodeIndex - i - 1, sizeof(Node), compareNodesByFrequency);
    }
    // Return the root node of the Huffman tree
    return &nodes[nextNodeIndex - 1];
}

// Struct for storing the bit sequence for a given character
typedef struct {
    char ch;
    int numBits;
    char bits[256];
} BitSequence;

// Array of BitSequence objects for each character in the file
BitSequence bitSequences[256] = {0};

// Function to recursively generate the bit sequences for each character in the Huffman tree
void generateBitSequences(Node *node, int depth, int path) {
    if (node->left == NULL && node->right == NULL) {
        // Leaf node, add bit sequence to array
        BitSequence *bitSeq = &bitSequences[node->data.ch];
        bitSeq->ch = node->data.ch;
        bitSeq->numBits = depth;
        // Iterate through the bits in the path and add them to the array in reverse order
        for (int i = depth - 1; i >= 0; i--) {
            bitSeq->bits[i] = (path >> i) & 1;
        }
    } else {
        // Non-leaf node, recursively generate bit sequences for child nodes
        generateBitSequences(node->left, depth + 1, path << 1);
        generateBitSequences(node->right, depth + 1, (path << 1) | 1);
    }
}

// Function to write the Huffman tree to the compressed output file
void writeHuffmanTree(Node *node, FILE *outputFile) {
    if (node->left == NULL && node->right == NULL) {
        // Leaf node, write "1" followed by the character code
        fputc('1', outputFile);
        fputc(node->data.ch, outputFile);
    } else {
        // Non-leaf node, write "0" and recursively write child nodes
        fputc('0', outputFile);
        writeHuffmanTree(node->left, outputFile);
        writeHuffmanTree(node->right, outputFile);
    }
}

// Function to compress the input file and write the compressed data to the output file
void compressFile(char *inputFilePath, char *outputFilePath) {
    // Open the input file for reading
    FILE* inputFile = fopen(inputFilePath, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open file \"%s\" for reading.\n", inputFilePath);
        exit(1);
    }

    // Calculate the frequency of each character in the file
    calculateCharacterFrequencies(inputFile);

    // Initialize the Huffman tree nodes based on the character frequencies
    initializeHuffmanTreeNodes();

    // Build the Huffman tree
    Node *rootNode = buildHuffmanTree();

    // Generate the bit sequence for each character in the Huffman tree
    generateBitSequences(rootNode, 0, 0);

    // Open the output file for writing
    FILE* outputFile = fopen(outputFilePath, "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open file \"%s\" for writing.\n", outputFilePath);
        exit(1);
    }

    // Write the length of the input file to the compressed output file
    fwrite(&inputFileLength, sizeof(long long), 1, outputFile);

    // Write the Huffman tree to the compressed output file
    writeHuffmanTree(rootNode, outputFile);

    // Reset the input file pointer to the beginning of the file
    fseek(inputFile, 0, SEEK_SET);

    // Variable for reading bits from the input file
    int bitBuffer = 0;
    // Number of bits currently in the bit buffer
    int numBitsInBuffer = 0;

    // Iterate through each character in the input file
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // Get the bit sequence for the current character
        BitSequence bitSeq = bitSequences[ch];
        // Iterate through each bit in the bit sequence
        for (int i = 0; i < bitSeq.numBits; i++) {
            // Add the bit to the bit buffer
            bitBuffer = (bitBuffer << 1) | bitSeq.bits[i];
            numBitsInBuffer++;
            // If the bit buffer is full, write it to the output file
            if (numBitsInBuffer == 8) {
                fputc(bitBuffer, outputFile);
                bitBuffer = 0;
                numBitsInBuffer = 0;
            }
        }
    }

    // If there are any bits remaining in the bit buffer, add padding zeroes and write it to the output file
    if (numBitsInBuffer != 0) {
        bitBuffer = bitBuffer << (8 - numBitsInBuffer);
        fputc(bitBuffer, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// Function to read the Huffman tree from the compressed input file and return the root node
Node* readHuffmanTree(FILE *inputFile) {
    int bit;
    // Read the next bit from the input file
    if ((bit = fgetc(inputFile)) == EOF) {
        printf("Error: Unexpected end of file while reading Huffman tree.\n");
        exit(1);
    }

    if (bit == '1') {
        // Leaf node, read the character code and create a new node for it
        if ((bit = fgetc(inputFile)) == EOF) {
            printf("Error: Unexpected end of file while reading leaf node in Huffman tree.\n");
            exit(1);
        }
        Node *node = (Node *)malloc(sizeof(Node));
        node->data.ch = bit;
        node->data.freq = 0;
        node->left = NULL;
        node->right = NULL;
        return node;
    } else if (bit == '0') {
        // Non-leaf node, create a new node and recursively read child nodes
        Node *node = (Node *)malloc(sizeof(Node));
        node->data.ch = 0;
        node->data.freq = 0;
        node->left = readHuffmanTree(inputFile);
        node->right = readHuffmanTree(inputFile);
        return node;
    } else {
        printf("Error: Invalid bit value (%d) while reading Huffman tree.\n", bit);
        exit(1);
    }
}

// Function to decompress the input file and write the decompressed data to the output file
void decompressFile(char *inputFilePath, char *outputFilePath) {
    // Open the input file for reading
    FILE* inputFile = fopen(inputFilePath, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open file \"%s\" for reading.\n", inputFilePath);
        exit(1);
    }

    // Read the length of the input file from the compressed input file
    fread(&inputFileLength, sizeof(long long), 1, inputFile);

    // Read the Huffman tree from the compressed input file
    Node *rootNode = readHuffmanTree(inputFile);

    // Open the output file for writing
    FILE* outputFile = fopen(outputFilePath, "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open file \"%s\" for writing.\n", outputFilePath);
        exit(1);
    }

    // Variable for reading bits from the input file
    int bitBuffer = 0;
    // Number of bits currently in the bit buffer
    int numBitsInBuffer = 0;

    // Variable for keeping track of the number of characters written to the output file so far
    long long numCharsWritten = 0;

    // Start at the root node of the Huffman tree
    Node *currentNode = rootNode;

    // Iterate through each bit in the compressed input file
    int bit;
    while ((bit = fgetc(inputFile)) != EOF) {
        // Iterate through each bit in the current byte
        for (int i = 0; i < 8; i++) {
            // Get the next bit from the input file
            int bitValue = (bit >> (7 - i)) & 1;
            // Traverse the Huffman tree based on the bit value
            if (bitValue == 0) {
                currentNode = currentNode->left;
            } else if (bitValue == 1) {
                currentNode = currentNode->right;
            } else {
                printf("Error: Invalid bit value (%d) while decompressing file.\n", bitValue);
                exit(1);
            }
            // If we've reached a leaf node, write the corresponding character to the output file
            if (currentNode->left == NULL && currentNode->right == NULL) {
                fputc(currentNode->data.ch, outputFile);
                currentNode = rootNode;
                numCharsWritten++;
                // If we've written all the characters in the input file, stop decompressing
                if (numCharsWritten == inputFileLength) {
                    break;
                }
            }
        }
        // If we've written all the characters in the input file, stop decompressing
        if (numCharsWritten == inputFileLength) {
            break;
        }
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s [compress/decompress] [input file path] [output file path]\n", argv[0]);
        exit(1);
    }

    char *mode = argv[1];
    char *inputFilePath = argv[2];
    char *outputFilePath = argv[3];

    if (strcmp(mode, "compress") == 0) {
        compressFile(inputFilePath, outputFilePath);
    } else if (strcmp(mode, "decompress") == 0) {
        decompressFile(inputFilePath, outputFilePath);
    } else {
        printf("Error: Invalid mode \"%s\".\n", mode);
        exit(1);
    }

    return 0;
}