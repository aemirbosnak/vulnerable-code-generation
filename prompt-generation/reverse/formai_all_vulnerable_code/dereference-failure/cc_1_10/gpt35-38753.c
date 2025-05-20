//FormAI DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for Queue Node
struct Node {
    int data;
    struct Node* next;
};

// Structure for Queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new Node in Queue
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Queue
struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to check if Queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to enqueue an element in the Queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the Queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty!\n");
    }
    else if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
}

// Function to display the elements of Queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty!\n");
    }
    else {
        struct Node* temp = queue->front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue* queue = createQueue();  // Creating a Queue

    // Enqueuing elements in the Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Queue elements after Enqueue:\n");
    display(queue); // Displaying the elements of Queue after enqueue

    dequeue(queue); // Dequeing an element from Queue
    dequeue(queue); // Again dequeing an element from Queue

    printf("Queue elements after Dequeue:\n");
    display(queue); // Displaying the elements of Queue after dequeue

    return 0;
}