//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5 // The maximum number of customers in the queue at once

// Structure to represent a Queue
struct Queue {
    int front, rear, size;
    int tickets[MAX_SIZE];
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->rear = MAX_SIZE - 1; // rear is at the last position
    return queue;
}

// Queue is full when size becomes equal to the max size
bool isFull(struct Queue* queue) {
    return (queue->size == MAX_SIZE);
}

// Queue is empty when size is 0
bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add a ticket request to the queue
void enqueue(struct Queue* queue, int ticketNumber) {
    if (isFull(queue)) {
        printf("Adventure Land Queue is full! Please wait for the next showing.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->tickets[queue->rear] = ticketNumber;
    queue->size += 1;
    printf("Ticket request %d has been added to the queue! Welcome to Adventure Land!\n", ticketNumber);
}

// Function to remove a ticket request from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty! No ticket requests to process.\n");
        return -1;
    }
    int ticketNumber = queue->tickets[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size -= 1;
    printf("Processing ticket request %d... Enjoy the rides at Adventure Land!\n", ticketNumber);
    return ticketNumber;
}

// Function to display the current queue status
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is currently empty. Come join us for a thrilling adventure!\n");
        return;
    }
    printf("Current Queue: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->tickets[(queue->front + i) % MAX_SIZE]);
    }
    printf("\n");
}

// Main program to simulate ticket booking system
int main() {
    struct Queue* queue = createQueue();
    int choice, ticketNumber;

    while (true) {
        printf("\n***** Welcome to Adventure Land Ticketing System *****\n");
        printf("1. Request Ticket\n");
        printf("2. Process Ticket\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("*******************************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your ticket request number (1-100): ");
                scanf("%d", &ticketNumber);
                enqueue(queue, ticketNumber);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Thank you for using the Adventure Land Ticketing System! Have a magical day!\n");
                free(queue); // Freeing allocated memory
                return 0;
            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
        }
    }
    return 0;
}