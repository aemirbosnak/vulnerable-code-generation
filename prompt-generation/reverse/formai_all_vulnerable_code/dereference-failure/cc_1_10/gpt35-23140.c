//FormAI DATASET v1.0 Category: Queue ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the Queue
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *arr;
} Queue;

// Function to create a Queue
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int*) malloc(queue->capacity * sizeof(int));
    
    return queue;
}

// Check if the Queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the Queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the Queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
    
    printf("Enqueued item: %d\n", item);
}

// Function to remove an element from the Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    
    int item = queue->arr[queue->front];
    
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    
    printf("Dequeued item: %d\n", item);
    return item;
}

int main() {
    int capacity;
    printf("Enter capacity of Queue: ");
    scanf("%d", &capacity);
    
    Queue* queue = createQueue(capacity);
    int option, item;
    
    do {
        printf("\nSelect an option:\n");
        printf("1. Enqueue an item\n");
        printf("2. Dequeue an item\n");
        printf("3. Quit\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item != -1)
                    printf("Removed item: %d\n", item);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 3);
    
    return 0;
}