//FormAI DATASET v1.0 Category: Queue ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10 // Maximum size of queue

struct Queue {
    int front, rear, size;
    char* arr[MAX_SIZE];
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

    queue->front = queue->size = 0;
    queue->rear = MAX_SIZE - 1;

    return queue;
}

// Function to check if the queue is full
bool isFull(struct Queue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an affirmation to the queue
void enqueue(struct Queue* queue, char* affirmation) {
    if (isFull(queue)) {
        printf("Queue of Appreciation is full! Please wait until someone receives your compliments. \n");
        return;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->arr[queue->rear] = affirmation;
        queue->size++;
        printf("Your compliments have been added to the queue! Thank you for spreading love and joy. \n");
    }
}

// Function to remove an affirmation from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue of Appreciation is empty! Please wait till someone adds compliments. \n");
        return;
    } else {
        printf("Here's the next compliment: %s \n", queue->arr[queue->front]);
        queue->front = (queue->front + 1) % MAX_SIZE;
        queue->size--;
    }
}

int main() {
    struct Queue* queue = createQueue();

    // Adding positive affirmations to the queue
    enqueue(queue, "You are a kind and thoughtful person, and the world is lucky to have you in it!");
    enqueue(queue, "Your hard work and dedication are appreciated more than you know. Keep it up!");
    enqueue(queue, "You have a heart full of love and a spirit full of light. May your aura always shine bright!");

    // Removing affirmations from the queue
    dequeue(queue);
    dequeue(queue);

    // Adding more affirmations to the queue
    enqueue(queue, "You have a contagious smile that lights up the whole room. Keep beaming!");
    enqueue(queue, "Your positive attitude and energy make the world a better place. Thank you for being you.");

    // Removing affirmations from the queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    
    // Adding more affirmations to the queue, but it's full!
    enqueue(queue, "You are incredibly creative and talented, and your work inspires others. Keep creating and shining bright!");

    return 0;
}