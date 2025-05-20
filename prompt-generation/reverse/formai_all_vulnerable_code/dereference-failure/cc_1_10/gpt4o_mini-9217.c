//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function to find the frequency of each character in the input string
void findFrequency(const char* input, int* frequency) {
    while (*input) {
        frequency[*input++]++;
    }
}

// Function to create a min heap node
struct MinHeapNode {
    char data;
    int freq;
    struct MinHeapNode *left, *right;
};

// Function to create a new min heap node
struct MinHeapNode* newNode(char data, int freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to swap two min heap nodes
void swap(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to min heapify
void minHeapify(struct MinHeapNode** minHeap, int idx, int size) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && minHeap[left]->freq < minHeap[smallest]->freq)
        smallest = left;

    if (right < size && minHeap[right]->freq < minHeap[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap[smallest], &minHeap[idx]);
        minHeapify(minHeap, smallest, size);
    }
}

// Function to build the min heap
void buildMinHeap(struct MinHeapNode** minHeap, int size) {
    int startIdx = (size / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        minHeapify(minHeap, i, size);
    }
}

// Function to create and build the min heap
struct MinHeapNode** createMinHeap(int* frequency, int* size) {
    int count = 0;

    for (int i = 0; i < 256; i++) {
        if (frequency[i]) {
            count++;
        }
    }

    *size = count;
    struct MinHeapNode** minHeap = (struct MinHeapNode**)malloc(count * sizeof(struct MinHeapNode*));
    count = 0;

    for (int i = 0; i < 256; i++) {
        if (frequency[i]) {
            minHeap[count++] = newNode((char)i, frequency[i]);
        }
    }

    buildMinHeap(minHeap, count);
    return minHeap;
}

// Function to build the Huffman tree
struct MinHeapNode* buildHuffmanTree(struct MinHeapNode** minHeap, int size) {
    while (size > 1) {
        struct MinHeapNode* left = minHeap[0];
        minHeap[0] = minHeap[size - 1];

        minHeapify(minHeap, 0, size - 1);
        size--;

        struct MinHeapNode* right = minHeap[0];
        minHeap[0] = newNode('\0', left->freq + right->freq);
        minHeap[0]->left = left;
        minHeap[0]->right = right;

        minHeapify(minHeap, 0, size);
        size++;
    }

    return minHeap[0];
}

// Function to print the Huffman codes recursively
void printCodes(struct MinHeapNode* root, int* arr, int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Wrapper function for Huffman Coding
void HuffmanCoding(const char* input) {
    int frequency[256] = {0};
    findFrequency(input, frequency);

    int size;
    struct MinHeapNode** minHeap = createMinHeap(frequency, &size);

    struct MinHeapNode* root = buildHuffmanTree(minHeap, size);

    int arr[MAX_LEN], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
}

// Main function
int main() {
    char input[MAX_LEN];

    printf("Enter a string to compress using Huffman coding: ");
    fgets(input, MAX_LEN, stdin);
    
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;

    printf("\nInput String: %s\n", input);
    HuffmanCoding(input);

    return 0;
}