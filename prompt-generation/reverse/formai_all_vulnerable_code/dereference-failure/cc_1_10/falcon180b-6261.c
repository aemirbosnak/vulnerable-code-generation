//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a queue
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Error: Unable to create queue.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Get the size of the queue
int getSize(Queue* queue) {
    return queue->size;
}

// Add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Unable to add element to queue.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Remove the element from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Unable to remove element from queue.\n");
        exit(1);
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }
    queue->size--;
    return data;
}

// Display the elements of the queue
void display(Queue* queue) {
    Node* current = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        while (current!= NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Main function to test the queue implementation
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    display(queue);
    int removedElement = dequeue(queue);
    printf("Removed element: %d\n", removedElement);
    display(queue);
    int frontElement = dequeue(queue);
    printf("Front element: %d\n", frontElement);
    display(queue);
    int rearElement = dequeue(queue);
    printf("Rear element: %d\n", rearElement);
    display(queue);
    free(queue);
    return 0;
}