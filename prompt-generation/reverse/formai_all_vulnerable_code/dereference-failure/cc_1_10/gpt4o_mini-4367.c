//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node **array;
} MinHeap;

Node *createNode(char character, unsigned frequency) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeap *createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node **)malloc(minHeap->capacity * sizeof(Node *));
    return minHeap;
}

void swapNode(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx) {
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
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node *extractMin(MinHeap *minHeap) {
    Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap *minHeap, Node *minNode) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && minNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minNode;
}

int isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

MinHeap *createAndBuildMinHeap(char data[], int frequency[], int size) {
    MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++) {
        minHeap->array[i] = createNode(data[i], frequency[i]);
    }
    minHeap->size = size;
    for (int i = (minHeap->size - 1) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
    return minHeap;
}

Node *buildHuffmanTree(char data[], int frequency[], int size) {
    Node *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(data, frequency, size);
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

void printArr(int arr[], int top) {
    for (int i = 0; i < top; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void HuffmanCodes(Node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        HuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        HuffmanCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->character);
        printArr(arr, top);
    }
}

void freeNodes(Node *root) {
    if (root == NULL) return;
    freeNodes(root->left);
    freeNodes(root->right);
    free(root);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = buildHuffmanTree(arr, freq, size);

    int arrCode[MAX_TREE_NODES], top = 0;
    printf("Huffman Codes:\n");
    HuffmanCodes(root, arrCode, top);

    freeNodes(root);
    return 0;
}