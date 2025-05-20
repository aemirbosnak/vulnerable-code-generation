//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256 // Maximum number of nodes in the Huffman tree
#define MAX_CODE_LENGTH 256 // Maximum length of the encoded bits

// Structure to represent a Huffman tree node
struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
};

// Structure for a Min-Heap to keep track of nodes
struct MinHeap {
    int size;
    struct Node *array[MAX_TREE_NODES];
};

// Function to create a new tree node
struct Node* createNode(char character, int frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a Min-Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    for (int i = 0; i < capacity; i++) {
        minHeap->array[i] = NULL;
    }
    return minHeap;
}

// Function to swap two nodes
void swapNode(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify the Min-Heap
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

// Function to check if the size of the heap is 1
int isSizeOne(struct MinHeap* minHeap) {
    return minHeap->size == 1;
}

// Function to extract the minimum node from the heap
struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a node into the Min-Heap
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    minHeap->array[minHeap->size] = node;
    int i = minHeap->size;
    minHeap->size++;
    
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    struct Node *left, *right, *top;

    struct MinHeap* minHeap = createMinHeap(size);

    // Create an initial Min-Heap
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));
    }

    // Build the Huffman Tree
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap); // Return the root of the tree
}

// Function to print the Huffman Codes
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
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Function to decode the encoded string
void decode(struct Node* root, char* encodedString) {
    struct Node* current = root;
    for (int i = 0; encodedString[i]; i++) {
        if (encodedString[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        
        // When leaf node is reached
        if (!current->left && !current->right) {
            printf("%c", current->character);
            current = root; // reset to the root
        }
    }
    printf("\n");
}

// Main function to demonstrate Huffman coding
int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);
    
    // Build Huffman Tree
    struct Node* root = buildHuffmanTree(characters, frequencies, size);
    
    // Print Huffman Codes
    int arr[MAX_CODE_LENGTH], top = 0;
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);
    
    // Example of decoding
    char encodedString[] = "110011101"; // Example encoded string
    printf("\nDecoded String: ");
    decode(root, encodedString);
    
    return 0;
}