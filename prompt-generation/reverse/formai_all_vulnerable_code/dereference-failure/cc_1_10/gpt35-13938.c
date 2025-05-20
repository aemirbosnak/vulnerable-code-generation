//FormAI DATASET v1.0 Category: Data structures visualization ; Style: real-life
// C Data Structures Visualization Example
// in a real-life style: a queue at a fast-food restaurant

#include <stdio.h>
#include <stdlib.h>

// Define queue node structure
typedef struct QueueNode {
    int customerNumber;
    struct QueueNode* next;
} QueueNode;

// Define queue structure
typedef struct Queue {
    int size;
    QueueNode* head;
    QueueNode* tail;
} Queue;

// Function to initialize a new queue
void initializeQueue(Queue* queue) {
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
}

// Function to add a customer to the queue
void addCustomer(Queue* queue, int customerNumber) {
    QueueNode* newCustomer = (QueueNode*) malloc(sizeof(QueueNode));
    newCustomer->customerNumber = customerNumber;
    newCustomer->next = NULL;

    if (queue->tail != NULL) {
        queue->tail->next = newCustomer;
    }

    queue->tail = newCustomer;

    if (queue->head == NULL) {
        queue->head = newCustomer;
    }

    queue->size++;
}

// Function to remove a customer from the queue
void removeCustomer(Queue* queue) {
    if (queue->head != NULL) {
        QueueNode* oldHead = queue->head;
        queue->head = queue->head->next;
        free(oldHead);

        if (queue->head == NULL) {
            queue->tail = NULL;
        }

        queue->size--;
    }
}

// Function to print the queue
void printQueue(Queue* queue) {
    QueueNode* current = queue->head;

    printf("Customers in queue: ");

    while (current != NULL) {
        printf("%d ", current->customerNumber);
        current = current->next;
    }

    printf("\n");
}

// Main program
int main() {
    Queue queue;
    initializeQueue(&queue);

    // Add some customers to the queue
    addCustomer(&queue, 1);
    addCustomer(&queue, 2);
    addCustomer(&queue, 3);

    // Print the queue
    printQueue(&queue);

    // Serve the first customer and remove them from the queue
    removeCustomer(&queue);

    // Print the updated queue
    printQueue(&queue);

    // Add some more customers to the queue
    addCustomer(&queue, 4);
    addCustomer(&queue, 5);

    // Print the updated queue
    printQueue(&queue);

    return 0;
}