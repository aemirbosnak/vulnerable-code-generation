//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LEN 256

typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *nodes[MAX_TREE_NODES];
    int size;
} MinHeap;

MinHeap* createMinHeap() {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void insertMinHeap(MinHeap *minHeap, Node *node) {
    minHeap->nodes[minHeap->size++] = node;
}

Node* popMinHeap(MinHeap *minHeap) {
    if (minHeap->size == 0) return NULL;
    // Find minimum node
    int minIndex = 0;
    for (int i = 1; i < minHeap->size; i++) {
        if (minHeap->nodes[i]->frequency < minHeap->nodes[minIndex]->frequency)
            minIndex = i;
    }
    Node *minNode = minHeap->nodes[minIndex];
    // Remove node from heap
    for (int i = minIndex; i < minHeap->size - 1; i++) {
        minHeap->nodes[i] = minHeap->nodes[i + 1];
    }
    minHeap->size--;
    return minNode;
}

Node* createNode(char character, int frequency) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildHuffmanTree(char *str) {
    int freq[256] = {0};
    for (int i = 0; str[i]; i++) {
        freq[(unsigned char)str[i]]++;
    }

    MinHeap *minHeap = createMinHeap();

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            insertMinHeap(minHeap, createNode((char)i, freq[i]));
        }
    }

    while (minHeap->size > 1) {
        Node *left = popMinHeap(minHeap);
        Node *right = popMinHeap(minHeap);
        Node *newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        insertMinHeap(minHeap, newNode);
    }

    return popMinHeap(minHeap);
}

void generateCodes(Node *root, char *code, int depth, char codes[MAX_TREE_NODES][MAX_CODE_LEN]) {
    if (!root) return;
    
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        strcpy(codes[(unsigned char)root->character], code);
    }

    code[depth] = '0';
    generateCodes(root->left, code, depth + 1, codes);
    
    code[depth] = '1';
    generateCodes(root->right, code, depth + 1, codes);
}

void encode(const char *str, char codes[MAX_TREE_NODES][MAX_CODE_LEN], char *encoded) {
    encoded[0] = '\0';
    for (int i = 0; str[i]; i++) {
        strcat(encoded, codes[(unsigned char)str[i]]);
    }
}

void decode(Node *root, const char *encoded, char *decoded) {
    Node *current = root;
    int index = 0;

    for (int i = 0; encoded[i]; i++) {
        current = (encoded[i] == '0') ? current->left : current->right;
        
        if (current->left == NULL && current->right == NULL) {
            decoded[index++] = current->character;
            current = root;
        }
    }
    decoded[index] = '\0';
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char str[] = "hello huffman coding";
    Node *root = buildHuffmanTree(str);
    
    char codes[MAX_TREE_NODES][MAX_CODE_LEN];
    char code[MAX_CODE_LEN];
    generateCodes(root, code, 0, codes);
    
    printf("Character Codes:\n");
    for (int i = 0; i < 256; i++) {
        if (strlen(codes[i]) > 0) {
            printf("%c: %s\n", (char)i, codes[i]);
        }
    }

    char encoded[1000] = "";
    encode(str, codes, encoded);
    printf("\nEncoded String: %s\n", encoded);

    char decoded[100] = "";
    decode(root, encoded, decoded);
    printf("Decoded String: %s\n", decoded);
    
    freeTree(root);
    return 0;
}