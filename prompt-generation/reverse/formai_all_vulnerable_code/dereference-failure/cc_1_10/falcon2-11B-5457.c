//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

void enqueue(Queue *q, int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
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

int dequeue(Queue *q) {
    if (q->size == 0) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    Node *temp = q->front;
    if (q->size == 1) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }
    q->size--;
    free(temp);
    return temp->data;
}

void printQueue(Queue *q) {
    Node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printQueue(&q);
    printf("%d\n", dequeue(&q));
    printQueue(&q);
    printf("%d\n", dequeue(&q));
    printQueue(&q);
    printf("%d\n", dequeue(&q));
    printQueue(&q);

    return 0;
}