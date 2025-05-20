//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100
#define MAX_ELEMENTS 256

typedef struct HuffmanNode {
    char data;
    int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

typedef struct {
    HuffmanNode *array[MAX_ELEMENTS];
    int size;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void swapHuffmanNode(HuffmanNode **a, HuffmanNode **b) {
    HuffmanNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx) {
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
        swapHuffmanNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

HuffmanNode* extractMin(MinHeap *minHeap) {
    HuffmanNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap *minHeap, HuffmanNode *node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    
    minHeap->array[i] = node;
}

MinHeap* buildMinHeap(char data[], int freq[], int size) {
    MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++) {
        HuffmanNode *node = (HuffmanNode *) malloc(sizeof(HuffmanNode));
        node->data = data[i];
        node->freq = freq[i];
        node->left = node->right = NULL;
        insertMinHeap(minHeap, node);
    }
    return minHeap;
}

HuffmanNode* buildHuffmanTree(char data[], int freq[], int size) {
    HuffmanNode *left, *right, *top;
    
    MinHeap *minHeap = buildMinHeap(data, freq, size);
    
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = (HuffmanNode *) malloc(sizeof(HuffmanNode));
        top->data = '$'; // Internal node
        top->freq = left->freq + right->freq;
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(HuffmanNode *root, int *arr, int top) {
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
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    HuffmanNode *root = buildHuffmanTree(data, freq, size);
    
    int arr[MAX_TREE_HEIGHT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {5, 9, 12, 13, 16};
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanCodes(data, freq, size);
    return 0;
}