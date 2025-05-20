//FormAI DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10 // You can adjust the queue size to whatever you like

// Create a structure for the queue
typedef struct {
    int front; // Front index
    int rear; // Rear index
    int size; // Size of the queue
    int *elements; // Elements of the queue
} Queue;

// Create a function to initialize the queue
Queue* initializeQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = -1; // Set front to -1, indicating empty queue
    q->rear = -1; // Set rear to -1, indicating empty queue
    q->size = QUEUE_SIZE; // Set the queue size
    q->elements = (int*) malloc(q->size * sizeof(int)); // Allocate memory for the queue elements
    printf("Queue initialized successfully!\n");
    return q;
}

// Create a function to check if the queue is full
int isFull(Queue *q) {
    if (q->rear == q->size - 1) { // If the rear is at the end of the queue
        return 1; // Queue is full
    }
    return 0; // Queue is not full
}

// Create a function to check if the queue is empty
int isEmpty(Queue *q) {
    if (q->front == -1 || q->front > q->rear) { // If the front is before the rear, or the front is -1
        return 1; // Queue is empty
    }
    return 0; // Queue is not empty
}

// Create a function to add an element to the queue
void enqueue(Queue *q, int element) {
    if (isFull(q)) { // If the queue is full
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) { // If the queue is empty
            q->front = 0; // Set both indices to 0
            q->rear = 0;
        } else { // If the queue is not empty
            q->rear++; // Move the rear index
        }
        q->elements[q->rear] = element; // Add the element to the queue
        printf("%d added to the queue!\n", element);
    }
}

// Create a function to remove an element from the queue
int dequeue(Queue *q) {
    int element;
    if (isEmpty(q)) { // If the queue is empty
        printf("Queue is empty!\n");
        return -1; // Return -1 to indicate an error
    } else {
        element = q->elements[q->front]; // Get the first element in the queue
        q->front++; // Move the front index
        printf("%d removed from the queue!\n", element);
    }
    return element; // Return the element
}

// Create a function to display the elements in the queue
void display(Queue *q) {
    int i;
    if (isEmpty(q)) { // If the queue is empty
        printf("Queue is empty!\n");
    } else {
        printf("Elements in the queue: ");
        for (i = q->front; i <= q->rear; i++) { // Loop through the queue
            printf("%d ", q->elements[i]); // Display each element
        }
        printf("\n");
    }
}

int main() {
    Queue *q = initializeQueue(); // Initialize the queue
    enqueue(q, 5); // Add an element to the queue
    enqueue(q, 10); // Add an element to the queue
    enqueue(q, 15); // Add an element to the queue
    display(q); // Display the elements in the queue
    dequeue(q); // Remove an element from the queue
    display(q); // Display the elements in the queue
    enqueue(q, 20); // Add an element to the queue
    enqueue(q, 25); // Add an element to the queue
    enqueue(q, 30); // Add an element to the queue
    dequeue(q); // Remove an element from the queue
    dequeue(q); // Remove an element from the queue
    display(q); // Display the elements in the queue
    enqueue(q, 35); // Add an element to the queue
    display(q); // Display the elements in the queue
    return 0;
}