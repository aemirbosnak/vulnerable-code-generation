//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
/*
 * Huffman Coding Implementation
 * Created by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode {
    char data;              // Input data
    unsigned freq;          // Frequency of the input data
    struct MinHeapNode *left, *right;    // Left and right child of the node
};

// A Min Heap:  Collection of MinHeapNode pointers
struct MinHeap {
    unsigned size;          // Current size of min heap
    unsigned capacity;      // Capacity of min heap
    struct MinHeapNode **array; // Array of minheap node pointers
};

// Function prototypes
void encode(struct MinHeapNode *root, char *code);
void printCodes(struct MinHeapNode *root, char *code);
struct MinHeap *createMinHeap(unsigned capacity);
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b);
void minHeapify(struct MinHeap *minHeap, int idx);
int isSizeOne(struct MinHeap *minHeap);
struct MinHeapNode *extractMin(struct MinHeap *minHeap);
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode);
void buildMinHeap(struct MinHeap *minHeap);
struct MinHeapNode *newMinHeapNode(char data, unsigned freq);
struct MinHeap *createAndBuildMinHeap(char data[], unsigned freq[], int size);
struct MinHeapNode *buildHuffmanTree(char data[], unsigned freq[], int size);
void printArr(char arr[], int n);

// Main function
int main() { 
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'}; // Input data
    unsigned freq[] = {5, 9, 12, 13, 16, 45};     // Frequency of input data
    int size = sizeof(data)/sizeof(data[0]);

    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    char code[MAX_TREE_HT];
    encode(root, code);
    printCodes(root, code);

    return 0; 
}

// Function to encode input data to Huffman encoded data
void encode(struct MinHeapNode *root, char *code) {
    static int index = 0;

    if(root->left) {
        code[index++] = '0';
        encode(root->left, code);
    }
    if(root->right) {
        code[index++] = '1';
        encode(root->right, code);
    }
    if(!(root->left) && !(root->right)) {
        printf("%c --> %s\n", root->data, code);
    }

    index--;
}

// Function to print the Huffman codes
void printCodes(struct MinHeapNode *root, char *code) {
    printf("The Huffman codes are:\n");
    encode(root, code);
}

// Function to create a new Min Heap node with given data and frequency
struct MinHeapNode *newMinHeapNode(char data, unsigned freq) {
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Function to create a min heap of given capacity
struct MinHeap *createMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

// Function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a min heap with the given idx
void minHeapify(struct MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if the size of heap is 1
int isSizeOne(struct MinHeap *minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum value node from heap
struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new min heap node to the heap
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while(i && minHeapNode->freq < minHeap->array[(i-1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i-1)/2];
        i = (i-1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to build the min heap
void buildMinHeap(struct MinHeap *minHeap) {
    int n = minHeap->size - 1;
    int i;
    for(i = (n-1)/2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

// Function to create and build the min heap
struct MinHeap *createAndBuildMinHeap(char data[], unsigned freq[], int size) {
    struct MinHeap *minHeap = createMinHeap(size);

    for(int i = 0; i < size; ++i) {
        minHeap->array[i] = newMinHeapNode(data[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

// Function to build the Huffman Tree and return the root node
struct MinHeapNode *buildHuffmanTree(char data[], unsigned freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while(!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newMinHeapNode('$', left->freq + right->freq);      // Parent node
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to print an array of size n
void printArr(char arr[], int n) {
    for(int i = 0; i < n; ++i) {
        printf("%c", arr[i]);
    }
    printf("\n");
}