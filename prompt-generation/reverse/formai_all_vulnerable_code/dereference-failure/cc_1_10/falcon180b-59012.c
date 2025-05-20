//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

/* Node structure definition */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Queue structure definition */
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

/* Function to create an empty queue */
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/* Function to check if the queue is empty */
int isEmpty(Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/* Function to enqueue an element into the queue */
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

/* Function to dequeue an element from the queue */
int dequeue(Queue* queue) {
    int data;
    Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        data = temp->data;
        queue->front = temp->next;

        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        free(temp);

        return data;
    }
}

/* Function to display the elements in the queue */
void display(Queue* queue) {
    Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    return 0;
}