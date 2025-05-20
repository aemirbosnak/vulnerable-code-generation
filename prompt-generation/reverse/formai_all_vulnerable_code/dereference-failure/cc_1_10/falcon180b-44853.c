//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    int priority;
    struct node *next;
};

struct queue {
    int front, rear;
    struct node *q[MAX];
};

void enqueue(struct queue *q, int data, int priority) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->priority = priority;
    if (q->front == -1 && q->rear == -1) {
        q->front = 0;
        q->rear = 0;
        q->q[0] = newnode;
    } else if (q->rear == MAX - 1) {
        printf("\nQueue is Full!!");
        exit(0);
    } else {
        q->rear++;
        q->q[q->rear] = newnode;
    }
}

void dequeue(struct queue *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("\nQueue is Empty!!");
        exit(0);
    } else if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

void display(struct queue *q) {
    int i;
    if (q->front == -1 && q->rear == -1) {
        printf("\nQueue is Empty!!");
        exit(0);
    } else {
        printf("\nElements in the Queue are: ");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->q[i]->data);
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    q.front = -1;
    q.rear = -1;
    int choice, data, priority;

    while (1) {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d", &data);
            printf("\nEnter the priority of the data: ");
            scanf("%d", &priority);
            enqueue(&q, data, priority);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }

    return 0;
}