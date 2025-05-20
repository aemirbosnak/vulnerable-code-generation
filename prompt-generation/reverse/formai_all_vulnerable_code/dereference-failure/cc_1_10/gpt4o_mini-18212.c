//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

// Structure to represent a single node in the Huffman tree
struct HuffmanNode {
    char character;
    unsigned frequency;
    struct HuffmanNode *left, *right;
};

// A priority queue to store the Huffman nodes
struct PriorityQueue {
    struct HuffmanNode *array[MAX_TREE_NODES];
    int size;
};

// Function to create a new Huffman Node
struct HuffmanNode* createNode(char character, unsigned frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to create a priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->size = 0;
    return pq;
}

// Function to insert a node into the priority queue
void insert(struct PriorityQueue* pq, struct HuffmanNode* node) {
    pq->array[pq->size++] = node;
}

// Function to swap two nodes (used by the priority queue)
void swap(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the priority queue
void heapify(struct PriorityQueue* pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->array[left]->frequency < pq->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < pq->size && pq->array[right]->frequency < pq->array[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&pq->array[i], &pq->array[smallest]);
        heapify(pq, smallest);
    }
}

// Function to extract the minimum node from the priority queue
struct HuffmanNode* extractMin(struct PriorityQueue* pq) {
    struct HuffmanNode* minNode = pq->array[0];
    pq->array[0] = pq->array[--pq->size];
    heapify(pq, 0);
    return minNode;
}

// Function to build the Huffman tree
struct HuffmanNode* buildHuffmanTree(char characters[], unsigned frequencies[], int size) {
    struct PriorityQueue* pq = createPriorityQueue();
    for (int i = 0; i < size; i++) {
        insert(pq, createNode(characters[i], frequencies[i]));
    }

    while (pq->size > 1) {
        struct HuffmanNode* left = extractMin(pq);
        struct HuffmanNode* right = extractMin(pq);
        struct HuffmanNode* combined = createNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        insert(pq, combined);
    }

    return extractMin(pq);
}

// Recursive function to generate the Huffman codes
void generateHuffmanCodes(struct HuffmanNode* root, char* code, int index, char codes[][MAX_TREE_NODES]) {
    if (root->left) {
        code[index] = '0';
        generateHuffmanCodes(root->left, code, index + 1, codes);
    }
    if (root->right) {
        code[index] = '1';
        generateHuffmanCodes(root->right, code, index + 1, codes);
    }
    if (!(root->left || root->right)) {
        code[index] = '\0';
        strcpy(codes[root->character], code);
    }
}

// Main program function
int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    unsigned frequencies[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(characters) / sizeof(characters[0]);

    struct HuffmanNode* root = buildHuffmanTree(characters, frequencies, size);

    char codes[MAX_TREE_NODES][MAX_TREE_NODES] = { 0 };
    char code[MAX_TREE_NODES];
    generateHuffmanCodes(root, code, 0, codes);

    printf("Huffman Codes:\n");
    for (int i = 0; i < size; i++) {
        printf("Character: %c, Code: %s\n", characters[i], codes[characters[i]]);
    }

    char input[] = "abcdef";
    printf("\nEncoding the input string: %s\n", input);
    printf("Encoded output: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%s", codes[input[i]]);
    }
    printf("\n");

    // Freeing the allocated memory is a crucial practice in C to prevent memory leaks.
    free(root); // Note: In a real implementation, you would need to free all nodes in the tree

    return 0;
}