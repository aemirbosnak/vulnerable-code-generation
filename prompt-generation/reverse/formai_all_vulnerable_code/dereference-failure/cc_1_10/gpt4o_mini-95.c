//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// A utility function to create a new Min Heap Node
struct MinHeapNode* createNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// A utility function to build a min heap from the array of nodes
void minHeapify(struct MinHeapNode** minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap[0]->freq && minHeap[left]->freq < minHeap[smallest]->freq) {
        smallest = left;
    }
    if (right < minHeap[0]->freq && minHeap[right]->freq < minHeap[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        struct MinHeapNode* temp = minHeap[idx];
        minHeap[idx] = minHeap[smallest];
        minHeap[smallest] = temp;
        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if the size of the heap is one
int isSizeOne(int size) {
    return (size == 1);
}

// A utility function to extract the minimum node from the min heap
struct MinHeapNode* extractMin(struct MinHeapNode** minHeap, int* size) {
    struct MinHeapNode* temp = minHeap[0];
    minHeap[0] = minHeap[--(*size)];
    minHeapify(minHeap, 0);
    return temp;
}

// A utility function to insert a new node to the min heap
void insertMinHeap(struct MinHeapNode** minHeap, struct MinHeapNode* newNode, int* size) {
    ++(*size);
    int i = *size - 1;

    while (i && newNode->freq < minHeap[(i - 1) / 2]->freq) {
        minHeap[i] = minHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap[i] = newNode;
}

// A utility function to build a min heap from characters and their frequencies
struct MinHeapNode** buildMinHeap(char data[], int freq[], int size) {
    struct MinHeapNode** minHeap = (struct MinHeapNode**)malloc(sizeof(struct MinHeapNode*) * (size + 1));
    for (int i = 0; i < size; i++) {
        minHeap[i] = createNode(data[i], freq[i]);
    }
    minHeap[0] = createNode('\0', 0); // Dummy node
    return minHeap;
}

// A function to build the Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode **minHeap = buildMinHeap(data, freq, size);
    int heapSize = size;

    while (!isSizeOne(heapSize)) {
        struct MinHeapNode* left = extractMin(minHeap, &heapSize);
        struct MinHeapNode* right = extractMin(minHeap, &heapSize);
        struct MinHeapNode* top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top, &heapSize);
    }

    return extractMin(minHeap, &heapSize);
}

// A utility function to print the huffman codes based on the generated tree
void printCodes(struct MinHeapNode* root, int arr[], int top) {
    // If the node is a leaf, print its data and code
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
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// The main function that handles the input and calls other functions
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HEIGHT], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}