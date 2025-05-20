//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue structure definition
typedef struct queue {
    int top;
    unsigned capacity;
    char *array;
} Queue;

// Function to create a queue of given capacity.
Queue *createQueue(unsigned capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->top = -1;
    queue->array = (char *)malloc(queue->capacity * sizeof(char));
    return queue;
}

// Checks if the queue is empty.
int isEmpty(Queue *queue) {
    return (queue->top < 0);
}

// Adds an item to the queue.
void enqueue(Queue *queue, char newelement) {
    if (queue->top >= queue->capacity - 1) {
        printf("\nQueue is Full!");
        return;
    }
    queue->array[++queue->top] = newelement;
}

// Removes an item from the queue.
char dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("\nQueue is Empty!");
        return '\0';
    }
    return queue->array[queue->top--];
}

// Driver code
int main() {
    Queue *q = createQueue(5); // Queue of capacity 5

    printf("\nInserting elements in the Queue\n");

    // Let us insert some elements
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    enqueue(q, 'E');

    // Let us print the elements in the Queue
    printf("\nElements in the Queue: ");
    while (!isEmpty(q)) {
        printf("%c ", dequeue(q));
    }

    printf("\n\nDeleting and Inserting elements in the Queue\n");

    // Let us delete an element from the queue and insert a new one
    char deleted = dequeue(q);
    printf("Deleted Element: %c \n", deleted);
    enqueue(q, 'F');

    // Let us print the elements in the Queue
    printf("\nElements in the Queue: ");
    while (!isEmpty(q)) {
        printf("%c ", dequeue(q));
    }

    printf("\n\nFreeing memory\n");

    // Freeing memory allocated to the queue and its array
    free(q->array);
    free(q);

    return 0;
}