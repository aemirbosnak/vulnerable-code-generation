//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char data;
    unsigned frequency;
    struct Node *left, *right;
} Node;

typedef struct PriorityQueue {
    Node *array[MAX_TREE_NODES];
    int size;
} PriorityQueue;

Node* createNode(char data, unsigned frequency) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

PriorityQueue* createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(PriorityQueue *pq, int index) {
    int smallest = index, left = 2 * index + 1, right = 2 * index + 2;

    if (left < pq->size && pq->array[left]->frequency < pq->array[smallest]->frequency)
        smallest = left;

    if (right < pq->size && pq->array[right]->frequency < pq->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swap(&pq->array[smallest], &pq->array[index]);
        minHeapify(pq, smallest);
    }
}

void insert(PriorityQueue *pq, Node *newNode) {
    pq->array[pq->size++] = newNode;
    for (int i = pq->size / 2 - 1; i >= 0; i--) {
        minHeapify(pq, i);
    }
}

Node* extractMin(PriorityQueue *pq) {
    if (pq->size == 0)
        return NULL;
    Node *minNode = pq->array[0];
    pq->array[0] = pq->array[--pq->size];
    minHeapify(pq, 0);
    return minNode;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    PriorityQueue *pq = createPriorityQueue();

    for (int i = 0; i < size; i++) {
        insert(pq, createNode(data[i], freq[i]));
    }

    while (pq->size > 1) {
        Node *left = extractMin(pq);
        Node *right = extractMin(pq);
        Node *sum = createNode('$', left->frequency + right->frequency);
        sum->left = left;
        sum->right = right;
        insert(pq, sum);
    }
    return extractMin(pq);
}

void printCodes(Node *root, char *arr, int top) {
    if (root->left) {
        arr[top] = '0';
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = '1';
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        arr[top] = '\0';
        printf("%c: %s\n", root->data, arr);
    }
}

void HuffmanCoding(char data[], int freq[], int size) {
    Node *root = buildHuffmanTree(data, freq, size);
    char arr[MAX_TREE_NODES];
    printCodes(root, arr, 0);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Character Huffman Codes:\n");
    HuffmanCoding(data, freq, size);

    return 0;
}