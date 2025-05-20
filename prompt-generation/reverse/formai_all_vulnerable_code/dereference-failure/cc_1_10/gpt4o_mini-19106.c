//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256  

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node **array;
} MinHeap;

// Function to create a new node
Node* createNode(char character, unsigned frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a min heap
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
    return minHeap;
}

// Function to swap two nodes
void swapNode(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to min-heapify
void minHeapify(MinHeap* minHeap, int idx) {
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

// Function to check if the size of the heap is 1
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum node
Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node to the min-heap
void insertMinHeap(MinHeap* minHeap, Node* newNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && newNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = newNode;
}

// Function to build the min-heap from a given character array
MinHeap* buildMinHeap(char characters[], unsigned freq[], unsigned size) {
    MinHeap* minHeap = createMinHeap(size);
    for (unsigned i = 0; i < size; ++i) {
        minHeap->array[i] = createNode(characters[i], freq[i]);
    }
    minHeap->size = size;
    for (int i = (minHeap->size - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
    return minHeap;
}

// Function to build the Huffman Tree
Node* buildHuffmanTree(char characters[], unsigned freq[], unsigned size) {
    Node *left, *right, *top;
    MinHeap* minHeap = buildMinHeap(characters, freq, size);
    
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

// A utility function to print the codes
void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Wrapper function to generate and print Huffman codes
void generateHuffmanCodes(char characters[], unsigned freq[], unsigned size) {
    Node* root = buildHuffmanTree(characters, freq, size);
    int arr[MAX_TREE_NODES], top = 0;
    printCodes(root, arr, top);
}

// Main program
int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e' };
    unsigned freq[] = { 5, 9, 12, 13, 16 };
    unsigned size = sizeof(characters) / sizeof(characters[0]);
    
    printf("Huffman Codes for the given characters:\n");
    generateHuffmanCodes(characters, freq, size);
    
    return 0;
}