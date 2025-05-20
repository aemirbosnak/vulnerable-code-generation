//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the structure of each element in the queue
typedef struct {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to initialize the queue
void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    data = temp->data;
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

// Function to display the current state of the queue
void display(Queue* q) {
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the queue implementation
int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);
    enqueue(&q, 40);
    display(&q);
    return 0;
}