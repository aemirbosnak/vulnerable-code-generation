//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100

// Node structure for the Huffman tree
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Min Heap structure
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Function prototypes
struct MinHeapNode *newNode(char data, unsigned freq);
struct MinHeap *createMinHeap(unsigned capacity);
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b);
void minHeapify(struct MinHeap *minHeap, int idx);
int isSizeOne(struct MinHeap *minHeap);
struct MinHeapNode *extractMin(struct MinHeap *minHeap);
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode);
void buildMinHeap(struct MinHeap *minHeap);
void printArr(int arr[], int n);
void storeCodes(struct MinHeapNode *root, int arr[], int top);
void HuffmanCodes(char data[], int freq[], int size);
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size);
void printHuffmanCoding(char *str, int *arr);

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Creating Huffman Codes...\n\n");
    HuffmanCodes(data, freq, size);

    return 0;
}

// Function to create a new min heap node
struct MinHeapNode *newNode(char data, unsigned freq) {
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Create a Min Heap of a given capacity
struct MinHeap *createMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

// Swap two nodes
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// Rearranges the min heap to maintain the min heap property
void minHeapify(struct MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if min heap size is one
int isSizeOne(struct MinHeap *minHeap) {
    return (minHeap->size == 1);
}

// Extract the minimum value node from the heap
struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into the MinHeap
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Build a min heap
void buildMinHeap(struct MinHeap *minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Print array in the form of a binary code
void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

// Store codes in an array
void storeCodes(struct MinHeapNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

// Create and build a MinHeap
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// The main function that builds the Huffman tree and prints codes
void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        struct MinHeapNode *left = extractMin(minHeap);
        struct MinHeapNode *right = extractMin(minHeap);

        struct MinHeapNode *top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    int arr[MAX_TREE_HEIGHT], top = 0;
    storeCodes(extractMin(minHeap), arr, top);
}

// Print Huffman coding for a string
void printHuffmanCoding(char *str, int *arr) {
    printf("Huffman coding for string \"%s\":\n", str);
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%c: %d\n", str[i], arr[i]);
    }
}