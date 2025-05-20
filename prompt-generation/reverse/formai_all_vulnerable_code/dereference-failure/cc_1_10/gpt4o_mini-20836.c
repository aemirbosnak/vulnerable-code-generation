//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the Huffman Tree
struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};

// A min heap to help build the Huffman Tree
struct MinHeap {
    int size;
    int capacity;
    struct HuffmanNode **array;
};

// Function to create a new Huffman node
struct HuffmanNode* createNode(char character, int frequency) {
    struct HuffmanNode* newNode = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a min heap of a given capacity
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct HuffmanNode**)malloc(minHeap->capacity * sizeof(struct HuffmanNode*));
    return minHeap;
}

// Function to swap two min heap nodes
void swapNode(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the min heap
void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != index) {
        swapNode(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if the size of the heap is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum node from the heap
struct HuffmanNode* extractMin(struct MinHeap* minHeap) {
    struct HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a node in the min heap
void insertMinHeap(struct MinHeap* minHeap, struct HuffmanNode* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to build the Huffman tree
struct HuffmanNode* buildHuffmanTree(char characters[], int frequencies[], int size) {
    struct HuffmanNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);
    
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));
    }

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
void printHuffmanCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("Character: %c | Code: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate Huffman coding
int main() {
    // Example input characters and their frequencies
    char characters[] = { 'a', 'b', 'c', 'd', 'e' };
    int frequencies[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(characters) / sizeof(characters[0]);
    
    // Build the Huffman Tree
    struct HuffmanNode* root = buildHuffmanTree(characters, frequencies, size);
    int arr[100], top = 0;

    // Print the Huffman codes
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);
    
    return 0;
}