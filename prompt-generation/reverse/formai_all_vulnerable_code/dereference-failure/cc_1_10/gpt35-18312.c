//FormAI DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

/* Let's create our queue data structure using a struct in C */
typedef struct queue {
    int arr[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

/* Let's define our C functions for queue operations */

/* This function will initialize our queue */
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

/* This function will tell us if our queue is empty */
int isQueueEmpty(Queue* q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    }
    return 0;
}

/* This function will tell us if our queue is full */
int isQueueFull(Queue* q) {
    if ((q->rear+1)%QUEUE_SIZE == q->front) {
        return 1;
    }
    return 0;
}

/* This function will add an element to the rear of our queue */
void enqueue(Queue* q, int element) {
    if (isQueueFull(q)) {
        printf("Queue Overflow! Cannot add more elements.\n");
    }
    else if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = element;
    }
    else {
        q->rear = (q->rear+1)%QUEUE_SIZE;
        q->arr[q->rear] = element;
    }
}

/* This function will remove an element from the front of our queue */
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow! Cannot remove elements.\n");
        return -1;
    }
    else if (q->front == q->rear) {
        int element = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
        return element;
    }
    else {
        int element = q->arr[q->front];
        q->front = (q->front+1)%QUEUE_SIZE;
        return element;
    }
}

/* Let's test our implementation with some sample code */
int main() {
    Queue* myQueue = createQueue();
    
    /* Let's add some elements to the queue */
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    enqueue(myQueue, 60);
    enqueue(myQueue, 70);
    enqueue(myQueue, 80);
    
    /* Let's remove some elements from the queue */
    int element1 = dequeue(myQueue);
    printf("Removed Element: %d\n", element1);
    int element2 = dequeue(myQueue);
    printf("Removed Element: %d\n", element2);
    int element3 = dequeue(myQueue);
    printf("Removed Element: %d\n", element3);
    
    /* Let's add some more elements to the queue */
    enqueue(myQueue, 90);
    enqueue(myQueue, 100);
    
    /* Let's remove all elements from the queue */
    while (!isQueueEmpty(myQueue)) {
        int element = dequeue(myQueue);
        printf("Removed Element: %d\n", element);
    }
    
    /* Let's test what happens if we try to remove an element from an empty queue */
    int element4 = dequeue(myQueue);
    
    /* Let's test what happens if we try to add an element to a full queue */
    enqueue(myQueue, 110);
    enqueue(myQueue, 120);
    enqueue(myQueue, 130);
    enqueue(myQueue, 140);
    enqueue(myQueue, 150);
    enqueue(myQueue, 160);
    enqueue(myQueue, 170);
    enqueue(myQueue, 180);
    enqueue(myQueue, 190);
    enqueue(myQueue, 200);
    enqueue(myQueue, 210);
    
    /* Let's free the memory allocated for the queue */
    free(myQueue);
    
    return 0;
}