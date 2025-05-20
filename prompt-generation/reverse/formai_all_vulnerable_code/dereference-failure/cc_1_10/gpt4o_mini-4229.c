//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR 256
#define MAX_TREE_NODES 512
#define MAX_CODE_LENGTH 16

typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    char character;
    char code[MAX_CODE_LENGTH];
} HuffmanCode;

Node *createNode(char character, int frequency) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Node **heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left]->frequency < heap[smallest]->frequency)
        smallest = left;

    if (right < size && heap[right]->frequency < heap[smallest]->frequency)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

Node *extractMin(Node **heap, int *size) {
    Node *minNode = heap[0];
    heap[0] = heap[--(*size)];
    minHeapify(heap, *size, 0);
    return minNode;
}

void insertHeap(Node **heap, int *size, Node *node) {
    heap[(*size)++] = node;
    for (int i = (*size) / 2 - 1; i >= 0; i--)
        minHeapify(heap, *size, i);
}

Node *buildHuffmanTree(int frequencies[MAX_CHAR]) {
    Node **minHeap = (Node **)malloc(MAX_TREE_NODES * sizeof(Node *));
    int size = 0;

    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequencies[i] > 0) {
            insertHeap(minHeap, &size, createNode(i, frequencies[i]));
        }
    }

    while (size > 1) {
        Node *left = extractMin(minHeap, &size);
        Node *right = extractMin(minHeap, &size);
        Node *top = createNode('\0', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertHeap(minHeap, &size, top);
    }

    Node *root = extractMin(minHeap, &size);
    free(minHeap);
    return root;
}

void generateHuffmanCodes(Node *root, HuffmanCode *codes, int *index, char *code, int codeLength) {
    if (!root)
        return;

    if (root->left) {
        code[codeLength] = '0';
        generateHuffmanCodes(root->left, codes, index, code, codeLength + 1);
    }

    if (root->right) {
        code[codeLength] = '1';
        generateHuffmanCodes(root->right, codes, index, code, codeLength + 1);
    }

    if (!root->left && !root->right) {
        code[codeLength] = '\0';
        codes[*index].character = root->character;
        strcpy(codes[*index].code, code);
        (*index)++;
    }
}

void printHuffmanCodes(HuffmanCode *codes, int size) {
    printf("==== Huffman Codes ====\n");
    for (int i = 0; i < size; i++) {
        printf("Character: '%c' - Code: %s\n", codes[i].character, codes[i].code);
    }
    printf("========================\n");
}

void freeHuffmanTree(Node *node) {
    if (!node) return;
    freeHuffmanTree(node->left);
    freeHuffmanTree(node->right);
    free(node);
}

int main() {
    printf("Welcome to the Cyberpunk Huffman Encoding Hub.\n");
    int frequencies[MAX_CHAR] = {0};
    char input[1024];

    printf("Enter your data stream (up to 1024 characters):\n");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < strlen(input); i++) {
        frequencies[(unsigned char)input[i]]++;
    }

    Node *root = buildHuffmanTree(frequencies);

    HuffmanCode codes[MAX_CHAR];
    char code[MAX_CODE_LENGTH];
    int index = 0;

    generateHuffmanCodes(root, codes, &index, code, 0);

    printHuffmanCodes(codes, index);
    freeHuffmanTree(root);

    return 0;
}