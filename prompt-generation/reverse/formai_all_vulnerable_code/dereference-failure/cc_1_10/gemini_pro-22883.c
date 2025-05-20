//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Structure of a queue node
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// Structure of a queue
typedef struct Queue {
    QueueNode *front, *rear;
    int size;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Enqueue an element
void enqueue(Queue *q, int data) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Dequeue an element
int dequeue(Queue *q) {
    assert(!isEmpty(q));

    QueueNode *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

// Get the front element
int front(Queue *q) {
    assert(!isEmpty(q));
    return q->front->data;
}

// Get the rear element
int rear(Queue *q) {
    assert(!isEmpty(q));
    return q->rear->data;
}

// Print the queue
void printQueue(Queue *q) {
    QueueNode *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    Queue *q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printQueue(q);

    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", rear(q));

    dequeue(q);
    dequeue(q);
    dequeue(q);

    printQueue(q);

    return 0;
}