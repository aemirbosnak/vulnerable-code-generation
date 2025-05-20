//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

bool is_empty(struct queue *q) {
    return q->front == NULL;
}

void enqueue(struct queue *q, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(struct queue *q) {
    if (is_empty(q)) {
        return -1;
    }
    struct node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

void display(struct queue *q) {
    struct node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue q;
    q.front = q.rear = NULL;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 6);
    enqueue(&q, 7);
    display(&q);
    return 0;
}