//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

// Structure for a tree node
struct Node {
    char character;  // Character stored in this node
    int frequency;   // Frequency of the character
    struct Node *left, *right;  // Left and right child nodes
};

// Structure for the min heap
struct MinHeap {
    int size;
    struct Node *array[MAX_TREE_NODES];
};

// Function prototypes
struct Node* createNode(char character, int frequency);
struct MinHeap* createMinHeap(int capacity);
void insertMinHeap(struct MinHeap* minHeap, struct Node* node);
struct Node* extractMin(struct MinHeap* minHeap);
void buildMinHeap(struct MinHeap* minHeap);
void printCodes(struct Node* root, int code[], int top);
void freeTree(struct Node* root);
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size);

int main() {
    char characters[] = "abcdef";
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);

    struct Node* root = buildHuffmanTree(characters, frequencies, size);
    
    int code[MAX_TREE_NODES], top = 0;
    printCodes(root, code, top);
    
    freeTree(root);
    return 0;
}

// Create a new node with a character and its frequency
struct Node* createNode(char character, int frequency) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Create a min heap of given capacity
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    return minHeap;
}

// Insert a new node into the Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    minHeap->array[minHeap->size] = node;
    int index = minHeap->size;
    minHeap->size++;

    while (index && node->frequency < minHeap->array[(index - 1) / 2]->frequency) {
        minHeap->array[index] = minHeap->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    minHeap->array[index] = node;
}

// Extract the minimum node from the Min Heap
struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    buildMinHeap(minHeap);
    return temp;
}

// Build the min heap using the frequencies
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
            smallest = left;
        }
        if (right < n && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
            smallest = right;
        }
        if (smallest != i) {
            struct Node* temp = minHeap->array[i];
            minHeap->array[i] = minHeap->array[smallest];
            minHeap->array[smallest] = temp;
        }
    }
}

// Print the codes from the Huffman tree
void printCodes(struct Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

// Free the allocated memory for tree nodes
void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Build and return the Huffman Tree
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));
    }

    while (minHeap->size > 1) {
        struct Node* left = extractMin(minHeap);
        struct Node* right = extractMin(minHeap);
        struct Node* merged = createNode('$', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;
        insertMinHeap(minHeap, merged);
    }

    struct Node* root = extractMin(minHeap);
    free(minHeap); // Deallocate the minHeap structure
    return root;
}