//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

typedef struct {
    Node *queueArray;
    int front, rear, size;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue *Q = (Queue*) malloc(sizeof(Queue));
    if(Q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    Q->queueArray = (Node*) malloc(MAX_SIZE * sizeof(Node));
    if(Q->queueArray == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    Q->front = Q->rear = -1;
    Q->size = 0;
    return Q;
}

// Function to check if the queue is empty
int isEmpty(Queue *Q) {
    if(Q->front == -1 && Q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is full
int isFull(Queue *Q) {
    if(Q->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(Queue *Q, int data) {
    if(isFull(Q)) {
        printf("Queue is full\n");
        return;
    }
    if(isEmpty(Q)) {
        Q->front = Q->rear = 0;
    } else {
        Q->rear++;
    }
    Q->queueArray[Q->rear].data = data;
    Q->queueArray[Q->rear].index = Q->rear;
    Q->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue *Q) {
    int data;
    if(isEmpty(Q)) {
        printf("Queue is empty\n");
        return -1;
    }
    data = Q->queueArray[Q->front].data;
    Q->front++;
    Q->size--;
    return data;
}

// Function to display the elements of the queue
void display(Queue *Q) {
    int i;
    if(isEmpty(Q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for(i=Q->front; i<=Q->rear; i++) {
        printf("%d ", Q->queueArray[i].data);
    }
    printf("\n");
}

int main() {
    Queue *Q = createQueue();
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    display(Q);
    dequeue(Q);
    dequeue(Q);
    display(Q);
    return 0;
}