//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Queue Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue Structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new Queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to insert an element at the rear of the Queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the Queue
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

// Function to display the Queue
void displayQueue(Queue* q) {
    Node* temp = q->front;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Function to check if the Queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to check if the Queue is full
int isFull(Queue* q) {
    return (q->rear == NULL);
}

// Driver program to test the Queue implementation
int main() {
    Queue* q = createQueue();

    // Enqueue 5 elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Display the Queue
    displayQueue(q);

    // Dequeue an element
    int data = dequeue(q);

    // Display the Queue after dequeue
    displayQueue(q);

    return 0;
}