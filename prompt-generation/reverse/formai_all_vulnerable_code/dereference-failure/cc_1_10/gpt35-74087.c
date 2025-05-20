//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

// Define the maximum character size
#define MAX_CHAR_SIZE 256

// Define the structure for Huffman codes
struct huffCode {
    int freq;
    int bits[MAX_CHAR_SIZE];
    int size;
};

// Define the structure for Huffman tree node
struct huffNode {
    int freq;
    char data;
    struct huffNode* left;
    struct huffNode* right;
};

// Define the structure for priority queue node
struct pqNode {
    struct huffNode* data;
    struct pqNode* next;
};

// Declare the global variables for priority queue front and rear
struct pqNode* front = NULL;
struct pqNode* rear = NULL;

// Function to create new Huffman tree node
struct huffNode* newHuffNode(char data, int freq) {
    struct huffNode* node = (struct huffNode*) malloc(sizeof(struct huffNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create new priority queue node
struct pqNode* newPQNode(struct huffNode* node) {
    struct pqNode* pqN = (struct pqNode*) malloc(sizeof(struct pqNode));
    pqN->data = node;
    pqN->next = NULL;
    return pqN;
}

// Function to check if priority queue is empty
bool isPQEmpty() {
    return front == NULL;
}

// Function to add a new node to the priority queue
void enQueue(struct huffNode* huffN) {

    struct pqNode* pqN = newPQNode(huffN);

    // If queue is empty
    if (isPQEmpty()) {
        front = rear = pqN;
        return;
    }

    // If new node has lower frequency than front node
    if (huffN->freq < front->data->freq) {
        pqN->next = front;
        front = pqN;
        return;
    }

    // If new node has greater frequency than rear node
    if (huffN->freq > rear->data->freq) {
        rear->next = pqN;
        rear = pqN;
        return;
    }

    // Find the correct position for new node
    struct pqNode* curr = front;
    while (curr->next->data->freq < huffN->freq)
        curr = curr->next;
    pqN->next = curr->next;
    curr->next = pqN;
}

// Function to remove node from the front of the priority queue
struct huffNode* deQueue() {

    if (isPQEmpty()) return NULL;

    struct pqNode* temp = front;
    struct huffNode* node = temp->data;

    // If queue has only one node
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;

    free(temp);
    return node;
}

// Function to build Huffman tree
struct huffNode* buildHuffmanTree(int freq[MAX_CHAR_SIZE]) {

    // Add all characters to the priority queue
    for (int i = 0; i < MAX_CHAR_SIZE; i++) {
        if (freq[i] != 0) {
            struct huffNode* node = newHuffNode(i, freq[i]);
            enQueue(node);
        }
    }

    while (front != rear) {

        // Dequeue two nodes with lowest frequency
        struct huffNode* left = deQueue();
        struct huffNode* right = deQueue();

        // Create a new node with frequency equal to sum of left and right nodes
        struct huffNode* parent = newHuffNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        // Add the new node to the priority queue
        enQueue(parent);
    }

    return deQueue();
}

// Function to generate Huffman codes for each character
void generateCodes(struct huffNode* root, struct huffCode codes[], int arr[], int top) {

    if (root->left != NULL) {
        arr[top] = 0;
        generateCodes(root->left, codes, arr, top + 1);
    }
    if (root->right != NULL) {
        arr[top] = 1;
        generateCodes(root->right, codes, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        codes[root->data].freq = root->freq;
        codes[root->data].size = top;
        memcpy(codes[root->data].bits, arr, top * sizeof(int));
    }
}

// Function to encode input data to Huffman code
void encode(char data[], struct huffCode codes[], char encodedData[], int* size) {

    int len = strlen(data);
    *size = 0;

    for (int i = 0; i < len; i++) {
        memcpy(&encodedData[*size], codes[data[i]].bits, codes[data[i]].size * sizeof(int));
        *size += codes[data[i]].size;
    }
}

// Function to decode Huffman code to original data
void decode(int encodedBits[], struct huffNode* root, char decodedData[], int size) {

    int i = 0, j = 0;
    struct huffNode* curr = root;

    while (i < size) {
        if (encodedBits[i] == 0) curr = curr->left;
        else curr = curr->right;
        i++;
        if (curr->left == NULL && curr->right == NULL) {
            decodedData[j++] = curr->data;
            curr = root;
        }
    }
    decodedData[j] = '\0';
}

int main() {

    char data[] = "Huffman Coding is a data compression algorithm.";

    // Calculate frequency of each character
    int freq[MAX_CHAR_SIZE] = { 0 };
    for (int i = 0; i < strlen(data); i++)
        freq[data[i]]++;

    // Build Huffman tree
    struct huffNode* root = buildHuffmanTree(freq);

    // Generate Huffman codes for each character
    struct huffCode codes[MAX_CHAR_SIZE] = { 0 };
    int arr[MAX_CHAR_SIZE] = { 0 };
    generateCodes(root, codes, arr, 0);

    // Encode input data to Huffman code
    char encodedData[5000] = { 0 };
    int encodedSize = 0;
    encode(data, codes, encodedData, &encodedSize);

    // Print Huffman codes for each character
    printf("Huffman Codes:\n\n");
    for (int i = 0; i < MAX_CHAR_SIZE; i++) {
        if (codes[i].freq > 0) {
            printf("%c: ", i);
            for (int j = 0; j < codes[i].size; j++)
                printf("%d", codes[i].bits[j]);
            printf("\n");
        }
    }

    printf("\nInput Data: %s\n\n", data);
    printf("Encoded Data: ");
    for (int i = 0; i < encodedSize; i++)
        printf("%d", encodedData[i]);
    printf("\n\n");

    // Decode Huffman code to original data
    char decodedData[5000] = { 0 };
    decode(encodedData, root, decodedData, encodedSize);

    printf("Decoded Data: %s\n\n", decodedData);

    return 0;
}