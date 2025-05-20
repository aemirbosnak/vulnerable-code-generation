//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
};

struct queue *createQueue() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue *q, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct queue *q) {
    if (q->front == NULL) {
        return -1;
    }
    struct node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int front(struct queue *q) {
    if (q->front == NULL) {
        return -1;
    }
    return q->front->data;
}

int rear(struct queue *q) {
    if (q->rear == NULL) {
        return -1;
    }
    return q->rear->data;
}

int isEmpty(struct queue *q) {
    return q->front == NULL;
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
    struct queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    display(q);
    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", rear(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", rear(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", rear(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", rear(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", rear(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", rear(q));
    printf("Is empty: %d\n", isEmpty(q));
    return 0;
}