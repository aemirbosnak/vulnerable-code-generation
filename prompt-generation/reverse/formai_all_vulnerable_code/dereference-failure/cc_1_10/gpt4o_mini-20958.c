//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 10 // Maximum size of the queue

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("\nQueue is full! The challenge intensifies.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("\nEnqueued: %d", value);
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty! No elements to dequeue.\n");
        return -1; // Return an error value
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Reset the queue
    }
    printf("\nDequeued: %d", item);
    return item;
}

// Peek function to see the front element without removing
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty! Nothing to peek.\n");
        return -1; // Return an error value
    }
    return q->items[q->front];
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty! An empty void...\n");
        return;
    }
    printf("\nQueue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Function to special print queue based on algorithm
void specialDisplay(Queue* q) {
    if (isEmpty(q)) {
        printf("\nNothing to reveal in the depths of the queue.\n");
        return;
    }
    printf("\nSpecial Display - Elements in Reverse Order: ");
    for (int i = q->rear; i >= q->front; i--) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function to interact with the user
int main() {
    Queue* q = createQueue();
    char command[20];
    int value;
    
    printf("Welcome to the Queue Adventure!\n");
    printf("Commands: enqueue <number>, dequeue, peek, display, specialDisplay, exit\n");
    
    while (1) {
        printf("\nEnter a command: ");
        scanf("%s", command);

        if (strcmp(command, "enqueue") == 0) {
            printf("Enter number to enqueue: ");
            scanf("%d", &value);
            enqueue(q, value);
        } 
        else if (strcmp(command, "dequeue") == 0) {
            dequeue(q);
        } 
        else if (strcmp(command, "peek") == 0) {
            int frontValue = peek(q);
            if (frontValue != -1) {
                printf("\nFront value is: %d\n", frontValue);
            }
        } 
        else if (strcmp(command, "display") == 0) {
            display(q);
        } 
        else if (strcmp(command, "specialDisplay") == 0) {
            specialDisplay(q);
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting the adventure...\n");
            break;
        } 
        else {
            printf("Mistyped command. Try again with clear eyes.\n");
        }
    }

    free(q);
    return 0;
}