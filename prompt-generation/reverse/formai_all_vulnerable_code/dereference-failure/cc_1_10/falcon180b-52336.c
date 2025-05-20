//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Unable to create queue.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if queue is empty
int isEmpty(Queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add element to rear of queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Unable to add element to queue.\n");
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
}

// Function to remove element from front of queue
int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        exit(1);
    } else if (q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        data = q->front->data;
        free(q->front);
        q->front = q->front->next;
    }
    return data;
}

// Function to display elements in queue
void display(Queue* q) {
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Front element is: %d\n", dequeue(q));
    display(q);
    printf("Front element is: %d\n", dequeue(q));
    display(q);
    printf("Front element is: %d\n", dequeue(q));
    display(q);
    return 0;
}