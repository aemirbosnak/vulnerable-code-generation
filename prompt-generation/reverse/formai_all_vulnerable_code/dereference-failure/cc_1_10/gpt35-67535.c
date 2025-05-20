//FormAI DATASET v1.0 Category: Queue ; Style: calm
/*
* Program: queue.c
* Author: [Your Name]
* Description: This program demonstrates the implementation of a Queue data structure in C
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // maximum size of queue

// structure for Queue
struct queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// function to create a Queue
struct queue* createQueue() {
    struct queue *newQ = (struct queue*) malloc(sizeof(struct queue));
    newQ->front = -1; // initialize front and rear to -1
    newQ->rear = -1;
    return newQ;
}

// function to check if queue is empty
int isEmpty(struct queue *q) {
    if(q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

// function to check if queue is full
int isFull(struct queue *q) {
    if(q->rear == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

// function to insert an element in queue
void enqueue(struct queue *q, int x) {
    if(isFull(q)) {
        printf("\nQueue is full. Element cannot be inserted.\n");
        return;
    }
    else if(isEmpty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear++;
    }
    q->arr[q->rear] = x;
}

// function to remove an element from queue
void dequeue(struct queue *q) {
    if(isEmpty(q)) {
        printf("\nQueue is empty. Element cannot be deleted.\n");
        return;
    }
    else if(q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front++;
    }
}

// function to display the queue
void display(struct queue *q) {
    if(isEmpty(q)) {
        printf("\nQueue is empty.\n");
        return;
    }
    else {
        printf("\nQueue elements are: ");
        for(int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

// main function
int main() {
    struct queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    dequeue(q);

    display(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    dequeue(q); // queue is already empty

    display(q); // queue is already empty

    return 0;
}