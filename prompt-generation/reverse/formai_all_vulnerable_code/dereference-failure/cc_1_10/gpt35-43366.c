//FormAI DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Defining the Queue structure
struct Queue {
    int front, rear, maxsize;
    int* arr;
};

// Function to create a new queue
struct Queue* createQueue(int maxsize) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->maxsize = maxsize;
    queue->arr = (int*) malloc(queue->maxsize * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == queue->maxsize - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("\nQueue Overflow!\n");
        return;
    }
    else {
        if(queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->arr[queue->rear] = data;
        printf("\nItem %d has been added to the Queue.", data);
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    int data;
    if (isEmpty(queue)) {
        printf("\nQueue Underflow!\n");
        return -1;
    }
    else {
        data = queue->arr[queue->front];
        if(queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        }
        else {
            queue->front++;
        }
        printf("\nItem %d has been removed from the Queue.", data);
        return data;
    }
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nQueue is empty!\n");
        return;
    }
    else {
        printf("\nThe elements in the Queue are: ");
        for(int i=queue->front; i<=queue->rear; i++) {
            printf("%d ",queue->arr[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, item, maxsize;
    printf("Enter the maximum size of the Queue: ");
    scanf("%d", &maxsize);
    
    struct Queue* queue = createQueue(maxsize);
    
    while(1) {
        // Displaying the menu
        printf("\nQUEUE OPERATIONS:\n");
        printf("1. Add item to the Queue\n");
        printf("2. Remove item from the Queue\n");
        printf("3. Display the elements in the Queue\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter the item to be added to the Queue: ");
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
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}