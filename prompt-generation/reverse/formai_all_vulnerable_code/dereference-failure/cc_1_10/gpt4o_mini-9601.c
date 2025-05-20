//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a Node structure for the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        perror("Failed to create queue");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to enqueue an item into the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to enqueue");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear != NULL) {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;

    if (queue->front == NULL) {
        queue->front = newNode;
    }

    queue->size++;
}

// Function to dequeue an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the queue
void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Main function for user interaction
int main() {
    Queue* queue = createQueue();
    int choice, data;

    while (true) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            while(getchar() != '\n'); // Clear the invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a number to enqueue: ");
                if (scanf("%d", &data) == 1) {
                    enqueue(queue, data);
                    printf("%d enqueued to queue.\n", data);
                } else {
                    fprintf(stderr, "Invalid input. Please enter an integer.\n");
                    while(getchar() != '\n'); // Clear the invalid input
                }
                break;
            case 2:
                data = dequeue(queue);
                printf("%d dequeued from queue.\n", data);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                freeQueue(queue);
                printf("Exiting. Queue has been freed.\n");
                return 0;
            default:
                fprintf(stderr, "Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }

    return 0;
}