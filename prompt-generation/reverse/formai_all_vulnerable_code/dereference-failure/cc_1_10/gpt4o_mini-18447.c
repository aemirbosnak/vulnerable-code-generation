//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define NUM_BAGGAGE 10
#define NUM_CONVEYORS 3
#define MAX_WAIT_TIME 5

sem_t emptyBags;
sem_t fullBags;

pthread_mutex_t mutex;
int baggageCounter = 0;

typedef struct {
    int baggageID;
    int conveyorID;
} Baggage;

Baggage *baggages[NUM_BAGGAGE];

void* baggageProducer(void* arg) {
    for (int i = 0; i < NUM_BAGGAGE; i++) {
        sleep(rand() % MAX_WAIT_TIME);
        
        int conveyorID = rand() % NUM_CONVEYORS;
        Baggage *newBaggage = malloc(sizeof(Baggage));
        newBaggage->baggageID = i;
        newBaggage->conveyorID = conveyorID;

        sem_wait(&emptyBags);
        pthread_mutex_lock(&mutex);
        
        baggages[baggageCounter] = newBaggage;
        printf("Produced baggage %d on Conveyor %d\n", newBaggage->baggageID, conveyorID);
        baggageCounter++;

        pthread_mutex_unlock(&mutex);
        sem_post(&fullBags);
    }
    return NULL;
}

void* baggageConsumer(void* arg) {
    while (1) {
        sem_wait(&fullBags);
        pthread_mutex_lock(&mutex);
        
        if (baggageCounter == 0) {
            pthread_mutex_unlock(&mutex);
            sem_post(&fullBags);
            break;
        }
        
        baggageCounter--;
        Baggage *baggage = baggages[baggageCounter];
        
        printf("Processed baggage %d from Conveyor %d\n", baggage->baggageID, baggage->conveyorID);
        
        pthread_mutex_unlock(&mutex);
        sem_post(&emptyBags);
        
        free(baggage);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    sem_init(&emptyBags, 0, NUM_BAGGAGE);
    sem_init(&fullBags, 0, 0);
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_t producerThread;
    pthread_t consumerThreads[NUM_CONVEYORS];
    
    pthread_create(&producerThread, NULL, baggageProducer, NULL);
    
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_create(&consumerThreads[i], NULL, baggageConsumer, NULL);
    }

    pthread_join(producerThread, NULL);
    
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_join(consumerThreads[i], NULL);
    }

    sem_destroy(&emptyBags);
    sem_destroy(&fullBags);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}