//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the Huffman Tree nodes
struct Node {
    char character;
    unsigned frequency;
    struct Node* left;
    struct Node* right;
};

// Structure for the min-heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct Node** array;
};

// Function prototypes
struct Node* createNode(char character, unsigned frequency);
struct MinHeap* createMinHeap(unsigned capacity);
void swapNode(struct Node** a, struct Node** b);
void minHeapify(struct MinHeap* minHeap, int idx);
int isSizeOne(struct MinHeap* minHeap);
struct Node* extractMin(struct MinHeap* minHeap);
void insertMinHeap(struct MinHeap* minHeap, struct Node* minHeapNode);
void buildMinHeap(struct MinHeap* minHeap);
void printArr(int arr[], int top);
void printCodes(struct Node* root, int arr[], int top);
struct MinHeap* createAndBuildMinHeap(char characters[], int freq[], int size);
struct Node* buildHuffmanTree(char characters[], int freq[], int size);
void HuffmanCodes(char characters[], int freq[], int size);

int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(characters) / sizeof(characters[0]);

    HuffmanCodes(characters, freq, size);
    return 0;
}

struct Node* createNode(char character, unsigned frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

void swapNode(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
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

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct Node* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

void printArr(int arr[], int top) {
    for (int i = 0; i < top; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

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
        printf("%c: ", root->character);
        printArr(arr, top);
    }
}

struct MinHeap* createAndBuildMinHeap(char characters[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = createNode(characters[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct Node* buildHuffmanTree(char characters[], int freq[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(characters, freq, size);

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

void HuffmanCodes(char characters[], int freq[], int size) {
    struct Node* root = buildHuffmanTree(characters, freq, size);
    int arr[100], top = 0;
    printCodes(root, arr, top);
}