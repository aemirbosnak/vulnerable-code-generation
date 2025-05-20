//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
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
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    int data = dequeue(queue);
    printf("Data: %d\n", data);

    data = dequeue(queue);
    printf("Data: %d\n", data);

    data = dequeue(queue);
    printf("Data: %d\n", data);

    data = dequeue(queue);
    printf("Data: %d\n", data);

    data = dequeue(queue);
    printf("Data: %d\n", data);

    return 0;
}