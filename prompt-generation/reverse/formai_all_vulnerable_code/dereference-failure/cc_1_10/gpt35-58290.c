//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100

// A Huffman tree node
struct minHeapNode {
    char data;
    int freq;
    struct minHeapNode *left, *right;
};

// A min heap node
struct minHeap {
    int size;
    int capacity;
    struct minHeapNode **array;
};

// Create a new min heap node
struct minHeapNode* newNode(char data, int freq) {
    struct minHeapNode* node = (struct minHeapNode*) malloc(sizeof(struct minHeapNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a new min heap with given capacity
struct minHeap* createMinHeap(int capacity) {
    struct minHeap* minHeap = (struct minHeap*) malloc(sizeof(struct minHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct minHeapNode**) malloc(minHeap->capacity * sizeof(struct minHeapNode*));
    return minHeap;
}

// Swap two min heap nodes
void swapNodes(struct minHeapNode** a, struct minHeapNode** b) {
    struct minHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify a min heap
void heapify(struct minHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != index) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);
        heapify(minHeap, smallest);
    }
}

// Check if a given node is a leaf node
int isLeaf(struct minHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Create a min heap from given array of min heap nodes
struct minHeap* buildMinHeap(char data[], int freq[], int size) {
    struct minHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; i++) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }

    minHeap->size = size;

    for (int i = minHeap->size / 2 - 1; i >= 0; i--) {
        heapify(minHeap, i);
    }

    return minHeap;
}

// Extract the minimum node from a min heap
struct minHeapNode* extractMin(struct minHeap* minHeap) {
    struct minHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    heapify(minHeap, 0);
    return temp;
}

// Insert a node in a min heap
void insertNode(struct minHeap* minHeap, struct minHeapNode* node) {
    minHeap->size++;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

// Build a Huffman tree and return the root node
struct minHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct minHeapNode *left, *right, *top;
    struct minHeap* minHeap = buildMinHeap(data, freq, size);

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(minHeap, top);
    }

    return extractMin(minHeap);
}

// Print binary codes for Huffman tree nodes
void printCodes(struct minHeapNode* root, int codes[], int top) {
    if (root->left) {
        codes[top] = 0;
        printCodes(root->left, codes, top + 1);
    }

    if (root->right) {
        codes[top] = 1;
        printCodes(root->right, codes, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

// Perform Huffman encoding on a string
void encode(struct minHeapNode* root, char data[], int size) {
    int codes[MAX_TREE_HT], i = 0;
    printCodes(root, codes, i);

    printf("Encoded string is: ");
    for (int i = 0; i < size; i++) {
        printf("%d", codes[data[i]]);
    }
    printf("\n");
}

// Perform Huffman decoding on a string
void decode(struct minHeapNode* root, char data[], int size) {
    struct minHeapNode* temp = root;
    printf("Decoded string is: ");

    for (int i = 0; i < size; i++) {
        if (data[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        
        if (isLeaf(temp)) {
            printf("%c", temp->data);
            temp = root;
        }
    }
    printf("\n");
}

// Test Driver
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct minHeapNode* root = buildHuffmanTree(data, freq, size);

    printf("\nHuffman Codes:\n");
    printCodes(root, data, 0);

    char test[] = "abdafeccdbee";
    int testSize = sizeof(test) / sizeof(test[0]) - 1;
    
    encode(root, test, testSize);
    decode(root, "10001101010101100100", strlen("10001101010101100100"));

    return 0;
}