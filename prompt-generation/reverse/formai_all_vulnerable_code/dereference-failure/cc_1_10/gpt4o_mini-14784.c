//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct MinHeap {
    int size;
    Node* array[MAX_TREE_NODES];
} MinHeap;

// Function to create a new node
Node* createNode(char character, unsigned frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new MinHeap
MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

// Function to swap two nodes
void swapNode(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain min-heap property
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

// Function to add a node to min-heap
void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->array[minHeap->size] = node;
    int current = minHeap->size++;
    
    while (current && minHeap->array[current]->frequency < minHeap->array[(current - 1) / 2]->frequency) {
        swapNode(&minHeap->array[current], &minHeap->array[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Function to extract the minimum element from the heap
Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to build a Huffman Tree
Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = createMinHeap();

    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to print the Huffman codes
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
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// The main function to execute the Huffman Coding example
int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);

    Node* root = buildHuffmanTree(characters, frequencies, size);
    
    int arr[MAX_TREE_NODES], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
    
    return 0;
}