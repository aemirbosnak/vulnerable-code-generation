//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define NUM_BAGGAGE_CLAIMS 3
#define NUM_BAGGAGE_LOADERS 5
#define MAX_BAGS 10
#define MAX_LOAD_TIME 3

typedef struct {
    int id;
    int bags;
} BaggageClaim;

typedef struct {
    int id;
} BaggageLoader;

sem_t baggageClaimSem[NUM_BAGGAGE_CLAIMS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int totalBagsOnBelt = 0;

void* baggageClaimProcess(void* arg) {
    BaggageClaim* claim = (BaggageClaim*)arg;

    while (1) {
        sem_wait(&baggageClaimSem[claim->id]);
        
        pthread_mutex_lock(&mutex);
        if (totalBagsOnBelt > 0) {
            int bagsToClaim = rand() % (totalBagsOnBelt + 1);
            printf("Baggage Claim %d is claiming %d bags.\n", claim->id, bagsToClaim);
            totalBagsOnBelt -= bagsToClaim;
            printf("Total bags remaining on the belt: %d.\n", totalBagsOnBelt);
        } else {
            printf("Baggage Claim %d found no bags to claim.\n", claim->id);
        }
        pthread_mutex_unlock(&mutex);
        
        sleep(rand() % 5); // Simulate time until next claim
    }
    pthread_exit(NULL);
}

void* baggageLoaderProcess(void* arg) {
    BaggageLoader* loader = (BaggageLoader*)arg;

    while (1) {
        pthread_mutex_lock(&mutex);
        if (totalBagsOnBelt < MAX_BAGS) {
            int bagsToLoad = rand() % (MAX_BAGS - totalBagsOnBelt + 1);
            totalBagsOnBelt += bagsToLoad;
            printf("Baggage Loader %d loaded %d bags. Total on belt: %d.\n", loader->id, bagsToLoad, totalBagsOnBelt);
            pthread_mutex_unlock(&mutex);
            sleep(rand() % MAX_LOAD_TIME);
            sem_post(&baggageClaimSem[rand() % NUM_BAGGAGE_CLAIMS]); // Notify a random claim
        } else {
            pthread_mutex_unlock(&mutex);
        }
        sleep(rand() % 4); // Simulate time until next load
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    
    pthread_t baggageClaims[NUM_BAGGAGE_CLAIMS];
    pthread_t baggageLoaders[NUM_BAGGAGE_LOADERS];

    for (int i = 0; i < NUM_BAGGAGE_CLAIMS; i++) {
        sem_init(&baggageClaimSem[i], 0, 0);
    }

    for (int i = 0; i < NUM_BAGGAGE_CLAIMS; i++) {
        BaggageClaim* claim = malloc(sizeof(BaggageClaim));
        claim->id = i;
        pthread_create(&baggageClaims[i], NULL, baggageClaimProcess, (void*)claim);
    }

    for (int i = 0; i < NUM_BAGGAGE_LOADERS; i++) {
        BaggageLoader* loader = malloc(sizeof(BaggageLoader));
        loader->id = i;
        pthread_create(&baggageLoaders[i], NULL, baggageLoaderProcess, (void*)loader);
    }

    for (int i = 0; i < NUM_BAGGAGE_CLAIMS; i++) {
        pthread_join(baggageClaims[i], NULL);
    }

    for (int i = 0; i < NUM_BAGGAGE_LOADERS; i++) {
        pthread_join(baggageLoaders[i], NULL);
    }

    for (int i = 0; i < NUM_BAGGAGE_CLAIMS; i++) {
        sem_destroy(&baggageClaimSem[i]);
    }
    
    pthread_mutex_destroy(&mutex);
    return 0;
}