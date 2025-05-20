//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LENGTH 32

typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    int size;
    Node *array[MAX_TREE_NODES];
} MinHeap;

Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
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
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

int isLeaf(Node* node) {
    return !(node->left) && !(node->right);
}

Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = createMinHeap();
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));
    }

    while (minHeap->size != 1) {
        Node* left = extractMin(minHeap);
        Node* right = extractMin(minHeap);
        Node* newNode = createNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        insertMinHeap(minHeap, newNode);
    }
    return extractMin(minHeap);
}

void generateCodes(Node* root, int arr[], int top, char codes[][MAX_CODE_LENGTH]) {
    if (root->left) {
        arr[top] = 0;
        generateCodes(root->left, arr, top + 1, codes);
    }
    if (root->right) {
        arr[top] = 1;
        generateCodes(root->right, arr, top + 1, codes);
    }
    if (isLeaf(root)) {
        codes[(unsigned char)root->character][0] = '\0';
        for (int i = 0; i < top; i++) {
            strncat(codes[(unsigned char)root->character], arr[i] ? "1" : "0", MAX_CODE_LENGTH - 1);
        }
    }
}

void printCodes(char characters[], char codes[][MAX_CODE_LENGTH], int size) {
    printf("Character Huffman Codes:\n");
    for (int i = 0; i < size; i++) {
        printf("%c: %s\n", characters[i], codes[(unsigned char)characters[i]]);
    }
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e'};
    int frequencies[] = {5, 9, 12, 13, 16};
    int size = sizeof(characters) / sizeof(characters[0]);

    Node* root = buildHuffmanTree(characters, frequencies, size);
    char codes[MAX_TREE_NODES][MAX_CODE_LENGTH] = {0};
    int arr[MAX_CODE_LENGTH], top = 0;

    generateCodes(root, arr, top, codes);
    printCodes(characters, codes, size);

    // Free memory omitted for brevity
    return 0;
}