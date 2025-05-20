//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256 

typedef struct HuffmanNode {
    unsigned char character;
    unsigned freq;
    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct {
    unsigned char character;
    char code[MAX_TREE_NODES]; 
} HuffmanCode;

// Priority Queue to hold Huffman nodes
HuffmanNode* priorityQueue[MAX_TREE_NODES];
int pqSize = 0;

// Function prototypes
void insertPriorityQueue(HuffmanNode* node);
HuffmanNode* extractMin();
HuffmanNode* createNode(unsigned char character, unsigned freq);
void buildHuffmanTree(const char *text);
void printCodes(HuffmanNode *root, char *code);
void freeHuffmanTree(HuffmanNode *root);

// Utility function to calculate the frequency of each character
void calculateFrequency(const char *text, unsigned freq[]) {
    while (*text) {
        freq[(unsigned char)(*text)]++;
        text++;
    }
}

// Functions to manage the priority queue
void insertPriorityQueue(HuffmanNode* node) {
    priorityQueue[pqSize++] = node;
}

HuffmanNode* extractMin() {
    int minIndex = 0;
    for (int i = 1; i < pqSize; i++) {
        if (priorityQueue[i]->freq < priorityQueue[minIndex]->freq) {
            minIndex = i;
        }
    }
    HuffmanNode* minNode = priorityQueue[minIndex];
    priorityQueue[minIndex] = priorityQueue[--pqSize];
    return minNode;
}

// Function to create a Huffman Node
HuffmanNode* createNode(unsigned char character, unsigned freq) {
    HuffmanNode *node = malloc(sizeof(HuffmanNode));
    node->character = character;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to build the Huffman Tree
void buildHuffmanTree(const char *text) {
    unsigned freq[MAX_TREE_NODES] = {0};
    calculateFrequency(text, freq);
    
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (freq[i] > 0) {
            insertPriorityQueue(createNode(i, freq[i]));
        }
    }

    while (pqSize > 1) {
        HuffmanNode *left = extractMin();
        HuffmanNode *right = extractMin();
        
        HuffmanNode *sumNode = createNode('\0', left->freq + right->freq);
        sumNode->left = left;
        sumNode->right = right;
        
        insertPriorityQueue(sumNode);
    }
    
    HuffmanNode *root = extractMin();
    char code[MAX_TREE_NODES];
    printCodes(root, code);
    freeHuffmanTree(root);
}

// Function to print all codes in tree
void printCodes(HuffmanNode *root, char *code) {
    if (root->left) {
        code[strlen(code)] = '0';
        printCodes(root->left, code);
    }
    
    if (root->right) {
        code[strlen(code)] = '1';
        printCodes(root->right, code);
    }

    if (!(root->left) && !(root->right)) {
        code[strlen(code)] = '\0';
        printf("Character: '%c' Code: %s\n", root->character, code);
    }
    code[strlen(code) - 1] = '\0';  // Remove last character
}

// Function to free the Huffman Tree
void freeHuffmanTree(HuffmanNode *root) {
    if (root) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    const char *text = "this is an example for huffman encoding";
    printf("Input Text: %s\n", text);
    buildHuffmanTree(text);
    return 0;
}