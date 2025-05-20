//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 10  

struct Queue {
    int front, rear;
    int size;
    int *arr;
};

struct Queue *createQueue(int size) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

int isFull(struct Queue *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear = (queue->rear + 1) % queue->size;
        queue->arr[queue->rear] = data;
    }
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        int data = queue->arr[queue->front];
        if (queue->front == queue->rear)
            queue->front = queue->rear = -1;
        else
            queue->front = (queue->front + 1) % queue->size;
        return data;
    }
}

void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    else {
        printf("Queue: ");
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d ", queue->arr[i]);
            i = (i + 1) % queue->size;
        }
        printf("%d\n", queue->arr[i]);
    }
}

int main() {
    struct Queue *queue = createQueue(QUEUE_MAX_SIZE);
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    display(queue);
    
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    
    display(queue);
    
    enqueue(queue, 50);
    enqueue(queue, 60);
    
    display(queue);
    
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    
    display(queue);
    
    return 0;
}