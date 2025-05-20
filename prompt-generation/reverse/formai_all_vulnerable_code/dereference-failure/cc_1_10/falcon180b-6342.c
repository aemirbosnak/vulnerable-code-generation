//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
void createQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return true;
    } else {
        return false;
    }
}

// Function to check if the queue is full
bool isFull(struct Queue* queue) {
    if ((queue->rear == NULL)? true : false) {
        return false;
    } else {
        return true;
    }
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Error\n");
        exit(0);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    int value;
    struct Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        exit(0);
    }

    value = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    struct Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        exit(0);
    }

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Driver program to test above functions
int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    createQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    int value = dequeue(queue);
    printf("Dequeued value is: %d\n", value);

    display(queue);

    return 0;
}