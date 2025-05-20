//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Huffman tree node
struct Node {
    char data;
    int freq;
    struct Node *left;
    struct Node *right;
};

// A Min Heap of Huffman Tree Nodes
struct MinHeap {
    int size;
    int capacity;
    struct Node **array;
};

// A Huffman Coding Tree
struct HuffmanTree {
    struct Node *root;
};

// A Huffman Code
struct HuffmanCode {
    char *code;
    int len;
};

// Create a new Huffman tree node
struct Node *newNode(char data, int freq) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Create a new Min Heap of size capacity
struct MinHeap *createMinHeap(int capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node **)malloc(capacity * sizeof(struct Node *));
    return minHeap;
}

// Insert a new node into the Min Heap
void insertMinHeap(struct MinHeap *minHeap, struct Node *node) {
    int i = minHeap->size;
    minHeap->array[i] = node;
    minHeap->size++;

    while (i && minHeap->array[i]->freq < minHeap->array[(i - 1) / 2]->freq) {
        struct Node *temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Extract the minimum node from the Min Heap
struct Node *extractMin(struct MinHeap *minHeap) {
    struct Node *node = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;

    int i = 0;
    while (2 * i + 1 < minHeap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int minIndex = i;

        if (minHeap->array[left]->freq < minHeap->array[minIndex]->freq) {
            minIndex = left;
        }

        if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[minIndex]->freq) {
            minIndex = right;
        }

        if (minIndex != i) {
            struct Node *temp = minHeap->array[i];
            minHeap->array[i] = minHeap->array[minIndex];
            minHeap->array[minIndex] = temp;
            i = minIndex;
        } else {
            break;
        }
    }

    return node;
}

// Build a Huffman tree from the given frequencies
struct HuffmanTree *buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, newNode(data[i], freq[i]));
    }

    while (minHeap->size > 1) {
        struct Node *left = extractMin(minHeap);
        struct Node *right = extractMin(minHeap);

        struct Node *parent = newNode(0, left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        insertMinHeap(minHeap, parent);
    }

    struct HuffmanTree *huffmanTree = (struct HuffmanTree *)malloc(sizeof(struct HuffmanTree));
    huffmanTree->root = extractMin(minHeap);

    return huffmanTree;
}

// Assign Huffman codes to the nodes of the Huffman tree
void assignCodes(struct Node *root, struct HuffmanCode code[], int top) {
    if (root->left) {
        code[top].code = (char *)realloc(code[top].code, (top + 1) * sizeof(char));
        code[top].code[top] = '0';
        assignCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top].code = (char *)realloc(code[top].code, (top + 1) * sizeof(char));
        code[top].code[top] = '1';
        assignCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        code[top].code = (char *)realloc(code[top].code, (top + 1) * sizeof(char));
        code[top].code[top] = '\0';
    }
}

// Create Huffman codes for the given data
struct HuffmanCode *createHuffmanCodes(char data[], int freq[], int size) {
    struct HuffmanTree *huffmanTree = buildHuffmanTree(data, freq, size);

    struct HuffmanCode *code = (struct HuffmanCode *)malloc(size * sizeof(struct HuffmanCode));
    for (int i = 0; i < size; i++) {
        code[i].code = (char *)malloc(100 * sizeof(char));
        code[i].len = 0;
    }

    assignCodes(huffmanTree->root, code, 0);

    return code;
}

// Print the Huffman codes for the given data
void printHuffmanCodes(char data[], int freq[], int size) {
    struct HuffmanCode *code = createHuffmanCodes(data, freq, size);

    for (int i = 0; i < size; i++) {
        printf("%c: %s\n", data[i], code[i].code);
    }
}

// Driver program to test the Huffman Coding implementation
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    printHuffmanCodes(data, freq, size);

    return 0;
}