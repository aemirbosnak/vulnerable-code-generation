//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front, *rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty.\n");
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

int peek(Queue *q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int size(Queue *q) {
    return q->size;
}

void printQueue(Queue *q) {
    Node *temp = q->front;
    printf("[");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(", ");
        }
        temp = temp->next;
    }
    printf("]\n");
}

void destroyQueue(Queue *q) {
    while (q->front != NULL) {
        Node *temp = q->front;
        q->front = temp->next;
        free(temp);
    }
    free(q);
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printQueue(q);
    printf("Peek: %d\n", peek(q));
    printf("Size: %d\n", size(q));
    printf("Is Empty: %d\n", isEmpty(q));
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));
    printQueue(q);
    printf("Peek: %d\n", peek(q));
    printf("Size: %d\n", size(q));
    printf("Is Empty: %d\n", isEmpty(q));
    destroyQueue(q);
    return 0;
}