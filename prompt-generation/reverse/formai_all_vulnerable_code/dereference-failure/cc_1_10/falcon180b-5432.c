//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of a node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure of the queue
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

// Remove an element from the front of the queue
int dequeue(Queue* q) {
    Node* temp = q->front;
    int data = temp->data;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

// Display the elements in the queue
void display(Queue* q) {
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    int dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    display(q);

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    display(q);

    return 0;
}