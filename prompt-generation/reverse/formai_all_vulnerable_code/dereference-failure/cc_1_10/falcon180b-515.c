//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

void enqueue(struct queue *q, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (q->front == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(struct queue *q) {
    int data;
    struct node *temp = q->front;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    data = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return data;
}

void display(struct queue *q) {
    struct node *temp = q->front;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue q;
    q.front = NULL;
    q.rear = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Queue after enqueue: ");
    display(&q);

    int data = dequeue(&q);
    printf("Dequeued element: %d\n", data);

    printf("Queue after dequeue: ");
    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);

    printf("Queue after enqueue: ");
    display(&q);

    data = dequeue(&q);
    printf("Dequeued element: %d\n", data);

    printf("Queue after dequeue: ");
    display(&q);

    return 0;
}