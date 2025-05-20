//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
// Romeo and Juliet - A Queue Implementation Story

#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for Queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Helper function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the given queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue an element at the end of the queue
void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    if(q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue an element from the front of the queue
int dequeue(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Alas, the queue is empty! How can I dequeue?\n");
        exit(1);
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if(q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to display all the elements currently in the queue
void display(struct Queue* q) {
    if(isEmpty(q)) {
        printf("The queue is empty, my love!\n");
        return;
    }
    struct Node* temp = q->front;
    printf("The elements in the queue, my beloved, are: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main: The Beginning of our Story
int main() {
    printf("Oh, Romeo, Romeo! Thou art a great programmer indeed!\n");
    struct Queue* q = createQueue();
    printf("My love, let us add some elements to the queue!\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("My dearest, let us dequeue an element from the queue!\n");
    printf("The dequeued element is: %d\n", dequeue(q));
    display(q);
    printf("My love, let us add some more elements to the queue!\n");
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    printf("Oh, how I love to see the elements in the queue!\n");
    return 0;
}