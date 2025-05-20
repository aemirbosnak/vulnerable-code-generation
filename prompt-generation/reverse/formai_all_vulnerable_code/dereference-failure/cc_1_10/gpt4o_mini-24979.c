//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Queue Node
typedef struct Node {
    int id;
    char name[50];
    struct Node* next;
} Node;

// Structure for Queue
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to add a customer to the queue
void enqueue(Queue* queue, int id, const char* name) {
    Node* newNode = createNode(id, name);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
    printf("Customer %s with ID %d added to the queue.\n", name, id);
}

// Function to remove a customer from the queue
Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty. No customer to serve.\n");
        return NULL;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("Customer %s with ID %d has been served.\n", temp->name, temp->id);
    return temp;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("(ID: %d, Name: %s) ", current->id, current->name);
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    Queue* queue = createQueue();
    int choice, id;
    char name[50];

    do {
        printf("\nCustomer Service Counter\n");
        printf("1. Add customer\n");
        printf("2. Serve customer\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer ID: ");
                scanf("%d", &id);
                printf("Enter customer name: ");
                scanf("%s", name);
                enqueue(queue, id, name);
                break;
            case 2: {
                Node* servedCustomer = dequeue(queue);
                free(servedCustomer);
                break;
            }
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    // Cleanup the queue before exiting
    while (!isEmpty(queue)) {
        Node* servedCustomer = dequeue(queue);
        free(servedCustomer);
    }
    free(queue);
    
    return 0;
}