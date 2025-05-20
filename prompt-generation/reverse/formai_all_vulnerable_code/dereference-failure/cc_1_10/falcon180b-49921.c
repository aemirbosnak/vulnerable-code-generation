//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the Queue
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

// Define the Queue structure
typedef struct Queue {
    QNode* front;
    QNode* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q))
        return -1;
    else {
        QNode* temp = q->front;
        int data = q->front->data;
        q->front = q->front->next;
        free(temp);
        return data;
    }
}

// Function to display the elements of the queue
void display(Queue* q) {
    QNode* temp = q->front;
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    return 0;
}