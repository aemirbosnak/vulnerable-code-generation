//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
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

// function for creating an empty queue
void createQueue(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// function for checking if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

// function for adding an element to the rear of the queue
void enqueue(struct queue* q, int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Queue is full\n");
        exit(0);
    }

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

// function for removing an element from the front of the queue
int dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }

    int value = q->front->data;
    struct node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);

    return value;
}

// function for displaying the elements in the queue
void display(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = q->front;

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int value = dequeue(&q);
    printf("Dequeued value is: %d\n", value);

    display(&q);

    return 0;
}