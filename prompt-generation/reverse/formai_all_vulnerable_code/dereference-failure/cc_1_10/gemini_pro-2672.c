//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <assert.h>
#include <stdlib.h>

#define QUEUE_SIZE 100
#define INIT_SIZE 10

typedef struct queue {
    int *items;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue *create_queue(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = queue->rear = -1;
    queue->items = malloc(sizeof(int) * capacity);
    return queue;
}

void destroy_queue(Queue *queue) {
    free(queue->items);
    free(queue);
}

int is_empty(Queue *queue) {
    return queue->size == 0;
}

int is_full(Queue *queue) {
    return queue->size == queue->capacity;
}

void enqueue(Queue *queue, int item) {
    if (is_full(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    queue->size--;
    return item;
}

int front(Queue *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    return queue->items[queue->front];
}

int rear(Queue *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    return queue->items[queue->rear];
}

int main() {
    Queue *queue = create_queue(INIT_SIZE);

    assert(is_empty(queue) == 1);
    assert(is_full(queue) == 0);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    assert(is_empty(queue) == 0);
    assert(is_full(queue) == 0);
    assert(front(queue) == 1);
    assert(rear(queue) == 3);

    dequeue(queue);
    dequeue(queue);

    assert(is_empty(queue) == 0);
    assert(is_full(queue) == 0);
    assert(front(queue) == 3);
    assert(rear(queue) == 3);

    enqueue(queue, 4);
    enqueue(queue, 5);

    assert(is_empty(queue) == 0);
    assert(is_full(queue) == 0);
    assert(front(queue) == 3);
    assert(rear(queue) == 5);

    destroy_queue(queue);

    return 0;
}