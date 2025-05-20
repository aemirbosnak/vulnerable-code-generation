//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define BIT_SIZE 8

struct HuffmanTree {
    unsigned char c;
    int freq;
    struct HuffmanTree *left, *right;
};

struct MinHeap {
    int size;
    int capacity;
    struct HuffmanTree** ht;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->ht = (struct HuffmanTree**) malloc(capacity * sizeof(struct HuffmanTree*));

    return minHeap;
}

void swapNodes(struct HuffmanTree** a, struct HuffmanTree** b) {
    struct HuffmanTree* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->ht[left]->freq < minHeap->ht[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->ht[right]->freq < minHeap->ht[smallest]->freq)
        smallest = right;

    if (smallest != index) {
        swapNodes(&minHeap->ht[smallest], &minHeap->ht[index]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct HuffmanTree* extractMinNode(struct MinHeap* minHeap) {
    struct HuffmanTree* node = minHeap->ht[0];
    minHeap->ht[0] = minHeap->ht[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);

    return node;
}

void insertMinHeap(struct MinHeap* minHeap, struct HuffmanTree* ht) {
    ++minHeap->size;
    int index = minHeap->size - 1;

    while (index && ht->freq < minHeap->ht[(index - 1) / 2]->freq) {
        minHeap->ht[index] = minHeap->ht[(index - 1) / 2];
        index = (index - 1) / 2;
    }

    minHeap->ht[index] = ht;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

struct HuffmanTree* buildHuffmanTree(unsigned char c[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->ht[i] = (struct HuffmanTree*) malloc(sizeof(struct HuffmanTree));

    minHeap->size = size;

    for (int i = 0; i < size; ++i) {
        minHeap->ht[i]->c = c[i];
        minHeap->ht[i]->freq = freq[i];
        minHeap->ht[i]->left = minHeap->ht[i]->right = NULL;
    }

    buildMinHeap(minHeap);

    while (!isSizeOne(minHeap)) {
        struct HuffmanTree* left = extractMinNode(minHeap);
        struct HuffmanTree* right = extractMinNode(minHeap);

        struct HuffmanTree* node = (struct HuffmanTree*) malloc(sizeof(struct HuffmanTree));

        node->freq = left->freq + right->freq;
        node->c = '0';
        node->left = left;
        node->right = right;

        insertMinHeap(minHeap, node);
    }

    return extractMinNode(minHeap);
}

void printCodes(struct HuffmanTree* tree, int code[], int top) {
    if (tree->left) {
        code[top] = 0;
        printCodes(tree->left, code, top + 1);
    }
    if (tree->right) {
        code[top] = 1;
        printCodes(tree->right, code, top + 1);
    }
    if (!tree->left && !tree->right) {
        printf("%c: ", tree->c);
        for (int i = 0; i < top; ++i)
            printf("%d", code[i]);
        printf("\n");
    }
}

void HuffmanCodes(unsigned char c[], int freq[], int size) {
    struct HuffmanTree* tree = buildHuffmanTree(c, freq, size);

    int code[size];
    int top = 0;

    printCodes(tree, code, top);
}

int main() {
    unsigned char c[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(c) / sizeof(c[0]);

    HuffmanCodes(c, freq, size);

    return 0;
}