//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_COUNT 256
#define MAX_CODE_LENGTH 16

typedef struct Node {
    int frequency;
    char character;
    struct Node *left, *right;
} Node;

typedef struct QueueNode {
    Node *node;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

Node *createNode(char character, int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, Node *node) {
    QueueNode *queueNode = (QueueNode *)malloc(sizeof(QueueNode));
    queueNode->node = node;
    queueNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = queueNode;
    } else {
        queue->rear->next = queueNode;
        queue->rear = queueNode;
    }
}

Node *dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    Node *node = queue->front->node;
    QueueNode *queueNode = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(queueNode);
    return node;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

Node *buildHuffmanTree(char *characters, int *frequencies, int size) {
    Queue *queue = createQueue();
    for (int i = 0; i < size; i++) {
        enqueue(queue, createNode(characters[i], frequencies[i]));
    }
    while (!isQueueEmpty(queue)) {
        Node *leftNode = dequeue(queue);
        Node *rightNode = dequeue(queue);
        Node *parentNode = createNode(' ', leftNode->frequency + rightNode->frequency);
        parentNode->left = leftNode;
        parentNode->right = rightNode;
        enqueue(queue, parentNode);
    }
    return dequeue(queue);
}

void printCodes(Node *root, char *code, int length) {
    if (root == NULL) {
        return;
    }
    if (root->character != ' ') {
        printf("%c: %s\n", root->character, code);
    }
    printCodes(root->left, strcat(code, "0"), length + 1);
    printCodes(root->right, strcat(code, "1"), length + 1);
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);
    Node *root = buildHuffmanTree(characters, frequencies, size);
    char code[MAX_CODE_LENGTH];
    printCodes(root, code, 0);
    return 0;
}