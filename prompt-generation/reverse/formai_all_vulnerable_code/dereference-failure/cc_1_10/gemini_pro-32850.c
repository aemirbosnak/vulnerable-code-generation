//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    unsigned char byte;
    struct node *left;
    struct node *right;
} node;

node *createNode(int freq, unsigned char byte) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->freq = freq;
    newNode->byte = byte;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int compareNodes(const void *a, const void *b) {
    node *node1 = (node *)a;
    node *node2 = (node *)b;
    return node1->freq - node2->freq;
}

node *buildTree(unsigned char *bytes, int size) {
    // Create a frequency table
    int freq[256] = {0};
    for (int i = 0; i < size; i++) {
        freq[bytes[i]]++;
    }

    // Create a priority queue of nodes
    node *queue[size];
    int queueSize = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            queue[queueSize++] = createNode(freq[i], i);
        }
    }

    // Build the Huffman tree
    while (queueSize > 1) {
        // Sort the queue by frequency
        qsort(queue, queueSize, sizeof(node *), compareNodes);

        // Create a new node for the two nodes with the lowest frequency
        node *newNode = createNode(queue[0]->freq + queue[1]->freq, 0);
        newNode->left = queue[0];
        newNode->right = queue[1];

        // Remove the two nodes with the lowest frequency from the queue
        for (int i = 0; i < queueSize - 2; i++) {
            queue[i] = queue[i + 2];
        }
        queueSize -= 2;

        // Insert the new node into the queue
        queue[queueSize++] = newNode;
    }

    return queue[0];
}

void printCodes(node *root, unsigned char *codes[], int codeSize[], int top) {
    if (root->left == NULL && root->right == NULL) {
        codes[root->byte] = malloc(top + 1);
        memcpy(codes[root->byte], codeSize, top);
        codes[root->byte][top] = '\0';
        return;
    }

    codeSize[top] = 0;
    printCodes(root->left, codes, codeSize, top + 1);
    codeSize[top] = 1;
    printCodes(root->right, codes, codeSize, top + 1);
}

void encode(unsigned char *bytes, int size, unsigned char **encodedBytes, int *encodedSize) {
    // Build the Huffman tree
    node *root = buildTree(bytes, size);

    // Create a table of codes
    unsigned char *codes[256];
    int codeSize[256];
    printCodes(root, codes, codeSize, 0);

    // Encode the bytes
    *encodedSize = 0;
    for (int i = 0; i < size; i++) {
        unsigned char *code = codes[bytes[i]];
        int codeLen = strlen(code);
        *encodedSize += codeLen;
    }

    *encodedBytes = malloc(*encodedSize);
    int offset = 0;
    for (int i = 0; i < size; i++) {
        unsigned char *code = codes[bytes[i]];
        int codeLen = strlen(code);
        memcpy(*encodedBytes + offset, code, codeLen);
        offset += codeLen;
    }
}

void decode(unsigned char *encodedBytes, int encodedSize, unsigned char **decodedBytes, int *decodedSize) {
    // Build the Huffman tree
    node *root = buildTree(encodedBytes, encodedSize);

    // Decode the bytes
    *decodedSize = 0;
    node *current = root;
    for (int i = 0; i < encodedSize; i++) {
        if (encodedBytes[i] == '0') {
            current = current->left;
        } else if (encodedBytes[i] == '1') {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            (*decodedBytes)[(*decodedSize)++] = current->byte;
            current = root;
        }
    }
}

int main() {
    // Input bytes
    unsigned char bytes[] = "Hello world!";
    int size = strlen(bytes);

    // Encode the bytes
    unsigned char *encodedBytes;
    int encodedSize;
    encode(bytes, size, &encodedBytes, &encodedSize);

    // Decode the bytes
    unsigned char *decodedBytes;
    int decodedSize;
    decode(encodedBytes, encodedSize, &decodedBytes, &decodedSize);

    // Print the decoded bytes
    printf("%s\n", decodedBytes);

    // Free the allocated memory
    free(encodedBytes);
    free(decodedBytes);

    return 0;
}