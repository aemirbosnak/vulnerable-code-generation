//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

// A node in the Huffman tree
struct Node {
    char data;
    unsigned frequency;
    struct Node *left, *right;
};

// A min heap structure, which is a collection of Nodes
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct Node **array;
};

// Function prototypes
struct Node* createNode(char data, unsigned frequency);
struct MinHeap* createMinHeap(unsigned capacity);
void insertMinHeap(struct MinHeap* minHeap, struct Node* node);
void minHeapify(struct MinHeap* minHeap, int idx);
struct Node* extractMin(struct MinHeap* minHeap);
int isSizeOne(struct MinHeap* minHeap);
void buildHuffmanTree(char data[], int frequency[], int size);
void printCodes(struct Node* root, int arr[], int top);
void HuffmanCodes(char data[], int frequency[], int size);

// Function to create a new Node
struct Node* createNode(char data, unsigned frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a Min Heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

// Function to insert a new node into the Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to minHeapify
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        struct Node* temp = minHeap->array[idx];
        minHeap->array[idx] = minHeap->array[smallest];
        minHeap->array[smallest] = temp;
        minHeapify(minHeap, smallest);
    }
}

// Function to extract the minimum node from the Min Heap
struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to check if the size of the heap is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to build the Huffman Tree
void buildHuffmanTree(char data[], int frequency[], int size) {
    struct Node *left, *right, *top;
    
    struct MinHeap* minHeap = createMinHeap(size);
    
    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, createNode(data[i], frequency[i]));
    }

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    printCodes(extractMin(minHeap), (int[]){}, 0);
}

// Function to print codes of characters by traversing the Huffman tree
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to generate Huffman codes
void HuffmanCodes(char data[], int frequency[], int size) {
    buildHuffmanTree(data, frequency, size);
}

// Main function
int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequency[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    printf("Character with their Huffman codes:\n");
    HuffmanCodes(data, frequency, size);
    
    return 0;
}