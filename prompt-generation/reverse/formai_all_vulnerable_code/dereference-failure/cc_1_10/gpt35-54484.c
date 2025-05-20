//FormAI DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int rear;
    int front;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->rear = -1;
    queue->front = -1;
    return queue;
}

int isFull(Queue* queue) {
    if(queue->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue* queue) {
    if(queue->front == -1 || queue->front > queue->rear) {
        return 1;
    }
    return 0;
}

void enqueue(Queue* queue, int x) {
    if(isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", x);
    }
    else {
        if(queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = x;
        printf("Enqueued %d\n", x);    
    }
}

int dequeue(Queue* queue) {
    int item;
    if(isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else {
        item = queue->items[queue->front];
        queue->front++;
        if(queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("Dequeued %d\n", item);
        return item;
    }
}

int main() {
    Queue* queue = createQueue();

    printf("Welcome to the Unique C Queue Implementation program\n");
    printf("Enter 1 to enqueue an item\n");
    printf("Enter 2 to dequeue an item\n");
    printf("Enter 3 to exit\n");

    int choice, item;

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the item to be enqueued: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid choice\n");
                break;
        }
    } while(choice != 3);

    return 0;
}