//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
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
    Node** array;
} MinHeap;

// Function prototypes
Node* createNode(char character, int frequency);
MinHeap* createMinHeap(int capacity);
void insertMinHeap(MinHeap* minHeap, Node* node);
Node* extractMin(MinHeap* minHeap);
MinHeap* buildMinHeap(char *data, int *freq, int size);
Node* buildHuffmanTree(char *data, int *freq, int size);
void printHuffmanCodes(Node* root, int code[], int top);
void compressFile(const char *inputFile, const char *outputFile);
void freeTree(Node* root);

int main() {
    const char *inputFile = "input.txt";
    const char *outputFile = "output.huff";

    compressFile(inputFile, outputFile);
    printf("Compression complete! Check the output file: %s\n", outputFile);

    return 0;
}

Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->array = (Node**)malloc(capacity * sizeof(Node*));
    return minHeap;
}

void swapNode(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->array[minHeap->size++] = node;
    int i = minHeap->size - 1;

    while (i && minHeap->array[i]->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        swapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    // MinHeapify downwards
    int i = 0, leftChild, rightChild, smallest;
    
    while (i < minHeap->size / 2) {
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
        smallest = i;

        if (leftChild < minHeap->size && minHeap->array[leftChild]->frequency < minHeap->array[smallest]->frequency) {
            smallest = leftChild;
        }
        if (rightChild < minHeap->size && minHeap->array[rightChild]->frequency < minHeap->array[smallest]->frequency) {
            smallest = rightChild;
        }
        if (smallest == i) break;

        swapNode(&minHeap->array[i], &minHeap->array[smallest]);
        i = smallest;
    }
    return temp;
}

MinHeap* buildMinHeap(char *data, int *freq, int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, createNode(data[i], freq[i]));
    }
    return minHeap;
}

Node* buildHuffmanTree(char *data, int *freq, int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = buildMinHeap(data, freq, size);
    
    while (minHeap->size > 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printHuffmanCodes(Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printHuffmanCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printHuffmanCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

void compressFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    if (!inFile) {
        printf("Could not open input file %s\n", inputFile);
        exit(EXIT_FAILURE);
    }

    int frequency[MAX_TREE_NODES] = {0};
    char data[MAX_TREE_NODES];
    int uniqueChars = 0;
    char ch;
    
    while ((ch = fgetc(inFile)) != EOF) {
        if (frequency[(unsigned char)ch] == 0) {
            data[uniqueChars++] = ch;
        }
        frequency[(unsigned char)ch]++;
    }
    
    fclose(inFile);

    Node* root = buildHuffmanTree(data, frequency, uniqueChars);
    int code[MAX_TREE_NODES], top = 0;
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, top);

    freeTree(root);
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}