//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50
#define MAX_CODE_LEN 100

// Structure to represent a Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Structure to represent a min heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Helper function to create a new min heap node
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* node =
        (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Helper function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function for the min heap
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < (int)minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < (int)minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Helper function to check if the given min heap is of size 1
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract the minimum element from the min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into the min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// Build the min heap from the given characters with their corresponding frequencies
struct MinHeap* buildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap =
        (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = size;
    minHeap->array =
        (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    for (int i = (int)minHeap->size / 2 - 1; i >= 0; --i)
        minHeapify(minHeap, i);

    return minHeap;
}

// Check if the given node is a leaf node
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Helper function to print an array of 0s and 1s
void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%d", arr[i]);
    printf("\n");
}

// Recursive function to generate Huffman codes for the nodes
void generateCodes(struct MinHeapNode* root, int arr[], int top, char codes[][MAX_CODE_LEN]) {
    if (root->left) {
        arr[top] = 0;
        generateCodes(root->left, arr, top + 1, codes);
    }

    if (root->right) {
        arr[top] = 1;
        generateCodes(root->right, arr, top + 1, codes);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        printArr(arr, top);
        strcpy(codes[(int)root->data], "");
        for(int i = 0; i < top; i++){
            int temp = arr[i];
            codes[(int)root->data][i] = (char)(temp + 48);
        }
    }
}

// Funktion zur Kodierung der gegebenen Zeichen
void huffmanCode(char data[], int freq[], int size) {
    // Erstellen des Min-Heap
    struct MinHeap* minHeap = buildMinHeap(data, freq, size);

    // Erstellen des Huffman-Baums
    while (!isSizeOne(minHeap)) {
        struct MinHeapNode* left = extractMin(minHeap);
        struct MinHeapNode* right = extractMin(minHeap);

        struct MinHeapNode* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    // Generieren der Huffman-Codes für die Zeichen
    int arr[MAX_TREE_HT], top = 0;
    char codes[256][MAX_CODE_LEN];
    generateCodes(minHeap->array[0], arr, top, codes);
    
    // Ausgabe der Huffman-Codes
    printf("\nHuffman Codes for the given characters:\n");
    for (int i = 0; i < size; ++i) {
        printf("%c: %s\n", data[i], codes[(int)data[i]]);
    }

    free(minHeap);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    huffmanCode(arr, freq, size);

    return 0;
}