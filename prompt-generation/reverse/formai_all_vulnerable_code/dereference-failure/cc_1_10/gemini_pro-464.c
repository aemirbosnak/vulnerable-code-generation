//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

struct queue *create_queue() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("Error allocating memory for queue.\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct queue *q, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error allocating memory for new node.\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(struct queue *q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty.\n");
        return 0;
    }
    int data = q->front->data;
    struct node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    struct queue *q = create_queue();
    if (q == NULL) {
        return 1;
    }
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    enqueue(q, 5);
    enqueue(q, 6);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    return 0;
}