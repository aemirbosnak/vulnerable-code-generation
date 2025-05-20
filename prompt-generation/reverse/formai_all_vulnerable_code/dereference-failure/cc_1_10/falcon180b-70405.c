//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// struct for a node in the queue
typedef struct node {
    int data;
    struct node *next;
} Node;

// struct for the queue itself
typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

// function to initialize an empty queue
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == NULL;
}

// function to add an element to the rear of the queue
void enqueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

// function to remove an element from the front of the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node *temp = q->front;
    int data = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

// function to print the contents of the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    int frontElement = dequeue(&q);
    printf("Dequeued element: %d\n", frontElement);

    printQueue(&q);

    return 0;
}