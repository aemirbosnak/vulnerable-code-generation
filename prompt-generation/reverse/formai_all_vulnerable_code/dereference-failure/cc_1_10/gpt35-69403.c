//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MinHeapNode {
    char data;
    int freq;
    struct MinHeapNode* left;
    struct MinHeapNode* right;
};

struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* createNode(char data, int freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (struct MinHeapNode**)malloc(heap->capacity * sizeof(struct MinHeapNode*));
    return heap;
}

void swapNodes(struct MinHeapNode** x, struct MinHeapNode** y) {
    struct MinHeapNode* temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(struct MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != index) {
        swapNodes(&heap->array[smallest], &heap->array[index]);
        minHeapify(heap, smallest);
    }
}

int isSizeOne(struct MinHeap* heap) {
    return heap->size == 1;
}

int isLeaf(struct MinHeapNode* node) {
    return !(node->left) && !(node->right);
}

struct MinHeapNode* extractMin(struct MinHeap* heap) {
    struct MinHeapNode* minNode = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return minNode;
}

void insertMinHeap(struct MinHeap* heap, struct MinHeapNode* node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void buildMinHeap(struct MinHeap* heap) {
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; i--) {
        minHeapify(heap, i);
    }
}

struct MinHeapNode* buildHuffmanTree(char* data, int* freq, int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; i++) {
        insertMinHeap(heap, createNode(data[i], freq[i]));
    }
    buildMinHeap(heap);
    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap);
}

int isBitSet(char byte, int position) {
    return ((byte >> position) & 1);
}

void printCodes(struct MinHeapNode* root, int* arr, int top) {
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
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffmanCodes(char* data, int* freq, int size) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    huffmanCodes(data, freq, size);
    return 0;
}