//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function for creating an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function for checking if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == NULL)
        return 1;
    else
        return 0;
}

// Function for adding an element to the rear of the queue
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function for removing an element from the front of the queue
int dequeue(Queue* queue) {
    int value;
    Node* temp = queue->front;

    if (isEmpty(queue))
        return -1;

    value = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return value;
}

// Function for displaying the elements in the queue
void display(Queue* queue) {
    Node* temp = queue->front;

    if (isEmpty(queue))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    return 0;
}