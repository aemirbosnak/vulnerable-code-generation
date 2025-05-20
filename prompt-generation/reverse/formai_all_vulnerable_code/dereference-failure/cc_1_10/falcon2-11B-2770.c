//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->front->data;
    Node* temp = q->front;

    if (q->size == 1) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        free(temp);
    }

    q->size--;
    return data;
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("Queue elements: ");
    printQueue(q);

    printf("Dequeued element: %d\n", dequeue(q));
    printf("Queue elements: ");
    printQueue(q);

    return 0;
}