//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
    int size;
    int capacity;
} Queue;

Queue* queue_create(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void queue_insert(Queue* queue, int data) {
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

int queue_peek(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    } else {
        return queue->head->data;
    }
}

void queue_delete(Queue* queue) {
    free(queue->head);
    free(queue);
}

int main() {
    Queue* queue = queue_create(MAX_SIZE);
    queue_insert(queue, 10);
    queue_insert(queue, 20);
    queue_insert(queue, 30);
    queue_insert(queue, 40);

    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue_peek(queue));
    }

    queue_delete(queue);

    return 0;
}