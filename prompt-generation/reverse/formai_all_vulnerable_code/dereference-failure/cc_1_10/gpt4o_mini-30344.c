//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int value) {
    Node* temp = createNode(value);
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue an item.\n");
        return -1; // Indicating that the queue is empty
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

// Function to get the front item of the queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front item available.\n");
        return -1; // Indicating that the queue is empty
    }
    return queue->front->data;
}

// Function to get the rear item of the queue
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No rear item available.\n");
        return -1; // Indicating that the queue is empty
    }
    return queue->rear->data;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
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

// Command-line interface for interacting with the queue
void queueInterface() {
    Queue* queue = createQueue();
    int choice, value;

    do {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Front\n");
        printf("4. Display Rear\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Select an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(queue, value);
            printf("Enqueued %d to the queue.\n", value);
            break;
        case 2:
            value = dequeue(queue);
            if (value != -1) {
                printf("Dequeued %d from the queue.\n", value);
            }
            break;
        case 3:
            value = front(queue);
            if (value != -1) {
                printf("Front item: %d\n", value);
            }
            break;
        case 4:
            value = rear(queue);
            if (value != -1) {
                printf("Rear item: %d\n", value);
            }
            break;
        case 5:
            displayQueue(queue);
            break;
        case 6:
            printf("Exiting the program. Thank you!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    // Free allocated memory for the queue
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    queueInterface();
    return 0;
}