//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int peek(struct Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

void printQueue(struct Queue *queue) {
    struct Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printQueue(queue);

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));

    printQueue(queue);

    enqueue(queue, 50);
    enqueue(queue, 60);

    printQueue(queue);

    printf("Peek: %d\n", peek(queue));

    printf("Is Empty: %d\n", isEmpty(queue));

    return 0;
}