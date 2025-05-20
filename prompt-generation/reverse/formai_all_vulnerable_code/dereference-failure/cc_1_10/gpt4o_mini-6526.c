//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256
#define CODE_LEN 16

// A node in the Huffman tree
typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

// A Min-Heap for storing nodes
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node **array;
} MinHeap;

// Function prototypes
Node* createNode(char character, unsigned frequency);
MinHeap* createMinHeap(unsigned capacity);
void insertMinHeap(MinHeap* minHeap, Node* node);
Node* extractMin(MinHeap* minHeap);
void buildHuffmanTree(char* text);
void printCodes(Node* root, char* code, int depth);
void freeHuffmanTree(Node* root);

int main() {
    char input[MAX_LEN];

    printf("Welcome to the Artistic Huffman Compression Program!\n");
    printf("Please enter a string (max %d characters): ", MAX_LEN - 1);
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    printf("\nYou entered: %s\n", input);
    buildHuffmanTree(input);

    return 0;
}

Node* createNode(char character, unsigned frequency) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**) malloc(minHeap->capacity * sizeof(Node*));
    return minHeap;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->array[minHeap->size++] = node;
    // Insert this node at the correct position to maintain the min-heap property
    for (int i = minHeap->size - 1; i > 0; i--) {
        if (minHeap->array[i]->frequency < minHeap->array[(i - 1) / 2]->frequency) {
            Node* temp = minHeap->array[i];
            minHeap->array[i] = minHeap->array[(i - 1) / 2];
            minHeap->array[(i - 1) / 2] = temp;
        } else {
            break;
        }
    }
}

Node* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    
    Node* root = minHeap->array[0];

    // Move the last item to root and reduce heap size
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;

    // Min-Heapify
    for (int i = 0; (2 * i + 1) < minHeap->size;) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
            smallest = left;
        if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
            smallest = right;

        if (smallest == i) break;

        Node* temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[smallest];
        minHeap->array[smallest] = temp;
        i = smallest;
    }

    return root;
}

void buildHuffmanTree(char* text) {
    unsigned frequency[256] = {0};
    // Count frequency of each character
    for (int i = 0; text[i] != '\0'; i++) {
        frequency[(unsigned char)text[i]]++;
    }

    MinHeap* minHeap = createMinHeap(256);

    // Create a leaf node for each character and add it to the min heap
    for (char ch = 0; ch < 256; ch++) {
        if (frequency[(unsigned char)ch]) {
            Node* node = createNode(ch, frequency[(unsigned char)ch]);
            insertMinHeap(minHeap, node);
        }
    }

    // Build the Huffman Tree
    while (minHeap->size > 1) {
        Node* left = extractMin(minHeap);
        Node* right = extractMin(minHeap);
        Node* combined = createNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        insertMinHeap(minHeap, combined);
    }

    Node* root = extractMin(minHeap);

    printf("\nHuffman Codes:\n");
    char code[CODE_LEN];
    printCodes(root, code, 0);

    freeHuffmanTree(root);
    free(minHeap->array);
    free(minHeap);
}

void printCodes(Node* root, char* code, int depth) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0'; // Terminate the string
        printf("%c: %s\n", root->character, code);
    } else {
        code[depth] = '0'; // Left edge
        printCodes(root->left, code, depth + 1);
        code[depth] = '1'; // Right edge
        printCodes(root->right, code, depth + 1);
    }
}

void freeHuffmanTree(Node* root) {
    if (root == NULL) return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}