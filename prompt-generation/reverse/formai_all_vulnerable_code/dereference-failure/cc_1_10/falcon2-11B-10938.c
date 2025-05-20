//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

bool enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return true;
}

int dequeue(Queue* q) {
    int data = q->front->data;
    if (isQueueEmpty(q)) {
        return -1;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
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
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    printf("Dequeued: %d\n", dequeue(q));
    printQueue(q);
    return 0;
}