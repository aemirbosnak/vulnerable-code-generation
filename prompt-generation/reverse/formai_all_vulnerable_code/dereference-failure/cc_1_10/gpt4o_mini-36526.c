//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct MinHeap {
    int size;
    Node *array[MAX_TREE_NODES];
} MinHeap;

Node* createNode(char character, int frequency) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap() {
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) {
        return NULL;
    }
    Node* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return root;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->array[minHeap->size] = node;
    int idx = minHeap->size;
    minHeap->size++;

    while (idx && minHeap->array[idx]->frequency < minHeap->array[(idx - 1) / 2]->frequency) {
        swapNodes(&minHeap->array[idx], &minHeap->array[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

MinHeap* buildMinHeap(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = createMinHeap();
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));
    }
    return minHeap;
}

Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = buildMinHeap(characters, frequencies, size);
    while (minHeap->size > 1) {
        Node* left = extractMin(minHeap);
        Node* right = extractMin(minHeap);
        Node* combined = createNode('\0', left->frequency + right->frequency);
        
        combined->left = left;
        combined->right = right;

        insertMinHeap(minHeap, combined);
    }
    return extractMin(minHeap);
}

void printHuffmanCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e'};
    int frequencies[] = {5, 9, 12, 13, 16};
    int size = sizeof(characters) / sizeof(characters[0]);

    Node* root = buildHuffmanTree(characters, frequencies, size);
    int arr[MAX_TREE_NODES], top = 0;

    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);
    
    return 0;
}