//FormAI DATASET v1.0 Category: Queue ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

// Define the QueueNode structure
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Define the Queue structure
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// Function to create a new QueueNode
QueueNode* createNode(int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the Queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue an element into the Queue
void enqueue(Queue* q, int data) {
    QueueNode* newNode = createNode(data);

    if(q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    q->size++;
}

// Function to dequeue an element from the Queue
int dequeue(Queue* q) {
    if(isEmpty(q))
        return -1;

    QueueNode* temp = q->front;
    int data = temp->data;

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->size--;
    return data;
}

// Main function to test the Queue
int main() {

    Queue* q = createQueue();

    // Enqueue some elements into the Queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Dequeue the elements from the Queue
    printf("Dequeuing elements from the Queue...\n");
    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));

    return 0;
}