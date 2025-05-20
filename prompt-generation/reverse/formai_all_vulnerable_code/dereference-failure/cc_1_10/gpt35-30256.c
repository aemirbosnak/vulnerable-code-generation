//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 100

// Define a node structure for creating a Huffman Tree
typedef struct Node {
    char data;
    unsigned frequency;
    struct Node *left, *right;
} Node;

// Define a structure for creating a min heap
typedef struct MinHeap {
    int size;
    int capacity;
    Node **array;
} MinHeap;

// Function to allocate a new node
Node* newNode(char data, unsigned frequency) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// Function to create a new min heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Node**) malloc(heap->capacity * sizeof(Node*));
    return heap;
}

// Function to swap two nodes in the min heap
void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min heap property
void minHeapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)
        smallest = left;
    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)
        smallest = right;
    if (smallest != index) {
        swapNodes(&heap->array[smallest], &heap->array[index]);
        minHeapify(heap, smallest);
    }
}

// Function to check if the heap contains only one node
int isSizeOne(MinHeap* heap) {
    return (heap->size == 1);
}

// Function to extract the minimum value node from the heap
Node* extractMinimum(MinHeap* heap) {
    Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

// Function to insert a new node into the heap
void insertNode(MinHeap* heap, Node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Function to build a min heap
void buildMinHeap(MinHeap* heap) {
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(heap, i);
}

// Function to check if a node is a leaf node
int isLeaf(Node* node) {
    return !(node->left) && !(node->right);
}

// Function to create a min heap and build a Huffman tree from the given characters and their frequencies
Node* buildHuffmanTree(char data[], int frequency[], int size) {
    Node *left, *right, *top;
    MinHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        insertNode(heap, newNode(data[i], frequency[i]));
    buildMinHeap(heap);
    while (!isSizeOne(heap)) {
        left = extractMinimum(heap);
        right = extractMinimum(heap);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertNode(heap, top);
    }
    return extractMinimum(heap);
}

// Function to print the Huffman codes
void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c : ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to perform Huffman coding on the given input string
void performCoding(char input[]) {
    int length = strlen(input);
    char data[length];
    int frequency[length];
    int uniqueCharacters = 0;
    for (int i = 0; i < length; ++i) {
        int flag = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (input[i] == input[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            data[uniqueCharacters] = input[i];
            frequency[uniqueCharacters] = 1;
            for (int k = i + 1; k < length; ++k) {
                if (input[k] == input[i])
                    ++frequency[uniqueCharacters];
            }
            ++uniqueCharacters;
        }
    }
    Node* root = buildHuffmanTree(data, frequency, uniqueCharacters);
    int arr[MAX_LENGTH], top = 0;
    printCodes(root, arr, top);
}

// Main function to accept user input and perform Huffman coding
int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to perform Huffman coding: ");
    fgets(input, MAX_LENGTH, stdin);
    performCoding(input);
    return 0;
}