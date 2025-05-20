//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
 
typedef struct HuffmanTree {
    char data;
    unsigned freq;
    struct HuffmanTree *left, *right;
} HuffmanTree;
 
MinHeapNode *newMinHeapNode(char data, unsigned freq) {
    MinHeapNode *newnode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    newnode->left = newnode->right = NULL;
    newnode->data = data;
    newnode->freq = freq;
    return newnode;
}
 
MinHeap *createMinHeap(unsigned capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (MinHeapNode **)malloc(heap->capacity * sizeof(MinHeapNode *));
    return heap;
}
 
void swapMinHeapNodes(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}
 
void minHeapify(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}
 
bool isSizeOne(struct MinHeap *heap) {
    return heap->size == 1;
}
 
MinHeapNode *extractMin(MinHeap *heap) {
    MinHeapNode *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}
 
void insertMinHeap(MinHeap *heap, MinHeapNode *node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}
 
void buildMinHeap(MinHeap *heap) {
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2;i >= 0;--i) {
        minHeapify(heap, i);
    }
}
 
void printArr(int[],int);
 
int isLeaf(MinHeapNode *root) {
    return !(root->left) && !(root->right);
}
 
MinHeap *createAndBuildMinHeap(char data[],int freq[],int size) {
    MinHeap *heap = createMinHeap(size);
    for (int i = 0;i < size;++i) {
        heap->array[i] = newMinHeapNode(data[i], freq[i]);
    }
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}
 
HuffmanTree *buildHuffmanTree(char data[],int freq[],int size) {
    HuffmanTree *left, *right, *top;
    MinHeap *heap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = (HuffmanTree *)malloc(sizeof(HuffmanTree));
        top->data = '#';
        top->freq = left->freq + right->freq;
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap);
}
 
void printHuffmanCodes(HuffmanTree *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c\t\t", root->data);
        printArr(arr, top);
    }
}
 
void printArr(int arr[], int n) {
    for (int i = 0;i < n;++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void HuffmanCodes(char data[],int freq[],int size) {
    HuffmanTree *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT],top = 0;
    printf("Huffman Codes are:\n\n");
    printf("Symbol\t\tCode\n");
    printHuffmanCodes(root,arr,top);
}

int main() {
    char arr[] = {'A','B','C','D','E','F'};
    int freq[] = {5,9,12,13,16,45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}