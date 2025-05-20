//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

// Structure for the nodes in the Huffman tree
struct Node {
    char character;
    unsigned freq;
    struct Node *left, *right;
};

// Array to hold the frequency of each character
unsigned freq[256];

// Create a new node
struct Node* createNode(char character, unsigned freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->character = character;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// A comparison function for the priority queue (min-heap)
int compare(const void *a, const void *b) {
    return ((struct Node*)a)->freq - ((struct Node*)b)->freq;
}

// Build the Huffman tree
struct Node* buildHuffmanTree() {
    struct Node* priorityQueue[MAX_TREE_NODES];
    int size = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            priorityQueue[size++] = createNode(i, freq[i]);
        }
    }

    while (size > 1) {
        qsort(priorityQueue, size, sizeof(struct Node*), compare);
        struct Node* left = priorityQueue[0];
        struct Node* right = priorityQueue[1];

        struct Node* newNode = createNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Replace the two smallest nodes with the new node
        priorityQueue[0] = newNode;
        size--;
        // Move the last element to the front
        priorityQueue[1] = priorityQueue[size];
    }

    return priorityQueue[0];
}

// Function to print the codes
void printHuffmanCodes(struct Node* root, char* code, int top) {
    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        code[top] = '\0';
        printf("%c: %s\n", root->character, code);
    }
}

// Function to perform Huffman Coding on a given input string
void huffmanCoding(char* input) {
    // Initialize frequency array
    memset(freq, 0, sizeof(freq));

    // Count frequency of each character
    for (int i = 0; i < strlen(input); i++) {
        freq[(unsigned char)input[i]]++;
    }

    // Build the Huffman tree
    struct Node* root = buildHuffmanTree();

    // Buffer to store the codes
    char code[MAX_TREE_NODES];
    int top = 0;

    // Print Huffman codes
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, top);
}

int main() {
    // Test string for Huffman Coding
    char input[] = "Huffman coding is a compression algorithm.";
    
    printf("Input String: %s\n", input);
    huffmanCoding(input);

    return 0;
}