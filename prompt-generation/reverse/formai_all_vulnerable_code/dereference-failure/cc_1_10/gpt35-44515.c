//FormAI DATASET v1.0 Category: Queue Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int* elements;
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->elements = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));
    new_queue->front = -1;
    new_queue->rear = -1;
    return new_queue;
}

int isFull(Queue* queue) {
    return (queue->rear == MAX_QUEUE_SIZE-1);
}

int isEmpty(Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->elements[queue->rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else {
        item = queue->elements[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

void display(Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Contents of queue: ");
        for (i=queue->front; i<=queue->rear; i++) {
            printf("%d ", queue->elements[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;
    Queue* queue = createQueue();
    while (1) {
        printf("Enter:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}