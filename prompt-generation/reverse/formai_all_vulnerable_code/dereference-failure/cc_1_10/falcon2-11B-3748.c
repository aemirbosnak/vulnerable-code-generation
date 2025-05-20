//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
    }
    q->tail = newNode;
}

int dequeue(Queue* q) {
    if (q->head == NULL) {
        return -1;
    }

    int data = q->head->data;
    Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
    return data;
}

bool isEmpty(Queue* q) {
    return q->head == NULL;
}

int peek(Queue* q) {
    if (q->head == NULL) {
        return -1;
    }
    return q->head->data;
}

void printQueue(Queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = q->head;
    printf("Queue: ");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    printQueue(q);
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));

    printQueue(q);
}