//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Function to store the frequency of characters
void calculateFrequency(const char *input, int *freq) {
    while (*input) {
        freq[(unsigned char) *input]++;
        input++;
    }
}

// Node structure
typedef struct Node {
    char data; 
    unsigned freq; 
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(char data, unsigned freq) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to build a min heap from an array of nodes
void minHeapify(Node **heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left]->freq < heap[smallest]->freq)
        smallest = left;

    if (right < n && heap[right]->freq < heap[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        Node *temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, n, smallest);
    }
}

// Function to build a min heap
void buildMinHeap(Node **heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(heap, n, i);
}

// Function to extract minimum node
Node* extractMin(Node **heap, int *n) {
    Node *temp = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap, *n, 0);
    return temp;
}

// Function to insert a new node to the heap
void insertMinHeap(Node **heap, int *n, Node *newNode) {
    heap[*n] = newNode;
    int i = (*n)++;
    while (i && heap[(i - 1) / 2]->freq > heap[i]->freq) {
        Node *temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to build Huffman Tree
Node* buildHuffmanTree(int *freq) {
    Node *heap[MAX_CHAR];
    int heap_size = 0;
    
    for (int i = 0; i < MAX_CHAR; i++)
        if (freq[i]) {
            heap[heap_size++] = createNode(i, freq[i]);
        }

    buildMinHeap(heap, heap_size);
    
    while (heap_size > 1) {
        Node *left = extractMin(heap, &heap_size);
        Node *right = extractMin(heap, &heap_size);
        
        Node *newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        
        insertMinHeap(heap, &heap_size, newNode);
    }
    
    return extractMin(heap, &heap_size);
}

// Function to store the encoding of characters
void storeCodes(Node *root, char *arr, int top) {
    if (root->left) {
        arr[top] = '0';
        storeCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = '1';
        storeCodes(root->right, arr, top + 1);
    }
    
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%c", arr[i]);
        printf("\n");
    }
}

// Main function to compress using Huffman coding
void compress(const char *input) {
    int freq[MAX_CHAR] = {0}; // frequency array
    calculateFrequency(input, freq); // get the frequency
    
    Node *root = buildHuffmanTree(freq); // build tree
    
    // To store the codes
    char arr[MAX_CHAR];
    storeCodes(root, arr, 0);
}

// Main function
int main() {
    const char *input = "hello huffman, this is an example of compression!";
    printf("Input string: %s\n", input);
    printf("Character Huffman Codes:\n");
    compress(input);
    return 0;
}