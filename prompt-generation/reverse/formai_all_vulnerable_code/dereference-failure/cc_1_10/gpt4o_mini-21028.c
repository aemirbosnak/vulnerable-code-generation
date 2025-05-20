//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024
#define HASH_SIZE 256

typedef struct Node {
    char character;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    char character;
    char* code;
} Code;

Node* createNode(char character, int freq) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void freeNode(Node* node) {
    if (node) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

int compare(const void* a, const void* b) {
    return ((Node*)a)->freq - ((Node*)b)->freq;
}

Node** buildFrequencyTable(const char* str, int* size) {
    int freq[HASH_SIZE] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    Node** nodes = (Node**)malloc(HASH_SIZE * sizeof(Node*));
    *size = 0;

    for (int i = 0; i < HASH_SIZE; i++) {
        if (freq[i] > 0) {
            nodes[(*size)++] = createNode((char)i, freq[i]);
        }
    }

    return nodes;
}

Node* buildHuffmanTree(Node** nodes, int size) {
    while (size > 1) {
        qsort(nodes, size, sizeof(Node*), compare);
        
        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* parent = createNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        nodes[0] = parent;
        for (int i = 1; i < size - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        size--;
    }

    return nodes[0];
}

void generateCodes(Node* node, char* code, int depth, Code* codes, int* index) {
    if (node->left) {
        code[depth] = '0';
        generateCodes(node->left, code, depth + 1, codes, index);
    }
    
    if (node->right) {
        code[depth] = '1';
        generateCodes(node->right, code, depth + 1, codes, index);
    }

    if (!node->left && !node->right) {
        code[depth] = '\0';
        codes[*index].character = node->character;
        codes[*index].code = strdup(code);
        (*index)++;
    }
}

void compress(const char* input) {
    int size;
    Node** nodes = buildFrequencyTable(input, &size);

    Node* root = buildHuffmanTree(nodes, size);
    
    Code codes[HASH_SIZE];
    int codeIndex = 0;
    char code[MAX_STRING_LENGTH];
    generateCodes(root, code, 0, codes, &codeIndex);

    // Output compressed data
    printf("Character Codes:\n");
    for (int i = 0; i < codeIndex; i++) {
        printf("'%c': %s\n", codes[i].character, codes[i].code);
    }

    // Encode input string
    printf("\nCompressed Output:\n");
    for (int i = 0; input[i] != '\0'; i++) {
        for (int j = 0; j < codeIndex; j++) {
            if (input[i] == codes[j].character) {
                printf("%s", codes[j].code);
                break;
            }
        }
    }
    
    // Free memory
    for (int i = 0; i < size; i++) {
        freeNode(nodes[i]);
    }
    free(nodes);
    free(root);
    for (int i = 0; i < codeIndex; i++) {
        free(codes[i].code);
    }
}

int main() {
    const char* input = "Hello, Huffman Compression!";
    compress(input);
    return 0;
}