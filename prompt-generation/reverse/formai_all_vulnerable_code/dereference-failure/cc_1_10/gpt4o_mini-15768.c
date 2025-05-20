//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

// Structure to represent a node in the Huffman tree
struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
};

// Structure to store code information
struct Code {
    char character;
    char *code;
};

// Function to create a new tree node
struct Node* createNode(char character, unsigned frequency) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to compare two nodes (used for sorting)
int compare(const void* a, const void* b) {
    return ((struct Node*)a)->frequency - ((struct Node*)b)->frequency;
}

// Function to build a Huffman tree
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    struct Node* nodes[MAX_TREE_NODES];

    // Create nodes for each character and frequency
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(characters[i], frequencies[i]);
    }

    int n = size;
    
    while (n > 1) {
        // Sort the nodes by frequency
        qsort(nodes, n, sizeof(struct Node*), compare);

        // Create a new internal node with two least frequency nodes
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];
        struct Node* newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        // Replace the two nodes with the new node
        nodes[0] = newNode;
        nodes[1] = nodes[n-1]; // last node
        n--;
    }
    
    return nodes[0]; // root of the Huffman tree
}

// Function to generate the Huffman codes
void generateCodes(struct Node* root, char* code, int depth, struct Code* codes, int* count) {
    if (root->left) {
        code[depth] = '0';
        generateCodes(root->left, code, depth + 1, codes, count);
    }
    if (root->right) {
        code[depth] = '1';
        generateCodes(root->right, code, depth + 1, codes, count);
    }
    if (!root->left && !root->right) { // leaf node
        code[depth] = '\0';
        codes[*count].character = root->character;
        codes[*count].code = strdup(code);
        (*count)++;
    }
}

// Function to perform Huffman encoding
void huffmanEncode(char characters[], int frequencies[], int size) {
    struct Node* root = buildHuffmanTree(characters, frequencies, size);
    struct Code codes[MAX_TREE_NODES];
    int count = 0;
    char code[MAX_TREE_NODES];
    
    generateCodes(root, code, 0, codes, &count);

    // Print out the generated codes
    printf("Character Codes:\n");
    for (int i = 0; i < count; i++) {
        printf("%c: %s\n", codes[i].character, codes[i].code);
    }
    
    // Clean up allocated memory
    for (int i = 0; i < count; i++) {
        free(codes[i].code);
    }
    free(root);
}

// Function to decode the Huffman encoded data
void huffmanDecode(struct Node* root, char* encodedData) {
    struct Node* current = root;
    printf("Decoded Output: ");
    
    for (int i = 0; encodedData[i] != '\0'; i++) {
        if (encodedData[i] == '0') {
            current = current->left;
        } else if (encodedData[i] == '1') {
            current = current->right;
        }
        if (!current->left && !current->right) { // leaf node
            printf("%c", current->character);
            current = root; // go back to root
        }
    }
    printf("\n");
}

int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e' };
    int frequencies[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(characters) / sizeof(characters[0]);
    
    huffmanEncode(characters, frequencies, size);
    
    // Example encoded data representing: "abcde"
    char encodedData[] = "101011111000";
    huffmanDecode(buildHuffmanTree(characters, frequencies, size), encodedData);

    return 0;
}