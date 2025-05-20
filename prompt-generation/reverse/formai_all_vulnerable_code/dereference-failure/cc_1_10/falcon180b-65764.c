//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the structure for the queue
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Function to create a new node with given data
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue *queue, int data) {
    Node *newNode = createNode(data);
    if (newNode == NULL)
        return;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    Node *tempNode = queue->front;
    int data = tempNode->data;
    queue->front = tempNode->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(tempNode);
    return data;
}

// Function to print the elements of the queue
void printQueue(Queue *queue) {
    Node *currentNode = queue->front;
    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    Queue *myQueue = createQueue();
    if (myQueue == NULL)
        return 1;

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    printQueue(myQueue);

    int removedElement = dequeue(myQueue);
    printf("Removed element: %d\n", removedElement);

    printQueue(myQueue);

    return 0;
}