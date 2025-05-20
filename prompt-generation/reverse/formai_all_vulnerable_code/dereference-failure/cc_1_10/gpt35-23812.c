//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

struct HuffmanTreeNode {
    char character;
    unsigned frequency;
    struct HuffmanTreeNode *left, *right;
};

struct HuffmanTreeHeap {
    unsigned size;
    unsigned capacity;
    struct HuffmanTreeNode **array;
};

struct HuffmanTreeNode *CreateHuffmanTreeNode(char ch, unsigned frequency) {
    struct HuffmanTreeNode *node = (struct HuffmanTreeNode *) malloc(sizeof (struct HuffmanTreeNode));
    node->character = ch;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

struct HuffmanTreeHeap *CreateHuffmanTreeHeap(unsigned capacity) {
    struct HuffmanTreeHeap *heap = (struct HuffmanTreeHeap *) malloc(sizeof (struct HuffmanTreeHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HuffmanTreeNode **) malloc(heap->capacity * sizeof (struct HuffmanTreeNode *));
    return heap;
}

void SwapHuffmanTreeHeapNodes(struct HuffmanTreeNode **a, struct HuffmanTreeNode **b) {
    struct HuffmanTreeNode *temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeapify(struct HuffmanTreeHeap *heap, int index) {
    int smallestIndex = index;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    if (leftIndex < heap->size &&
            heap->array[leftIndex]->frequency < heap->array[smallestIndex]->frequency)
        smallestIndex = leftIndex;

    if (rightIndex < heap->size &&
            heap->array[rightIndex]->frequency < heap->array[smallestIndex]->frequency)
        smallestIndex = rightIndex;

    if (smallestIndex != index) {
        SwapHuffmanTreeHeapNodes(&heap->array[smallestIndex], &heap->array[index]);
        MinHeapify(heap, smallestIndex);
    }
}

int IsSizeOne(struct HuffmanTreeHeap *heap) {
    return heap->size == 1;
}

struct HuffmanTreeNode *ExtractMin(struct HuffmanTreeHeap *heap) {
    struct HuffmanTreeNode *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    MinHeapify(heap, 0);
    return temp;
}

void InsertintoHuffmanTreeHeap(struct HuffmanTreeHeap *heap, struct HuffmanTreeNode *node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void BuildHuffmanTreeHeap(struct HuffmanTreeHeap *heap) {
    int n = heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        MinHeapify(heap, i);
}

struct HuffmanTreeNode *BuildHuffmanTree(char data[], int freq[], int size) {
    struct HuffmanTreeNode *left, *right, *top;
    struct HuffmanTreeHeap *heap = CreateHuffmanTreeHeap(size);
    for (int i = 0; i < size; ++i)
        InsertintoHuffmanTreeHeap(heap, CreateHuffmanTreeNode(data[i], freq[i]));
    BuildHuffmanTreeHeap(heap);
    while (!IsSizeOne(heap)) {
        left = ExtractMin(heap);
        right = ExtractMin(heap);

        top = CreateHuffmanTreeNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        InsertintoHuffmanTreeHeap(heap, top);
    }
    return ExtractMin(heap);
}

void PrintHuffmanTreeCode(struct HuffmanTreeNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        PrintHuffmanTreeCode(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        PrintHuffmanTreeCode(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCoding(char data[], int freq[], int size) {
    struct HuffmanTreeNode *root = BuildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    PrintHuffmanTreeCode(root, arr, top);
}

int main() {
    char str[] = "abcdefghijklmnopqrstuvwxyz ";
    int freq[] = {19, 6, 8, 4, 12, 2, 2, 6, 3, 12, 2, 7, 6, 10, 11, 3, 2, 8, 12, 3, 3, 5, 2, 5, 2, 11, 2};
    int size = sizeof (str) / sizeof (str[0]);

    HuffmanCoding(str, freq, size);

    return 0;
}