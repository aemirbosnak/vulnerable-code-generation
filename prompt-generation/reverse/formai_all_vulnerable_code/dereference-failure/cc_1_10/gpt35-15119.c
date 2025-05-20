//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store information about a passenger
typedef struct Passenger {
    char* name;
    int bagWeight;
} Passenger;

// Structure to store information about a flight
typedef struct Flight {
    char* name;
    int maxBagWeight;
} Flight;

// Queue implementation for holding baggage
typedef struct Queue {
    Passenger** data;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;

// Create a new passenger
Passenger* createPassenger(char* name, int bagWeight) {
    Passenger* passenger = malloc(sizeof(Passenger));
    passenger->name = name;
    passenger->bagWeight = bagWeight;
    return passenger;
}

// Create a new flight
Flight* createFlight(char* name, int maxBagWeight) {
    Flight* flight = malloc(sizeof(Flight));
    flight->name = name;
    flight->maxBagWeight = maxBagWeight;
    return flight;
}

// Create a new queue
Queue* createQueue(int capacity) {
    Queue* queue = malloc(sizeof(Queue));
    queue->data = (Passenger**)malloc(sizeof(Passenger*) * capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

// Add a passenger to the queue
void enqueue(Queue* queue, Passenger* passenger) {
    if (queue->size < queue->capacity) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->data[queue->rear] = passenger;
        queue->size++;
    }
}

// Remove a passenger from the queue
Passenger* dequeue(Queue* queue) {
    if (queue->size > 0) {
        Passenger* passenger = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        return passenger;
    }
    return NULL;
}

// Calculate the total weight of all bags in the queue
int calculateQueueWeight(Queue* queue) {
    int totalWeight = 0;
    for (int i = queue->front; i <= queue->rear; i++) {
        if (queue->data[i] != NULL) {
            totalWeight += queue->data[i]->bagWeight;
        }
    }
    return totalWeight;
}

int main() {
    srand(time(NULL));
    Queue* baggageQueue = createQueue(10);
    Flight* flight = createFlight("Flight 123", 1000);

    // simulate passengers arriving at baggage check-in
    int numPassengers = rand() % 10 + 1;
    printf("Number of passengers: %d\n", numPassengers);
    for (int i = 0; i < numPassengers; i++) {
        char name[20];
        sprintf(name, "Passenger %d", i + 1);
        int bagWeight = rand() % 50 + 1;
        Passenger* passenger = createPassenger(name, bagWeight);
        enqueue(baggageQueue, passenger);
        printf("%s arrives with a bag weighing %d kg. Added to queue.\n", passenger->name, passenger->bagWeight);
    }

    // begin baggage handling process
    printf("Flight %s is now boarding.\n", flight->name);
    while (baggageQueue->size > 0) {
        Passenger* passenger = dequeue(baggageQueue);
        int queueWeight = calculateQueueWeight(baggageQueue);
        if (passenger->bagWeight + queueWeight <= flight->maxBagWeight) {
            printf("%s's bag is loaded onto the plane.\n", passenger->name);
        } else {
            printf("%s's bag is too heavy and cannot be loaded onto the plane.\n", passenger->name);
        }
    }

    // cleanup memory
    for (int i = 0; i < baggageQueue->capacity; i++) {
        if (baggageQueue->data[i] != NULL) {
            free(baggageQueue->data[i]->name);
            free(baggageQueue->data[i]);
        }
    }
    free(baggageQueue->data);
    free(baggageQueue);
    free(flight->name);
    free(flight);
    return 0;
}