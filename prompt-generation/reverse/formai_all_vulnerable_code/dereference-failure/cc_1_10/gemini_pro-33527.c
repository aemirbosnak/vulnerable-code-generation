//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue {
    Node *data[100];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

void enqueue(Queue *queue, Node *node) {
    if (queue->rear == INT_MAX) {
        printf("Queue is full.");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->data[queue->rear] = node;
}

Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.");
        return NULL;
    }

    Node *node = queue->data[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        initQueue(queue);
    }

    return node;
}

Node *createNode(char ch, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void buildTree(Node **root, char *str) {
    Queue queue;
    initQueue(&queue);

    for (int i = 0; str[i] != '\0'; i++) {
        int freq = 1;
        while (str[i + 1] == str[i]) {
            freq++;
            i++;
        }

        Node *node = createNode(str[i], freq);
        enqueue(&queue, node);
    }

    while (queue.rear > 0) {
        Node *left = dequeue(&queue);
        Node *right = dequeue(&queue);

        if (!left && !right) {
            break;
        }

        Node *parent = createNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        enqueue(&queue, parent);
    }

    *root = dequeue(&queue);
}

void printCodes(Node *root, char *code) {
    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        printf("%c: %s\n", root->ch, code);
        return;
    }

    char leftCode[strlen(code) + 1];
    char rightCode[strlen(code) + 1];
    strcpy(leftCode, code);
    strcpy(rightCode, code);
    strcat(leftCode, "0");
    strcat(rightCode, "1");

    printCodes(root->left, leftCode);
    printCodes(root->right, rightCode);
}

int main() {
    char str[] = "aabaacc";
    Node *root = NULL;
    buildTree(&root, str);

    char code[strlen(str) + 1];
    code[0] = '\0';

    printCodes(root, code);

    return 0;
}