//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
    int size;
};

struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(struct Queue *q, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

int dequeue(struct Queue *q) {
    if (q->front == NULL) {
        return -1;
    }
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return temp->data;
}

int front(struct Queue *q) {
    if (q->front == NULL) {
        return -1;
    }
    return q->front->data;
}

int rear(struct Queue *q) {
    if (q->rear == NULL) {
        return -1;
    }
    return q->rear->data;
}

bool isEmpty(struct Queue *q) {
    return q->size == 0;
}

int main() {
    struct Queue *q = createQueue();

    // Enqueue some elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    printf("Queue: ");
    while (!isEmpty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");

    return 0;
}