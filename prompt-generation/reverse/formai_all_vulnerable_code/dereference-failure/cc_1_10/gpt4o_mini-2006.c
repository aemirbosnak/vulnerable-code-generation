//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BAGS_CAPACITY 10
#define NUM_BAGGAGE_HANDLERS 3
#define NUM_FLIGHTS 5
#define BAGS_PER_FLIGHT 5

typedef struct {
    int id;
    char* status;
} Baggage;

Baggage* baggageQueue[BAGS_CAPACITY];
int front = 0, rear = 0;

sem_t emptyBags;
sem_t fullBags;
pthread_mutex_t mutex;

void* baggageHandler(void* arg) {
    int handlerId = *((int*)arg);

    while (1) {
        sem_wait(&fullBags); // Wait for a bag to be available
        pthread_mutex_lock(&mutex); // Lock access to the baggage queue

        Baggage* bag = baggageQueue[front];
        front = (front + 1) % BAGS_CAPACITY;

        pthread_mutex_unlock(&mutex); // Release the lock
        sem_post(&emptyBags); // Signal that there's space for another bag

        printf("Handler %d processing bag ID: %d with status: %s\n", handlerId, bag->id, bag->status);
        sleep(1); // Simulate time taken to process the bag
        free(bag); // Free the processed bag
    }
    return NULL;
}

void* flightArrival(void* arg) {
    int flightId = *((int*)arg);
    
    for (int i = 0; i < BAGS_PER_FLIGHT; i++) {
        Baggage* bag = (Baggage*)malloc(sizeof(Baggage));
        bag->id = (flightId * BAGS_PER_FLIGHT) + i;
        bag->status = "Arrived";

        sem_wait(&emptyBags); // Wait for space in the baggage queue
        pthread_mutex_lock(&mutex); // Lock access to the baggage queue

        baggageQueue[rear] = bag;
        rear = (rear + 1) % BAGS_CAPACITY;

        pthread_mutex_unlock(&mutex); // Release the lock
        sem_post(&fullBags); // Signal that a new bag is available
        
        printf("Flight %d has added bag ID: %d to the queue.\n", flightId, bag->id);
        sleep(rand() % 3 + 1); // Simulate the time between bag arrivals
    }
    return NULL;
}

int main() {
    pthread_t handlers[NUM_BAGGAGE_HANDLERS];
    pthread_t flights[NUM_FLIGHTS];
    sem_init(&emptyBags, 0, BAGS_CAPACITY);
    sem_init(&fullBags, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create baggage handlers
    int handlerIds[NUM_BAGGAGE_HANDLERS];
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        handlerIds[i] = i + 1; // Assign handler IDs (1 to NUM_BAGGAGE_HANDLERS)
        pthread_create(&handlers[i], NULL, baggageHandler, &handlerIds[i]);
    }

    // Create flights
    int flightIds[NUM_FLIGHTS];
    for (int i = 0; i < NUM_FLIGHTS; i++) {
        flightIds[i] = i + 1; // Assign flight IDs (1 to NUM_FLIGHTS)
        pthread_create(&flights[i], NULL, flightArrival, &flightIds[i]);
    }

    // Wait for all flights to complete
    for (int i = 0; i < NUM_FLIGHTS; i++) {
        pthread_join(flights[i], NULL);
    }

    // Clean up
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        pthread_cancel(handlers[i]); // Cancel baggage handlers after flights are done
    }

    sem_destroy(&emptyBags);
    sem_destroy(&fullBags);
    pthread_mutex_destroy(&mutex);

    printf("All flights processed and baggage handlers shut down.\n");
    return 0;
}