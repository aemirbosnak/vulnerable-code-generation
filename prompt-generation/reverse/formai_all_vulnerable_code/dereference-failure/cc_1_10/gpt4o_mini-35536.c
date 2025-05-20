//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** array;
} MinHeap;

// Function prototypes
MinHeapNode* createNode(char data, unsigned freq);
MinHeap* createMinHeap(unsigned capacity);
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode);
MinHeapNode* removeMinHeap(MinHeap* minHeap);
void buildHuffmanTree(char data[], int freq[], int size);
void printCodes(MinHeapNode* root, int arr[], int top);
void decode(MinHeapNode* root, char* encodedStr);
void freeHuffmanTree(MinHeapNode* root);

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Could not open file\n");
        return 1;
    }

    char data[MAX_TREE_NODES];
    int freq[MAX_TREE_NODES] = {0};
    int uniqueChars = 0;

    // Read the input file and calculate frequencies of each character
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (freq[c] == 0) {
            uniqueChars++;
            data[uniqueChars - 1] = c;
        }
        freq[c]++;
    }
    fclose(file);

    // Build Huffman Tree
    buildHuffmanTree(data, freq, uniqueChars);

    return 0;
}

MinHeapNode* createNode(char data, unsigned freq) {
    MinHeapNode* newNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    minHeap->array[minHeap->size++] = minHeapNode;
    int i = minHeap->size - 1;

    while (i && minHeap->array[i]->freq < minHeap->array[(i - 1) / 2]->freq) {
        MinHeapNode* temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

MinHeapNode* removeMinHeap(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;

    int i = 0;
    while (i < minHeap->size / 2) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallChild = (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[left]->freq) ? right : left;

        if (minHeap->array[i]->freq <= minHeap->array[smallChild]->freq) {
            break;
        }
        MinHeapNode* tempNode = minHeap->array[i];
        minHeap->array[i] = minHeap->array[smallChild];
        minHeap->array[smallChild] = tempNode;

        i = smallChild;
    }
    return temp;
}

void buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, createNode(data[i], freq[data[i]]));
    }

    while (minHeap->size != 1) {
        MinHeapNode* left = removeMinHeap(minHeap);
        MinHeapNode* right = removeMinHeap(minHeap);
        MinHeapNode* top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    // Root of the Huffman tree
    MinHeapNode* root = removeMinHeap(minHeap);
    int arr[MAX_TREE_NODES], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    // Free memory allocated for the Huffman tree
    freeHuffmanTree(root);
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
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void freeHuffmanTree(MinHeapNode* root) {
    if (root != NULL) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}