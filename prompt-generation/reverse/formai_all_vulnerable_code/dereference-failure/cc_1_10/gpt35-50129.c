//FormAI DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

void init_queue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, int val) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;

    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(Queue *q) {
    if (q->front == NULL) return -1;

    Node *temp = q->front;
    int val = temp->val;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    return val;
}

int main() {
    Queue q;
    init_queue(&q);

    printf("Visualization of Queue Data Structure\n\n");

    enqueue(&q, 12);
    enqueue(&q, 30);
    enqueue(&q, 45);
    enqueue(&q, 78);
    enqueue(&q, 53);

    printf("%d <- front\n", q.front->val);

    Node *temp = q.front->next;
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }

    printf("\n%d <- rear\n", q.rear->val);

    int dequeued_val = dequeue(&q);
    printf("\nDequeued Value: %d\n\n", dequeued_val);

    printf("%d <- front\n", q.front->val);

    temp = q.front->next;
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }

    printf("\n%d <- rear\n", q.rear->val);

    return 0;
}