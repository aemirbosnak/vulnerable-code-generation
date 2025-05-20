//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a customer
typedef struct Customer {
    int id;
    char name[50];
    struct Customer* next;
} Customer;

// Define a structure for the queue
typedef struct Queue {
    Customer* front;
    Customer* rear;
} Queue;

// Function to create a new customer
Customer* createCustomer(int id, const char* name) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->id = id;
    strcpy(newCustomer->name, name);
    newCustomer->next = NULL;
    return newCustomer;
}

// Function to initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to add a customer to the queue
void enqueue(Queue* queue, int id, const char* name) {
    Customer* newCustomer = createCustomer(id, name);
    if (isEmpty(queue)) {
        queue->front = newCustomer;
        queue->rear = newCustomer;
    } else {
        queue->rear->next = newCustomer;
        queue->rear = newCustomer;
    }
    printf("Customer %s (ID: %d) has been added to the queue.\n", name, id);
}

// Function to serve the next customer
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("No customers in the queue to serve.\n");
        return;
    }
    Customer* temp = queue->front;
    printf("Serving customer %s (ID: %d).\n", temp->name, temp->id);

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

// Function to display the queue status
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is currently empty.\n");
        return;
    }
    Customer* temp = queue->front;
    printf("Current queue:\n");
    while (temp != NULL) {
        printf("Customer %s (ID: %d)\n", temp->name, temp->id);
        temp = temp->next;
    }
}

// Main function to run the cinema ticketing system
int main() {
    Queue* ticketQueue = createQueue();
    int choice, id;
    char name[50];

    do {
        printf("\n--- Cinema Ticketing System ---\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Serve Next Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer ID: ");
                scanf("%d", &id);
                printf("Enter customer name: ");
                scanf("%s", name);
                enqueue(ticketQueue, id, name);
                break;
            case 2:
                dequeue(ticketQueue);
                break;
            case 3:
                displayQueue(ticketQueue);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the queue memory before exit
    while (!isEmpty(ticketQueue)) {
        dequeue(ticketQueue);
    }
    free(ticketQueue);

    return 0;
}