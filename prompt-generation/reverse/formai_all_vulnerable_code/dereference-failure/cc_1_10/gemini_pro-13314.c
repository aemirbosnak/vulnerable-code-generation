//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: protected
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure for Huffman tree
typedef struct Node {
    unsigned char character;
    unsigned int frequency;
    struct Node *left;
    struct Node *right;
} Node;

// Priority queue structure for storing nodes
typedef struct Queue {
    struct Node **nodes;
    unsigned int size;
    unsigned int capacity;
} Queue;

// Function to create a new node
Node *createNode(unsigned char character, unsigned int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new priority queue
Queue *createQueue(unsigned int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->nodes = (Node **)malloc(sizeof(Node *) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to insert a node into the priority queue
void enqueue(Queue *queue, Node *node) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->nodes = (Node **)realloc(queue->nodes, sizeof(Node *) * queue->capacity);
    }
    queue->nodes[queue->size++] = node;
}

// Function to remove the node with the highest frequency from the priority queue
Node *dequeue(Queue *queue) {
    unsigned int maxIndex = 0;
    for (unsigned int i = 1; i < queue->size; i++) {
        if (queue->nodes[i]->frequency > queue->nodes[maxIndex]->frequency) {
            maxIndex = i;
        }
    }
    Node *node = queue->nodes[maxIndex];
    queue->nodes[maxIndex] = queue->nodes[--queue->size];
    return node;
}

// Function to build a Huffman tree from the priority queue
Node *buildTree(Queue *queue) {
    if (queue->size == 1) {
        return queue->nodes[0];
    }
    Node *left = dequeue(queue);
    Node *right = dequeue(queue);
    Node *parent = createNode('\0', left->frequency + right->frequency);
    parent->left = left;
    parent->right = right;
    enqueue(queue, parent);
    return buildTree(queue);
}

// Function to print the Huffman code for a character
void printCode(Node *root, unsigned char character, char *code) {
    if (root->character == character) {
        printf("%s\n", code);
        return;
    }
    if (root->left != NULL) {
        char leftCode[strlen(code) + 1];
        strcpy(leftCode, code);
        strcat(leftCode, "0");
        printCode(root->left, character, leftCode);
    }
    if (root->right != NULL) {
        char rightCode[strlen(code) + 1];
        strcpy(rightCode, code);
        strcat(rightCode, "1");
        printCode(root->right, character, rightCode);
    }
}

// Function to print the Huffman codes for all characters in the input string
void printCodes(Node *root, unsigned char *input, unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        char code[100] = {0};
        printCode(root, input[i], code);
    }
}

// Main function
int main() {
    // Input string
    unsigned char input[] = "Huffman coding is a lossless data compression algorithm";
    unsigned int length = strlen((char *)input);

    // Create a frequency table
    unsigned int frequencies[256] = {0};
    for (unsigned int i = 0; i < length; i++) {
        frequencies[input[i]]++;
    }

    // Create a priority queue
    Queue *queue = createQueue(length);

    // Insert the frequency table into the priority queue
    for (unsigned int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            Node *node = createNode(i, frequencies[i]);
            enqueue(queue, node);
        }
    }

    // Build the Huffman tree
    Node *root = buildTree(queue);

    // Print the Huffman codes
    printCodes(root, input, length);

    return 0;
}