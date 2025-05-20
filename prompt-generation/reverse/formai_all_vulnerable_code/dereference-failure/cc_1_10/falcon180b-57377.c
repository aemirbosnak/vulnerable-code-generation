//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Queue structure
typedef struct {
    Node *front, *rear;
} Queue;

// Function to create an empty queue
Queue *createQueue(void) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(Queue *q, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(0);
    }
    int data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return data;
}

// Function to display the elements of the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        Node *temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver program
int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q); // Queue Underflow
    return 0;
}