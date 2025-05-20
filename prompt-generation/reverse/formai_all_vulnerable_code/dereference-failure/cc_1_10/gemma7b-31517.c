//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Queue {
    Node* head;
    Node* tail;
    int size;
    int capacity;
};

void initializeQueue(struct Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->capacity = MAX_SIZE;
}

void enqueue(struct Queue* queue, int data) {
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

    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (queue->size == 0) {
        return -1;
    }

    int data = queue->head->data;
    free(queue->head);
    queue->head = queue->head->next;
    queue->size--;

    return data;
}

int main() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    initializeQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Data at the front of the queue: %d\n", dequeue(queue));
    printf("Data at the front of the queue: %d\n", dequeue(queue));
    printf("Data at the front of the queue: %d\n", dequeue(queue));
    printf("Data at the front of the queue: %d\n", dequeue(queue));

    return 0;
}