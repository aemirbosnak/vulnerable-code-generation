//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to initialize queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Function to check if queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to enqueue an element
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

// Function to dequeue an element
int dequeue(Queue* q) {
    int data = -1;
    Node* temp = q->front;

    if (!isEmpty(q)) {
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
        q->size--;
    }

    return data;
}

// Function to display queue
void display(Queue* q) {
    Node* temp = q->front;
    printf("Queue: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int data = dequeue(&q);
    printf("Dequeued element: %d\n", data);

    display(&q);

    return 0;
}