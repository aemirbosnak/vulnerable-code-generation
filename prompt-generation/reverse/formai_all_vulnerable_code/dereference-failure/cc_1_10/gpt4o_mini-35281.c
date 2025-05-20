//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LENGTH 256

// Structure for the Huffman tree nodes
typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

// Structure to store symbol codes
typedef struct Code {
    char character;
    char code[MAX_CODE_LENGTH];
} Code;

// Priority queue for the Huffman tree
Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return ((Node*)a)->frequency > ((Node*)b)->frequency;
}

// Build the Huffman tree
Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    Node* nodes[MAX_TREE_NODES];
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(characters[i], frequencies[i]);
    }
    
    while (size > 1) {
        qsort(nodes, size, sizeof(Node*), compare);
        
        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        nodes[1] = newNode; // Replace the smallest two nodes
        size--;
    }
    
    return nodes[0];
}

// Generate codes from the Huffman tree
void generateCodes(Node* root, char* code, int depth, Code* codes, int* codeIndex) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        codes[*codeIndex].character = root->character;
        strncpy(codes[*codeIndex].code, code, depth);
        codes[*codeIndex].code[depth] = '\0';
        (*codeIndex)++;
    }

    code[depth] = '0';
    generateCodes(root->left, code, depth + 1, codes, codeIndex);
    code[depth] = '1';
    generateCodes(root->right, code, depth + 1, codes, codeIndex);
}

// Encode the input string
void encode(char* input, Code* codes, int codeCount, char* output) {
    output[0] = '\0'; // Initialize output string
    for (int i = 0; input[i] != '\0'; i++) {
        for (int j = 0; j < codeCount; j++) {
            if (codes[j].character == input[i]) {
                strcat(output, codes[j].code);
                break;
            }
        }
    }
}

// Free the Huffman tree
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    printf("Welcome to the Whimsical Huffman Coding Program!\n");
    char input[100];
    printf("Please enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline

    // Calculate frequency
    int frequencies[MAX_TREE_NODES] = {0};
    char characters[MAX_TREE_NODES];
    int uniqueCharsCount = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        int found = 0;
        for (int j = 0; j < uniqueCharsCount; j++) {
            if (characters[j] == ch) {
                frequencies[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            characters[uniqueCharsCount] = ch;
            frequencies[uniqueCharsCount] = 1;
            uniqueCharsCount++;
        }
    }

    // Build Huffman tree
    Node* root = buildHuffmanTree(characters, frequencies, uniqueCharsCount);

    // Generate codes
    Code codes[MAX_TREE_NODES];
    int codeIndex = 0;
    char code[MAX_CODE_LENGTH];
    generateCodes(root, code, 0, codes, &codeIndex);

    // Encode input
    char encodedOutput[1000];
    encode(input, codes, codeIndex, encodedOutput);

    printf("Encoded Output: %s\n", encodedOutput);

    // Clean up
    freeTree(root);
    printf("Thank you for using the program! Have a whimsical day!\n");

    return 0;
}