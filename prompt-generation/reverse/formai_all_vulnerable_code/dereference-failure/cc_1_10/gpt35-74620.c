//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TREE_HT 100

// Struct of a Huffman tree node
struct HuffmanNode {
    char character; // The character stored in the node
    int frequency; // The frequency of the character
    struct HuffmanNode *leftChild; // Pointer to left child node
    struct HuffmanNode *rightChild; // Pointer to right child node
};

// Struct of a Huffman tree (used for traversing the tree)
struct HuffmanTree {
    struct HuffmanNode *root; // The root node of the tree
    char *code; // The Huffman code of the current node
    int codeLength; // The length of the Huffman code
};

// Function to create a new Huffman tree node with the given character and frequency
struct HuffmanNode* createHuffmanNode(char character, int frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->character = character;
    node->frequency = frequency;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

// Function to create a new Huffman tree
struct HuffmanTree* createHuffmanTree() {
    struct HuffmanTree* tree = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
    tree->root = NULL;
    tree->code = (char*)malloc(sizeof(char) * MAX_TREE_HT);
    tree->codeLength = 0;
    return tree;
}

// Function to check if the given node is a leaf node
int isLeafNode(struct HuffmanNode* node) {
    return (node->leftChild == NULL && node->rightChild == NULL);
}

// Function to swap two Huffman nodes
void swapNodes(struct HuffmanNode** node1, struct HuffmanNode** node2) {
    struct HuffmanNode* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// Function to sort an array of Huffman nodes in non-decreasing order of frequency
void sortNodes(struct HuffmanNode** nodes, int numNodes) {
    int i, j, minIndex;
    for (i = 0; i < numNodes - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < numNodes; j++) {
            if (nodes[j]->frequency < nodes[minIndex]->frequency) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapNodes(&nodes[minIndex], &nodes[i]);
        }
    }
}

// Function to build a Huffman tree from the given array of characters and their frequencies
struct HuffmanNode* buildHuffmanTree(char* characters, int* frequencies, int numNodes) {
    int i;
    struct HuffmanNode* node1;
    struct HuffmanNode* node2;
    struct HuffmanNode* newNode;
    struct HuffmanNode** nodes = (struct HuffmanNode**)malloc(sizeof(struct HuffmanNode*) * numNodes);

    // Create an array of leaf nodes corresponding to the characters and frequencies
    for (i = 0; i < numNodes; i++) {
        nodes[i] = createHuffmanNode(characters[i], frequencies[i]);
    }

    // Sort the array of leaf nodes
    sortNodes(nodes, numNodes);

    // Build the tree by merging the two nodes with minimum frequency until there is only one node left
    while (numNodes > 1) {
        node1 = nodes[0];
        node2 = nodes[1];
        newNode = createHuffmanNode('\0', node1->frequency + node2->frequency);
        newNode->leftChild = node1;
        newNode->rightChild = node2;
        nodes[0] = newNode;
        numNodes--;
        for (i = 1; i < numNodes; i++) {
            nodes[i] = nodes[i + 1];
        }
        sortNodes(nodes, numNodes);
    }

    return nodes[0];
}

// Function to traverse a Huffman tree and print the Huffman code of each character
void printHuffmanCodesUtil(struct HuffmanNode* node, struct HuffmanTree* tree) {
    if (node->leftChild != NULL) {
        tree->code[tree->codeLength++] = '0';
        printHuffmanCodesUtil(node->leftChild, tree);
        tree->codeLength--;
    }
    if (node->rightChild != NULL) {
        tree->code[tree->codeLength++] = '1';
        printHuffmanCodesUtil(node->rightChild, tree);
        tree->codeLength--;
    }
    if (isLeafNode(node)) {
        printf("%c: ", node->character);
        int i;
        for (i = 0; i < tree->codeLength; i++) {
            printf("%c", tree->code[i]);
        }
        printf("\n");
    }
}

// Function to print the Huffman codes of all characters in the given array
void printHuffmanCodes(char* characters, int* frequencies, int numNodes) {
    struct HuffmanTree* tree = createHuffmanTree();
    tree->root = buildHuffmanTree(characters, frequencies, numNodes);
    printHuffmanCodesUtil(tree->root, tree);
}

// Main function
int main() {
    // Array of characters and their respective frequencies
    char characters[] = {'a', 'b', 'c', 'd', 'e'};
    int frequencies[] = {5, 2, 1, 6, 9};
    int numNodes = sizeof(characters)/sizeof(char);

    // Print the Huffman codes of all characters in the array
    printHuffmanCodes(characters, frequencies, numNodes);

    return 0;
}