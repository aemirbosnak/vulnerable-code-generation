//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Queue structure
typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

// Initialize a queue
Queue* createQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == NULL;
}

// Enqueue an element
void enqueue(Queue *q, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    } else {
        Node *temp = q->front;
        int data = temp->data;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
}

// Print the queue
void printQueue(Queue *q) {
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a queue
    Queue *q = createQueue();

    // Enqueue some elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    printf("Queue: ");
    printQueue(q);

    // Dequeue some elements
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);

    // Print the queue
    printf("Queue: ");
    printQueue(q);

    return 0;
}