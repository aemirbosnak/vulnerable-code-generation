//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int priority;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int data, int priority) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;

    if (q->rear == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(Queue *q) {
    Node *temp = q->front;
    int data = temp->data;

    if (q->front == q->rear) {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    return data;
}

void display(Queue *q) {
    Node *temp = q->front;

    printf("Queue: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 10, 1);
    enqueue(q, 20, 2);
    enqueue(q, 30, 3);

    display(q);

    int data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    display(q);

    return 0;
}