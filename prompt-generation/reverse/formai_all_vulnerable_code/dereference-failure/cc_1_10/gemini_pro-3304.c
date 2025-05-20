//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
typedef struct node {
    int data;
    struct node *next;
} node;

// Define the structure of a queue
typedef struct queue {
    node *front;
    node *rear;
    int size;
} queue;

// Create a new queue
queue *createQueue() {
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

// Check if the queue is empty
int isEmpty(queue *q) {
    return (q->size == 0);
}

// Get the size of the queue
int size(queue *q) {
    return q->size;
}

// Enqueue an element to the queue
void enqueue(queue *q, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

// Dequeue an element from the queue
int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    node *temp = q->front;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

// Print the queue
void printQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        node *temp = q->front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver code to test the queue
int main() {
    queue *q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printQueue(q);

    dequeue(q);
    dequeue(q);

    printQueue(q);

    return 0;
}