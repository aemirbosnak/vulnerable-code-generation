//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

// define structure for the queue
typedef struct {
    int data;
    struct node* next;
} Node;

// define structure for the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// function to initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// function to check if the queue is empty
bool isEmptyQueue(Queue* q) {
    return (q->front == NULL);
}

// function to check if the queue is full
bool isFullQueue(Queue* q) {
    return (q->rear == NULL);
}

// function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmptyQueue(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// function to remove an element from the front of the queue
int dequeue(Queue* q) {
    Node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;

    if (isEmptyQueue(q)) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

// function to display the contents of the queue
void displayQueue(Queue* q) {
    Node* temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Queue after enqueueing elements: ");
    displayQueue(&q);

    int dequeuedElement = dequeue(&q);
    printf("Dequeued element: %d\n", dequeuedElement);

    printf("Queue after dequeuing an element: ");
    displayQueue(&q);

    return 0;
}