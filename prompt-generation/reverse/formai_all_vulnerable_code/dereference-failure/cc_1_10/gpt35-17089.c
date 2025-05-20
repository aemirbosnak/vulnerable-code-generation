//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Struct for the queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1 && queue->rear == -1;
}

// Function to add an item to the queue
void enqueue(struct Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot add item\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear++;
        }

        queue->items[queue->rear] = item;
        printf("Added item %d to the queue\n", item);
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue *queue) {
    int item;

    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot remove item\n");
        return -1;
    } else {
        item = queue->items[queue->front];

        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }

        printf("Removed item %d from the queue\n", item);
        return item;
    }
}

int main() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    int option, item;

    printf("Welcome to the Queue implementation program!\n");
    printf("How can I assist you? Please choose an option from the menu:\n");

    do {
        printf("\n1. Add an item to the queue\n");
        printf("2. Remove an item from the queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the item you want to add to the queue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Exiting the program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose from the available options\n");
                break;
        }
    } while (option != 3);

    free(queue);

    return 0;
}