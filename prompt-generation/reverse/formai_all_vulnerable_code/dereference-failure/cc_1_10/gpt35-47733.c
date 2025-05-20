//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct HuffmanTreeNode {
    char data;
    unsigned freq;
    struct HuffmanTreeNode *left, *right;
};

// Huffman tree structure
struct HuffmanTree {
    int size;
    struct HuffmanTreeNode **arr;
};

// Priority queue node
struct PriorityQueueNode {
    struct HuffmanTreeNode* node;
    struct PriorityQueueNode* next;
};

// Priority queue structure
struct PriorityQueue {
    int size;
    struct PriorityQueueNode *front, *rear;
};

// Create a new Huffman tree node
struct HuffmanTreeNode* newHuffmanTreeNode(char data, unsigned freq) {
    struct HuffmanTreeNode* temp = (struct HuffmanTreeNode*)malloc(sizeof(struct HuffmanTreeNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Create a new priority queue node
struct PriorityQueueNode* newPriorityQueueNode(struct HuffmanTreeNode* node) {
    struct PriorityQueueNode* temp = (struct PriorityQueueNode*)malloc(sizeof(struct PriorityQueueNode));
    temp->node = node;
    temp->next = NULL;
    return temp;
}

// Create an empty priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->front = pq->rear = NULL;
    pq->size = 0;
    return pq;
}

int isEmptyPriorityQueue(struct PriorityQueue* pq) {
    return pq->front == NULL;
}

void enqueue(struct PriorityQueue* pq, struct HuffmanTreeNode* node) {
    struct PriorityQueueNode* temp = newPriorityQueueNode(node);

    if (isEmptyPriorityQueue(pq)) {
        pq->front = pq->rear = temp;
        pq->size++;
        return;
    }

    if (pq->front->node->freq > node->freq) {
        temp->next = pq->front;
        pq->front = temp;
        pq->size++;
        return;
    }

    struct PriorityQueueNode* curr = pq->front;
    while (curr->next != NULL && curr->next->node->freq < node->freq) {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    pq->size++;
}

struct HuffmanTreeNode* dequeue(struct PriorityQueue* pq) {
    if (isEmptyPriorityQueue(pq)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    struct PriorityQueueNode* temp = pq->front;
    pq->front = pq->front->next;

    if (pq->front == NULL) {
        pq->rear = NULL;
    }

    pq->size--;
    return temp->node;
}

struct HuffmanTree* createHuffmanTree(char data[], int freq[], int size) {
    struct HuffmanTree* htree = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
    htree->size = size;
    htree->arr = (struct HuffmanTreeNode**)malloc(size * sizeof(struct HuffmanTreeNode*));

    for (int i = 0; i < size; i++) {
        htree->arr[i] = newHuffmanTreeNode(data[i], freq[i]);
    }

    struct PriorityQueue* pq = createPriorityQueue();
    for (int i = 0; i < size; i++) {
        enqueue(pq, htree->arr[i]);
    }

    while (pq->size > 1) {
        struct HuffmanTreeNode* left = dequeue(pq);
        struct HuffmanTreeNode* right = dequeue(pq);

        struct HuffmanTreeNode* temp = newHuffmanTreeNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;

        enqueue(pq, temp);
    }

    htree->arr[0] = dequeue(pq);
    return htree;
}

// Print the Huffman codes for each character in the tree
void printHuffmanCodes(struct HuffmanTreeNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCoding(char data[], int freq[], int size) {
    struct HuffmanTree* htree = createHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(htree->arr[0], arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {12, 9, 7, 5, 4, 3};
    int size = sizeof(data)/sizeof(data[0]);

    HuffmanCoding(data, freq, size);
    return 0;
}