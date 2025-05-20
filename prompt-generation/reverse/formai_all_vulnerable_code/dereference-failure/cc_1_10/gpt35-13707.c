//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char value;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct PriorityQueue {
    int size;
    Node **nodes;
} PriorityQueue;

Node* createNode(char value, int freq) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *priorityQueue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    priorityQueue->size = 0;
    priorityQueue->nodes = (Node**) malloc(sizeof(Node*) * capacity);
    return priorityQueue;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue *priorityQueue, int index) {
    int smallest = index;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    if (leftIndex < priorityQueue->size && priorityQueue->nodes[leftIndex]->freq < priorityQueue->nodes[smallest]->freq) {
        smallest = leftIndex;
    }
    if (rightIndex < priorityQueue->size && priorityQueue->nodes[rightIndex]->freq < priorityQueue->nodes[smallest]->freq) {
        smallest = rightIndex;
    }
    if (smallest != index) {
        swap(&priorityQueue->nodes[smallest], &priorityQueue->nodes[index]);
        heapify(priorityQueue, smallest);
    }
}

void push(PriorityQueue *priorityQueue, Node *node) {
    priorityQueue->nodes[priorityQueue->size++] = node;
    int index = priorityQueue->size - 1;
    while (index != 0 && priorityQueue->nodes[(index - 1) / 2]->freq > priorityQueue->nodes[index]->freq) {
        swap(&priorityQueue->nodes[(index - 1) / 2], &priorityQueue->nodes[index]);
        index = (index - 1) / 2;
    }
}

Node* pop(PriorityQueue *priorityQueue) {
    Node *node = priorityQueue->nodes[0];
    priorityQueue->nodes[0] = priorityQueue->nodes[--priorityQueue->size];
    heapify(priorityQueue, 0);
    return node;
}

bool isLeaf(Node *node) {
    return node->left == NULL && node->right == NULL;
}

void printCodes(Node *root, char *code, int index) {
    if (root == NULL) {
        return;
    }
    if (isLeaf(root)) {
        printf("%c: %s\n", root->value, code);
    } else {
        code[index] = '0';
        printCodes(root->left, code, index + 1);
        code[index] = '1';
        printCodes(root->right, code, index + 1);
    }
}

void huffmanCoding(char *string) {
    int freq[128] = {0};
    for (int i = 0; i < strlen(string); i++) {
        freq[(int) string[i]]++;
    }
    PriorityQueue *priorityQueue = createPriorityQueue(128);
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            push(priorityQueue, createNode((char) i, freq[i]));
        }
    }
    while (priorityQueue->size > 1) {
        Node *left = pop(priorityQueue);
        Node *right = pop(priorityQueue);
        Node *parent = createNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        push(priorityQueue, parent);
    }
    char code[128] = {0};
    printCodes(pop(priorityQueue), code, 0);
}

int main() {
    char string[] = "hello, world!";
    huffmanCoding(string);
    return 0;
}