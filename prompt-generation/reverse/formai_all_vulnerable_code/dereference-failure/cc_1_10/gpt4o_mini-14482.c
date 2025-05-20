//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure of the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(q)) {
        q->front = q->rear = newNode; // Front and rear point to the new node
    } else {
        q->rear->next = newNode; // Link new node at the end of the queue
        q->rear = newNode; // Update the rear pointer
    }
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Error case
    }
    Node* temp = q->front;
    int dequeuedValue = temp->data;

    q->front = q->front->next; // Move front to the next node
    if (q->front == NULL) {
        q->rear = NULL; // If the queue is now empty, update the rear
    }
    free(temp); // Free the dequeued node
    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the contents of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    Node* current = q->front;
    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the entire queue
void clearQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Main function to demonstrate the queue operations
int main() {
    Queue* q = createQueue();
    
    int choice, value;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                clearQueue(q);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}