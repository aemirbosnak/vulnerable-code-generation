//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256

// Node structure for Huffman tree
typedef struct Node {
    char symbol;
    unsigned frequency;
    struct Node *left, *right;
} Node;

// Priority queue for Huffman tree construction
typedef struct PriorityQueue {
    Node **array;
    int size;
} PriorityQueue;

// Function to create a new node
Node* createNode(char symbol, unsigned frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a priority queue
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->array = (Node**)malloc(capacity * sizeof(Node*));
    return pq;
}

// Function to swap two nodes for priority queue management
void swap(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

// Function to min heapify the priority queue
void minHeapify(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->array[left]->frequency < pq->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < pq->size && pq->array[right]->frequency < pq->array[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&pq->array[smallest], &pq->array[idx]);
        minHeapify(pq, smallest);
    }
}

// Function to extract the minimum node from the priority queue
Node* extractMin(PriorityQueue* pq) {
    Node* temp = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);
    return temp;
}

// Function to insert a new node into the priority queue
void insert(PriorityQueue* pq, Node* node) {
    pq->size++;
    int i = pq->size - 1;
    pq->array[i] = node;

    while (i && pq->array[i]->frequency < pq->array[(i - 1) / 2]->frequency) {
        swap(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to check if the size of the priority queue is one
int isSizeOne(PriorityQueue* pq) {
    return pq->size == 1;
}

// Function to build the Huffman tree
Node* buildHuffmanTree(char* data, int* freq, int size) {
    Node *left, *right, *top;
    PriorityQueue* pq = createPriorityQueue(size);

    for (int i = 0; i < size; ++i) {
        insert(pq, createNode(data[i], freq[i]));
    }

    while (!isSizeOne(pq)) {
        left = extractMin(pq);
        right = extractMin(pq);

        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insert(pq, top);
    }

    return extractMin(pq);
}

// Function to store the Huffman codes
void storeCodes(Node* root, int arr[], int top, char codes[MAX_SYMBOLS][MAX_SYMBOLS]) {
    if (root->left) {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1, codes);
    }

    if (root->right) {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1, codes);
    }

    if (!root->left && !root->right) {
        codes[(unsigned char)root->symbol][0] = '\0';
        for (int i = 0; i < top; ++i) {
            codes[(unsigned char)root->symbol][i] = arr[i] + '0';
        }
        codes[(unsigned char)root->symbol][top] = '\0';
    }
}

// Function to print the Huffman codes
void printCodes(char data[], int freq[], int size) {
    Node* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_SYMBOLS], top = 0;
    char codes[MAX_SYMBOLS][MAX_SYMBOLS] = {0};

    storeCodes(root, arr, top, codes);

    printf("Symbol\tFrequency\tHuffman Code\n");
    for (int i = 0; i < size; ++i) {
        printf("%c\t%d\t\t%s\n", data[i], freq[i], codes[(unsigned char)data[i]]);
    }
}

// Example implementation
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    printCodes(data, freq, size);
    return 0;
}