//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** array;
} MinHeap;

typedef struct HuffmanNode {
    char data;
    char* code;
    struct HuffmanNode* next;
} HuffmanNode;

MinHeapNode* createMinHeapNode(char data, unsigned frequency) {
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (MinHeapNode**) malloc(heap->capacity * sizeof(MinHeapNode*));
    return heap;
}

void swapNodes(MinHeapNode** node1, MinHeapNode** node2) {
    MinHeapNode* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

void minHeapify(MinHeap* heap, int i) {
    int smallest = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;

    if (leftChild < heap->size && heap->array[leftChild]->frequency < heap->array[smallest]->frequency)
        smallest = leftChild;

    if (rightChild < heap->size && heap->array[rightChild]->frequency < heap->array[smallest]->frequency)
        smallest = rightChild;

    if (smallest != i) {
        swapNodes(&heap->array[i], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

bool isSizeOne(MinHeap* heap) {
    return heap->size == 1;
}

MinHeapNode* extractMin(MinHeap* heap) {
    MinHeapNode* minNode = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return minNode;
}

void insertMinHeap(MinHeap* heap, MinHeapNode* node) {
    ++heap->size;
    unsigned i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1)/2]->frequency) {
        heap->array[i] = heap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    heap->array[i] = node;
}

void buildMinHeap(MinHeap* heap) {
    int n = heap->size - 1;
    for (int i = (n - 1)/2; i >= 0; --i)
        minHeapify(heap, i);
}

void printCodes(MinHeapNode* root, char* code, HuffmanNode** list) {
    if (!root)
        return;

    if (root->data != '*') {
        HuffmanNode* node = (HuffmanNode*) malloc(sizeof(HuffmanNode));
        node->data = root->data;
        node->code = (char*) malloc(strlen(code) + 1);
        strcpy(node->code, code);
        node->next = NULL;

        if (*list == NULL)
            *list = node;
        else {
            HuffmanNode* tmp = *list;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = node;
        }
    }

    char* leftCode = (char*) malloc(strlen(code) + 2);
    strcpy(leftCode, code);
    strcat(leftCode, "0");
    printCodes(root->left, leftCode, list);

    char* rightCode = (char*) malloc(strlen(code) + 2);
    strcpy(rightCode, code);
    strcat(rightCode, "1");
    printCodes(root->right, rightCode, list);
}

void HuffmanCodes(char* data, int* freq, int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* heap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        insertMinHeap(heap, createMinHeapNode(data[i], freq[i]));

    buildMinHeap(heap);

    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);

        top = createMinHeapNode('*', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(heap, top);
    }

    HuffmanNode* list = NULL;

    printCodes(extractMin(heap), "", &list);

    printf("Huffman codes: \n");
    while (list != NULL) {
        printf("%c: %s\n", list->data, list->code);
        list = list->next;
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}