//FormAI DATASET v1.0 Category: Queue Implementation ; Style: standalone
/*
 * This program implements the Queue abstract data type using the C programming language.
 * The program includes functions for initializing the queue, adding elements, removing elements,
 * checking if the queue is empty and full, and printing the elements in the queue.
 * The program uses a circular array to implement the queue.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10  // maximum number of elements that can be stored in the queue

typedef struct {
    int front;  // index of the first element in the queue
    int rear;  // index of the last element in the queue
    int size;  // current size of the queue
    int* elements;  // array to store the elements in the queue
} Queue;

// function to create a new empty queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->elements = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));
    return q;
}

// function to add an element to the end of the queue
void enqueue(Queue* q, int value) {
    if (q->size >= MAX_QUEUE_SIZE) {
        printf("Error: queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;  // increment the rear index in a circular fashion
    q->elements[q->rear] = value;  // add the element to the end of the queue
    q->size++;  // increment the size of the queue
}

// function to remove the first element from the queue and return its value
int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Error: queue is empty\n");
        return -1;
    }
    int value = q->elements[q->front];  // get the value of the first element in the queue
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;  // increment the front index in a circular fashion
    q->size--;  // decrement the size of the queue
    return value;
}

// function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// function to check if the queue is full
int isFull(Queue* q) {
    return q->size >= MAX_QUEUE_SIZE;
}

// function to print the elements in the queue
void printQueue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i;
    for (i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_QUEUE_SIZE;
        printf("%d ", q->elements[index]);
    }
    printf("\n");
}

// main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printQueue(q);
    enqueue(q, 40);
    enqueue(q, 50);
    printQueue(q);
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printQueue(q);
    free(q->elements);
    free(q);
    return 0;
}