//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->rear == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
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
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Queue: ");
    printQueue(q);

    printf("\nDequeue: %d\n", dequeue(q));

    printf("Queue: ");
    printQueue(q);

    printf("\nDequeue: %d\n", dequeue(q));

    printf("Queue: ");
    printQueue(q);

    printf("\nDequeue: %d\n", dequeue(q));

    printf("Queue is empty: %s\n", (isEmpty(q)? "true" : "false"));

    return 0;
}