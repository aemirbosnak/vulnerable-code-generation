//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // We decided to only queue up 5 items, we don't wanna hog the whole memory!

// Let's define our Queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->rear == -1 && queue->front == -1;
}

// Add elements to the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Sorry buddy! The queue is full! Take it easy yo, we only have limited space!\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("%d has been added to the Queue! Going with the flow huh?\n", value);
    }
}

// Remove elements from the queue
int dequeue(Queue* queue) {
    int value;
    if (isEmpty(queue)) {
        printf("Hey pal, the Queue is empty, no need to be so pushy, relax!\n");
        return -1;
    } else {
        value = queue->items[queue->front];
        if (queue->front >= queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        printf("%d has left the Queue. Wasn't feeling it I guess. Sad.\n", value);
        return value;
    }
}

// Let's print out the Queue!
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The Queue is empty, there's nothing to display. Don't be so needy!\n");
    } else {
        printf("Queue:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d\n", queue->items[i]);
        }
    }
}

// Main method to drive the program
int main() {
    Queue* queue;
    queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
  
    printf("Hello there, I'm a Queue program! Let's start things off using enqueue.\n"); 
    enqueue(queue, 2); // Add values
    enqueue(queue, 4);
    enqueue(queue, 6);
    display(queue); // Show queue
    dequeue(queue); // Remove values
    display(queue);
    enqueue(queue, 8); // Add values
    display(queue);
    dequeue(queue); // Remove values
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    return 0;
}