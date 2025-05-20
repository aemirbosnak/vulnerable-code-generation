//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Structure to hold the node information
struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
};

// Structure to hold the heap information
struct Heap {
    unsigned size;
    unsigned capacity;
    struct HuffmanNode** array;
};

// Function prototypes
struct HuffmanNode* createNode(char data, unsigned freq);
struct Heap* createHeap(unsigned capacity);
void swapNodes(struct HuffmanNode** a, struct HuffmanNode** b);
void buildHeap(struct Heap* heap);
void printArray(int arr[], int n);
int isLeaf(struct HuffmanNode* node);
struct Heap* createAndBuildHeap(char data[], unsigned freq[], int size);
struct HuffmanNode* buildHuffmanTree(char data[], unsigned freq[], int size);
void printCodes(struct HuffmanNode* root, int arr[], int top); 
void HuffmanCodes(char data[], unsigned freq[], int size);

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}

// Function to create a new node
struct HuffmanNode* createNode(char data, unsigned freq) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new heap
struct Heap* createHeap(unsigned capacity) {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HuffmanNode**)malloc(heap->capacity * sizeof(struct HuffmanNode*));
    return heap;
}

// Function to swap two nodes
void swapNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the heap
void heapify(struct Heap* heap, int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != index) {
        swapNodes(&heap->array[smallest], &heap->array[index]);
        heapify(heap, smallest);
    }
}

// Function to check if the node is a leaf
int isLeaf(struct HuffmanNode* node) {
    return !(node->left) && !(node->right);
}

// Function to create and build the heap
struct Heap* createAndBuildHeap(char data[], unsigned freq[], int size) {
    struct Heap* heap = createHeap(size);
    for (int i = 0; i < size; ++i) {
        heap->array[i] = createNode(data[i], freq[i]);
    }
    heap->size = size;
    for (int i = (heap->size - 1)/2; i >= 0; --i) {
        heapify(heap, i);
    }
    return heap;
}

// Function to build the Huffman tree
struct HuffmanNode* buildHuffmanTree(char data[], unsigned freq[], int size) {
    struct HuffmanNode *left, *right, *top;
    struct Heap* heap = createAndBuildHeap(data, freq, size);
    while (heap->size != 1) {
        left = heap->array[0];
        right = heap->array[1];
        heap->array[0] = createNode('$', left->freq + right->freq);
        heap->array[0]->left = left;
        heap->array[0]->right = right;
        heap->size--;
        heapify(heap, 0);
    }
    return heap->array[0];
}

// Function to print the codes from the Huffman tree
void printCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        printArray(arr, top);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// Function to generate the Huffman codes and print them
void HuffmanCodes(char data[], unsigned freq[], int size) { 
    struct HuffmanNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}