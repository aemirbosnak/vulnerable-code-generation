//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: safe
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
    return q->front == NULL;
}

// Function to check if the queue is full
int isFull(struct queue* q) {
    return ((q->rear == NULL)? 0 : 1);
}

// Function to add an element to the queue
void enqueue(struct queue* q, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the queue
int dequeue(struct queue* q) {
    int value = -1;
    struct node* temp = q->front;

    if (!isEmpty(q)) {
        value = q->front->data;
        q->front = q->front->next;

        if (q->front == NULL) {
            q->rear = NULL;
        }
    }

    free(temp);
    return value;
}

// Function to display the elements in the queue
void display(struct queue* q) {
    struct node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    int value = dequeue(&q);
    printf("Dequeued value: %d\n", value);

    display(&q);

    return 0;
}