//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct HuffmanNode {
    char symbol;
    int freq;
    struct HuffmanNode *left, *right;
}HuffmanNode;

typedef struct MinHeap {
    int size;
    int capacity;
    HuffmanNode **array;
}MinHeap;

HuffmanNode* newNode(char symbol, int freq){
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->symbol = symbol;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

MinHeap* initMinHeap(int capacity){
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HuffmanNode**)malloc(sizeof(HuffmanNode*) * heap->capacity);
    return heap;
}

void swap(HuffmanNode **a, HuffmanNode **b){
    HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if(right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if(smallest != index){
        swap(&heap->array[index], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

int isSizeOne(MinHeap* heap){
    return heap->size == 1;
}

HuffmanNode* extractMin(MinHeap* heap){
    HuffmanNode* node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return node;
}

void insertNode(MinHeap* heap, HuffmanNode* node){
    ++heap->size;
    int index = heap->size - 1;
    while(index && node->freq < heap->array[(index - 1) / 2]->freq){
        heap->array[index] = heap->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    heap->array[index] = node;
}

void buildMinHeap(MinHeap* heap){
    int n = heap->size - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; --i)
        minHeapify(heap, i);
}

int isLeaf(HuffmanNode* node){
    return node->left == NULL && node->right == NULL;
}

MinHeap* createAndBuildMinHeap(char symbol[], int freq[], int size){
    MinHeap* heap = initMinHeap(size);
    int i;
    for(i = 0; i < size; ++i)
        heap->array[i] = newNode(symbol[i], freq[i]);
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}

HuffmanNode* buildHuffmanTree(char symbol[], int freq[], int size){
    HuffmanNode *left, *right, *top;
    MinHeap* heap = createAndBuildMinHeap(symbol, freq, size);
    while(!isSizeOne(heap)){
        left = extractMin(heap);
        right = extractMin(heap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(heap, top);
    }
    return extractMin(heap);
}

void printCodes(HuffmanNode* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if(isLeaf(root)){
        printf("%c: ", root->symbol);
        int i;
        for(i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCodes(char symbol[], int freq[], int size){
    HuffmanNode* root = buildHuffmanTree(symbol, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main(){
    char symbol[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(symbol) / sizeof(symbol[0]);
    HuffmanCodes(symbol, freq, size);
    return 0;
}