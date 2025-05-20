//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BAGGAGE 5
#define NUM_CONVEYORS 3

sem_t availableBaggage;
sem_t availableConveyors[NUM_CONVEYORS];

typedef struct {
    int id;
    int weight;
} Baggage;

void* baggageHandling(void* arg) {
    Baggage* baggage = (Baggage*)arg;
    
    // Wait for available baggage place
    sem_wait(&availableBaggage);
    
    printf("Baggage %d (weight: %d kg) ready for handling.\n", baggage->id, baggage->weight);
    sleep(1); // Simulate handling process
    
    // Choose conveyor
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        if (sem_trywait(&availableConveyors[i]) == 0) {
            printf("Baggage %d is being loaded onto conveyor %d.\n", baggage->id, i);
            sleep(2); // Simulate loading time
            printf("Baggage %d has been loaded onto conveyor %d.\n", baggage->id, i);
            sem_post(&availableConveyors[i]); // Release conveyor
            break;
        }
    }
    
    // Mark baggage as handled
    sem_post(&availableBaggage);
    
    free(baggage);
    return NULL;
}

void* baggageGenerator(void* arg) {
    for (int i = 0; i < NUM_BAGGAGE; i++) {
        Baggage* newBaggage = (Baggage*)malloc(sizeof(Baggage));
        newBaggage->id = i + 1;
        newBaggage->weight = rand() % 20 + 5; // Random weight between 5 and 25

        printf("Creating baggage %d with weight %d kg.\n", newBaggage->id, newBaggage->weight);
        
        pthread_t thread;
        pthread_create(&thread, NULL, baggageHandling, (void*)newBaggage);
        pthread_detach(thread);
        
        sleep(1); // Simulate time between baggage arrivals
    }
    
    return NULL;
}

int main() {
    srand(time(NULL));
    
    // Initialize semaphores
    sem_init(&availableBaggage, 0, NUM_BAGGAGE);
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        sem_init(&availableConveyors[i], 0, 1);
    }
    
    printf("Starting baggage handling simulation...\n");
    
    pthread_t generatorThread;
    pthread_create(&generatorThread, NULL, baggageGenerator, NULL);
    pthread_detach(generatorThread);
    
    // Run for a specific duration
    sleep(20);
    
    // Clean up semaphores
    sem_destroy(&availableBaggage);
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        sem_destroy(&availableConveyors[i]);
    }
    
    printf("Baggage handling simulation finished.\n");
    
    return 0;
}