//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_BAGGAGE 10
#define NUM_HANDLERS 3
#define AIRPLANE_LOAD_TIME 5
#define BAGGAGE_HANDLING_TIME 2

typedef struct {
    int id;
    bool isLoaded;
} Baggage;

Baggage baggageQueue[MAX_BAGGAGE];
int baggageCount = 0;

sem_t emptyBags;
sem_t fullBags;
pthread_mutex_t mutex;

void* baggageHandler(void* arg) {
    int handlerId = *(int*)arg;

    while (true) {
        sem_wait(&fullBags);

        pthread_mutex_lock(&mutex);
        if (baggageCount > 0) {
            Baggage bag = baggageQueue[--baggageCount];
            pthread_mutex_unlock(&mutex);
            printf("Handler %d is processing baggage %d\n", handlerId, bag.id);
            sleep(BAGGAGE_HANDLING_TIME);
            printf("Handler %d finished processing baggage %d\n", handlerId, bag.id);
        } else {
            pthread_mutex_unlock(&mutex);
        }

        sem_post(&emptyBags);
    }
    return NULL;
}

void* airplane(void* arg) {
    while (true) {
        sleep(AIRPLANE_LOAD_TIME);
        pthread_mutex_lock(&mutex);

        for (int i = 0; i < MAX_BAGGAGE; i++) {
            if (baggageCount < MAX_BAGGAGE) {
                baggageQueue[baggageCount].id = baggageCount + 1;
                baggageQueue[baggageCount].isLoaded = false;
                printf("Airplane loaded baggage %d\n", baggageQueue[baggageCount].id);
                baggageCount++;
            } else {
                printf("All baggage slots full! Waiting...\n");
                break;
            }
        }

        pthread_mutex_unlock(&mutex);
        for (int i = 0; i < NUM_HANDLERS; i++) {
            sem_post(&fullBags);
        }
    }
    return NULL;
}

int main() {
    pthread_t handlers[NUM_HANDLERS];
    pthread_t plane;

    sem_init(&emptyBags, 0, MAX_BAGGAGE);
    sem_init(&fullBags, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    int handlerIds[NUM_HANDLERS];
    for (int i = 0; i < NUM_HANDLERS; i++) {
        handlerIds[i] = i + 1;
        pthread_create(&handlers[i], NULL, baggageHandler, &handlerIds[i]);
    }

    pthread_create(&plane, NULL, airplane, NULL);

    // Simulate running for a certain time before ending
    sleep(30);

    // Cleanup
    for (int i = 0; i < NUM_HANDLERS; i++) {
        pthread_cancel(handlers[i]);
    }
    pthread_cancel(plane);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&emptyBags);
    sem_destroy(&fullBags);

    return 0;
}