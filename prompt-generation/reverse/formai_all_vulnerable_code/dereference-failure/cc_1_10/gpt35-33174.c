//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100
#define MAX_CHAR 256

typedef struct heapNode {
    char ch;
    unsigned freq;
    struct heapNode *left;
    struct heapNode *right;
} HeapNode;

typedef struct heap {
    unsigned size;
    unsigned capacity;
    HeapNode **array;
} Heap;

HeapNode *createHeapNode(char ch, unsigned freq) {
    HeapNode *node = (HeapNode *) malloc(sizeof(HeapNode));
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
  
    return node;
}

Heap *createHeap(unsigned capacity) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HeapNode **) malloc(heap->capacity * sizeof(HeapNode *));
  
    return heap;
}

void swapHeapNodes(HeapNode **a, HeapNode **b) {
    HeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Heap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapHeapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

bool isSizeOne(Heap *heap) {
    return heap->size == 1;
}

HeapNode *getMinHeapNode(Heap *heap) {
    HeapNode *node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    minHeapify(heap, 0);
    return node;
}

void insertHeapNode(Heap *heap, HeapNode *node) {
    heap->size++;
    int i = heap->size - 1;

    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->array[i] = node;
}

void buildMinHeap(Heap *heap) {
    int n = heap->size - 1;
    int i;
  
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(heap, i);
}

void printArr(int arr[], int n) {
    int i;
  
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
  
    printf("\n");
}

bool isLeaf(HeapNode *root) {
    return !(root->left) && !(root->right);
}

Heap *createAndBuildMinHeap(char ch[], int freq[], int size) {
    Heap *heap = createHeap(size);
  
    for (int i = 0; i < size; ++i)
        heap->array[i] = createHeapNode(ch[i], freq[i]);
  
    heap->size = size;
    buildMinHeap(heap);
  
    return heap;
}

HeapNode *buildHuffmanTree(char ch[], int freq[], int size) {
    HeapNode *left, *right, *top;
    Heap *heap = createAndBuildMinHeap(ch, freq, size);

    while (!isSizeOne(heap)) {
        left = getMinHeapNode(heap);
        right = getMinHeapNode(heap);
  
        top = createHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
  
        insertHeapNode(heap, top);
    }
    
    return getMinHeapNode(heap);
}

void printHuffmanCodes(HeapNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
  
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
  
    if (isLeaf(root)) {
        printf("%c: ", root->ch);
        printArr(arr, top);
    }
}

void huffmanCoding(char ch[], int freq[], int size) {
    HeapNode *root = buildHuffmanTree(ch, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, arr, top);
}

int main() {
    char ch[MAX_CHAR];
    int freq[MAX_CHAR], i, size;
  
    printf("Enter the string: ");
    scanf("%[^\n]", ch);
  
    size = strlen(ch);
  
    for (i = 0; i < size; ++i)
        freq[ch[i]]++;

    huffmanCoding(ch, freq, size);
  
    return 0;
}