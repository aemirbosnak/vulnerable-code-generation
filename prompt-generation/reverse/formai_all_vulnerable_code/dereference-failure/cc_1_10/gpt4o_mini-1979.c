//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

// Node structure for Huffman tree
struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
};

// Min heap structure
struct MinHeap {
    int size;
    struct Node *array[MAX_TREE_NODES];
};

// Function prototypes
struct Node* newNode(char character, unsigned frequency);
struct MinHeap* createMinHeap(int capacity);
void insertMinHeap(struct MinHeap* minHeap, struct Node* node);
void buildMinHeap(struct MinHeap* minHeap);
void minHeapify(struct MinHeap* minHeap, int idx);
struct Node* extractMin(struct MinHeap* minHeap);
int isSizeOne(struct MinHeap* minHeap);
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size);
void printHuffmanCodes(struct Node* root, int arr[], int top);
void HuffmanCodes(char characters[], int frequencies[], int size);
void destroyTree(struct Node* node);

void apocalypseSurvivor();

int main() {
    apocalypseSurvivor();
    return 0;
}

// Function implementations
void apocalypseSurvivor() {
    // In the aftermath, survival requires communication!
    char characters[] = {'s', 'e', 'c', 'r', 'e', 't', 'a', 'g', 'e'};
    int frequencies[] = {5, 9, 12, 13, 16, 45, 25, 19, 30};
  
    int size = sizeof(characters) / sizeof(characters[0]);
  
    // Build the Huffman tree and generate codes
    HuffmanCodes(characters, frequencies, size);
  
    // A fierce silence surrounds us, revealing the strength of our newfound codes.
}

struct Node* newNode(char character, unsigned frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->character = character;
    temp->frequency = frequency;
    return temp;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    minHeap->array[minHeap->size++] = node;
    buildMinHeap(minHeap);
}

void buildMinHeap(struct MinHeap* minHeap) {
    int i = (minHeap->size / 2) - 1;
    while (i >= 0) {
        minHeapify(minHeap, i);
        i--;
    }
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
        struct Node* temp = minHeap->array[smallest];
        minHeap->array[smallest] = minHeap->array[idx];
        minHeap->array[idx] = temp;
        minHeapify(minHeap, smallest);
    }
}

struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);
  
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, newNode(characters[i], frequencies[i]));
    }
  
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
  
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
  
        insertMinHeap(minHeap, top);
    }
  
    return extractMin(minHeap);
}

void printHuffmanCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
  
    if (!root->left && !root->right) {
        printf("Character: %c, Huffman Code: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCodes(char characters[], int frequencies[], int size) {
    struct Node* root = buildHuffmanTree(characters, frequencies, size);
    int arr[MAX_TREE_NODES], top = 0;
    printHuffmanCodes(root, arr, top);
    destroyTree(root);
}

void destroyTree(struct Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        free(node);
    }
}