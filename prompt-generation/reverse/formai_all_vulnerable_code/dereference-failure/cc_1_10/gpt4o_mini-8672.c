//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A joyful struct that represents a node in the Huffman tree
struct Node {
    char data;                // The character we are encoding
    unsigned freq;           // Frequency of the character
    struct Node *left, *right; // Child nodes for Huffman tree
};

// A fun comparator function for the priority queue (min heap)
struct Node* createNode(char data, unsigned freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Node comparison for priority queue sorting (by frequency)
struct PriorityQueue {
    int size;
    int capacity;
    struct Node** array;
};

// A cheerful function to create a priority queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->array = (struct Node**)malloc(pq->capacity * sizeof(struct Node*));
    return pq;
}

// Fun function to swap nodes in the priority queue
void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// A jolly function to heapify the priority queue
void minHeapify(struct PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->array[left]->freq < pq->array[smallest]->freq)
        smallest = left;
  
    if (right < pq->size && pq->array[right]->freq < pq->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->array[smallest], &pq->array[idx]);
        minHeapify(pq, smallest);
    }
}

// Yay! Extract the minimum node
struct Node* extractMin(struct PriorityQueue* pq) {
    struct Node* temp = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);
    return temp;
}

// A delightful function to insert a node into the priority queue
void insertPriorityQueue(struct PriorityQueue* pq, struct Node* node) {
    pq->size++;
    int i = pq->size - 1;

    while (i && node->freq < pq->array[(i - 1) / 2]->freq) {
        pq->array[i] = pq->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->array[i] = node;
}

// A vibrant function to build the Huffman tree
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node* left, *right, *top;
    
    struct PriorityQueue* pq = createPriorityQueue(size);
    
    for (int i = 0; i < size; ++i)
        insertPriorityQueue(pq, createNode(data[i], freq[i]));

    while (pq->size != 1) {
        left = extractMin(pq);
        right = extractMin(pq);

        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertPriorityQueue(pq, top);
    }
    return extractMin(pq);
}

// A bright array to hold the codes
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Our cheerful main function
int main() {
    printf("Welcome to the Magical World of Huffman Coding!\n");
    char arr[] = { 'a', 'b', 'c', 'd', 'e' };
    int freq[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = buildHuffmanTree(arr, freq, size);
    int arrCode[100], top = 0;

    printf("And here are the codes for your characters:\n");
    printCodes(root, arrCode, top);

    return 0;
}