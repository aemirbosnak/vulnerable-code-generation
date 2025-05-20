//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: decentralized
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
    struct queue *q = malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct queue *q, int data) {
    struct node *new_node = malloc(sizeof(struct node));
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
        printf("Queue is empty\n");
        return -1;
    } else {
        struct node *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        int data = temp->data;
        free(temp);
        return data;
    }
}

int main() {
    struct queue *q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    printf("Queue elements:\n");
    while (q->front != NULL) {
        printf("%d ", dequeue(q));
    }
    printf("\n");
    return 0;
}