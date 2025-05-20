//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int head, tail, size;
} Queue;

Queue *new_queue(int size) {
    Queue *queue = malloc(sizeof(Queue));
    queue->data = malloc(sizeof(int) * size);
    queue->head = queue->tail = queue->size = 0;
    return queue;
}

void free_queue(Queue *queue) {
    free(queue->data);
    free(queue);
}

void enqueue(Queue *queue, int item) {
    if (queue->size == queue->head - queue->tail) {
        fprintf(stderr, "Error: Queue is full.\n");
        return;
    }
    queue->data[queue->head++ % queue->size] = item;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        fprintf(stderr, "Error: Queue is empty.\n");
        return -1;
    }
    int item = queue->data[queue->tail++ % queue->size];
    queue->size--;
    return item;
}

int main() {
    Queue *queue = new_queue(10);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("%d ", dequeue(queue));  // 1
    printf("%d ", dequeue(queue));  // 2
    printf("%d ", dequeue(queue));  // 3
    printf("%d ", dequeue(queue));  // 4
    printf("%d\n", dequeue(queue)); // 5
    free_queue(queue);
    return 0;
}