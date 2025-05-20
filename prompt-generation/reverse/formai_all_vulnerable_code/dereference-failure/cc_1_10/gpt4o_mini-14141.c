//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure which contains pointers to the front and rear of the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        // If the queue is empty, new node becomes both front and rear
        queue->front = queue->rear = newNode;
        newNode->next = queue->front; // Circular link
    } else {
        // Add the new node at the end of the queue and update the rear
        queue->rear->next = newNode;
        queue->rear = newNode;
        newNode->next = queue->front; // Circular link
    }
    printf("Enqueued: %d\n", data);
}

// Function to remove and return an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1; // Indicating an empty queue
    }
    
    Node* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        // Only one element in the queue
        queue->front = queue->rear = NULL;
    } else {
        // Move front to the next node and update the rear's next pointer
        queue->front = queue->front->next;
        queue->rear->next = queue->front; // Circular link
    }

    free(temp);
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to display the contents of the queue
void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    Node* current = queue->front;
    printf("Queue contents: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

// Function to free all allocated memory for the queue
void freeQueue(Queue* queue) {
    if (queue->front == NULL) {
        free(queue);
        return;
    }

    Node* current = queue->front;
    Node* temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != queue->front);

    free(queue);
    printf("Queue memory freed successfully!\n");
}

// Main function to demonstrate queue operations
int main() {
    Queue* queue = createQueue();

    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                freeQueue(queue);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}