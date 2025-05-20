//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Define the Node struct for our linked list
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Define the Queue struct, which keeps track of the front and back nodes of the linked list
typedef struct Queue {
    Node* front;
    Node* back;
} Queue;

// Initialize a new empty queue
void init(Queue* q) {
    q->front = NULL;
    q->back = NULL;
}

// Add an element to the end of the queue
void enqueue(Queue* q, int val) {
    // Create a new node for the element
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    // If the queue is empty, set the front and back to the new node
    if (q->front == NULL) {
        q->front = newNode;
        q->back = newNode;
    }
    // Otherwise, add the new node to the back of the queue
    else {
        q->back->next = newNode;
        q->back = newNode;
    }
}

// Remove and return the element at the front of the queue
int dequeue(Queue* q) {
    // If the queue is empty, return an error message
    if (q->front == NULL) {
        printf("Error: queue is empty\n");
        return -1;
    }

    // Retrieve the element at the front of the queue
    int val = q->front->val;

    // Move the front of the queue to the next element
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    // If the queue is now empty, reset the back to NULL
    if (q->front == NULL) {
        q->back = NULL;
    }

    // Return the removed element
    return val;
}

// Output the elements of the queue to the console
void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
    } 
    else {
        printf("Queue: ");
        Node* current = q->front;
        while (current != NULL) {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a new queue
    Queue q;
    init(&q);

    // Enqueue some elements into the queue
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    // Output the queue
    printQueue(&q);

    // Dequeue some elements and output them
    printf("Dequeued %d\n", dequeue(&q));
    printf("Dequeued %d\n", dequeue(&q));

    // Output the updated queue
    printQueue(&q);

    // Enqueue some more elements and output them
    enqueue(&q, 5);
    enqueue(&q, 6);
    printQueue(&q);

    // Continue dequeuing elements until the queue is empty
    while (q.front != NULL) {
        printf("Dequeued %d\n", dequeue(&q));
    }
    printQueue(&q);

    return 0;
}