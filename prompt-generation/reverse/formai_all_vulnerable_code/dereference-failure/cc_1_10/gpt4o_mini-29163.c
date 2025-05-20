//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Maximum number of wizards in the queue

typedef struct Wizard {
    int id;                    // Unique ID for each wizard
    char name[30];            // Name of the wizard
} Wizard;

typedef struct Queue {
    Wizard *wizards[MAX];     // Array of pointers to wizards
    int front;                // Index of front wizard
    int rear;                 // Index of rear wizard
    int count;                // Current number of wizards in the queue
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

bool isFull(Queue *queue) {
    return queue->count == MAX;
}

bool isEmpty(Queue *queue) {
    return queue->count == 0;
}

void enqueue(Queue *queue, Wizard *wizard) {
    if (isFull(queue)) {
        printf("The queue is full! Wizard %d (%s) can't borrow more scrolls.\n", wizard->id, wizard->name);
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->wizards[queue->rear] = wizard;
    queue->count++;
    printf("Wizard %d (%s) has entered the queue.\n", wizard->id, wizard->name);
}

Wizard *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("No wizards are in line! The library is empty.\n");
        return NULL;
    }
    Wizard *wizard = queue->wizards[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->count--;
    printf("Wizard %d (%s) has borrowed a scroll and is leaving the queue.\n", wizard->id, wizard->name);
    return wizard;
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is currently empty.\n");
        return;
    }
    printf("Current queue of wizards:\n");
    for (int i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % MAX;
        printf(" - Wizard %d (%s)\n", queue->wizards[index]->id, queue->wizards[index]->name);
    }
}

void freeQueue(Queue *queue) {
    for (int i = 0; i < queue->count; i++) {
        free(queue->wizards[(queue->front + i) % MAX]);
    }
    free(queue);
}

int main() {
    Queue *queue = createQueue();
    
    // Wizards arriving at the mystical library
    for (int i = 0; i < 7; i++) {
        Wizard *newWizard = (Wizard *)malloc(sizeof(Wizard));
        newWizard->id = i + 1;
        snprintf(newWizard->name, sizeof(newWizard->name), "Wizard_%d", newWizard->id);
        enqueue(queue, newWizard);
        displayQueue(queue);
    }

    // Wizards are borrowing scrolls
    for (int j = 0; j < 5; j++) {
        dequeue(queue);
        displayQueue(queue);
    }

    // Final clearing of queue
    while (!isEmpty(queue)) {
        dequeue(queue);
    }

    freeQueue(queue);
    return 0;
}