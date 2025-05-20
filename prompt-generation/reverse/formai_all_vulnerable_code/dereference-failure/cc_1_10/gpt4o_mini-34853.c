//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the queue
typedef struct Node {
    int ticketNumber;
    char customerName[100];
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int ticketNumber, const char* customerName);
void dequeue(Queue* q);
void displayQueue(Queue* q);
int isEmpty(Queue* q);

int main() {
    Queue* ticketQueue = createQueue();
    int choice, ticketNumber;
    char customerName[100];

    do {
        printf("\n=== Cinema Ticketing System ===\n");
        printf("1. Buy Ticket\n");
        printf("2. Serve Next Customer\n");
        printf("3. Display Current Queue\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter Customer Name: ");
                fgets(customerName, sizeof(customerName), stdin);
                customerName[strcspn(customerName, "\n")] = 0; // Remove newline character
                ticketNumber = rand() % 1000 + 1; // Generate a random ticket number
                enqueue(ticketQueue, ticketNumber, customerName);
                printf("Ticket Number %d purchased by %s. Added to the queue.\n", ticketNumber, customerName);
                break;

            case 2:
                if (!isEmpty(ticketQueue)) {
                    printf("Serving the next customer:\n");
                    dequeue(ticketQueue);
                } else {
                    printf("The queue is empty! No customers to serve.\n");
                }
                break;

            case 3:
                printf("Current Queue:\n");
                displayQueue(ticketQueue);
                break;

            case 4:
                printf("Exiting the system. Thank you!\n");
                break;

            default:
                printf("Invalid option! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add a customer to the queue
void enqueue(Queue* q, int ticketNumber, const char* customerName) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->ticketNumber = ticketNumber;
    strcpy(temp->customerName, customerName);
    temp->next = NULL;

    if (q->rear == NULL) {
        // The queue is empty
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of the queue
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a customer from the queue
void dequeue(Queue* q) {
    if (q->front == NULL) {
        return; // Queue is empty
    }

    Node* temp = q->front;
    printf("Customer %s with Ticket Number %d served.\n", temp->customerName, temp->ticketNumber);
    q->front = q->front->next;

    // If the front becomes NULL, then change rear also as NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

// Function to display the current queue
void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    Node* temp = q->front;
    while (temp != NULL) {
        printf("Customer: %s | Ticket Number: %d\n", temp->customerName, temp->ticketNumber);
        temp = temp->next;
    }
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}