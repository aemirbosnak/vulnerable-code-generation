//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int* arr;
    int front, rear;
    int size;
};

/* Function to create a Queue */
struct Queue* createQueue(int size) {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->size = size;
    newQueue->arr = (int*)malloc(newQueue->size * sizeof(int));
    return newQueue;
}

/* Function to check if the Queue is empty */
int isEmpty(struct Queue* q) {
    return (q->rear == -1);
}

/* Function to check if the Queue is full */
int isFull(struct Queue* q) {
    return (q->rear == q->size - 1);
}

/* Function to enqueue an element in the Queue */
void enqueue(struct Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = val;
}

/* Function to dequeue an element from the Queue */
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return q->arr[q->front];
}

/* Function to print the elements of the Queue */
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 5;
    struct Queue* q = createQueue(size);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Queue is empty? %s\n", isEmpty(q)? "Yes" : "No");
    return 0;
}