//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the structure for each element in the queue
typedef struct {
    int data;
    struct node* next;
} node;

// Define the structure for the queue itself
typedef struct {
    node* front;
    node* rear;
    int count;
} queue;

// Initialize an empty queue
queue* createQueue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

// Add an element to the rear of the queue
void enqueue(queue* q, int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->count++;
}

// Remove an element from the front of the queue
int dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->front->data;
    node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->count--;

    return data;
}

// Display the elements in the queue
void display(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    node* temp = q->front;
    printf("Queue elements: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Check if the queue is empty
bool isEmpty(queue* q) {
    return q->front == NULL;
}

// Check if the queue is full
bool isFull(queue* q) {
    return q->count == MAX_SIZE;
}

// Main function to test the queue implementation
int main() {
    queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    int dequeued = dequeue(q);
    printf("Dequeued element: %d\n", dequeued);

    display(q);

    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}