//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to add an item to the queue
void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    
    // If the queue is empty, then the new node is both front and rear
    if (isEmpty(q)) {
        q->front = q->rear = temp;
        printf("Enqueued: %d\n", data);
        return;
    }

    // Add the new node at the end of the queue
    q->rear->next = temp;
    q->rear = temp;
    printf("Enqueued: %d\n", data);
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    // Store the previous front and move front one node ahead
    struct Node* temp = q->front;
    int dequeuedData = temp->data;

    q->front = q->front->next;

    // If front becomes NULL, then update rear as NULL as well
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    printf("Dequeued: %d\n", dequeuedData);
    return dequeuedData;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    struct Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);

    dequeue(q);
    dequeue(q);
    displayQueue(q);

    enqueue(q, 40);
    displayQueue(q);
    
    dequeue(q);
    dequeue(q);
    dequeue(q); // Dequeue from empty queue
    displayQueue(q);

    // Clean up remaining queue
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q); // Free the queue structure
    return 0;
}