//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to define the Queue
struct Queue {
    int* array;
    int front;
    int rear;
    int size;
};

// Function to initialize the Queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->array = (int*)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to insert an element in the Queue
void insertElement(struct Queue* queue, int data) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->array[queue->rear] = data;
        printf("Inserted element %d into the Queue\n", data);
    }
}

// Function to delete an element from the Queue
void deleteElement(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return;
    } else {
        printf("Deleted element %d from the Queue\n", queue->array[queue->front]);
        queue->front = (queue->front + 1) % queue->size;
    }
}

// Function to display the Queue
void displayQueue(struct Queue* queue) {
    int i;
    printf("Queue elements are: ");
    for (i = 0; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    struct Queue* queue = createQueue(5);
    int element;

    while (1) {
        printf("Enter 1 to insert an element\n");
        printf("Enter 2 to delete an element\n");
        printf("Enter 3 to display the Queue\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &element);
                insertElement(queue, element);
                break;
            case 2:
                deleteElement(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                free(queue->array);
                free(queue);
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}