//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char data;
    int freq;
    struct node *left, *right;
}node;

typedef struct heap {
    int size;
    int capacity;
    node **array;
}heap;

node* createNode(unsigned char data, int freq) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

heap* createHeap(int capacity) {
    heap* newHeap = (heap*)malloc(sizeof(heap));
    newHeap->size = 0;
    newHeap->capacity = capacity;
    newHeap->array = (node**)malloc(capacity * sizeof(node*));
    return newHeap;
}

void swapNode(node** a, node** b) {
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap* myHeap, int index) {
    int smallest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if(left < myHeap->size && myHeap->array[left]->freq < myHeap->array[smallest]->freq)
        smallest = left;
    if(right < myHeap->size && myHeap->array[right]->freq < myHeap->array[smallest]->freq)
        smallest = right;
    if(smallest != index) {
        swapNode(&myHeap->array[index], &myHeap->array[smallest]);
        heapify(myHeap, smallest);
    }
}

void insertHeap(heap* myHeap, node* newNode) {
    ++myHeap->size;
    int i = myHeap->size - 1;
    while(i > 0 && newNode->freq < myHeap->array[(i-1)/2]->freq) {
        myHeap->array[i] = myHeap->array[(i-1)/2];
        i = (i-1)/2;
    }
    myHeap->array[i] = newNode;
}

node* extractMinNode(heap* myHeap) {
    node* minNode = myHeap->array[0];
    myHeap->array[0] = myHeap->array[myHeap->size-1];
    --myHeap->size;
    heapify(myHeap, 0);
    return minNode;
}

int isLeafNode(node* root) {
    return !(root->left) && !(root->right);
}

heap* createHeapFromData(unsigned char *data, int *freq, int size) {
    heap* myHeap = createHeap(size);
    for(int i=0; i<size; ++i) {
        node* newNode = createNode(data[i], freq[i]);
        insertHeap(myHeap, newNode);
    }
    return myHeap;
}

node* buildHuffmanTree(unsigned char *data, int *freq, int size) {
    heap* myHeap = createHeapFromData(data, freq, size);
    while(myHeap->size > 1) {
        node* leftNode = extractMinNode(myHeap);
        node* rightNode = extractMinNode(myHeap);
        node* newNode = createNode('$', leftNode->freq + rightNode->freq);
        newNode->left = leftNode;
        newNode->right = rightNode;
        insertHeap(myHeap, newNode);
    }
    return extractMinNode(myHeap);
}

void printCodes(node* root, int arr[], int top) {
    if(root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    if(root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if(isLeafNode(root)) {
        printf("%c: ", root->data);
        for(int i=0; i<top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCodes(unsigned char *data, int *freq, int size) {
    node* root = buildHuffmanTree(data, freq, size);
    int arr[size], top=0;
    printCodes(root, arr, top);
}

int main() {
    unsigned char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}