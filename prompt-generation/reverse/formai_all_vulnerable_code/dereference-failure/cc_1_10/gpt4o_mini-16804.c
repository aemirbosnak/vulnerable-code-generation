//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An eerie structure silently whispers the node of the tree
typedef struct Node {
    char charValue; // The ghostly character
    int frequency;  // The lonesome frequency
    struct Node *leftChild, *rightChild; // The offspring of choices
} Node;

// A menacing array that holds the weights of each character
int freqTable[256];

// The echoes of the Huffman tree
void calculateFrequency(const char *input) {
    while (*input) {
        freqTable[(unsigned char)(*input)]++;
        input++;
    }
}

// The inexplicable comparator for our haunted nodes
int nodeComparator(const void *a, const void *b) {
    return ((Node *)a)->frequency - ((Node *)b)->frequency;
}

// A ritualistic function to create a new node
Node *createNode(char charValue, int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->charValue = charValue;
    node->frequency = frequency;
    node->leftChild = node->rightChild = NULL;
    return node;
}

// The dark descent into the Huffman tree
Node *buildHuffmanTree() {
    Node *nodes[256];
    int nodeCount = 0;

    for (int i = 0; i < 256; i++) {
        if (freqTable[i]) {
            nodes[nodeCount++] = createNode((char)i, freqTable[i]);
        }
    }

    while (nodeCount > 1) {
        qsort(nodes, nodeCount, sizeof(Node *), nodeComparator);
       
        Node *left = nodes[0];
        Node *right = nodes[1];

        Node *newNode = createNode('\0', left->frequency + right->frequency);
        newNode->leftChild = left;
        newNode->rightChild = right;

        nodes[1] = newNode; // Replace the first two nodes
        nodeCount--; // A new entity emerges
    }
    return nodes[0]; // The crowned monarch of the tree
}

// The cryptic codes are bestowed upon the characters
void encode(Node *root, const char *prefix, char codes[256][256]) {
    if (root->leftChild) {
        char newPrefix[256];
        sprintf(newPrefix, "%s0", prefix);
        encode(root->leftChild, newPrefix, codes);
    }
    if (root->rightChild) {
        char newPrefix[256];
        sprintf(newPrefix, "%s1", prefix);
        encode(root->rightChild, newPrefix, codes);
    }
    if (!root->leftChild && !root->rightChild) { // A leaf reveals its majesty
        strcpy(codes[(unsigned char)(root->charValue)], prefix);
    }
}

// The weaving of characters into enigmatic strings
void printEncoded(const char *input, char codes[256][256]) {
    while (*input) {
        printf("%s", codes[(unsigned char)(*input)]);
        input++;
    }
    printf("\n"); // A dénouement of silence after the cosmic unraveling
}

int main() {
    char *inputString = "In a world of whispers, shadows dance.";
    memset(freqTable, 0, sizeof(freqTable)); // The slate is wiped clean in the void

    // The frequency echoes in the ether
    calculateFrequency(inputString);
    
    // The grand architect of meanings is summoned
    Node *root = buildHuffmanTree();
    
    // The runes of encoding are inscribed
    char codes[256][256] = {{0}};
    encode(root, "", codes);
    
    // The symphony of the encoded message begins
    printf("Original string: %s\n", inputString);
    printf("Encoded string:   ");
    printEncoded(inputString, codes);
    
    free(root); // The sacrifice for the greater good, freeing the realm
    return 0; // The final whisper of a surreal journey
}