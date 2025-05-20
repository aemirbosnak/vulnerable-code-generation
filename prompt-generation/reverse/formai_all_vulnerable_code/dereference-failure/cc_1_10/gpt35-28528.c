//FormAI DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_TREE_HT 100

typedef struct HuffmanNode {
    char data;
    int freq;
    struct HuffmanNode *leftChild;
    struct HuffmanNode *rightChild;
} HuffmanNode;

typedef struct HuffmanMinHeap {
    int size;
    int capacity;
    HuffmanNode **array;
} HuffmanMinHeap;

typedef struct HuffmanCodeTable {
    char data;
    char *code;
} HuffmanCodeTable;

HuffmanNode* createNode(char data, int freq) {
    HuffmanNode *newNode = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    newNode->data = data;
    newNode->freq = freq;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

HuffmanMinHeap* createMinHeap(int capacity) {
    HuffmanMinHeap *heap = (HuffmanMinHeap*) malloc(sizeof(HuffmanMinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HuffmanNode**) malloc(capacity * sizeof(HuffmanNode*));
    return heap;
}

void swapNodes(HuffmanNode **a, HuffmanNode **b) {
    HuffmanNode *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(HuffmanMinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;

    if(right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if(smallest != index) {
        swapNodes(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

bool isLeaf(HuffmanNode *node) {
    return node->leftChild == NULL && node->rightChild == NULL;
}

HuffmanNode* extractMin(HuffmanMinHeap* heap) {
    HuffmanNode *min = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size -= 1;
    heapify(heap, 0);
    return min;
}

void insertMinHeap(HuffmanMinHeap *heap, HuffmanNode *node) {
    heap->size += 1;
    int i = heap->size - 1;

    while(i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->array[i] = node;
}

void buildMinHeap(HuffmanMinHeap *heap) {
    int n = heap->size - 1;
    int i;

    for(i = (n - 1) / 2; i >= 0; --i) {
        heapify(heap, i);
    }
}

HuffmanNode* buildHuffmanTree(char *data, int *freq, int size) {
    HuffmanNode *leftChild, *rightChild, *top;
    HuffmanMinHeap *heap = createMinHeap(size);

    for(int i = 0; i < size; ++i) {
        heap->array[i] = createNode(data[i], freq[i]);
    }

    heap->size = size;
    buildMinHeap(heap);

    while(heap->size != 1) {
        leftChild = extractMin(heap);
        rightChild = extractMin(heap);

        top = createNode('$', leftChild->freq + rightChild->freq);
        top->leftChild = leftChild;
        top->rightChild = rightChild;

        insertMinHeap(heap, top);
    }

    return extractMin(heap);
}

void generateHuffmanCodes(HuffmanNode *root, char *code, int index, HuffmanCodeTable *codeTable) {
    if(root->leftChild) {
        code[index] = '0';
        generateHuffmanCodes(root->leftChild, code, index + 1, codeTable);
    }

    if(root->rightChild) {
        code[index] = '1';
        generateHuffmanCodes(root->rightChild, code, index + 1, codeTable);
    }

    if(isLeaf(root)) {
        codeTable[root->data].data = root->data;
        codeTable[root->data].code = (char*) malloc((index + 1) * sizeof(char));
        strncpy(codeTable[root->data].code, code, index);
        codeTable[root->data].code[index] = '\0';
    }
}

void compress(char *data) {
    int freq[256] = {0};
    int dataSize = (int) strlen(data);

    for(int i = 0; i < dataSize; ++i) {
        freq[data[i]]++;
    }

    HuffmanNode *root = buildHuffmanTree(data, freq, 256);
    HuffmanCodeTable *codeTable = (HuffmanCodeTable*) malloc(256 * sizeof(HuffmanCodeTable));
    char code[MAX_TREE_HT];

    generateHuffmanCodes(root, code, 0, codeTable);

    printf("Original data: %s\n", data);
    printf("Compressed data: ");

    for(int i = 0; i < dataSize; ++i) {
        printf("%s", codeTable[data[i]].code);
    }

    printf("\n");

    double bitsBefore = 8 * dataSize;
    double bitsAfter = 0;

    for(int i = 0; i < 256; ++i) {
        if(freq[i] > 0) {
            bitsAfter += freq[i] * strlen(codeTable[i].code);
        }
    }

    double compressionRatio = bitsBefore / bitsAfter;

    printf("Number of bits before compression: %.0f\n", bitsBefore);
    printf("Number of bits after compression: %.0f\n", bitsAfter);
    printf("Compression ratio: %.3f\n", compressionRatio);
}

int main() {
    char data[] = "abbcccddddeeeeeffffff";
    compress(data);
    return 0;
}