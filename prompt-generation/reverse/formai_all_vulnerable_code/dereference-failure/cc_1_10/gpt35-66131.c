//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman tree node structure
typedef struct HuffNode {
    char character;
    int frequency;
    struct HuffNode *left;
    struct HuffNode *right;
} HuffNode;

// Heap node structure
typedef struct HeapNode {
    int size;
    int capacity;
    HuffNode **nodes;
} HeapNode;

// Create a new Huffman tree node
HuffNode* createHuffNode(char character, int frequency) {
    HuffNode* node = (HuffNode*) malloc(sizeof(HuffNode));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a new heap node
HeapNode* createHeapNode(int capacity) {
    HeapNode* heap = (HeapNode*) malloc(sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    heap->nodes = (HuffNode**) malloc(capacity * sizeof(HuffNode*));
    return heap;
}

// Swap two Huffman tree nodes
void swap(HuffNode** a, HuffNode** b) {
    HuffNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for building heap
void heapify(HeapNode* heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->nodes[left]->frequency > heap->nodes[largest]->frequency)
        largest = left;

    if (right < heap->size && heap->nodes[right]->frequency > heap->nodes[largest]->frequency)
        largest = right;

    if (largest != i) {
        swap(&heap->nodes[i], &heap->nodes[largest]);
        heapify(heap, largest);
    }
}

// Insert a Huffman tree node into a heap
void insertHeapNode(HeapNode* heap, HuffNode* node) {
    heap->size++;
    int i = heap->size - 1;

    while (i && node->frequency > heap->nodes[(i - 1) / 2]->frequency) {
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->nodes[i] = node;
}

// Extract the root node (minimum frequency) from a heap
HuffNode* extractMin(HeapNode* heap) {
    HuffNode* root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

// Build Huffman tree from given characters and frequencies
HuffNode* buildHuffTree(char characters[], int frequencies[], int numCharacters) {
    HuffNode *x, *y;

    HeapNode* heap = createHeapNode(numCharacters);

    for (int i = 0; i < numCharacters; i++) {
        x = createHuffNode(characters[i], frequencies[i]);
        insertHeapNode(heap, x);
    }

    for (int i = 0; i < numCharacters - 1; i++) {
        x = extractMin(heap);
        y = extractMin(heap);
        HuffNode* z = createHuffNode('$', x->frequency + y->frequency);
        z->left = x;
        z->right = y;
        insertHeapNode(heap, z);
    }

    return extractMin(heap);
}

// Recursive function to print Huffman codes and traverse Huffman tree
void printCodes(HuffNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Driver program
int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int numCharacters = sizeof(characters) / sizeof(char);
    int arr[100], top = 0;
    HuffNode* root = buildHuffTree(characters, frequencies, numCharacters);
    printCodes(root, arr, top);
    return 0;
}