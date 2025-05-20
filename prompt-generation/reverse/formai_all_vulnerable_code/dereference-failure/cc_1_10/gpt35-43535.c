//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_INPUT_SIZE 1000
#define MAX_ENCODE_TREE_SIZE 256
#define CHAR_BITS 8

// Node structure for Huffman Tree
typedef struct Node {
    int freq;
    unsigned char ch;
    struct Node* left;
    struct Node* right;
} Node;

// Priority queue implementation for the Huffman Tree
typedef struct PriorityQueue {
    int size;
    int capacity;
    Node** nodes;
} PriorityQueue;

// Function to create a new node
Node* createNode(unsigned char ch, int freq) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create the priority queue
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->nodes = (Node**) malloc(capacity * sizeof(Node*));
    return queue;
}

// Function to swap two nodes in the priority queue
void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the priority queue
void heapify(PriorityQueue* queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->nodes[left]->freq < queue->nodes[smallest]->freq) {
        smallest = left;
    }

    if (right < queue->size && queue->nodes[right]->freq < queue->nodes[smallest]->freq) {
        smallest = right;
    }

    if (smallest != index) {
        swapNodes(&queue->nodes[index], &queue->nodes[smallest]);
        heapify(queue, smallest);
    }
}

// Function to insert a node in the priority queue
void insertNode(PriorityQueue* queue, Node* node) {
    int i = queue->size;
    queue->size++;
    queue->nodes[i] = node;

    while (i != 0 && queue->nodes[(i - 1) / 2]->freq > queue->nodes[i]->freq) {
        swapNodes(&queue->nodes[(i - 1) / 2], &queue->nodes[i]);
        i = (i - 1) / 2;
    }
}

// Function to get the minimum frequency node from the priority queue
Node* getMinNode(PriorityQueue* queue) {
    Node* minNode = queue->nodes[0];
    queue->size--;
    queue->nodes[0] = queue->nodes[queue->size];
    heapify(queue, 0);
    return minNode;
}

// Function to create the Huffman Tree
Node* createHuffmanTree(unsigned char* input, int* freqTable) {
    PriorityQueue* queue = createPriorityQueue(MAX_ENCODE_TREE_SIZE);

    for (int i = 0; i < MAX_ENCODE_TREE_SIZE; i++) {
        if (freqTable[i] > 0) {
            insertNode(queue, createNode((unsigned char) i, freqTable[i]));
        }
    }

    while (queue->size > 1) {
        Node* left = getMinNode(queue);
        Node* right = getMinNode(queue);

        Node* newNode = createNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        insertNode(queue, newNode);
    }

    return getMinNode(queue); // Returns the root of the Huffman Tree
}

// Function to generate the Huffman Code Table
void generateHuffmanCodeTable(Node* root, char** huffmanCodes, char* code, int index) {
    if (root->left != NULL) {
        code[index] = '0';
        generateHuffmanCodeTable(root->left, huffmanCodes, code, index + 1);
    }

    if (root->right != NULL) {
        code[index] = '1';
        generateHuffmanCodeTable(root->right, huffmanCodes, code, index + 1);
    }

    if (root->left == NULL && root->right == NULL) {
        code[index] = '\0';
        huffmanCodes[root->ch] = (char*) malloc(strlen(code) * sizeof(char));
        strcpy(huffmanCodes[root->ch], code);
    }
}

// Function to decode the input string using the Huffman Tree
void decodeHuffmanEncoding(unsigned char* input, int inputSize, Node* root, FILE* outputFile) {
    Node* currentNode = root;
    for (int i = 0; i < inputSize; i++) {
        if (input[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (currentNode->left == NULL && currentNode->right == NULL) {
            fprintf(outputFile, "%c", currentNode->ch);
            currentNode = root;
        }
    }
}

int main() {
    unsigned char input[MAX_INPUT_SIZE];
    int freqTable[MAX_ENCODE_TREE_SIZE] = {0};
    char* huffmanCodes[MAX_ENCODE_TREE_SIZE] = {0};

    // Get input from user
    printf("Enter the input message: ");
    fgets((char*) input, MAX_INPUT_SIZE, stdin);
    int inputSize = strlen((char*) input) - 1; // Ignore newline character

    // Generate frequency table
    for (int i = 0; i < inputSize; i++) {
        freqTable[input[i]]++;
    }

    // Create the Huffman Tree
    Node* root = createHuffmanTree(input, freqTable);

    // Generate the Huffman Code Table
    char* code = (char*) malloc(inputSize * sizeof(char));
    generateHuffmanCodeTable(root, huffmanCodes, code, 0);
    free(code);

    // Print the Huffman Code Table
    printf("\nHuffman Code Table:\n");
    for (int i = 0; i < MAX_ENCODE_TREE_SIZE; i++) {
        if (huffmanCodes[i] != NULL) {
            printf("%c\t%s\n", i, huffmanCodes[i]);
        }
    }
    printf("\n");

    // Encode the input message using the Huffman Code Table and print it to a file
    FILE* outputFile;
    outputFile = fopen("encoded_message.bin", "wb");
    int bitIndex = 0;
    unsigned char bitBuffer = 0;
    for (int i = 0; i < inputSize; i++) {
        char* huffmanCode = huffmanCodes[input[i]];
        int huffmanCodeLength = strlen(huffmanCode);
        for (int j = 0; j < huffmanCodeLength; j++) {
            if (huffmanCode[j] == '1') {
                bitBuffer |= 1 << (CHAR_BITS - 1 - bitIndex);
            }
            bitIndex++;
            if (bitIndex == CHAR_BITS) {
                fwrite(&bitBuffer, sizeof(unsigned char), 1, outputFile);
                bitIndex = 0;
                bitBuffer = 0;
            }
        }
    }
    if (bitIndex != 0) {
        fwrite(&bitBuffer, sizeof(unsigned char), 1, outputFile);
    }
    fclose(outputFile);

    // Read and decode the encoded message from the file using the Huffman Tree and print it to console
    unsigned char encodedMessage[MAX_INPUT_SIZE];
    int encodedMessageSize = 0;
    outputFile = fopen("encoded_message.bin", "rb");
    while (fread(&encodedMessage[encodedMessageSize], sizeof(unsigned char), 1, outputFile) == 1) {
        encodedMessageSize++;
    }
    fclose(outputFile);
    printf("Decoded message: ");
    decodeHuffmanEncoding(encodedMessage, encodedMessageSize, root, stdout);
    printf("\n");

    // Free memory
    for (int i = 0; i < MAX_ENCODE_TREE_SIZE; i++) {
        free(huffmanCodes[i]);
    }
    free(root);
    free(huffmanCodes);
    return 0;
}