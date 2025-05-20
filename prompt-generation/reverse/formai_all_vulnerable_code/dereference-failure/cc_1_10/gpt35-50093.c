//FormAI DATASET v1.0 Category: Data structures visualization ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in the Linked List
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the Queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Add element to queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(q->rear) {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if(isEmpty(q)) {
        q->front = newNode;
    }
}

// Remove element from queue
int dequeue(struct Queue* q) {
    if(isEmpty(q)) {
        return -1;
    }
    int data = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;

    if(!q->front) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Print the Queue
void printQueue(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node* temp = q->front;
    while(temp) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Queue* q = createQueue();
    printf(" queue visualization\n right arrow -> enqueue\n down arrow -> dequeue\n\n");

    // Enqueue some elements
    enqueue(q,10);
    printf("10 -> \n");
    enqueue(q,20);
    printf("10 -> 20 -> \n");
    enqueue(q,30);
    printf("10 -> 20 -> 30 -> \n");
    enqueue(q,40);
    printf("10 -> 20 -> 30 -> 40 -> \n");

    printf("\nDequeue: %d\n",dequeue(q));
    printf("20 -> 30 -> 40 -> \n");
    printf("\nDequeue: %d\n",dequeue(q));
    printf("30 -> 40 -> \n");

    // Enqueue some more elements
    enqueue(q,50);
    printf("30 -> 40 -> 50 -> \n");
    enqueue(q,60);
    printf("30 -> 40 -> 50 -> 60 -> \n");
    
    return 0;
}