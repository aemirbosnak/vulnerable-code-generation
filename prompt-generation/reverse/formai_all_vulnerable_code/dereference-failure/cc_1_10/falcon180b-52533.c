//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Memory could not be allocated for the queue.\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Error: Memory could not be allocated for the node.\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

// Function to display the contents of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    free(q);
    return 0;
}