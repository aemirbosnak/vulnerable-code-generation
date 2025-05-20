//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS_PER_FLIGHT 100
#define MAX_FLIGHTS_PER_DAY 50

typedef struct Baggage {
    int id;
    char destination[50];
} Baggage;

typedef struct Flight {
    int id;
    char origin[50];
    Baggage* baggage[MAX_BAGS_PER_FLIGHT];
    int num_bags;
} Flight;

typedef struct BaggageNode {
    struct BaggageNode* next;
    Baggage* baggage;
} BaggageNode;

typedef struct BaggageQueue {
    BaggageNode* front;
    BaggageNode* rear;
} BaggageQueue;

BaggageQueue* createQueue() {
    BaggageQueue* queue = (BaggageQueue*)malloc(sizeof(BaggageQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(BaggageQueue* queue) {
    return queue->front == NULL;
}

void enqueue(BaggageQueue* queue, Baggage* baggage) {
    BaggageNode* newNode = (BaggageNode*)malloc(sizeof(BaggageNode));
    newNode->baggage = baggage;
    newNode->next = NULL;
    if(isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Baggage* dequeue(BaggageQueue* queue) {
    if(isEmpty(queue)) {
        return NULL;
    }
    BaggageNode* frontNode = queue->front;
    Baggage* baggage = frontNode->baggage;
    queue->front = queue->front->next;
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    free(frontNode);
    return baggage;
}

void printQueue(BaggageQueue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue contains:\n");
    BaggageNode* currentNode = queue->front;
    while(currentNode != NULL) {
        printf("{id: %d, destination: %s}\n", currentNode->baggage->id, currentNode->baggage->destination);
        currentNode = currentNode->next;
    }
}

void unloadFlight(Flight* flight, BaggageQueue* conveyorBelt, BaggageQueue* screeningQueue, BaggageQueue* transferQueue) {
    for(int i = 0; i < flight->num_bags; i++) {
        Baggage* baggage = flight->baggage[i];
        if(strcmp(baggage->destination, flight->origin) == 0) {
            // Baggage needs to be screened
            enqueue(screeningQueue, baggage);
        } else if(strcmp(baggage->destination, "Transfer") == 0) {
            // Baggage needs to be transferred to another flight
            enqueue(transferQueue, baggage);
        } else {
            // Baggage goes on the conveyor belt
            enqueue(conveyorBelt, baggage);
        }
    }
}

void screenBaggage(BaggageQueue* screeningQueue, BaggageQueue* conveyorBelt) {
    while(!isEmpty(screeningQueue)) {
        Baggage* baggage = dequeue(screeningQueue);
        // Screening process here...
        enqueue(conveyorBelt, baggage);
    }
}

void transferBaggage(BaggageQueue* transferQueue, Flight* flights[], int numFlights) {
    while(!isEmpty(transferQueue)) {
        Baggage* baggage = dequeue(transferQueue);
        for(int i = 0; i < numFlights; i++) {
            if(strcmp(flights[i]->origin, baggage->destination) == 0) {
                // Baggage belongs to this flight
                flights[i]->baggage[flights[i]->num_bags++] = baggage;
                break;
            }
        }
    }
}

int main() {
    BaggageQueue* conveyorBelt = createQueue();
    BaggageQueue* screeningQueue = createQueue();
    BaggageQueue* transferQueue = createQueue();

    Flight* flights[MAX_FLIGHTS_PER_DAY];
    int numFlights = 5;

    for(int i = 0; i < numFlights; i++) {
        flights[i] = (Flight*)malloc(sizeof(Flight));
        flights[i]->id = i + 1;

        if(i % 2 == 0) {
            strcpy(flights[i]->origin, "Denver");
        } else {
            strcpy(flights[i]->origin, "New York");
        }

        flights[i]->num_bags = rand() % MAX_BAGS_PER_FLIGHT + 1;

        for(int j = 0; j < flights[i]->num_bags; j++) {
            flights[i]->baggage[j] = (Baggage*)malloc(sizeof(Baggage));
            flights[i]->baggage[j]->id = j + 1;
            if(j % 2 == 0) {
                strcpy(flights[i]->baggage[j]->destination, "Dallas");
            } else {
                strcpy(flights[i]->baggage[j]->destination, "Transfer");
            }
        }
    }

    printf("Initial state of the simulation:\n");
    for(int i = 0; i < numFlights; i++) {
        printf("Flight %d from %s has %d bags:\n", flights[i]->id, flights[i]->origin, flights[i]->num_bags);
        for(int j = 0; j < flights[i]->num_bags; j++) {
            printf("{id: %d, destination: %s}\n", flights[i]->baggage[j]->id, flights[i]->baggage[j]->destination);
        }
        printf("Unloading Flight %d...\n", flights[i]->id);
        unloadFlight(flights[i], conveyorBelt, screeningQueue, transferQueue);
    }

    printf("Bags on the conveyor belt before screening:\n");
    printQueue(conveyorBelt);

    printf("Screening bags...\n");
    screenBaggage(screeningQueue, conveyorBelt);

    printf("Bags on the conveyor belt after screening:\n");
    printQueue(conveyorBelt);

    printf("Transferring bags...\n");
    transferBaggage(transferQueue, flights, numFlights);

    printf("Final state of the simulation:\n");
    for(int i = 0; i < numFlights; i++) {
        printf("Flight %d from %s has %d bags:\n", flights[i]->id, flights[i]->origin, flights[i]->num_bags);
        for(int j = 0; j < flights[i]->num_bags; j++) {
            printf("{id: %d, destination: %s}\n", flights[i]->baggage[j]->id, flights[i]->baggage[j]->destination);
        }
    }
    return 0;
}