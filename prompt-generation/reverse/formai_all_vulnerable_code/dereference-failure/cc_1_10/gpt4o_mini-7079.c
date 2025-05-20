//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold passenger information
typedef struct Passenger {
    int id;
    char name[50];
    char destination[50];
} Passenger;

// Structure to represent the queue
typedef struct Queue {
    Passenger* passengers;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->passengers = (Passenger*)malloc(capacity * sizeof(Passenger));
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == (queue->rear + 1) % queue->capacity);
}

// Function to add a passenger to the queue
void enqueue(Queue* queue, Passenger passenger) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot add passenger %s.\n", passenger.name);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->passengers[queue->rear] = passenger;
    printf("Passenger %s is on board for %s.\n", passenger.name, passenger.destination);
}

// Function to remove a passenger from the queue
Passenger dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No passengers to remove.\n");
        Passenger emptyPassenger = {0, "", ""};
        return emptyPassenger;
    }
    Passenger passenger = queue->passengers[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    printf("Passenger %s has exited the hyperloop to %s.\n", passenger.name, passenger.destination);
    return passenger;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("No passengers in the queue.\n");
        return;
    }
    printf("Current passengers in the hyperloop:\n");
    int i = queue->front;
    while (i != (queue->rear + 1) % queue->capacity) {
        printf(" - Passenger ID: %d, Name: %s, Destination: %s\n", 
                queue->passengers[i].id, 
                queue->passengers[i].name, 
                queue->passengers[i].destination);
        i = (i + 1) % queue->capacity;
    }
}

// Main function to test the queue implementation
int main() {
    int capacity = 5; // Maximum number of passengers
    Queue* queue = createQueue(capacity);

    // Creating some sample passengers
    Passenger p1 = {1, "Alice", "Mars"};
    Passenger p2 = {2, "Bob", "Venus"};
    Passenger p3 = {3, "Charlie", "Jupiter"};
    Passenger p4 = {4, "Diana", "Saturn"};
    Passenger p5 = {5, "Eve", "Neptune"};
    Passenger p6 = {6, "Frank", "Pluto"};

    // Enqueuing passengers
    enqueue(queue, p1);
    enqueue(queue, p2);
    enqueue(queue, p3);
    enqueue(queue, p4);
    enqueue(queue, p5);
    enqueue(queue, p6); // This should show a queue full message

    displayQueue(queue);
    
    // Dequeuing passengers
    dequeue(queue);
    dequeue(queue);
    
    displayQueue(queue); // Display current passengers after some exits

    // Free allocated memory
    free(queue->passengers);
    free(queue);

    return 0;
}