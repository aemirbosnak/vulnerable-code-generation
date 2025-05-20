//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void displayQueue(Queue* q);
void recursiveDisplay(Node* node);
void freeQueue(Queue* q);
int isEmpty(Queue* q);

int main() {
    Queue* queue = createQueue();
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
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
                if (!isEmpty(queue)) {
                    value = dequeue(queue);
                    printf("Dequeued value: %d\n", value);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;
            case 3:
                printf("Current Queue: ");
                displayQueue(queue);
                break;
            case 4:
                freeQueue(queue);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    
    q->size++;
}

// Dequeue operation
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue Underflow\n");
        return -1; // Error value
    }
    
    Node* temp = q->front;
    int value = temp->data;
    
    q->front = q->front->next;
    free(temp);
    
    if (q->front == NULL) {
        q->rear = NULL; // Queue is now empty
    }

    q->size--;
    return value;
}

// Display Queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    recursiveDisplay(q->front);
    printf("\n");
}

// Recursive function to display queue nodes
void recursiveDisplay(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    recursiveDisplay(node->next);
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Free memory allocated to queue
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}