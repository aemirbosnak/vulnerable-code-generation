//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} queue_t;

void queue_create(queue_t *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool is_queue_full(queue_t *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

bool is_queue_empty(queue_t *queue) {
    return queue->front == -1 && queue->rear == -1;
}

void queue_enqueue(queue_t *queue, int data) {
    if (is_queue_full(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
        return;
    }

    if (is_queue_empty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }

    queue->data[queue->rear] = data;
}

int queue_dequeue(queue_t *queue) {
    int data;

    if (is_queue_empty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    data = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }

    return data;
}

void queue_print(queue_t *queue) {
    int i;

    if (is_queue_empty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", queue->data[i]);
    }

    printf("%d\n", queue->data[queue->rear]);
}

void queue_destroy(queue_t *queue) {
    free(queue);
}

int main() {
    queue_t *queue;
    int i;

    queue = malloc(sizeof(queue_t));
    queue_create(queue);

    printf("Queue created.\n");

    for (i = 0; i < 10; i++) {
        queue_enqueue(queue, i);
        printf("Enqueued %d.\n", i);
    }

    printf("Queue after enqueueing 10 elements:\n");
    queue_print(queue);

    for (i = 0; i < 5; i++) {
        int data = queue_dequeue(queue);
        printf("Dequeued %d.\n", data);
    }

    printf("Queue after dequeueing 5 elements:\n");
    queue_print(queue);

    queue_destroy(queue);
    printf("Queue destroyed.\n");

    return 0;
}