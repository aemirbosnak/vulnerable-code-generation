//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 256

typedef struct Node {
    char charValue;
    int frequency;
    struct Node *left, *right;
} Node;

Node* createNode(char charValue, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->charValue = charValue;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int compare(const void* a, const void* b) {
    return ((Node*)a)->frequency - ((Node*)b)->frequency;
}

Node* buildHuffmanTree(char* data, int* freq, int size) {
    Node** nodes = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], freq[i]);
    }

    int n = size;
    while (n > 1) {
        qsort(nodes, n, sizeof(Node*), compare);
        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        nodes[1] = newNode;
        for (int i = 2; i < n; i++) {
            nodes[i - 1] = nodes[i];
        }
        n--;
    }

    Node* root = nodes[0];
    free(nodes);
    return root;
}

void generateCodes(Node* root, char* code, int depth, char codes[][MAX_TREE_SIZE]) {
    if (root->left) {
        code[depth] = '0';
        generateCodes(root->left, code, depth + 1, codes);
    }
    if (root->right) {
        code[depth] = '1';
        generateCodes(root->right, code, depth + 1, codes);
    }
    if (!root->left && !root->right) {
        code[depth] = '\0';
        strcpy(codes[root->charValue], code);
    }
}

void huffmanEncoding(char* data, int* freq, int size) {
    Node* root = buildHuffmanTree(data, freq, size);
    char codes[MAX_TREE_SIZE][MAX_TREE_SIZE];
    char code[MAX_TREE_SIZE];
    
    generateCodes(root, code, 0, codes);
    
    printf("Character\tFrequency\tHuffman Code\n");
    for (int i = 0; i < size; i++) {
        printf("%c\t\t%d\t\t%s\n", data[i], freq[i], codes[data[i]]);
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    huffmanEncoding(data, freq, size);
    return 0;
}