//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct HuffmanNode {
    char character;
    unsigned int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

typedef struct {
    HuffmanNode *nodes[MAX_TREE_NODES];
    int size;
} MinHeap;

HuffmanNode* createNode(char character, unsigned int frequency) {
    HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}

void insertMinHeap(MinHeap* heap, HuffmanNode* node) {
    int index = heap->size++;
    while (index && node->frequency < heap->nodes[(index - 1) / 2]->frequency) {
        heap->nodes[index] = heap->nodes[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    heap->nodes[index] = node;
}

HuffmanNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    HuffmanNode* minNode = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    int index = 0;

    while (index * 2 + 1 < heap->size) {
        int leftChild = index * 2 + 1;
        int rightChild = leftChild + 1;
        int smallestChild = leftChild;

        if (rightChild < heap->size && heap->nodes[rightChild]->frequency < heap->nodes[leftChild]->frequency) {
            smallestChild = rightChild;
        }

        if (heap->nodes[index]->frequency <= heap->nodes[smallestChild]->frequency) {
            break;
        }

        HuffmanNode* temp = heap->nodes[index];
        heap->nodes[index] = heap->nodes[smallestChild];
        heap->nodes[smallestChild] = temp;

        index = smallestChild;
    }

    return minNode;
}

HuffmanNode* buildHuffmanTree(char characters[], int frequencies[], int size) {
    MinHeap* heap = createMinHeap();
    for (int i = 0; i < size; ++i) {
        insertMinHeap(heap, createNode(characters[i], frequencies[i]));
    }

    while (heap->size > 1) {
        HuffmanNode* leftChild = extractMin(heap);
        HuffmanNode* rightChild = extractMin(heap);
        HuffmanNode* combinedNode = createNode('\0', leftChild->frequency + rightChild->frequency);
        combinedNode->left = leftChild;
        combinedNode->right = rightChild;
        insertMinHeap(heap, combinedNode);
    }

    HuffmanNode* root = extractMin(heap);
    free(heap);
    return root;
}

void generateCodes(HuffmanNode* root, char* code, int deepness, char codes[MAX_TREE_NODES][MAX_TREE_NODES]) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        code[deepness] = '\0';
        strcpy(codes[(unsigned char)root->character], code);
    } else {
        code[deepness] = '0';
        generateCodes(root->left, code, deepness + 1, codes);
        code[deepness] = '1';
        generateCodes(root->right, code, deepness + 1, codes);
    }
}

void printHuffmanCodes(char codes[MAX_TREE_NODES][MAX_TREE_NODES], char characters[], int size) {
    printf("Huffman Codes:\n");
    for (int i = 0; i < size; ++i) {
        printf("Character: %c Frequency: %d Code: %s\n", characters[i], codes[(unsigned char)characters[i]][0], codes[(unsigned char)characters[i]]);
    }
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e'};
    int frequencies[] = {5, 9, 12, 13, 16};
    int size = sizeof(characters) / sizeof(characters[0]);
    
    HuffmanNode* root = buildHuffmanTree(characters, frequencies, size);
    char codes[MAX_TREE_NODES][MAX_TREE_NODES] = {0};
    char code[MAX_TREE_NODES];

    generateCodes(root, code, 0, codes);
    printHuffmanCodes(codes, characters, size);

    // Free memory associated with tree nodes
    // Implement a function for tree destruction if necessary.

    return 0;
}