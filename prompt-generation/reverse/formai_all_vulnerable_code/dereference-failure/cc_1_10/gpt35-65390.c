//FormAI DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

typedef struct queue Queue;

void init(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int x) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        struct node *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

void print(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        struct node *temp = q->front;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    print(&q);
    dequeue(&q);
    print(&q);
    enqueue(&q, 4);
    enqueue(&q, 5);
    print(&q);
    dequeue(&q);
    print(&q);
    return 0;
}