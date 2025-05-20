//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// A MinHeap: Collection of min-heap (or Huffman tree) nodes
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// A utility function allocate a new min-heap node with given character and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// A utility function to create a min-heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// A function that swaps two min-heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// The standard minHeapify function.
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

// A utility function to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// A standard function to extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// A utility function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// A standard function to build min heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) minHeapify(minHeap, i);
}

// A utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// A utility function to print an array of size n
void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) printf("%d", arr[i]);
    printf("\n");
}

// Function to read in the file and return its size in bytes
int readInFile(char* filename, char** buffer) {
    int fileLen;
    FILE* pFile;
    pFile = fopen(filename, "rb");
    fseek(pFile, 0, SEEK_END);
    fileLen = ftell(pFile);
    rewind(pFile);
    *buffer = (char*)malloc(fileLen * sizeof(char));
    fread(*buffer, fileLen, 1, pFile);
    fclose(pFile);
    return fileLen;
}

// Function to write the encoded bytes to file
void writeOutFile(char* filename, char* outBuff, int len) {
    FILE* pFile;
    pFile = fopen(filename, "wb");
    fwrite(outBuff, len, 1, pFile);
    fclose(pFile);
    free(outBuff);
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) insertMinHeap(minHeap, newNode(data[i], freq[i]));
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

// The function to create and print Huffman codes for all characters
void createHuffmanCodes(struct MinHeapNode* root, int arr[], int top, int* freqCount, char** codes) {
    if (root->left) {
        arr[top] = 0;
        createHuffmanCodes(root->left, arr, top + 1, freqCount, codes);
    }
    if (root->right) {
        arr[top] = 1;
        createHuffmanCodes(root->right, arr, top + 1, freqCount, codes);
    }
    if (isLeaf(root)) {
        codes[(int)root->data] = (char*)malloc((top + 1) * sizeof(char));
        memcpy(codes[(int)root->data], arr, (top + 1) * sizeof(char));
        freqCount[(int)root->data] = root->freq;
    }
}

// Huffman Encoding function
char* huffmanEncode(char* input, char** codes, int* freqCount, int inputLen, int* outputLen) {
    int i, j;
    char* outBuff = (char*)malloc(inputLen * MAX_TREE_HT * sizeof(char));
    *outputLen = 0;
    for (i = 0; i < inputLen; i++) {
        memcpy(outBuff + *outputLen, codes[(int)input[i]], strlen(codes[(int)input[i]]));
        *outputLen += strlen(codes[(int)input[i]]);
    }
    char freq[256] = {0};
    for (i = 0; i < inputLen; i++) {
        if (freq[input[i]] == 0) {
            freq[input[i]] = 1;
        }
    }
    int encodeSize = 0;
    for (i = 0; i < 256; i++) {
        if (freq[i] == 1) {
            encodeSize += freqCount[i] + 2; 
        }
    }
    char* encStart = (char*)malloc(encodeSize * sizeof(char));
    j = 0;
    for (i = 0; i < 256; i++) {
        if (freq[i] == 1) {
            encStart[j++] = (char)i;
            memcpy(encStart+j, &freqCount[i], sizeof(int));
            j += sizeof(int);
            memcpy(encStart+j, codes[i], strlen(codes[i]));
            j += strlen(codes[i]);
        }
    }
    *outputLen += j; 
    memcpy(outBuff + *outputLen, encStart, j);
    *outputLen += j;
    free(encStart);
    return outBuff;
}

int main() {
    char* filenameIn = "input.txt";
    char* filenameOut = "output.dat";
    char* buffer;
    char data[256];
    int freq[256] = {0};
    int fileLen = readInFile(filenameIn, &buffer);
    for (int i = 0; i < fileLen; i++) {
        freq[(int)buffer[i]]++;
    }
    int uniqueChar = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            uniqueChar++;
        }
    }
    int arr[uniqueChar];
    char* codes[256];
    struct MinHeapNode* root = buildHuffmanTree(data, freq, uniqueChar);
    createHuffmanCodes(root, arr, 0, freq, codes);
    int outputLen = 0;
    char* outBuff = huffmanEncode(buffer, codes, freq, fileLen, &outputLen);
    writeOutFile(filenameOut, outBuff, outputLen);
    free(buffer);
    for (int i = 0; i < 256; i++) {
        if (codes[i]) {
            free(codes[i]);
        }
    }
    return 0;
}