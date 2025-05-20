//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
// This is a C program that implements a queue using a singly linked list
// Inspired by Ada Lovelace's emphasis on logical reasoning and innovative thinking

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int data) {
    // Create a new node
    struct Node* temp = newNode(data);

    // If queue is empty
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Else add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
void dequeue(struct Queue* q) {
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    struct Node* temp = q->front;
    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Function to print the queue
void display(struct Queue* q) {
    struct Node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the C Queue Implementation example program
int main() {
    struct Queue *q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    printf("Queue before dequeue:\n");
    display(q);

    dequeue(q);
    printf("Queue after one dequeue:\n");
    display(q);

    dequeue(q);
    printf("Queue after two dequeue:\n");
    display(q);

    enqueue(q, 5);
    printf("Queue after one enqueue:\n");
    display(q);

    return 0;
}