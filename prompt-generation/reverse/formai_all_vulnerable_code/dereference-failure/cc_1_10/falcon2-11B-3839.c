//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

/* Function to create a new queue */
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

/* Function to enqueue (add element to the queue) */
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

/* Function to dequeue (remove element from the queue) */
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

/* Function to display the queue */
void displayQueue(Queue* q) {
    Node* curr = q->front;
    printf("Queue:\n");
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

/* Function to check if the queue is empty */
int isQueueEmpty(Queue* q) {
    return (q->front == NULL) && (q->rear == NULL);
}

/* Function to check if the queue is full */
int isQueueFull(Queue* q) {
    return (q->size == MAX_SIZE);
}

/* Main function */
int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    displayQueue(q);
    printf("Dequeued %d\n", dequeue(q));
    displayQueue(q);

    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    if (isQueueFull(q)) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }

    return 0;
}