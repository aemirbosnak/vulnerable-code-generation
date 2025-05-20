//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->size == 0) {
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
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    q->size--;
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
    enqueue(q, 4);
    enqueue(q, 5);

    printQueue(q);
    printf("Dequeueing the first element:\n");
    printf("%d\n", dequeue(q));

    printQueue(q);
    printf("Dequeueing the second element:\n");
    printf("%d\n", dequeue(q));

    printQueue(q);
    printf("Dequeueing the third element:\n");
    printf("%d\n", dequeue(q));

    printQueue(q);
    printf("Dequeueing the fourth element:\n");
    printf("%d\n", dequeue(q));

    printQueue(q);
    printf("Dequeueing the fifth element:\n");
    printf("%d\n", dequeue(q));

    printf("Queue is empty.\n");

    return 0;
}