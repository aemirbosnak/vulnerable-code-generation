//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_TREE_HT 100
typedef struct MinHeapNode{
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
}MinHeapNode;

typedef struct MinHeap{
    unsigned size;
    unsigned limit;
    MinHeapNode **heapArray;
}MinHeap;

MinHeapNode *newNode(char data, unsigned freq){
    MinHeapNode *temp = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

void swapNodes(MinHeapNode **a, MinHeapNode **b){
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && 
        minHeap->heapArray[left]->freq < minHeap->heapArray[smallest]->freq) 
        smallest = left;
 
    if (right < minHeap->size && 
        minHeap->heapArray[right]->freq < minHeap->heapArray[smallest]->freq) 
        smallest = right;
 
    if (smallest != index) {
        swapNodes(&minHeap->heapArray[smallest], &minHeap->heapArray[index]);
        minHeapify(minHeap, smallest);
    }
}
 
MinHeap* createMinHeap(int limit){
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->limit = limit;
    minHeap->heapArray =
        (MinHeapNode**)malloc(minHeap->limit * sizeof(MinHeapNode*));
    return minHeap;
}

void insertMinHeapNode(MinHeap* minHeap, MinHeapNode* minHeapNode){
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->heapArray[(i - 1) / 2]->freq) {
        minHeap->heapArray[i] = minHeap->heapArray[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->heapArray[i] = minHeapNode;
}

MinHeapNode* extractMinHeapNode(MinHeap* minHeap){
    MinHeapNode* temp = minHeap->heapArray[0];
    minHeap->heapArray[0] = minHeap->heapArray[minHeap->size - 1];
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return temp;
}

int leafNode(MinHeapNode* root){
    return !(root->left) && !(root->right);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->heapArray[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    int i;
    for (i = (minHeap->size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (minHeap->size != 1) {
        left = extractMinHeapNode(minHeap);
        right = extractMinHeapNode(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right; 
        insertMinHeapNode(minHeap, top);
    }
    return extractMinHeapNode(minHeap);
}

void printCodes(MinHeapNode* root, int arr[], int top){
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (leafNode(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCodes(char data[], int freq[], int size){
    MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main(){
    char data[6]={'A','B','C','D','E','F'};
    int freq[6] ={5,9,12,13,16,45};
    int size=sizeof(data)/sizeof(data[0]);
    HuffmanCodes(data,freq,size);
    return 0;
}