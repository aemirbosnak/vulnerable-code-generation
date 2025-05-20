//FormAI DATASET v1.0 Category: Queue ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct Queue {
    int front, rear;
    int items[MAX_SIZE];
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int item) {
    if (q->rear == MAX_SIZE-1) {
        printf("Queue is full!");
        return;
    }
    if (q->front == -1 && q->rear == -1)
        q->front = q->rear = 0;
    else
        q->rear++;
    q->items[q->rear] = item;
    printf("%d has been added to the queue\n", item);
}

int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty!");
        return -1;
    }
    int removedItem = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    printf("%d has been removed from the queue\n", removedItem);
    return removedItem;
}

void display(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty!");
        return;
    }
    printf("Current queue: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    int option, item, removedItem;
    bool isRunning = true;
    Queue* q = createQueue();

    printf("Welcome to the Queue!\n");
    printf("---------------------\n");

    while (isRunning) {
        printf("Please choose an option:\n");
        printf("1. Enqueue item\n");
        printf("2. Dequeue item\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Please enter the item you would like to enqueue: ");
                scanf("%d", &item);
                enqueue(q, item);
                break;
            case 2:
                removedItem = dequeue(q);
                printf("%d has been removed from the queue\n", removedItem);
                break;
            case 3:
                display(q);
                break;
            case 4:
                isRunning = false;
                printf("Exiting the Queue. Goodbye!\n");
                break;
            default:
                printf("Please enter a valid option (1-4).\n");
                break;
        }
    }

    return 0;
}