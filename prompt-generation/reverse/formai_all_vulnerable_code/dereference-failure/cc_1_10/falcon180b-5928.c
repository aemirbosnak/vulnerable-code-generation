//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: memory allocation failed\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isEmpty(Queue *q) {
    return q->front == NULL;
}

bool isFull(Queue *q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: memory allocation failed\n");
        exit(1);
    }
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

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: queue is empty\n");
        exit(1);
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: queue is empty\n");
        exit(1);
    }
    return q->front->data;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    Node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int dequeued = dequeue(q);
    printf("Dequeued element: %d\n", dequeued);
    display(q);
    return 0;
}