//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
struct queue* createQueue() {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(struct queue* q, int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    int value = -1;
    struct node* tempNode = q->front;

    if (!isEmpty(q)) {
        value = q->front->data;
        q->front = q->front->next;

        if (q->front == NULL)
            q->rear = NULL;

        free(tempNode);
    }

    return value;
}

// Function to display the contents of the queue
void display(struct queue* q) {
    struct node* tempNode = q->front;

    if (isEmpty(q))
        printf("Queue is empty.\n");
    else {
        printf("Queue elements are: ");
        while (tempNode!= NULL) {
            printf("%d ", tempNode->data);
            tempNode = tempNode->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Queue elements after enqueue operations:\n");
    display(q);

    int dequeuedValue = dequeue(q);
    printf("Dequeued value: %d\n", dequeuedValue);

    printf("Queue elements after dequeue operation:\n");
    display(q);

    return 0;
}