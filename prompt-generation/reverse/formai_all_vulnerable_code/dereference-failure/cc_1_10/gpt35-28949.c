//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent each node of Queue
typedef struct node {
    int data;
    struct node* next;
} QueueNode;

// Structure to perform Queue operations
typedef struct queue {
    QueueNode *front, *rear;
} Queue;

// Function to create a new node in Queue
QueueNode* createNode(int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty Queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add data at the rear end of Queue
void enqueue(Queue* queue, int data) {
    QueueNode* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

//Function to remove data from the front end of Queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to get data at the front end of Queue
int front(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Function to display the Queue
void display(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    QueueNode* temp = queue->front;
    while (temp) {
        printf("-> %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();

    // Add elements into the Queue
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 20);

    // Display the Queue
    display(queue);

    // Remove an element from the Queue
    printf("Front element: %d\n", front(queue));
    printf("Element dequeued: %d\n", dequeue(queue));

    // Display the Queue
    display(queue);

    return 0;
}