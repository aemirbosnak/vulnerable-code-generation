//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

typedef struct minHeapNode {
    uint8_t data;               
    uint32_t freq;              
    struct minHeapNode *left, *right;
} MinHeapNode;

typedef struct minHeap {
    uint32_t size;              
    uint32_t capacity;          
    MinHeapNode **array;        
} MinHeap;

typedef struct huffCode {
    uint8_t data;
    char *code;                 
} HuffCode;

MinHeapNode *newNode(uint8_t data, uint32_t freq) {
    MinHeapNode *node = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap *createMinHeap(uint32_t capacity) {
    MinHeap *minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNodes(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int32_t idx) {
    int32_t smallest = idx;
    int32_t left = 2 * idx + 1;
    int32_t right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swapMinHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

bool isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode *extractMin(MinHeap *minHeap) {
    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode) {
    minHeap->size++;
    int32_t i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap *minHeap) {
    int32_t n = minHeap->size - 1;
    int32_t i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

void printArr(char *arr, uint32_t n) {
    uint32_t i;
    for (i = 0; i < n; ++i) {
        printf("%c", arr[i]);
    }
}

bool isLeaf(MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

MinHeap *createAndBuildMinHeap(uint8_t data[], uint32_t freq[], uint32_t size) {
    MinHeap *minHeap = createMinHeap(size);
    for (uint32_t i = 0; i < size; i++) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

MinHeapNode *buildHuffmanTree(uint8_t data[], uint32_t freq[], uint32_t size) {
    MinHeapNode *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(MinHeapNode *root, char *arr, uint32_t top, HuffCode *huffCodes) {
    if (root->left) {
        arr[top] = '0';
        printCodes(root->left, arr, top + 1, huffCodes);
    }
    if (root->right) {
        arr[top] = '1';
        printCodes(root->right, arr, top + 1, huffCodes);
    }
    if (isLeaf(root)) {
        huffCodes[root->data].data = root->data;
        huffCodes[root->data].code = (char*) malloc((top + 1) * sizeof(char));
        memcpy(huffCodes[root->data].code, arr, top);
        huffCodes[root->data].code[top] = '\0';
    }
}

HuffCode *compress(uint8_t data[], uint32_t freq[], uint32_t size) {
    HuffCode *huffCodes = (HuffCode*) malloc(256 * sizeof(HuffCode));
    MinHeapNode *root = buildHuffmanTree(data, freq, size);
    char arr[MAX_TREE_HT];
    uint32_t top = 0;
    printCodes(root, arr, top, huffCodes);
    return huffCodes;
}

void encode(uint8_t *buffer, uint64_t n, FILE *fout, HuffCode *huffCodes) {
    uint64_t i, j;
    uint32_t index = 0;
    char *code;
    for (i = 0; i < n; ++i) {
        code = huffCodes[buffer[i]].code;
        for (j = 0; j < strlen(code); ++j) {
            if (code[j] == '0') {
                index &= ~(1 << 7);
            }
            else if (code[j] == '1') {
                index |= (1 << 7);
            }
            if (index & (1 << 7)) {
                for (uint32_t k = 0; k < 8; k++) {
                    fprintf(fout, "%d", (index & (1 << (7 - k))) ? 1 : 0);
                }
                index = 0;
            } else {
                index >>= 1;
            }
        }
    }
    if (index & (1 << 7)) {
        for (uint32_t k = 0; k < 8; k++) {
            fprintf(fout, "%d", (index & (1 << (7 - k))) ? 1 : 0);
        }
    }
}

int main() {
    uint8_t data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    uint32_t freq[] = {5, 9, 12, 13, 16, 45};
    uint32_t size = sizeof(data) / sizeof(data[0]);
    HuffCode *huffCodes = compress(data, freq, size);
    uint8_t buffer[] = {'a', 'b', 'c', 'd', 'e', 'f', 'a', 'b', 'c', 'd', 'e', 'f'};
    uint64_t n = sizeof(buffer) / sizeof(buffer[0]);
    FILE *fout = fopen("compressed_data.txt", "w");
    if (!fout) {
        fprintf(stderr, "Error opening compressed data file.\n");
        exit(EXIT_FAILURE);
    }
    encode(buffer, n, fout, huffCodes);
    fclose(fout);
    return 0;
}