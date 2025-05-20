//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    int size;
    Node *array[MAX_TREE_NODES];
} MinHeap;

Node* createNode(char character, unsigned frequency) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap() {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void swapNode(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < minHeap->size && minHeap->array[leftChild]->frequency < minHeap->array[smallest]->frequency) {
        smallest = leftChild;
    }
    if (rightChild < minHeap->size && minHeap->array[rightChild]->frequency < minHeap->array[smallest]->frequency) {
        smallest = rightChild;
    }
    if (smallest != index) {
        swapNode(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(MinHeap *minHeap) {
    if (minHeap->size == 0) return NULL;
    Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap *minHeap, Node *node) {
    minHeap->array[minHeap->size] = node;
    int current = minHeap->size++;
    while (current && minHeap->array[current]->frequency < minHeap->array[(current - 1) / 2]->frequency) {
        swapNode(&minHeap->array[current], &minHeap->array[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

int isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

Node* buildHuffmanTree(char data[], int frequency[], int size) {
    Node *left, *right, *top;
    MinHeap *minHeap = createMinHeap();
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(data[i], frequency[i]));
    }
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(Node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCodes(char data[], int frequency[], int size) {
    Node *root = buildHuffmanTree(data, frequency, size);
    int arr[MAX_TREE_NODES], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int frequency[] = {5, 9, 12, 13, 16};
    int size = sizeof(data) / sizeof(data[0]);
    HuffmanCodes(data, frequency, size);
    return 0;
}