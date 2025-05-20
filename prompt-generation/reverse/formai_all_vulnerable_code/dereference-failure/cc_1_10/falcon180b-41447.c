//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

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
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL)
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
    int value;
    struct node* temp = q->front;

    if (isEmpty(q))
        return -1;

    value = temp->data;
    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

// Function to display the elements in the queue
void display(struct queue* q) {
    struct node* temp = q->front;

    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
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
    enqueue(&q, 40);

    display(&q);

    int value = dequeue(&q);
    printf("Dequeued value: %d\n", value);

    display(&q);

    return 0;
}