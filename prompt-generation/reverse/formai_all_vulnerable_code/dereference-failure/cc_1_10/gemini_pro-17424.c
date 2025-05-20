//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int item) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("%d inserted\n", item);
    }
}

int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return(-1);
    }
    else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d deleted\n", item);
        return(item);
    }
}

void display(Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements:\n");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d  ", queue->items[i]);
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

    dequeue(queue);
    dequeue(queue);
    printf("\n");

    display(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);
    printf("\n");

    display(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue is not empty.\n");
    }

    return 0;
}