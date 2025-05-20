//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct MinHeap {
    unsigned size;
    Node* array[MAX_TREE_NODES];
} MinHeap;

Node* createNode(char character, unsigned frequency) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&minHeap->array[smallest], &minHeap->array[index]);
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
    int current = minHeap->size;
    minHeap->size++;
    while (current && minHeap->array[current]->frequency < minHeap->array[(current - 1) / 2]->frequency) {
        swap(&minHeap->array[current], &minHeap->array[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

MinHeap* buildMinHeap(char data[], int frequency[], int size) {
    MinHeap* minHeap = createMinHeap();
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(data[i], frequency[i]));
    }
    return minHeap;
}

Node* buildHuffmanTree(char data[], int frequency[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = buildMinHeap(data, frequency, size);
    
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

void printHuffmanCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void freeHuffmanTree(Node* root) {
    if (root) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequency[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    Node* root = buildHuffmanTree(data, frequency, size);
    int arr[MAX_TREE_NODES], top = 0;

    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);

    freeHuffmanTree(root);
    return 0;
}