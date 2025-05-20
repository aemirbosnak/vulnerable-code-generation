//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

#define MAX_BAGS 100
#define QUEUE_SIZE 10

typedef struct {
    int id;
    char type[20];
} Bag;

Bag bags[MAX_BAGS];
int bagCount = 0;
sem_t semEmpty, semFull;
pthread_mutex_t mutex;

void* bagProducer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (bagCount < MAX_BAGS) {
            Bag newBag;
            newBag.id = bagCount + 1;

            // Randomly assign a type
            int typeIndex = rand() % 3;
            switch(typeIndex) {
                case 0: snprintf(newBag.type, 20, "Regular"); break;
                case 1: snprintf(newBag.type, 20, "Fragile"); break;
                case 2: snprintf(newBag.type, 20, "Oversized"); break;
            }

            bags[bagCount++] = newBag;
            printf("Produced bag %d (%s)\n", newBag.id, newBag.type);
            pthread_mutex_unlock(&mutex);
            sem_post(&semFull);
        } else {
            pthread_mutex_unlock(&mutex);
            break; // Termination condition
        }
        usleep(100000); // Sleep to simulate time delay
    }
    return NULL;
}

void* bagConsumer(void* arg) {
    while (1) {
        sem_wait(&semFull);
        pthread_mutex_lock(&mutex);
        if (bagCount > 0) {
            Bag processedBag = bags[--bagCount];
            printf("Processed bag %d (%s)\n", processedBag.id, processedBag.type);
            pthread_mutex_unlock(&mutex);
        } else {
            pthread_mutex_unlock(&mutex);
            break; // Termination condition
        }
        usleep(150000); // Simulate processing time
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <num_producers> <num_consumers> <num_bags>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int numProducers = atoi(argv[1]);
    int numConsumers = atoi(argv[2]);
    int allowedBags = atoi(argv[3]);
    
    if (allowedBags > MAX_BAGS) {
        printf("Maximum allowed bags is %d\n", MAX_BAGS);
        return EXIT_FAILURE;
    }

    // Initialize semaphores and mutex
    sem_init(&semEmpty, 0, QUEUE_SIZE);
    sem_init(&semFull, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    
    pthread_t producers[numProducers];
    pthread_t consumers[numConsumers];

    // Seed the random number generator
    srand(time(NULL));

    // Create producer threads
    for (int i = 0; i < numProducers; i++) {
        pthread_create(&producers[i], NULL, bagProducer, NULL);
    }

    // Create consumer threads
    for (int i = 0; i < numConsumers; i++) {
        pthread_create(&consumers[i], NULL, bagConsumer, NULL);
    }

    // Join producer threads
    for (int i = 0; i < numProducers; i++) {
        pthread_join(producers[i], NULL);
    }
    
    // Join consumer threads
    for (int i = 0; i < numConsumers; i++) {
        pthread_join(consumers[i], NULL);
    }

    // Cleanup
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutex);

    printf("Simulation completed.\n");
    return EXIT_SUCCESS;
}