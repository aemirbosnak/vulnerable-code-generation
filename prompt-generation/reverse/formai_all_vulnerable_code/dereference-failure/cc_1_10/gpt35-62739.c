//FormAI DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 10

typedef struct Queue {
    int front;
    int rear;
    int size;
    int* storage;
} Queue;

Queue* create_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->storage = (int*) malloc(sizeof(int) * QUEUE_CAPACITY);
    return queue;
}

void destroy_queue(Queue* queue) {
    free(queue->storage);
    free(queue);
}

int is_empty(Queue* queue) {
    return queue->size == 0;
}

int is_full(Queue* queue) {
    return queue->size == QUEUE_CAPACITY;
}

void enqueue(Queue* queue, int value) {
    if (is_full(queue)) {
        printf("Queue overflow, cannot enqueue value %d\n", value);
        return;
    }
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->storage[queue->rear] = value;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue underflow, cannot dequeue value\n");
        return -1;
    }
    int value = queue->storage[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    queue->size--;
    return value;
}

int main() {
    Queue* queue = create_queue();
    for (int i = 1; i <= 11; i++) {
        enqueue(queue, i);
    }
    printf("Queue content: ");
    while (!is_empty(queue)) {
        int value = dequeue(queue);
        printf("%d ", value);
    }
    printf("\n");
    destroy_queue(queue);
    return 0;
}