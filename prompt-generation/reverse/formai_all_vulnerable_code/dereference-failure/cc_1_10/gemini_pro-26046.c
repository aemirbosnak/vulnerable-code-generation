//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct Queue {
    int front, rear;
    int items[QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue* queue, int item) {
    if (queue->rear == QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

int dequeue(Queue* queue) {
    int item;
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty!\n");
        return (-1);
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return (item);
    }
}

void display(Queue* queue) {
    int i;
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    display(queue);

    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));

    display(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    enqueue(queue, 100);

    display(queue);

    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));

    display(queue);

    return 0;
}