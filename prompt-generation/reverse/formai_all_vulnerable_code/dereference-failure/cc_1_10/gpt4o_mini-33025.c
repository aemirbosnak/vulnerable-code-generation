//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5  // Maximum size of the Queue

typedef struct {
    char name[50];
    char caseDetails[150];
} Case;

typedef struct {
    Case cases[MAX];
    int front, rear;
} Queue;

// Function to create and initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to add a new case to the queue
void enqueue(Queue* queue, Case newCase) {
    if (isFull(queue)) {
        printf("The case queue is full! Cannot add new case: %s\n", newCase.name);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->cases[queue->rear] = newCase;
    printf("Case added to queue: %s\n", newCase.name);
}

// Function to remove a case from the queue
Case dequeue(Queue* queue) {
    Case removedCase;
    if (isEmpty(queue)) {
        printf("The case queue is empty! No case to remove.\n");
        return (Case){"", ""}; // Return an empty case
    }
    removedCase = queue->cases[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    printf("Case removed from queue: %s\n", removedCase.name);
    return removedCase;
}

// Function to display the current cases in the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The case queue is empty!\n");
        return;
    }
    printf("Current Cases in Queue:\n");
    int i = queue->front;
    while (1) {
        printf("Case: %s | Details: %s\n", queue->cases[i].name, queue->cases[i].caseDetails);
        if (i == queue->rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    Queue* caseQueue = createQueue();

    // Introducing the cases
    Case case1 = {"The Hound of the Baskervilles", "A mysterious beast wreaking havoc on the moors."};
    Case case2 = {"The Adventure of the Blue Carbuncle", "A precious jewel found in a goose."};
    Case case3 = {"A Scandal in Bohemia", "Sherlock is blackmailed by a royal."};
    Case case4 = {"The Sign of the Four", "A treasure hunt with many twists."};
    Case case5 = {"The Engineer's Thumb", "A tale of deception and murder."};
    Case case6 = {"The Adventure of the Speckled Band", "Strange noises in a sinister house."};

    // Enqueueing cases for investigation
    enqueue(caseQueue, case1);
    enqueue(caseQueue, case2);
    enqueue(caseQueue, case3);
    enqueue(caseQueue, case4);
    enqueue(caseQueue, case5);
    enqueue(caseQueue, case6); // This should indicate the queue is full

    // Displaying the queue
    displayQueue(caseQueue);

    // Dequeueing cases for investigation
    dequeue(caseQueue);
    dequeue(caseQueue);

    // Displaying the queue again
    displayQueue(caseQueue);

    // Cleaning up
    free(caseQueue);
    return 0;
}