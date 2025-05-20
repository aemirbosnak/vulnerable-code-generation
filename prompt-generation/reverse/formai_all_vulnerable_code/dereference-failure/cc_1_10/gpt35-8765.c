//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// structure to store a Huffman tree node
struct MinHeapNode {
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

// structure to store a Min Heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// create a new Min Heap Node
struct MinHeapNode* newNode(char data, unsigned frequency){
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// create a new Min Heap
struct MinHeap* createMinHeap(unsigned capacity){
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// swap two Min Heap Nodes
void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b){
    struct MinHeapNode* tmp = *a;
    *a = *b;
    *b = tmp;
}

// heapify the passed Min Heap
void heapify(struct MinHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx){
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        heapify(minHeap, smallest);
    }
}

// check if size of heap is 1
int isSizeOne(struct MinHeap* minHeap){
    return (minHeap->size == 1);
}

// extract the minimum frequency node from Min Heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    heapify(minHeap, 0);
    return temp;
}

// insert a node into Min Heap
void insertNode(struct MinHeap* minHeap, struct MinHeapNode* node){
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency){
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// build a Min Heap and return root of heap
struct MinHeapNode* buildMinHeap(char data[], int freq[], int size){
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        heapify(minHeap, i);
    return extractMin(minHeap);
}

// print tree node with its code
void printCodes(struct MinHeapNode* root, int arr[], int top){
    if (root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL){
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) printf("%d", arr[i]);
        printf("\n");
    }
}

// build Huffman Tree and print codes for given data and its frequencies
void HuffmanCodes(char data[], int freq[], int size){
    struct MinHeapNode* root = buildMinHeap(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main(){
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}