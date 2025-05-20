//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 256
#define MAX_CODE_BITS 100

// Huffman Tree Node
struct HuffmanNode {
    char data;
    unsigned frequency;
    struct HuffmanNode *left, *right;
};

// Huffman Tree (Min Heap)
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct HuffmanNode **array;
};

// Create a new Huffman Tree Node
struct HuffmanNode* createHuffmanNode(char data, unsigned frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// Swap two nodes of a min heap
void swapMinHeapNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Create a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* heap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HuffmanNode**) malloc(heap->capacity * sizeof(struct HuffmanNode*));
    return heap;
}

// Heapify a subtree with root at given index
void minHeapify(struct MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)
        smallest = left;

    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapMinHeapNodes(&heap->array[smallest], &heap->array[index]);
        minHeapify(heap, smallest);
    }
}

// Check if the size of min heap is 1
bool isSizeOne(struct MinHeap* heap) {
    return (heap->size == 1);
}

// Extract the minimum node from heap
struct HuffmanNode* extractMin(struct MinHeap* heap) {
    struct HuffmanNode* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return temp;
}

// Insert a node into min heap
void insertMinHeap(struct MinHeap* heap, struct HuffmanNode* node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Check whether a given node is a leaf node
bool isLeafNode(struct HuffmanNode* node) {
    return !(node->left) && !(node->right);
}

// Display the code for every character in Huffman Tree
void displayHuffmanCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        displayHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        displayHuffmanCodes(root->right, arr, top + 1);
    }

    if (isLeafNode(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Build the Huffman Tree
struct HuffmanNode* buildHuffmanTree(char data[], int frequency[], int size) {
    struct HuffmanNode *left, *right, *top;

    // Create a min heap and insert all the nodes into it
    struct MinHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; i++) {
        heap->array[i] = createHuffmanNode(data[i], frequency[i]);
        heap->size++;
    }

    // Build the Huffman Tree
    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = createHuffmanNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }

    return extractMin(heap);
}

// Encode a given text
void encodeText(struct HuffmanNode* root, char* text) {
    int n = strlen(text);
    int code[MAX_CODE_BITS];
    for (int i = 0; i < n; i++) {
        int j = 0;
        struct HuffmanNode* current = root;
        while (text[i] != current->data) {
            if (code[j++])
                current = current->right;
            else
                current = current->left;
        }
        printf("%d", code[j-1]);
    }
}

int main() {
    char data[MAX_CHARS];
    int frequency[MAX_CHARS] = { 0 };
    printf("--- Medieval Huffman Encoding ---\n");

    // Input the text string
    printf("Enter the text string: ");
    fgets(data, 1000, stdin);

    // Calculate frequency of each character
    for (int i = 0; data[i]; i++) {
        frequency[data[i]]++;
    }

    // Build the Huffman Tree
    struct HuffmanNode* root = buildHuffmanTree(data, frequency, MAX_CHARS);

    // Display Huffman Codes for each character
    int arr[MAX_CODE_BITS], top = 0;
    printf("\nHuffman Codes for each character:\n");
    displayHuffmanCodes(root, arr, top);

    // Encode the text
    printf("\nEncoded text:\n");
    encodeText(root, data);

    return 0;
}