//FormAI DATASET v1.0 Category: Queue ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // Maximum queue size

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
    printf("%d enqueued to queue.\n", item);
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("%d dequeued from queue.\n", item);
    return item;
}

int main() {
    Queue* q = createQueue();

    printf("****Welcome to the Unique C Queue example program****\n");
    printf("**With this program, You can Enqueue and Dequeue items in the Queue**\n");
    printf("**The maximum size of the Queue is %d**\n", MAX_QUEUE_SIZE);

    int choice, item;

    while(1) {
        printf("Enter 1 to Enqueue and 2 to Dequeue: ");
        scanf("%d", &choice); // Taking user's choice from the keyboard
        switch(choice) {
            case 1:
                printf("Enter item to Enqueue: ");
                scanf("%d", &item); // Taking item to Enqueue from the keyboard
                enqueue(q, item);
                break;
            case 2:
                dequeue(q);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}