//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_DESTINATIONS 10
#define MAX_WAIT_TIME 100

// Structure for bags
typedef struct Bag {
    int id;
    int destination;
} Bag;

// Structure for conveyor belt (queue)
typedef struct Queue {
    int rear;
    int front;
    int capacity;
    Bag** bags;
} Queue;

// Function to create a new bag
Bag* createBag(int id, int destination) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    newBag->id = id;
    newBag->destination = destination;
    return newBag;
}

// Function to create a new queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->rear = -1;
    queue->front = -1;
    queue->capacity = capacity;
    queue->bags = (Bag**)malloc(sizeof(Bag*) * capacity);
    return queue;
}

// Function to check if queue is full
int isFull(Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Function to check if queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

// Function to add a bag to the queue
void enqueue(Queue* queue, Bag* bag) {
    if (isFull(queue)) {
        printf("Conveyor belt is full! Bag %d will be left behind...\n", bag->id);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->bags[queue->rear] = bag;
    printf("Bag %d added to the conveyor belt.\n", bag->id);
}

// Function to remove a bag from the queue
Bag* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Conveyor belt is empty!\n");
        return NULL;
    }
    Bag* bag = queue->bags[queue->front];
    queue->front++;
    printf("Bag %d removed from the conveyor belt.\n", bag->id);
    return bag;
}

// Function to generate a random number between 0 and max
int randomNumber(int max) {
    srand(time(0));
    return rand() % max;
}

int main() {
    // Create a queue
    Queue* conveyorBelt = createQueue(MAX_BAGS);

    // Generate random bags and add to conveyor belt
    for (int i = 0; i < MAX_BAGS; i++) {
        int destination = randomNumber(MAX_DESTINATIONS);
        Bag* bag = createBag(i+1, destination);
        enqueue(conveyorBelt, bag);
    }

    // Simulate baggage handling
    int time = 0;
    while (!isEmpty(conveyorBelt)) {
        printf("\nTime %d\n", time);
        Bag* bag = dequeue(conveyorBelt);
        if (bag != NULL) {
            int waitTime = randomNumber(MAX_WAIT_TIME);
            printf("Bag %d is being handled and will take approximately %d seconds.\n", bag->id, waitTime);
            time += waitTime;
            printf("Bag %d has been sent to its destination (Destination: %d).\n", bag->id, bag->destination);
            free(bag);
        }
    }

    printf("\nAll bags have been handled.\n");

    return 0;
}