//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

// Define a Huffman tree node structure
struct HuffmanTreeNode {
    char data;
    unsigned freq;
    struct HuffmanTreeNode *left, *right;
};

// Define a priority queue structure for Huffman coding
struct PriorityQueue {
    unsigned size;
    unsigned capacity;
    struct HuffmanTreeNode** array;
};

// Create a new node for Huffman coding
struct HuffmanTreeNode* newNode(char data, unsigned freq) {
    struct HuffmanTreeNode* node = (struct HuffmanTreeNode*) malloc(sizeof(struct HuffmanTreeNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

// Create a priority queue
struct PriorityQueue* createPriorityQueue(unsigned capacity) {
    struct PriorityQueue* priorityQueue = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    priorityQueue->size = 0;
    priorityQueue->capacity = capacity;
    priorityQueue->array = (struct HuffmanTreeNode**) malloc(priorityQueue->capacity * sizeof(struct HuffmanTreeNode*));

    return priorityQueue;
}

// Swap two Huffman tree nodes
void swapNodes(struct HuffmanTreeNode** firstNode, struct HuffmanTreeNode** secondNode) {
    struct HuffmanTreeNode* tempNode = *firstNode;
    *firstNode = *secondNode;
    *secondNode = tempNode;
}

// Heapify a priority queue
void heapify(struct PriorityQueue* priorityQueue, int index) {
    int smallestIndex = index;
    int leftNodeIndex = 2 * index + 1;
    int rightNodeIndex = 2 * index + 2;

    if (leftNodeIndex < priorityQueue->size && priorityQueue->array[leftNodeIndex]->freq < priorityQueue->array[smallestIndex]->freq) {
        smallestIndex = leftNodeIndex;
    }

    if (rightNodeIndex < priorityQueue->size && priorityQueue->array[rightNodeIndex]->freq < priorityQueue->array[smallestIndex]->freq) {
        smallestIndex = rightNodeIndex;
    }

    if (smallestIndex != index) {
        swapNodes(&priorityQueue->array[smallestIndex], &priorityQueue->array[index]);
        heapify(priorityQueue, smallestIndex);
    }
}

// Check if a priority queue has only one node
int isPriorityQueueSizeOne(struct PriorityQueue* priorityQueue) {
    return priorityQueue->size == 1;
}

// Extract the minimum value node from a priority queue
struct HuffmanTreeNode* extractMinNode(struct PriorityQueue* priorityQueue) {
    struct HuffmanTreeNode* minNode = priorityQueue->array[0];
    priorityQueue->array[0] = priorityQueue->array[priorityQueue->size - 1];
    --priorityQueue->size;
    heapify(priorityQueue, 0);

    return minNode;
}

// Insert a node into a priority queue
void insertNode(struct PriorityQueue* priorityQueue, struct HuffmanTreeNode* node) {
    ++priorityQueue->size;
    unsigned index = priorityQueue->size - 1;
    while (index && node->freq < priorityQueue->array[(index - 1) / 2]->freq) {
        priorityQueue->array[index] = priorityQueue->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    priorityQueue->array[index] = node;
}

// Check if a given node is a leaf node
int isLeafNode(struct HuffmanTreeNode* node) {
    return !(node->left) && !(node->right);
}

// Build a Huffman tree
struct HuffmanTreeNode* buildHuffmanTree(char data[], unsigned freq[], int size) {
    struct HuffmanTreeNode *leftNode, *rightNode, *topNode;
    struct PriorityQueue* priorityQueue = createPriorityQueue(size);

    for (int i = 0; i < size; ++i) {
        insertNode(priorityQueue, newNode(data[i], freq[i]));
    }

    while (!isPriorityQueueSizeOne(priorityQueue)) {
        leftNode = extractMinNode(priorityQueue);
        rightNode = extractMinNode(priorityQueue);
        topNode = newNode('$', leftNode->freq + rightNode->freq);
        topNode->left = leftNode;
        topNode->right = rightNode;
        insertNode(priorityQueue, topNode);
    }

    return extractMinNode(priorityQueue);
}

// Print Huffman codes from a root Huffman tree node
void printHuffmanCodes(struct HuffmanTreeNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    if (isLeafNode(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Main function for the Huffman coding implementation example program
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanTreeNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, arr, top);

    return 0;
}