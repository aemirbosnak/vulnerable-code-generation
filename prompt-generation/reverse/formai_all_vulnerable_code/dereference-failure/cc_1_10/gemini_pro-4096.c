//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int front, rear;
    int size;
    int data[MAX_SIZE];
} Queue;

Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, int data) {
    if (queue->size == MAX_SIZE) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->data[queue->rear] = data;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    return data;
}

int front(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->front];
}

int rear(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->rear];
}

int is_empty(Queue *queue) {
    return queue->size == 0;
}

int is_full(Queue *queue) {
    return queue->size == MAX_SIZE;
}

void print_queue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->data[i]);
}

int main() {
    Queue *queue = create_queue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    print_queue(queue);

    printf("Front of the queue: %d\n", front(queue));
    printf("Rear of the queue: %d\n", rear(queue));

    dequeue(queue);
    dequeue(queue);
    print_queue(queue);

    printf("Front of the queue: %d\n", front(queue));
    printf("Rear of the queue: %d\n", rear(queue));

    return 0;
}