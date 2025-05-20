//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Struct for representing a baggage item
typedef struct {
    int id;
    char status;
    struct Baggage* next;
    struct Baggage* prev;
} Baggage;

// Function to initialize a new baggage item
Baggage* newBaggage(int id, char status) {
    Baggage* newItem = (Baggage*) malloc(sizeof(Baggage));
    newItem->id = id;
    newItem->status = status;
    newItem->next = NULL;
    newItem->prev = NULL;
    return newItem;
}

// Function to print the current state of the baggage queue
void printQueue(Baggage* queue) {
    Baggage* current = queue;
    while (current!= NULL) {
        printf("%d: %c\n", current->id, current->status);
        current = current->next;
    }
}

// Function to check the current status of a baggage
void checkStatus(Baggage* queue, int id) {
    Baggage* current = queue;
    while (current!= NULL) {
        if (current->id == id) {
            printf("Baggage with ID %d is in state %c\n", id, current->status);
            return;
        }
        current = current->next;
    }
    printf("Baggage with ID %d does not exist\n", id);
}

// Function to enqueue a baggage item to the end of the queue
void enqueue(Baggage* queue, int id, char status) {
    Baggage* newItem = newBaggage(id, status);
    if (queue == NULL) {
        queue = newItem;
        return;
    }
    Baggage* current = queue;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newItem;
    newItem->prev = current;
}

// Function to dequeue a baggage item from the front of the queue
Baggage* dequeue(Baggage* queue) {
    Baggage* current = queue;
    if (queue == NULL) {
        return NULL;
    }
    Baggage* temp = current->next;
    current->next = NULL;
    current->prev = NULL;
    free(current);
    return temp;
}

// Function to check if the queue is empty
int isQueueEmpty(Baggage* queue) {
    return (queue == NULL);
}

// Main program
int main() {
    Baggage* baggageQueue = NULL;

    // Create some baggage items and enqueue them to the queue
    enqueue(baggageQueue, 1, 'c');
    enqueue(baggageQueue, 2, 'i');
    enqueue(baggageQueue, 3, 't');
    enqueue(baggageQueue, 4, 'd');
    enqueue(baggageQueue, 5, 'd');

    // Print the current state of the queue
    printQueue(baggageQueue);

    // Check the status of some baggage items
    checkStatus(baggageQueue, 1);
    checkStatus(baggageQueue, 6);

    // Dequeue and print the first item in the queue
    Baggage* dequeuedItem = dequeue(baggageQueue);
    printf("Dequeued item: %d, %c\n", dequeuedItem->id, dequeuedItem->status);

    // Print the current state of the queue
    printQueue(baggageQueue);

    // Check the status of some baggage items
    checkStatus(baggageQueue, 1);
    checkStatus(baggageQueue, 6);

    // Check if the queue is empty
    printf("Queue is empty: %d\n", isQueueEmpty(baggageQueue));

    return 0;
}