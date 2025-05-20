//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Defining the queue structure
typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

// Function to create a new queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->next = NULL;
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = queue->next;
    queue->next = newNode;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue) {
    if (queue->next == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    Queue *temp = queue->next;
    int data = temp->data;
    queue->next = temp->next;
    free(temp);
    return data;
}

// Function to print the queue
void printQueue(Queue *queue) {
    printf("Queue: ");
    Queue *temp = queue->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    Queue *queue = createQueue();

    // Enqueueing some elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Printing the queue
    printQueue(queue);

    // Dequeueing an element from the queue
    int data = dequeue(queue);

    // Printing the queue
    printQueue(queue);

    return 0;
}