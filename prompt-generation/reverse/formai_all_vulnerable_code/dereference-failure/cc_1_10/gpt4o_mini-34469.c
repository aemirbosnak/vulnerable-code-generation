//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for the Queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a Queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add an item to Queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to remove an item from Queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1; // Return a sentinel value
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to display the Queue
void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory allocated to the Queue
void freeQueue(Queue* queue) {
    Node* current = queue->front;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

// Main function to demonstrate Queue operations
int main() {
    Queue* queue = createQueue();
    int choice, data;

    do {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                printf("%d enqueued to the queue\n", data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("%d dequeued from the queue\n", data);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting...\n");
                freeQueue(queue);
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}