//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
void createQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == NULL);
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

// Function to dequeue an element
int dequeue(struct Queue* q) {
    int value;
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    else if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        value = q->front->data;
        q->front = q->front->next;
        free(temp);
    }

    return value;
}

// Function to display the elements of the queue
void display(struct Queue* q) {
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Elements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    int value = dequeue(&q);
    printf("Dequeued value: %d\n", value);
    display(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);

    return 0;
}