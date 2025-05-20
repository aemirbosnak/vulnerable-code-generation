//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Node structure for the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to enqueue an element
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

// Function to dequeue an element
int dequeue(Queue* queue) {
    int data = -1;

    if (!isEmpty(queue)) {
        Node* temp = queue->front;
        data = temp->data;
        queue->front = temp->next;

        if (isEmpty(queue)) {
            queue->rear = NULL;
        }

        free(temp);
        queue->size--;
    }

    return data;
}

// Function to display the queue
void display(Queue* queue) {
    Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
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

    int dequeuedElement = dequeue(queue);
    printf("Dequeued element is: %d\n", dequeuedElement);

    display(queue);

    return 0;
}