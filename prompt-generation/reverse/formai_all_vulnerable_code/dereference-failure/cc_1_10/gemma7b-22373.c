//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: authentic
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
    int size;
} Queue;

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

    queue->size++;
}

int dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    int data = queue->head->data;
    queue->head = queue->head->next;
    queue->size--;

    return data;
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Enqueued data: ");
    for (Node* node = queue->head; node; node = node->next) {
        printf("%d ", node->data);
    }

    printf("\n");

    int data = dequeue(queue);
    if (data != -1) {
        printf("Dequeued data: %d ", data);
    }

    printf("\n");

    data = dequeue(queue);
    if (data != -1) {
        printf("Dequeued data: %d ", data);
    }

    printf("\n");

    data = dequeue(queue);
    if (data != -1) {
        printf("Dequeued data: %d ", data);
    }

    printf("\n");

    printf("Enqueued data after dequeue: ");
    for (Node* node = queue->head; node; node = node->next) {
        printf("%d ", node->data);
    }

    return 0;
}