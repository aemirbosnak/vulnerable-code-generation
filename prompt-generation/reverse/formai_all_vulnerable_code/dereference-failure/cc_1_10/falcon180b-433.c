//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front, *rear;
} Queue;

Queue *create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(Queue *q) {
    int data = -1;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return data;
    }

    data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return data;
}

void display(Queue *q) {
    if (q->front == NULL) {
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
    Queue *q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    int dequeued_data = dequeue(q);
    printf("Dequeued data: %d\n", dequeued_data);

    display(q);

    dequeued_data = dequeue(q);
    printf("Dequeued data: %d\n", dequeued_data);

    display(q);

    dequeued_data = dequeue(q);
    printf("Dequeued data: %d\n", dequeued_data);

    display(q);

    dequeued_data = dequeue(q);
    printf("Dequeued data: %d\n", dequeued_data);

    display(q);

    return 0;
}