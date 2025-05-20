//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

typedef struct minHeapNode {
    char data;
    unsigned frequency;
    struct minHeapNode *left, *right;
} MinHeapNode;

typedef struct minHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

typedef struct code {
    char data;
    char *code;
} Code;

MinHeapNode *newMinHeapNode(char data, unsigned frequency) {
    MinHeapNode *node = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

MinHeap *createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode **)malloc(minHeap->capacity * sizeof(MinHeapNode *));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size &&
        minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < minHeap->size &&
        minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode *extractMin(MinHeap *minHeap) {
    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap *minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

void printArr(int arr[], int n, char *code) {
    int i;
    Code newCode;
    newCode.data = *code;
    newCode.code = (char *)malloc(n * sizeof(char));
    for (i = 0; i < n; ++i) {
        newCode.code[i] = (char)(arr[i] + '0');
    }
    newCode.code[i] = '\0';
    printf("%c:%s\n", newCode.data, newCode.code);
}

int isLeaf(MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

void printCodes(MinHeapNode *root, int arr[], int top, char *code, Code codes[]) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, code, codes);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, code, codes);
    }
    if (isLeaf(root)) {
        printArr(arr, top, code);
        int index = root->data - 'a';
        codes[index] = (Code){
            .data = root->data,
            .code = (char *)malloc(top * sizeof(char))
        };
        memcpy(codes[index].code, arr, top * sizeof(char));
    }
}

void huffmanCodes(char *data, int *freq, int size, Code codes[]) {
    MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newMinHeapNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    while (!isSizeOne(minHeap)) {
        MinHeapNode *left = extractMin(minHeap);
        MinHeapNode *right = extractMin(minHeap);
        MinHeapNode *top = newMinHeapNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    int arr[MAX_TREE_HT], top = 0;
    printCodes(minHeap->array[0], arr, top, data, codes);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    Code codes[size];
    huffmanCodes(data, freq, size, codes);
    return 0;
}