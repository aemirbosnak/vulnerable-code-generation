//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1; // Indicate failure
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    printf("%d dequeued from queue\n", item);
    return item;
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front item\n");
        return -1;
    }
    return queue->array[queue->front];
}

int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No rear item\n");
        return -1;
    }
    return queue->array[queue->rear];
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

void clearQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    printf("Queue cleared\n");
}

int main() {
    Queue* queue = createQueue(MAX);
    int choice, item;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Front Element\n");
        printf("4. Print Rear Element\n");
        printf("5. Print Queue\n");
        printf("6. Clear Queue\n");
        printf("7. Exit\n");
        printf("Select an operation (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                item = front(queue);
                if (item != -1) {
                    printf("Front element is: %d\n", item);
                }
                break;
            case 4:
                item = rear(queue);
                if (item != -1) {
                    printf("Rear element is: %d\n", item);
                }
                break;
            case 5:
                printQueue(queue);
                break;
            case 6:
                clearQueue(queue);
                break;
            case 7:
                free(queue->array);
                free(queue);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please select again.\n");
        }
    }

    return 0;
}