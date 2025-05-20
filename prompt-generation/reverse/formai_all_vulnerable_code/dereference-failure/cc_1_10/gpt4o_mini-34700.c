//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer {
    int id;
    char name[50];
    struct Customer* next;
} Customer;

typedef struct Queue {
    Customer* front;
    Customer* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int id, char* name) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->id = id;
    strcpy(newCustomer->name, name);
    newCustomer->next = NULL;

    if (isEmpty(q)) {
        q->front = newCustomer;
        q->rear = newCustomer;
    } else {
        q->rear->next = newCustomer;
        q->rear = newCustomer;
    }
    printf("Customer %s has been added to the queue.\n", name);
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("There are no customers in the queue.\n");
        return;
    }
    Customer* temp = q->front;
    printf("Customer %s is being served.\n", temp->name);
    q->front = q->front->next;
    free(temp);
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is currently empty.\n");
        return;
    }
    Customer* current = q->front;
    printf("Current Queue:\n");
    while (current != NULL) {
        printf("Customer ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int main() {
    Queue* coffeeShopQueue = createQueue();
    int choice, id;
    char name[50];

    while (1) {
        printf("\n--- Coffee Shop Queue Management ---\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                printf("Enter Customer Name: ");
                scanf("%s", name);
                enqueue(coffeeShopQueue, id, name);
                break;
            case 2:
                dequeue(coffeeShopQueue);
                break;
            case 3:
                displayQueue(coffeeShopQueue);
                break;
            case 4:
                freeQueue(coffeeShopQueue);
                printf("Exiting the program. Thank you!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}