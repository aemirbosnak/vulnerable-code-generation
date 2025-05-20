//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Unable to enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // First element
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Unable to dequeue\n");
        return -1; // Return an invalid value
    }
    int removed = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset it
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued %d\n", removed);
    return removed;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (true) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    int choice, value;

    while (true) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Check if Empty\n5. Check if Full\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                if (isEmpty(q)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;
            case 5:
                if (isFull(q)) {
                    printf("The queue is full.\n");
                } else {
                    printf("The queue is not full.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                free(q);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}