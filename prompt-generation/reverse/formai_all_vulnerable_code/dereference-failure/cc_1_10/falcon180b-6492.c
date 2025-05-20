//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    int count = 0;
    Node* temp = queue->front;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    if (count == 0)
        return 0;
    else
        return 1;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int data = -1;
    if (isEmpty(queue))
        printf("Queue is empty\n");
    else {
        Node* temp = queue->front;
        data = temp->data;
        queue->front = temp->next;
        free(temp);
        queue->size--;
    }
    return data;
}

// Function to display the elements of the queue
void display(Queue* queue) {
    Node* temp = queue->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}