//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_TREE_NODES (2 * MAX_CHAR - 1)

typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct {
    Node* nodes[MAX_TREE_NODES];
    int size;
} MinHeap;

void insertMinHeap(MinHeap* heap, Node* node) {
    heap->nodes[heap->size++] = node;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->nodes[left]->frequency < heap->nodes[smallest]->frequency)
        smallest = left;

    if (right < heap->size && heap->nodes[right]->frequency < heap->nodes[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        Node* temp = heap->nodes[smallest];
        heap->nodes[smallest] = heap->nodes[idx];
        heap->nodes[idx] = temp;
        minHeapify(heap, smallest);
    }
}

Node* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    Node* minNode = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    minHeapify(heap, 0);
    return minNode;
}

/* Build the Huffman tree */
Node* buildHuffmanTree(int* frequencies) {
    MinHeap heap = { .size = 0 };
    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequencies[i] > 0) {
            insertMinHeap(&heap, createNode((char)i, frequencies[i]));
        }
    }

    while (heap.size > 1) {
        Node* left = extractMin(&heap);
        Node* right = extractMin(&heap);
        Node* combined = createNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        insertMinHeap(&heap, combined);
    }
    return extractMin(&heap);
}

void generateCodes(Node* root, char* code, int index, char codes[MAX_CHAR][MAX_CHAR]) {
    if (root->left) {
        code[index] = '0';
        generateCodes(root->left, code, index + 1, codes);
    }
    if (root->right) {
        code[index] = '1';
        generateCodes(root->right, code, index + 1, codes);
    }
    if (!root->left && !root->right) {
        code[index] = '\0';
        strcpy(codes[root->character], code);
    }
}

void printCodes(char codes[MAX_CHAR][MAX_CHAR]) {
    printf("Character Codes:\n");
    for (int i = 0; i < MAX_CHAR; i++) {
        if (codes[i][0]) {
            printf("'%c': %s\n", (char)i, codes[i]);
        }
    }
}

int main() {
    char text[MAX_CHAR];
    int frequencies[MAX_CHAR] = {0};
    char codes[MAX_CHAR][MAX_CHAR] = {0};

    printf("Enter text to compress (max %d characters): ", MAX_CHAR - 1);
    fgets(text, MAX_CHAR, stdin);
    for (int i = 0; text[i] != '\0'; i++) {
        frequencies[(unsigned char)text[i]]++;
    }

    Node* root = buildHuffmanTree(frequencies);
    char code[MAX_CHAR] = {0};
    generateCodes(root, code, 0, codes);

    printCodes(codes);

    // Optionally clean up and free allocated memory
    // (Implement freeTree function here)

    return 0;
}