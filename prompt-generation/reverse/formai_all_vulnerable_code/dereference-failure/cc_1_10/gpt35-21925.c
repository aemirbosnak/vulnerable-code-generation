//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define Queue structure
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

// Function to add an element to the Queue
void enQueue(Queue* q, int data) {
    Node* temp = createNode(data);

    // If queue is empty, front and rear both point to new node
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    // Add the new node at the end of the queue and move rear pointer 
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from Queue
int deQueue(Queue* q) {
    // If queue is empty, return -1 as an error code
    if (q->front == NULL) {
        return -1;
    }

    // Store previous front and move front pointer one node ahead
    Node* temp = q->front;
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    // Free memory and return the removed element data
    int data = temp->data;
    free(temp);
    return data;
}

// Function to print the queue elements
void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Test the Queue
int main() {
    Queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);

    printf("Queue elements: ");
    printQueue(q);

    printf("\nDequeuing elements: %d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d\n", deQueue(q));

    // If Queue is empty, returns -1
    printf("Dequeuing empty Queue returns: %d", deQueue(q));
    return 0;
}