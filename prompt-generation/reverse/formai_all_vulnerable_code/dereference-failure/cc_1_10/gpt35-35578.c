//FormAI DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the Queue
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the queue itself
typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

// Function to initialize a new Queue
Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    printf("A brand new Queue has been created:)\n\n");
    return q;
}

// Function to add an item to the back of the Queue
void enqueue(Queue *q, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d has been added to the Queue:)\n\n", data);
}

// Function to remove and return an item from the front of the Queue
int dequeue(Queue *q) {
    int data;
    if (q->front == NULL) {
        printf("Queue is empty:(");
        return -1;
    } else {
        Node *temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
    }
    printf("%d has been dequeued from the Queue:)\n\n", data);
    return data;
}

int main() {
    Queue *q = createQueue();

    // Enqueue some items into the Queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // Dequeue some items from the Queue
    dequeue(q);
    dequeue(q);

    // Enqueue some more items into the Queue
    enqueue(q, 50);
    enqueue(q, 60);

    return 0;
}