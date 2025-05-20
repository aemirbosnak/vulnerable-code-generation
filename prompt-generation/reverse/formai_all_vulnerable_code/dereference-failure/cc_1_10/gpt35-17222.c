//FormAI DATASET v1.0 Category: Queue ; Style: portable
#include <stdio.h>
#include <stdlib.h>

//Maximum size of queue
#define MAX_SIZE 100

//Queue data structure
typedef struct queue {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

//Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//Function to check if the queue is full
int isFull(Queue* q) {
    if (q->rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

//Function to check if the queue is empty
int isEmpty(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return 1;
    }
    return 0;
}

//Function to enqueue an item to the rear of the queue
void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = item;
}

//Function to dequeue an item from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->data[q->front];
    q->front++;
    return item;
}

//Function to print the contents of the queue
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    enqueue(q, 40);
    enqueue(q, 50);
    printQueue(q);
    return 0;
}