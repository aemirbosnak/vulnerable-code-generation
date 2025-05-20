//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data;
    int frequency;
    struct Node *left, *right;
} Node;

typedef struct Heap{
    int heapSize;
    int capacity;
    Node** array;
} Heap;

Node* createNode(char data, int frequency){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Heap* createHeap(int capacity){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = capacity;
    heap->heapSize = 0;
    heap->array = (Node**)malloc(capacity*sizeof(Node*));
    return heap;
}

void swapNodes(Node** a, Node** b){
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Heap* heap, int index){
    int smallest = index;
    int leftChild = (2*index)+1;
    int rightChild = (2*index)+2;

    if(leftChild<heap->heapSize && heap->array[leftChild]->frequency < heap->array[smallest]->frequency){
        smallest = leftChild;
    }
    if(rightChild<heap->heapSize && heap->array[rightChild]->frequency < heap->array[smallest]->frequency){
        smallest = rightChild;
    }
    if(smallest!=index){
        swapNodes(&heap->array[smallest], &heap->array[index]);
        minHeapify(heap, smallest);
    }
}

int isSizeOne(Heap* heap){
    return heap->heapSize==1;
}

Node* extractMinNode(Heap* heap){
    Node* node = heap->array[0];
    heap->array[0] = heap->array[heap->heapSize-1];
    heap->heapSize--;
    minHeapify(heap, 0);
    return node;
}

void insertNode(Heap* heap, Node* node){
    heap->heapSize++;
    int index = heap->heapSize-1;
    while(index && node->frequency < heap->array[(index-1)/2]->frequency){
        heap->array[index] = heap->array[(index-1)/2];
        index = (index-1)/2;
    }
    heap->array[index] = node;
}

Heap* createAndBuildHeap(char data[], int frequency[], int size){
    Heap* heap = createHeap(size);
    for(int i=0; i<size; i++){
        heap->array[i] = createNode(data[i], frequency[i]);
    }
    heap->heapSize = size;
    for(int i=(heap->heapSize-1)/2; i>=0; i--){
        minHeapify(heap, i);
    }
    return heap;
}

Node* buildHuffmanTree(char data[], int frequency[], int size){
    Node *left, *right, *top;
    Heap* heap = createAndBuildHeap(data, frequency, size);
    while(!isSizeOne(heap)){
        left = extractMinNode(heap);
        right = extractMinNode(heap);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertNode(heap, top);
    }
    return extractMinNode(heap);
}

void printCodes(Node* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if(!root->left && !root->right){
        printf("%c : ", root->data);
        for(int i=0; i<top; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
    }

}

void huffmanCodes(char data[], int frequency[], int size){
    Node* root = buildHuffmanTree(data, frequency, size);
    int arr[100], top=0;
    printCodes(root, arr, top);
}

int main(){
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {23, 12, 9, 4, 5, 14};
    int size = sizeof(data)/sizeof(data[0]);
    huffmanCodes(data, frequency, size);
    return 0;
}