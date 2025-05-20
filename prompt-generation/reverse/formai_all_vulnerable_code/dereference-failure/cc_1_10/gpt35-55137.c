//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    if (queue->rear == MAX_QUEUE_SIZE - 1)
        printf("Error: Queue is Full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = data;
        printf("%d successfully added to queue\n", data);
    }
}

void dequeue(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear)
        printf("Error: Queue is Empty\n");
    else {
        printf("%d successfully removed from queue\n", queue->items[queue->front]);
        queue->front++;
    }
}

void display(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear)
        printf("Error: Queue is Empty\n");
    else {
        printf("Queue contains: ");
        for (int i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->items[i]);
        printf("\n");
    }
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);
    enqueue(queue, 11);
    display(queue);
    return 0;
}