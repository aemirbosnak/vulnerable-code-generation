//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Elements in the queue:");
    for (Node* node = queue->head; node; node = node->next) {
        printf(" %d ", node->data);
    }

    printf("\n");

    int data = dequeue(queue);
    if (data != -1) {
        printf("Dequed element: %d", data);
    }

    printf("\n");

    data = dequeue(queue);
    if (data != -1) {
        printf("Dequed element: %d", data);
    }

    printf("\n");

    data = dequeue(queue);
    if (data != -1) {
        printf("Dequed element: %d", data);
    }

    return 0;
}