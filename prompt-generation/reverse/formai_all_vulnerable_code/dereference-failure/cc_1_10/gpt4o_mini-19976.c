//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the Huffman Tree
struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
};

// Function to allocate a new node
struct Node* newNode(char character, unsigned frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a min-heap of given capacity
struct Node** createMinHeap(unsigned capacity) {
    return (struct Node**)malloc(capacity * sizeof(struct Node*));
}

// Function to swap two min-heap nodes
void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Function to min-heapify the node at index i
void minHeapify(struct Node** minHeap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && minHeap[left]->frequency < minHeap[smallest]->frequency)
        smallest = left;

    if (right < size && minHeap[right]->frequency < minHeap[smallest]->frequency)
        smallest = right;

    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapify(minHeap, size, smallest);
    }
}

// Function to build the min-heap
void buildMinHeap(struct Node** minHeap, int size) {
    int startIdx = (size / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        minHeapify(minHeap, size, i);
    }
}

// Function to insert a new node into the min-heap
void insertMinHeap(struct Node** minHeap, int *size, struct Node* newNode) {
    minHeap[*size] = newNode;
    (*size)++;
    for (int i = (*size - 1) / 2; i >= 0; i--) {
        minHeapify(minHeap, *size, i);
    }
}

// Function to extract the minimum node from the min-heap
struct Node* extractMin(struct Node** minHeap, int *size) {
    struct Node* root = minHeap[0];
    minHeap[0] = minHeap[*size - 1];
    (*size)--;
    minHeapify(minHeap, *size, 0);
    return root;
}

// Function to build the Huffman Tree
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    struct Node **minHeap = createMinHeap(size);
    int heapSize = 0;

    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, &heapSize, newNode(characters[i], frequencies[i]));
    }

    while (heapSize != 1) {
        struct Node* left = extractMin(minHeap, &heapSize);
        struct Node* right = extractMin(minHeap, &heapSize);

        struct Node* combined = newNode('$', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;

        insertMinHeap(minHeap, &heapSize, combined);
    }
    return extractMin(minHeap, &heapSize);
}

// Function to print the Huffman Codes
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
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to free the Huffman Tree memory
void freeHuffmanTree(struct Node* root) {
    if (root != NULL) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e' };
    int frequencies[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(characters) / sizeof(characters[0]);

    struct Node* root = buildHuffmanTree(characters, frequencies, size);

    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    freeHuffmanTree(root);
    return 0;
}