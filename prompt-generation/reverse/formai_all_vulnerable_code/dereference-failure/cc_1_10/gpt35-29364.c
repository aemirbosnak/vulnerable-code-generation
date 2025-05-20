//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TREE_HT 255

// Structure for the Huffman node
struct HuffmanNode {
    char data;
    unsigned frequency;
    struct HuffmanNode *left, *right;
};

// Structure for the Priority Queue node
struct PriorityQueueNode {
    struct HuffmanNode *node;
    struct PriorityQueueNode *next;
};

// Structure for the Priority Queue
struct PriorityQueue {
    struct PriorityQueueNode *head;
};

// Create a new Huffman Node
struct HuffmanNode* newHuffmanNode(char data, unsigned frequency) {
    struct HuffmanNode* node =
        (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// Create a new Priority Queue Node
struct PriorityQueueNode* newPriorityQueueNode(struct HuffmanNode* node) {
    struct PriorityQueueNode* priorityQueueNode =
        (struct PriorityQueueNode*)malloc(sizeof(struct PriorityQueueNode));
    priorityQueueNode->next = NULL;
    priorityQueueNode->node = node;
    return priorityQueueNode;
}

// Create a new Priority Queue
struct PriorityQueue* newPriorityQueue() {
    struct PriorityQueue* priorityQueue =
        (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    priorityQueue->head = NULL;
    return priorityQueue;
}

// Compare the frequency of two Huffman Nodes
int compareFrequencies(struct PriorityQueueNode* a, struct PriorityQueueNode* b) {
    return (a->node->frequency) - (b->node->frequency);
}

// Check if the Priority Queue is empty
int isPriorityQueueEmpty(struct PriorityQueue* priorityQueue) {
    return (priorityQueue->head == NULL);
}

// Insert a node in the Priority Queue
void insertPriorityQueue(struct PriorityQueue* priorityQueue, struct HuffmanNode* node) {
    struct PriorityQueueNode* priorityQueueNode = newPriorityQueueNode(node);
    if (priorityQueue->head == NULL) {
        priorityQueue->head = priorityQueueNode;
        return;
    }
    if (compareFrequencies(priorityQueue->head, priorityQueueNode) > 0) {
        priorityQueueNode->next = priorityQueue->head;
        priorityQueue->head = priorityQueueNode;
        return;
    }
    struct PriorityQueueNode* current = priorityQueue->head;
    while (current->next != NULL &&
           compareFrequencies(current->next, priorityQueueNode) < 0) {
        current = current->next;
    }
    priorityQueueNode->next = current->next;
    current->next = priorityQueueNode;
}

// Remove the first node from the Priority Queue
struct PriorityQueueNode* removePriorityQueue(struct PriorityQueue* priorityQueue) {
    if (isPriorityQueueEmpty(priorityQueue))
        return NULL;
    struct PriorityQueueNode* node = priorityQueue->head;
    priorityQueue->head = priorityQueue->head->next;
    return node;
}

// Check if the Huffman Node is a leaf node
int isLeaf(struct HuffmanNode* root) {
    return !(root->left) && !(root->right);
}

// Create the Huffman Tree and print the Huffman codes
void printHuffmanCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Compress the input text using the Huffman codes
void compress(char* inputText, struct HuffmanNode* root, int arr[]) {
    int i = 0;
    while (inputText[i]) {
        int j = 0;
        while (root->data != inputText[i]) {
            if (arr[j++] == 0) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        printf("%d", arr[j - 1]);
        root = root;
        i++;
    }
    printf("\n");
}

int main() {
    char inputText[] = "this is a sample text";
    int frequency[256] = {0};
    int length = strlen(inputText);
    for (int i = 0; i < length; i++) {
        frequency[inputText[i]]++;
    }
    struct PriorityQueue* priorityQueue = newPriorityQueue();
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            insertPriorityQueue(priorityQueue, newHuffmanNode(i, frequency[i]));
        }
    }
    while (priorityQueue->head->next != NULL) {
        struct HuffmanNode* left = removePriorityQueue(priorityQueue)->node;
        struct HuffmanNode* right = removePriorityQueue(priorityQueue)->node;
        struct HuffmanNode* node = newHuffmanNode('$', left->frequency + right->frequency);
        node->left = left;
        node->right = right;
        insertPriorityQueue(priorityQueue, node);
    }
    struct HuffmanNode* root = removePriorityQueue(priorityQueue)->node;
    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, arr, top);
    printf("Compressed text: ");
    compress(inputText, root, arr);
    return 0;
}