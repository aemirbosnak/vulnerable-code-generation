//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

typedef struct HuffmanCode {
    char character;
    char *code;
} HuffmanCode;

MinHeapNode *createMinHeapNode(char data, unsigned freq) {
    MinHeapNode *newNode = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    newNode->freq = freq;
    return newNode;
}

MinHeap *createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap *minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != index) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[index]);
        heapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode *extractMin(MinHeap *minHeap) {
    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    heapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap *minHeap) {
    int n = minHeap->size - 1; 
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(minHeap, i);
}

int isLeaf(MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(MinHeapNode *root, int arr[], int top, HuffmanCode huffmanCode[]) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, huffmanCode);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, huffmanCode);
    }
    if (isLeaf(root)) {
        huffmanCode[root->data - 'a'].character = root->data;
        huffmanCode[root->data - 'a'].code = (char*) malloc(sizeof(char) * (top + 1));
        for (int i = 0; i <= top; ++i)
            huffmanCode[root->data - 'a'].code[i] = arr[i] + '0';
        huffmanCode[root->data - 'a'].code[top + 1] = '\0';
    }
}

void printHuffmanCodes(char data[], int freq[], int size) {
    HuffmanCode huffmanCode[26];
    int arr[MAX_TREE_HT], top = 0;
    MinHeapNode *root = buildHuffmanTree(data, freq, size);
    printCodes(root, arr, top, huffmanCode);
    printf("Character\tFrequency\tHuffman Code\n\n");
    for (int i = 0; i < 26; ++i)
        if (huffmanCode[i].code != NULL)
            printf("%c\t\t%d\t\t%s\n", huffmanCode[i].character, freq[i], huffmanCode[i].code);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                   'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int freq[] = {3, 6, 23, 12, 23, 5, 7, 1, 2, 5, 4, 6, 12, 10, 20,
                  6, 0, 12, 15, 25, 3, 7, 21, 2, 4, 0};
    int size = sizeof(data) / sizeof(data[0]);
    printHuffmanCodes(data, freq, size);
    return 0;
}