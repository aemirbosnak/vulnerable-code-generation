//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct MinHeapNode {
    char character;
    unsigned frequency;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    int size;
    int capacity;
    MinHeapNode **array;
} MinHeap;

// Function prototypes
MinHeapNode* createNode(char character, unsigned frequency);
MinHeap* createMinHeap(int capacity);
void minHeapify(MinHeap* minHeap, int idx);
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode);
MinHeapNode* extractMin(MinHeap* minHeap);
int isSizeOne(MinHeap* minHeap);
void buildHuffmanTree(char characters[], int frequencies[], int size);
void printCodes(MinHeapNode* root, int arr[], int top);
void storeCodes(MinHeapNode* root, char* codes[], int arr[], int top);
void freeHuffmanTree(MinHeapNode* root);

void buildHuffmanTree(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    
    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));
    }

    while (!isSizeOne(minHeap)) {
        MinHeapNode* left = extractMin(minHeap);
        MinHeapNode* right = extractMin(minHeap);

        MinHeapNode* top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    printCodes(extractMin(minHeap), (int[]){0}, 0);
    freeHuffmanTree(minHeap->array[0]); // Clean up memory
    free(minHeap->array);
    free(minHeap);
}

void printCodes(MinHeapNode* root, int arr[], int top) {
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
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

MinHeapNode* createNode(char character, unsigned frequency) {
    MinHeapNode* newNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    newNode->left = newNode->right = NULL;
    newNode->character = character;
    newNode->frequency = frequency;
    return newNode;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swap(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

int isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

void freeHuffmanTree(MinHeapNode* root) {
    if (root) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e' };
    int frequencies[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(characters) / sizeof(characters[0]);

    printf("Huffman Codes:\n");
    buildHuffmanTree(characters, frequencies, size);

    return 0;
}