//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct Queue {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(struct Queue* queue) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue* queue) {
    if (queue->rear == -1 && queue->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full, cannot add %d :( \n", item);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("%d added to the queue! :D \n", item);
    }
}

int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue :( \n");
        return -1;
    } else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        printf("%d dequeued from the queue! :D \n", item);
        return item;
    }
}

int main() {
    struct Queue* queue = createQueue();

    printf("Hello! Welcome to my Queue program! :D \n");

    int choice, item;

    do {
        printf("\nMenu: \n");
        printf("1. Enqueue item \n");
        printf("2. Dequeue item \n");
        printf("3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the item you want to add to the queue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Thank you for using my Queue program! Goodbye! :D \n");
                break;
            default:
                printf("Invalid choice, please try again! \n");
        }
    } while(choice != 3);

    return 0;
}