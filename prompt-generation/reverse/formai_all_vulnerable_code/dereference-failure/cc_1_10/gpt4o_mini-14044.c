//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct Customer {
    int id;
    char name[30];
} Customer;

typedef struct Queue {
    Customer customers[MAX];
    int front, rear, count;
} Queue;

// Function declarations
Queue* createQueue();
int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, Customer customer);
Customer dequeue(Queue* q);
void displayQueue(Queue* q);
void simulateCoffeeShop();

int main() {
    simulateCoffeeShop();
    return 0;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    return q;
}

int isFull(Queue* q) {
    return q->count == MAX;
}

int isEmpty(Queue* q) {
    return q->count == 0;
}

void enqueue(Queue* q, Customer customer) {
    if (isFull(q)) {
        printf("Queue is full! %s cannot enter the line.\n", customer.name);
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->customers[q->rear] = customer;
    q->count++;
    printf("%s has entered the queue.\n", customer.name);
}

Customer dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No customer to serve.\n");
        Customer emptyCustomer = {-1, ""};
        return emptyCustomer;
    }
    Customer servedCustomer = q->customers[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    printf("%s is being served!\n", servedCustomer.name);
    return servedCustomer;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is currently empty.\n");
    } else {
        printf("Current Queue: ");
        for (int i = 0; i < q->count; i++) {
            int index = (q->front + i) % MAX;
            printf("[%d: %s] ", q->customers[index].id, q->customers[index].name);
        }
        printf("\n");
    }
}

void simulateCoffeeShop() {
    Queue* queue = createQueue();
    int choice;
    int idCounter = 1;

    while (1) {
        printf("\n--- Coffee Shop Simulation ---\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Customer newCustomer;
                newCustomer.id = idCounter++;
                printf("Enter the name of the customer: ");
                scanf("%s", newCustomer.name);
                enqueue(queue, newCustomer);
                break;
            }
            case 2: {
                Customer servedCustomer = dequeue(queue);
                break;
            }
            case 3: {
                displayQueue(queue);
                break;
            }
            case 4: {
                printf("Exiting the Coffee Shop Simulation. Have a great day!\n");
                free(queue);
                return;
            }
            default: {
                printf("Invalid option! Please try again.\n");
                break;
            }
        }
    }
}