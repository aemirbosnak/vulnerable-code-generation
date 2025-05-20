//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Define structure of Huffman tree
struct HuffmanNode {
    char data;
    int freq;
    struct HuffmanNode *left, *right;
};

// Initialize a new Huffman tree node
struct HuffmanNode* newNode(char data, int freq) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Compare function for sorting frequencies of characters
int compare(const void* a, const void* b) {
    int freq_a = (*(struct HuffmanNode**)a)->freq;
    int freq_b = (*(struct HuffmanNode**)b)->freq;
    return freq_a - freq_b;
}

// Create Huffman tree from input characters and their frequencies
struct HuffmanNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct HuffmanNode *left, *right, *top;
    // Create a node array of size equal to number of input characters
    struct HuffmanNode** nodeArr = (struct HuffmanNode**)malloc(size * sizeof(struct HuffmanNode*));
    // Initialize each node of array with corresponding input character and its frequency
    for(int i = 0; i < size; i++) {
        nodeArr[i] = newNode(data[i], freq[i]);
    }
    // Sort the node array based on the frequencies of the input characters
    qsort(nodeArr, size, sizeof(struct HuffmanNode*), compare);
    int nodeCount = size;
    // Create Huffman tree till only one node is left in node array
    while(nodeCount > 1) {
        // Pop the two lowest frequency nodes from node array 
        left = nodeArr[0];
        right = nodeArr[1];
        // Combine them into a single Huffman tree node with NULL data and frequency equal to the sum of both frequencies
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        // Push the combined node into node array
        nodeArr[0] = top;
        // Sort the node array based on the frequencies of nodes
        qsort(nodeArr, nodeCount, sizeof(struct HuffmanNode*), compare);
        // Decrease the count of nodes in node array by 1
        nodeCount--;
    }
    // The remaining node in node array is the root of Huffman tree
    struct HuffmanNode* root = nodeArr[0];
    return root;
}

// Print Huffman codes for all input characters
void printCodes(struct HuffmanNode* root, int code[], int top) {
    // Recursive function to traverse the Huffman tree and print codes
    if(root->left) {
        code[top] = 0;
        printCodes(root->left, code, top+1);
    }
    if(root->right) {
        code[top] = 1;
        printCodes(root->right, code, top+1);
    }
    if(!root->left && !root->right) {
        printf("%c - ", root->data);
        for(int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);

    // Build Huffman tree from input characters and their frequencies
    struct HuffmanNode* root = buildHuffmanTree(data, freq, size);

    // Traverse Huffman tree and print codes for all input characters
    int code[size], top = 0;
    printCodes(root, code, top);

    return 0;
}