//FormAI DATASET v1.0 Category: Queue ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10 //maximum size of the queue

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

Queue * createQueue() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    return queue;
}

int isEmpty(Queue * queue) {
    return queue->front == -1;
}

int isFull(Queue * queue) {
    return queue->rear == MAX_SIZE-1;
}

void enqueue(Queue * queue, int value) {
    if(isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if(isEmpty(queue)) {
        queue->front = queue->rear = 0;
    }
    else {
        queue->rear += 1;
    }
    queue->arr[queue->rear] = value;
    printf("%d has been added to the queue.\n", value);
}

void dequeue(Queue * queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int dequeuedValue = queue->arr[queue->front];
    if(queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front += 1;
    }
    printf("%d has been dequeued from the queue.\n", dequeuedValue);
}

void display(Queue * queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Current queue: ");
    for(int i=queue->front; i<=queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue * queue = createQueue();

    printf("Queue demonstration:\n");

    //Enqueue values
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);

    //Display values
    display(queue);

    //Dequeue values
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    //Display values again
    display(queue);

    //Enqueue more values
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);

    //Display values again
    display(queue);

    //Dequeue all values
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    //Display values again
    display(queue);

    return 0;
}