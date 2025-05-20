//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define AIRPORT_CAPACITY 30
#define NUM_BAGGAGE_HANDLERS 5
#define NUM_PASSENGERS 10

sem_t baggage_semaphore;
pthread_mutex_t mutex;

typedef struct {
    int id;
    int weight;
} Baggage;

Baggage* luggage[AIRPORT_CAPACITY];
int luggage_count = 0;

void* baggage_handler(void* arg) {
    int handler_id = *((int*)arg);
    while (1) {
        sem_wait(&baggage_semaphore);
        pthread_mutex_lock(&mutex);

        if (luggage_count > 0) {
            Baggage* bag = luggage[--luggage_count];
            printf("Baggage Handler %d is processing baggage ID: %d with weight: %d kg\n", 
                    handler_id, bag->id, bag->weight);
            free(bag);
        }

        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);  // Simulate time taken to process baggage
    }
    return NULL;
}

void* passenger(void* arg) {
    int passenger_id = *((int*)arg);
    for (int i = 0; i < 3; ++i) {
        int weight = rand() % 25 + 1;  // Random weight between 1 to 25
        printf("Passenger %d arrives with luggage of weight: %d kg\n", passenger_id, weight);
        pthread_mutex_lock(&mutex);

        if (luggage_count < AIRPORT_CAPACITY) {
            Baggage* bag = malloc(sizeof(Baggage));
            bag->id = luggage_count + 1; 
            bag->weight = weight;
            luggage[luggage_count++] = bag;
            sem_post(&baggage_semaphore);
            printf("Passenger %d hands over baggage ID: %d\n", passenger_id, bag->id);
        } else {
            printf("Passenger %d found the airport overflowing with baggage. A surreal circus of colors and sounds!\n", passenger_id);
        }

        pthread_mutex_unlock(&mutex);
        sleep(rand() % 2);  // Simulate time taken to check-in luggage
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t handlers[NUM_BAGGAGE_HANDLERS];
    pthread_t passengers[NUM_PASSENGERS];
    int passenger_ids[NUM_PASSENGERS];

    sem_init(&baggage_semaphore, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        int* handler_id = malloc(sizeof(int));
        *handler_id = i + 1;
        pthread_create(&handlers[i], NULL, baggage_handler, handler_id);
    }
    
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        passenger_ids[i] = i + 1;
        pthread_create(&passengers[i], NULL, passenger, &passenger_ids[i]);
    }
    
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        pthread_join(passengers[i], NULL);
    }

    // Allow baggage handlers to finish processing
    sleep(5);
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        pthread_cancel(handlers[i]); // Or use any proper exit strategy
        pthread_join(handlers[i], NULL);
    }

    sem_destroy(&baggage_semaphore);
    pthread_mutex_destroy(&mutex);
    
    printf("The airport’s baggage handling has transformed into a kaleidoscope of unrealized dreams!\n");
    return 0;
}