//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Queue structure
typedef struct queue {
    node *front;
    node *rear;
    int size;
} queue;

// Function to create a queue
queue *createQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to enqueue an element
void enqueue(queue *q, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->size == 0) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

// Function to dequeue an element
int dequeue(queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int data = q->front->data;
        node *temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->size--;
        return data;
    }
}

// Function to check if the queue is empty
int isEmpty(queue *q) {
    return q->size == 0;
}

// Function to print the queue
void printQueue(queue *q) {
    if (q->size == 0) {
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

// Driver code
int main() {
    queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    printQueue(q);

    enqueue(q, 60);
    enqueue(q, 70);

    printQueue(q);

    return 0;
}