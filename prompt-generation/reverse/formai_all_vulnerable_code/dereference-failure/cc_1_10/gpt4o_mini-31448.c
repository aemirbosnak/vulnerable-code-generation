//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the Queue
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        q->rear->next = newNode;
        newNode->next = q->front;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1; // Return an error value
    }
    
    int value = q->front->data;
    if (q->front == q->rear) { // Only one element
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        Node* temp = q->front;
        q->rear->next = q->front->next; // Rear points to second node
        q->front = q->front->next;
        free(temp);
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to get the front item of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// Function to display the contents of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* current = q->front;
    printf("Queue contents: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != q->front);
    printf("\n");
}

// Function to free the entire queue
void freeQueue(Queue* q) {
    if (isEmpty(q)) {
        free(q);
        return;
    }
    
    Node* current = q->front;
    Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while(current != q->front);
    
    free(q);
}

// Main function demonstrating Queue operations
int main() {
    Queue* q = createQueue();
    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                value = peek(q);
                if (value != -1) {
                    printf("Front item: %d\n", value);
                }
                break;
            case 4:
                displayQueue(q);
                break;
            case 5:
                freeQueue(q);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}