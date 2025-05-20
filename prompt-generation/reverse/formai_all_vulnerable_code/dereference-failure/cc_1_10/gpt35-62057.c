//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_TREE_HT 256

typedef struct node {
    char data;
    uint8_t freq;
    struct node *left, *right;
} node_t;

typedef struct minHeap {
    uint8_t size;
    uint8_t capacity;
    node_t **array;
} minHeap_t;

typedef struct huffmanTree {
    node_t *root;
} huffmanTree_t;

typedef struct huffmanCodeTable {
    char character;
    char *code;
} huffmanCodeTable_t;

node_t* newNode(char data, uint8_t freq) {
    node_t* node = (node_t*) malloc(sizeof (node_t));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

minHeap_t* createMinHeap(uint8_t capacity) {
    minHeap_t* minHeap = (minHeap_t*) malloc(sizeof (minHeap_t));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (node_t**) malloc(minHeap->capacity * sizeof (node_t*));
    return minHeap;
}

void swapNode(node_t** a, node_t** b) {
    node_t* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(minHeap_t* minHeap, uint8_t idx) {
    uint8_t smallest = idx;
    uint8_t left = 2 * idx + 1;
    uint8_t right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

bool isSizeOne(minHeap_t* minHeap) {
    return (minHeap->size == 1);
}

node_t* extractMin(minHeap_t* minHeap) {
    node_t* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(minHeap_t* minHeap, node_t* node) {
    ++minHeap->size;
    uint8_t i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

minHeap_t* buildMinHeap(char* data, uint8_t* freq, uint8_t size) {
    minHeap_t* minHeap = createMinHeap(size);

    for (uint8_t i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;

    while (!isSizeOne(minHeap)) {
        node_t* left = extractMin(minHeap);
        node_t* right = extractMin(minHeap);
        node_t* parent = newNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insertMinHeap(minHeap, parent);
    }

    return minHeap;
}

huffmanTree_t* buildHuffmanTree(char* data, uint8_t* freq, uint8_t size) {
    huffmanTree_t* tree = (huffmanTree_t*) malloc(sizeof (huffmanTree_t));
    minHeap_t* minHeap = buildMinHeap(data, freq, size);
    tree->root = extractMin(minHeap);
    free(minHeap);
    return tree;
}

void printCode(node_t* root, char* code, uint8_t idx, huffmanCodeTable_t* codeTable) {
    if (root->left) {
        code[idx] = '0';
        printCode(root->left, code, idx + 1, codeTable);
    }

    if (root->right) {
        code[idx] = '1';
        printCode(root->right, code, idx + 1, codeTable);
    }

    if (!root->left && !root->right) {
        codeTable[root->data].character = root->data;
        codeTable[root->data].code = (char*) malloc((idx + 1) * sizeof (char));
        codeTable[root->data].code[idx] = '\0';
        strncpy(codeTable[root->data].code, code, idx);
    }
}

huffmanCodeTable_t* buildHuffmanCodeTable(huffmanTree_t* tree, char* data, uint8_t* freq, uint8_t size) {
    char code[MAX_TREE_HT];
    huffmanCodeTable_t* codeTable = (huffmanCodeTable_t*) malloc(size * sizeof (huffmanCodeTable_t));
    printCode(tree->root, code, 0, codeTable);
    return codeTable;
}

void encode(char* data, uint8_t size, huffmanCodeTable_t* codeTable) {
    char* result = (char*) malloc((size * MAX_TREE_HT + 1) * sizeof (char));
    uint16_t idx = 0;

    for (uint8_t i = 0; i < size; ++i) {
        strncat(result, codeTable[data[i]].code, strlen(codeTable[data[i]].code));
    }

    printf("Encoded Huffman data: %s\n", result);
    free(result);
}

void decode(node_t* root, uint16_t* idx, char* data) {
    if (!root->left && !root->right) {
        printf("%c", root->data);
        return;
    }

    ++*idx;

    if (data[*idx] == '0')
        decode(root->left, idx, data);
    else
        decode(root->right, idx, data);
}

void decodeData(char* data, uint8_t size, huffmanTree_t* tree) {
    uint16_t idx = -1;

    while (idx < size - 2)
        decode(tree->root, &idx, data);

    printf("\n");
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    uint8_t freq[] = {5, 9, 12, 13, 16, 45};
    uint8_t size = sizeof (data) / sizeof (data[0]);

    huffmanTree_t* tree = buildHuffmanTree(data, freq, size);
    huffmanCodeTable_t* codeTable = buildHuffmanCodeTable(tree, data, freq, size);

    encode(data, size, codeTable);
    decodeData("011000010111110110001000", size, tree);

    return 0;
}