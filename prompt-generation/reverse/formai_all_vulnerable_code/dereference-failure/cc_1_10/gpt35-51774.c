//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman coding tree node
struct HuffmanNode {
    int frequency; // the frequency of the character
    char character; // the character it represents
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};

// Function to create a new Huffman coding tree node
struct HuffmanNode* createHuffmanNode(int frequency, char character) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->frequency = frequency;
    node->character = character;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to swap two Huffman coding tree nodes
void swap(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of Huffman coding tree nodes based on their frequencies
void sort(struct HuffmanNode** nodes, int size) {
    int i, j;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(nodes[j]->frequency > nodes[j + 1]->frequency) {
                swap(&nodes[j], &nodes[j + 1]);
            }
        }
    }
}

// Function to recursively build a Huffman coding tree
struct HuffmanNode* buildHuffmanTree(struct HuffmanNode** nodes, int size) {
    while(size > 1) {
        sort(nodes, size);

        struct HuffmanNode* left = nodes[0];
        struct HuffmanNode* right = nodes[1];
        int frequency = left->frequency + right->frequency;

        struct HuffmanNode* node = createHuffmanNode(frequency, '\0');
        node->left = left;
        node->right = right;

        nodes[0] = node;
        nodes[1] = nodes[size - 1];
        size--;
    }

    return nodes[0];
}

// Function to recursively traverse the Huffman coding tree and generate codes for each character
void generateHuffmanCodes(struct HuffmanNode* node, char* code, int index) {
    if(node->left == NULL && node->right == NULL) {
        printf("%c: %s\n", node->character, code);
        return;
    }

    code[index] = '0';
    generateHuffmanCodes(node->left, code, index + 1);

    code[index] = '1';
    generateHuffmanCodes(node->right, code, index + 1);
}

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanNode** nodes = (struct HuffmanNode**)malloc(size * sizeof(struct HuffmanNode*));
    int i;
    for(i = 0; i < size; i++) {
        nodes[i] = createHuffmanNode(frequencies[i], data[i]);
    }

    struct HuffmanNode* root = buildHuffmanTree(nodes, size);

    char code[100];
    generateHuffmanCodes(root, code, 0);

    return 0;
}