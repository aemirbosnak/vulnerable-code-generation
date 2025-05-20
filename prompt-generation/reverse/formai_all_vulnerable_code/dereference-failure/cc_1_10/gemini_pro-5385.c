//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *front, *rear;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
    } else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->front->data;
}

void displayQueue(Queue *queue) {
    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    displayQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    displayQueue(queue);

    printf("Peek: %d\n", peek(queue));

    return 0;
}