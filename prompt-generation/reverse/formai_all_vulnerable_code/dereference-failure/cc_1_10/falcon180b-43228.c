//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// node structure definition
struct node {
    int data;
    struct node* next;
};

// queue structure definition
struct queue {
    struct node* front;
    struct node* rear;
};

// function to create an empty queue
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// function to check if the queue is empty
int isEmpty(struct queue* q) {
    return q->front == NULL;
}

// function to add an element to the rear of the queue
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

// function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    int value;
    struct node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(0);
    }

    value = temp->data;
    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

// function to display the contents of the queue
void display(struct queue* q) {
    struct node* temp = q->front;
    printf("Queue: ");

    if (isEmpty(q))
        printf("Empty\n");
    else {
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// main function
int main() {
    struct queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    display(q);

    value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    display(q);

    value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    display(q);

    value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    display(q);

    return 0;
}