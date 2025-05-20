//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* queue_init() {
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void queue_insert(Queue* queue, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
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
    Queue* queue = queue_init();
    queue_insert(queue, 10);
    queue_insert(queue, 20);
    queue_insert(queue, 30);
    queue_insert(queue, 40);

    printf("Front element: %d\n", queue_peek(queue));
    printf("Elements in the queue: %d\n", queue_peek(queue));

    queue_delete(queue);

    return 0;
}