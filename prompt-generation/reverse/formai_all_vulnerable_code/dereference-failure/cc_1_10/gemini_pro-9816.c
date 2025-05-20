//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Node {
    uint8_t symbol;
    uint64_t freq;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(uint8_t symbol, uint64_t freq) {
    struct Node *node = malloc(sizeof(struct Node));
    node->symbol = symbol;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node **createHeap(uint8_t *symbols, uint64_t *freqs, uint64_t size) {
    struct Node **heap = malloc(sizeof(struct Node *) * size);
    for (uint64_t i = 0; i < size; i++) {
        heap[i] = createNode(symbols[i], freqs[i]);
    }
    return heap;
}

void heapify(struct Node **heap, uint64_t size, uint64_t i) {
    uint64_t smallest = i;
    uint64_t left = 2 * i + 1;
    uint64_t right = 2 * i + 2;

    if (left < size && heap[left]->freq < heap[smallest]->freq) {
        smallest = left;
    }

    if (right < size && heap[right]->freq < heap[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        struct Node *temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

struct Node *buildTree(struct Node **heap, uint64_t size) {
    while (size > 1) {
        struct Node *left = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(heap, size, 0);
        struct Node *right = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(heap, size, 0);
        struct Node *parent = createNode(' ', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        heap[0] = parent;
        heapify(heap, size, 0);
    }
    return heap[0];
}

void encode(struct Node *root, uint8_t symbol, char *code, uint64_t *index) {
    if (root->left == NULL && root->right == NULL) {
        code[*index] = '\0';
        printf("%c: %s\n", symbol, code);
        return;
    }

    if (root->left != NULL) {
        code[*index] = '0';
        (*index)++;
        encode(root->left, symbol, code, index);
    }

    if (root->right != NULL) {
        code[*index] = '1';
        (*index)++;
        encode(root->right, symbol, code, index);
    }

    (*index)--;
}

int main() {
    uint8_t symbols[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    uint64_t freqs[] = {5, 9, 12, 13, 16, 45};
    uint64_t size = sizeof(symbols) / sizeof(symbols[0]);

    struct Node **heap = createHeap(symbols, freqs, size);
    for (uint64_t i = (size / 2) - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }

    struct Node *root = buildTree(heap, size);

    char code[100];
    uint64_t index = 0;

    for (uint64_t i = 0; i < size; i++) {
        encode(root, symbols[i], code, &index);
    }

    return 0;
}