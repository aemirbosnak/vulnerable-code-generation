//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Structure for a node in the Huffman tree
struct MinHeapNode {
    char data;                // Character
    unsigned freq;           // Frequency of the character
    struct MinHeapNode *left, *right; // Left and right child
};

// Structure for Min Heap
struct MinHeap {
    int size;                // Current size of min heap
    int capacity;            // Capacity of min heap
    struct MinHeapNode **array; // Array of min heap nodes
};

// Function to create a new min heap node
struct MinHeapNode* createNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Function to create a min heap of given capacity
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify the min heap
void minHeapify(struct MinHeap* minHeap, int idx) {
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

// Function to check if size of heap is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract minimum node from the heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node to the min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to build the min heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Function to build the Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], freq[i]);
    
    minHeap->size = size;
    buildMinHeap(minHeap);
    
    while (!isSizeOne(minHeap)) {
        // Extract the two minimum frequency nodes
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // Create a new internal node with these two nodes as children
        top = createNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap); // Root of the Huffman Tree
}

// A utility function to print the Huffman codes of the characters
void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, print the character and its code
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to calculate frequency of characters
void calculateFrequency(char* str, char data[], int freq[], int* size) {
    int characterCount[256] = {0};
    int uniqueChars = 0;

    for (int i = 0; str[i]; i++) {
        if (characterCount[(unsigned char)str[i]] == 0) {
            data[uniqueChars] = str[i];
            uniqueChars++;
        }
        characterCount[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < uniqueChars; i++) {
        freq[i] = characterCount[(unsigned char)data[i]];
    }
    *size = uniqueChars;
}

// Driver code
int main() {
    char str[1000];
    printf("Enter the text to compress: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character from input

    char data[256]; // Array to store unique characters
    int freq[256]; // Array to store frequency of each character
    int size = 0;

    calculateFrequency(str, data, freq, &size);
    
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;
    printf("Huffman Codes for the characters:\n");
    printCodes(root, arr, top);

    return 0;
}