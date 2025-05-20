//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void enqueue(Queue* queue, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    int data = queue->head->data;
    queue->head = queue->head->next;

    return data;
}

int main() {
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    int data = dequeue(queue);
    printf("%d", data);

    return 0;
}