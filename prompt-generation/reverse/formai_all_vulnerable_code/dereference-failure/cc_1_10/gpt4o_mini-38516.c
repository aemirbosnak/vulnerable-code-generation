//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node* createNode(char character, unsigned frequency) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->left = newNode->right = NULL;
    newNode->character = character;
    newNode->frequency = frequency;
    return newNode;
}

// A Min Heap: A structure to hold the nodes
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct Node** array;
};

// Function to create a Min Heap
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

// Function to swap two nodes
void swapNode(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if size is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract minimum
struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert node
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to build Min Heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Function to create and build the min heap
struct MinHeap* createAndBuildMinHeap(char characters[], int frequencies[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(characters[i], frequencies[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Function to check if the heap is a valid min heap
void printHeap(struct MinHeap* minHeap) {
    for (int i = 0; i < minHeap->size; ++i) {
        printf("Character: %c Frequency: %u\n", minHeap->array[i]->character, minHeap->array[i]->frequency);
    }
}

// Function to build the Huffman Tree
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(characters, frequencies, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Function to print the codes recursively
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("Character: %c Code: ", root->character);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Wrapper function
void HuffmanCodes(char characters[], int frequencies[], int size) {
    struct Node* root = buildHuffmanTree(characters, frequencies, size);
    int arr[100], top = 0;
    printCodes(root, arr, top);
}

// The great puzzle
int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e'};
    int frequencies[] = {5, 9, 12, 13, 16};
    int size = sizeof(characters) / sizeof(characters[0]);
    printf("Huffman Codes:\n");
    HuffmanCodes(characters, frequencies, size);
    return 0;
}