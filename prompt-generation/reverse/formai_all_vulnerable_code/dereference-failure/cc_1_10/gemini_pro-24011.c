//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    struct node *front;
    struct node *rear;
} queue;

void enqueue(queue *q, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue *q) {
    if (q->front == NULL) {
        return -1;
    } else {
        int data = q->front->data;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        return data;
    }
}

void display(queue *q) {
    struct node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    q.front = q.rear = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    display(&q); // 1 2 3 4 5

    dequeue(&q);
    dequeue(&q);

    display(&q); // 3 4 5

    enqueue(&q, 6);
    enqueue(&q, 7);

    display(&q); // 3 4 5 6 7

    return 0;
}