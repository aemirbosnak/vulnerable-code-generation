//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100
#define MAX_CHAR 256

// Structure for Huffman Tree nodes
struct Node {
    char character;
    unsigned frequency;
    struct Node *left;
    struct Node *right;
};

// Min-Heap structure
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct Node **array;
};

// Function prototypes
struct Node* createNode(char character, unsigned frequency);
struct MinHeap* createMinHeap(unsigned capacity);
void swapNode(struct Node** a, struct Node** b);
void minHeapify(struct MinHeap* minHeap, int index);
int isSizeOne(struct MinHeap* minHeap);
struct Node* extractMin(struct MinHeap* minHeap);
void insertMinHeap(struct MinHeap* minHeap, struct Node* node);
void buildMinHeap(struct MinHeap* minHeap);
struct MinHeap* createAndBuildMinHeap(char characters[], int frequencies[], int size);
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size);
void printCodes(struct Node* root, int arr[], int top);
void HuffmanCodes(char characters[], int frequencies[], int size);
void freeHuffmanTree(struct Node* root);

// Function definitions
struct Node* createNode(char character, unsigned frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
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

void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapNode(&minHeap->array[smallest], &minHeap->array[index]);
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

void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

struct MinHeap* createAndBuildMinHeap(char characters[], int frequencies[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(characters[i], frequencies[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(characters, frequencies, size);
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

void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("Character: %c | Code: ", root->character);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCodes(char characters[], int frequencies[], int size) {
    struct Node* root = buildHuffmanTree(characters, frequencies, size);
    int arr[MAX_TREE_HEIGHT], top = 0;
    printCodes(root, arr, top);
    freeHuffmanTree(root);
}

void freeHuffmanTree(struct Node* root) {
    if (root == NULL)
        return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}

int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequencies[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(characters) / sizeof(characters[0]);
    printf("Huffman Codes:\n");
    HuffmanCodes(characters, frequencies, size);
    return 0;
}