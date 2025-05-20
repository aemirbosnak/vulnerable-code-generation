//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
// This C program demonstrates a unique compression algorithm that uses a combination of run-length encoding and Huffman coding.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Function to generate the run-length encoded data
char* runLengthEncoding(char* inputData, int inputSize, int* outputSize) {
    char* outputData = (char*) malloc(inputSize * sizeof(char));
    int count = 1, pos = 0;

    for (int i = 1; i < inputSize; i++) {
        if (inputData[i] == inputData[i - 1]) {
            count++;
        } else {
            outputData[pos++] = count;
            outputData[pos++] = inputData[i - 1];
            count = 1;
        }
    }

    outputData[pos++] = count;
    outputData[pos++] = inputData[inputSize - 1];

    *outputSize = pos;
    return outputData;
}

// Function to generate the Huffman tree
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

bool isSizeOne(struct MinHeap* minHeap) {
    return minHeap->size == 1;
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

bool isLeaf(struct MinHeapNode* root) {
    return !root->left && !root->right;
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = size;
    minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

// Function to compress the data
char* compressData(char* inputData, int inputSize, int* outputSize) {
    int freq[256] = {0}, pos = 0;
    char* outputData = (char*) malloc(inputSize * sizeof(char));

    for (int i = 0; i < inputSize; i++) {
        freq[inputData[i]]++;
    }

    struct MinHeapNode* root = buildHuffmanTree(inputData, freq, 256);
    int arr[100], top = 0;
    printCodes(root, arr, top);

    for (int i = 0; i < inputSize; i += 2) {
        int count = inputData[i];
        char symbol = inputData[i + 1];
        for (int j = 0; j < count; j++) {
            outputData[pos++] = symbol;
        }
    }

    *outputSize = pos;
    return outputData;
}

int main() {
    char inputData[] = "aaabbbbbcccccdddddddddd";
    int inputSize = strlen(inputData);
    int outputSize;

    char* rlEncodedData = runLengthEncoding(inputData, inputSize, &outputSize);
    char* compressedData = compressData(rlEncodedData, outputSize, &outputSize);

    printf("Input:\n%s\n", inputData);
    printf("Run-length encoded data:\n%s\n", rlEncodedData);
    printf("Compressed data:\n%s\n", compressedData);
    printf("Output size: %d\n", outputSize);

    return 0;
}
