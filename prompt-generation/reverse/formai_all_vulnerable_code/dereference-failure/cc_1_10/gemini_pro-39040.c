//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int head;
    int tail;
    int size;
} Queue;

Queue *queue_create(int size) {
    Queue *queue = malloc(sizeof(Queue));
    queue->data = malloc(sizeof(int) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

void queue_destroy(Queue *queue) {
    free(queue->data);
    free(queue);
}

int queue_is_empty(Queue *queue) {
    return queue->head == queue->tail;
}

int queue_is_full(Queue *queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

int queue_enqueue(Queue *queue, int data) {
    if (queue_is_full(queue)) {
        return -1;
    }
    queue->data[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->size;
    return 0;
}

int queue_dequeue(Queue *queue) {
    if (queue_is_empty(queue)) {
        return -1;
    }
    int data = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return data;
}

int main() {
    Queue *queue = queue_create(10);
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    printf("%d\n", queue_dequeue(queue));
    printf("%d\n", queue_dequeue(queue));
    queue_destroy(queue);
    return 0;
}