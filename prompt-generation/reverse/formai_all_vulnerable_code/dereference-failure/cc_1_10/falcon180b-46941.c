//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: random
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
void createQueue(struct queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(struct queue* q) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    else {
        free(temp);
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(struct queue* q, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the queue
void dequeue(struct queue* q) {
    if (isEmpty(q))
        printf("Queue Underflow\n");
    else if (q->front == q->rear) {
        printf("Deleted element is: %d\n", q->front->data);
        free(q->front);
        q->front = q->rear = NULL;
    }
    else {
        printf("Deleted element is: %d\n", q->front->data);
        q->front = q->front->next;
        free(q->front->next);
        q->front->next = NULL;
    }
}

// Function to display the queue
void display(struct queue* q) {
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Elements in the queue are: ");
        struct node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    createQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    return 0;
}