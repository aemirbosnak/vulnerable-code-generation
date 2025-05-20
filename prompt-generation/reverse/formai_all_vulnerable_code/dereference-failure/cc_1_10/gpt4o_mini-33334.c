//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100
#define MAX_CHARACTERS 256

// Node structure
struct MinHeapNode {
    char character;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

// Min-Heap structure
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Function to create a new tree node
struct MinHeapNode* createNode(char character, unsigned frequency) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->character = character;
    temp->frequency = frequency;
    return temp;
}

// Function to create a Min Heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to swap two nodes of the Min Heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify the node at index `idx`
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if size of heap is 1
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum node from the heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a node into the Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to build the Min Heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Function to check if the given character is present in the array
int isPresent(char arr[], char ch, int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] == ch)
            return 1;
    return 0;
}

// Function to build the Huffman Tree
struct MinHeapNode* buildHuffmanTree(char characters[], int frequency[], int size) {
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(characters[i], frequency[i]);
    
    minHeap->size = size;
    buildMinHeap(minHeap);

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

// Function to print the Huffman codes recursively
void printCodes(struct MinHeapNode* root, char arr[], int top) {
    if (root->left) {
        arr[top] = '0';
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = '1';
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i)
            printf("%c", arr[i]);
        printf("\n");
    }
}

// Function to calculate frequency of characters
void calculateFrequency(char* str, char characters[], int frequency[], int* size) {
    int count[MAX_CHARACTERS] = {0};
    int index = 0;

    for (int i = 0; str[i]; ++i) {
        if (!isPresent(characters, str[i], index)) {
            characters[index] = str[i];
            frequency[index] = 1;
            index++;
        } else {
            frequency[index - 1]++;
        }
    }
    *size = index;
}

// Main function to demonstrate Huffman Coding
int main() {
    char str[100];
    printf("Enter the string to be encoded: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    char characters[MAX_CHARACTERS];
    int frequency[MAX_CHARACTERS];
    int size;

    calculateFrequency(str, characters, frequency, &size);

    struct MinHeapNode* root = buildHuffmanTree(characters, frequency, size);
    char arr[MAX_TREE_HEIGHT];
    printf("Huffman Codes:\n");
    printCodes(root, arr, 0);

    return 0;
}