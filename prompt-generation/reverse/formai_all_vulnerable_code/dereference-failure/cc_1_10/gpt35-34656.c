//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int frequency;
    char character;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct HuffmanTree {
    Node *root;
} HuffmanTree;

typedef struct PriorityQueue {
    Node **nodes;
    int size;
} PriorityQueue;

Node *createNode(int frequency, char character, Node *left, Node *right) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->frequency = frequency;
    node->character = character;
    node->left = left;
    node->right = right;
    return node;
}

PriorityQueue *createPriorityQueue(int capacity) {
    PriorityQueue *queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->nodes = (Node**)malloc(capacity * sizeof(Node*));
    queue->size = 0;
    return queue;
}

void destroyPriorityQueue(PriorityQueue *queue) {
    free(queue->nodes);
    free(queue);
}

void enqueue(PriorityQueue *queue, Node *node) {
    queue->nodes[queue->size++] = node;
    int i = queue->size - 1;
    while (i > 0) {
        int j = (i - 1) / 2;
        if (queue->nodes[j]->frequency <= node->frequency) {
            break;
        }
        queue->nodes[i] = queue->nodes[j];
        i = j;
    }
    queue->nodes[i] = node;
}

Node *dequeue(PriorityQueue *queue) {
    Node *node = queue->nodes[0];
    queue->nodes[0] = queue->nodes[--queue->size];
    int i = 0;
    while (i * 2 + 1 < queue->size) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int min = left;
        if (right < queue->size && queue->nodes[right]->frequency < queue->nodes[left]->frequency) {
            min = right;
        }
        if (queue->nodes[i]->frequency <= queue->nodes[min]->frequency) {
            break;
        }
        Node *temp = queue->nodes[i];
        queue->nodes[i] = queue->nodes[min];
        queue->nodes[min] = temp;
        i = min;
    }
    return node;
}

Node *buildHuffmanTree(PriorityQueue *queue) {
    while (queue->size > 1) {
        Node *left = dequeue(queue);
        Node *right = dequeue(queue);
        Node *parent = createNode(left->frequency + right->frequency, '\0', left, right);
        enqueue(queue, parent);
    }
    return dequeue(queue);
}

void printCodes(Node *root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

void huffmanCoding(char *text) {
    int frequency[256] = {0};
    int length = strlen(text);
    for (int i = 0; i < length; ++i) {
        ++frequency[text[i]];
    }
    PriorityQueue *queue = createPriorityQueue(256);
    for (int i = 0; i < 256; ++i) {
        if (frequency[i] > 0) {
            enqueue(queue, createNode(frequency[i], i, NULL, NULL));
        }
    }
    Node *root = buildHuffmanTree(queue);

    int code[256];
    printCodes(root, code, 0);

    destroyPriorityQueue(queue);
}

int main() {
    char text[] = "hello world";
    huffmanCoding(text);
    return 0;
}