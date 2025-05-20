//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Declare a structure for a noble
typedef struct Noble {
    int id;
    char name[50];
} Noble;

// Declare a structure for the queue
typedef struct Queue {
    Noble* nobles;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->nobles = (Noble*)malloc(capacity * sizeof(Noble));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->capacity;
}

// Function to enqueue a noble into the queue
void enqueue(Queue* queue, Noble noble) {
    if (isFull(queue)) {
        printf("Alas! The queue of nobles is full.\n");
        return;
    }
    queue->nobles[queue->rear++] = noble;
    printf("Noble %s has joined the queue!\n", noble.name);
}

// Function to dequeue a noble from the queue
Noble dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Fret not! The queue of nobles is empty.\n");
        Noble emptyNoble = {0, ""};
        return emptyNoble;
    }
    Noble noble = queue->nobles[queue->front++];
    printf("Noble %s has departed from the queue!\n", noble.name);
    return noble;
}

// Function to display the nobles in the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty, no noble stands in line.\n");
        return;
    }

    printf("Nobles in the queue:\n");
    for (int i = queue->front; i < queue->rear; i++) {
        printf(" - %s\n", queue->nobles[i].name);
    }
}

// Main function - the castle's court
int main() {
    int capacity = 5; // The castle can hold at most 5 nobles at a time
    Queue* nobleQueue = createQueue(capacity);

    Noble noble1 = {1, "Sir Thaddeus of the North"};
    Noble noble2 = {2, "Lady Arabella of the East"};
    Noble noble3 = {3, "Lord Cedric of the South"};
    Noble noble4 = {4, "Dame Isolde of the West"};
    Noble noble5 = {5, "Baron Giles of the Highlands"};

    enqueue(nobleQueue, noble1);
    enqueue(nobleQueue, noble2);
    enqueue(nobleQueue, noble3);
    enqueue(nobleQueue, noble4);
    enqueue(nobleQueue, noble5);

    displayQueue(nobleQueue);

    // Lets some nobles leave the queue
    dequeue(nobleQueue);
    dequeue(nobleQueue);

    displayQueue(nobleQueue);

    // Adding more nobles after some have left the queue
    Noble noble6 = {6, "Count Roland of the Verdant Valley"};
    enqueue(nobleQueue, noble6);

    displayQueue(nobleQueue);

    // Clean up the allocated memory
    free(nobleQueue->nobles);
    free(nobleQueue);

    return 0;
}