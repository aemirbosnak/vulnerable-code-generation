//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the Huffman tree
typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} node;

// A Min Heap node
typedef struct minHeapNode {
    char ch;
    int freq;
} minHeapNode;

// A Min Heap
typedef struct MinHeap {
    int size;     // Number of min heap nodes present
    int capacity; // Capacity of min heap
    minHeapNode **heap;  // Array of min heap node pointers
} MinHeap;

// Create a new Min Heap node
minHeapNode *newNode(char ch, int freq) {
    minHeapNode *temp = (minHeapNode *)malloc(sizeof(minHeapNode));
    temp->ch = ch;
    temp->freq = freq;
    return temp;
}

// Create a new Min Heap
MinHeap *createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->heap = (minHeapNode **)malloc(capacity * sizeof(minHeapNode *));
    return minHeap;
}

// Swap two min heap nodes
void swapMinHeapNodes(minHeapNode **a, minHeapNode **b) {
    minHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

// Min heapify the min heap
void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heap[left]->freq < minHeap->heap[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->heap[right]->freq < minHeap->heap[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNodes(&minHeap->heap[smallest], &minHeap->heap[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the min heap is full
int isMinHeapFull(MinHeap *minHeap) {
    return minHeap->size == minHeap->capacity;
}

// Check if the min heap is empty
int isMinHeapEmpty(MinHeap *minHeap) {
    return minHeap->size == 0;
}

// Insert a new node to the min heap
void insertMinHeap(MinHeap *minHeap, minHeapNode *minHeapNode) {
    if (isMinHeapFull(minHeap)) {
        printf("Cannot insert more nodes to the min heap.\n");
        return;
    }

    // Insert the new node to the end of the heap
    minHeap->heap[minHeap->size++] = minHeapNode;

    // Min heapify the heap
    int i = minHeap->size - 1;
    while (i > 0 && minHeap->heap[i]->freq < minHeap->heap[(i - 1) / 2]->freq) {
        swapMinHeapNodes(&minHeap->heap[i], &minHeap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract the minimum node from the min heap
minHeapNode *extractMin(MinHeap *minHeap) {
    if (isMinHeapEmpty(minHeap)) {
        printf("Cannot extract from an empty min heap.\n");
        return NULL;
    }

    // Store the root node
    minHeapNode *root = minHeap->heap[0];

    // Replace the root node with the last node
    minHeap->heap[0] = minHeap->heap[minHeap->size - 1];
    minHeap->size--;

    // Min heapify the heap
    minHeapify(minHeap, 0);

    return root;
}

// Build a Huffman tree from the given characters and frequencies
node *buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));

    while (minHeap->size != 1) {
        // Extract the two minimum nodes from the min heap
        minHeapNode *left = extractMin(minHeap);
        minHeapNode *right = extractMin(minHeap);

        // Create a new node with the sum of the frequencies of the two extracted nodes
        node *temp = newNode('$', left->freq + right->freq);

        // Make the two extracted nodes as the left and right children of the new node
        temp->left = left;
        temp->right = right;

        // Insert the new node to the min heap
        insertMinHeap(minHeap, temp);
    }

    // Extract the root node from the min heap
    return extractMin(minHeap);
}

// Print the Huffman codes for the given characters
void printHuffmanCodes(node *root, char code[], int top) {
    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: %s\n", root->ch, code);
    }
}

// Huffman coding
void huffmanCoding(char data[], int freq[], int size) {
    // Build the Huffman tree
    node *root = buildHuffmanTree(data, freq, size);

    // Print the Huffman codes for the given characters
    char code[100];
    printHuffmanCodes(root, code, 0);
}

// main function
int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    huffmanCoding(arr, freq, size);

    return 0;
}