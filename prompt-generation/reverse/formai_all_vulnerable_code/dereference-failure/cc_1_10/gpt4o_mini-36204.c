//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the frequency of characters
typedef struct {
    unsigned char character;
    int frequency;
} CharFrequency;

// Node for Huffman Tree
typedef struct Node {
    CharFrequency data;
    struct Node *left, *right;
} Node;

// Function to compare two CharFrequency structs for qsort
int compare(const void *a, const void *b) {
    return ((CharFrequency *)a)->frequency - ((CharFrequency *)b)->frequency;
}

// Function to create a new node
Node* createNode(char character, int frequency) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data.character = character;
    newNode->data.frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build the Huffman Tree
Node* buildHuffmanTree(CharFrequency frequencies[], int size) {
    qsort(frequencies, size, sizeof(CharFrequency), compare);
    
    while (size > 1) {
        Node *left = createNode(frequencies[0].character, frequencies[0].frequency);
        Node *right = createNode(frequencies[1].character, frequencies[1].frequency);
        
        Node *parent = createNode('\0', left->data.frequency + right->data.frequency);
        parent->left = left;
        parent->right = right;

        frequencies[2] = parent->data; // Merge left and right
        memmove(frequencies, frequencies + 2, (size - 2) * sizeof(CharFrequency)); // Shift left
        size--;
        qsort(frequencies, size, sizeof(CharFrequency), compare); // Sort again
    }
    
    return createNode(frequencies[0].character, frequencies[0].frequency);
}

// Function to generate the Huffman Codes
void generateCodes(Node *root, char *code, int depth, char *codes[]) {
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        codes[root->data.character] = strdup(code); // Store the code for the character
        return;
    }
    
    code[depth] = '0'; // Traverse left
    generateCodes(root->left, code, depth + 1, codes);
    
    code[depth] = '1'; // Traverse right
    generateCodes(root->right, code, depth + 1, codes);
}

// Function to compress the data
void compress(const char *input, const char *output) {
    int freq[256] = {0};
    for (const char *p = input; *p; p++) {
        freq[(unsigned char)*p]++;
    }
    
    CharFrequency frequencies[256];
    int size = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            frequencies[size++] = (CharFrequency){(unsigned char)i, freq[i]};
        }
    }

    Node *root = buildHuffmanTree(frequencies, size);
    char *codes[256] = {0};
    char code[256];
    generateCodes(root, code, 0, codes);
    
    FILE *outFile = fopen(output, "wb");
    if (!outFile) {
        perror("Unable to open output file");
        return;
    }

    // Writing the size of the frequencies table
    fwrite(&size, sizeof(int), 1, outFile);
    fwrite(frequencies, sizeof(CharFrequency), size, outFile);
    
    // Writing the compressed data
    unsigned char buffer = 0;
    int bitCount = 0;
    
    for (const char *p = input; *p; p++) {
        const char *codePtr = codes[(unsigned char)*p];
        while (*codePtr) {
            buffer = (buffer << 1) | (*codePtr - '0');
            bitCount++;
            if (bitCount == 8) {
                fwrite(&buffer, sizeof(unsigned char), 1, outFile);
                buffer = 0;
                bitCount = 0;
            }
            codePtr++;
        }
    }
    
    if (bitCount > 0) {
        buffer <<= (8 - bitCount); // Pad remaining bits
        fwrite(&buffer, sizeof(unsigned char), 1, outFile);
    }

    fclose(outFile);
}

// Program entry point
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inFile = fopen(argv[1], "r");
    if (!inFile) {
        perror("Unable to open input file");
        return EXIT_FAILURE;
    }

    fseek(inFile, 0, SEEK_END);
    long fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);
    
    char *inputBuffer = (char *)malloc(fileSize + 1);
    fread(inputBuffer, 1, fileSize, inFile);
    inputBuffer[fileSize] = '\0';
    
    fclose(inFile);

    compress(inputBuffer, argv[2]);
    free(inputBuffer);
    printf("Compression complete. Output file: %s\n", argv[2]);

    return EXIT_SUCCESS;
}