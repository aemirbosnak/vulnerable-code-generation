//FormAI DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} Node;

typedef struct queue_t {
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *q, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        fprintf(stderr, "The queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    int data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void display(Queue q) {
    if (q.front == NULL) {
        printf("The queue is empty!\n");
        return;
    }
    Node *temp = q.front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q = {NULL, NULL};
    enqueue(&q, 10);
    enqueue(&q, 20);
    dequeue(&q);
    enqueue(&q, 30);
    display(q);
    return EXIT_SUCCESS;
}