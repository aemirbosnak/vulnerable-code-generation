//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_BAGGAGE 10
#define MAX_HISTORY 100

typedef struct {
    char id[10];
    char owner[50];
    int weight;
} Baggage;

typedef struct {
    Baggage baggage[MAX_BAGGAGE];
    int count;
    sem_t empty;
    sem_t full;
    pthread_mutex_t mutex;
} BaggageClaim;

typedef struct {
    char description[100];
    char time[20];
} EventLog;

volatile EventLog eventHistory[MAX_HISTORY];
int eventCount = 0;
pthread_mutex_t logMutex;

void logEvent(const char *event) {
    pthread_mutex_lock(&logMutex);
    if (eventCount < MAX_HISTORY) {
        strncpy(eventHistory[eventCount].description, event, 99);
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(eventHistory[eventCount].time, 20, "%Y-%m-%d %H:%M:%S", tm_info);
        eventCount++;
    }
    pthread_mutex_unlock(&logMutex);
}

void *baggageHandler(void *arg) {
    BaggageClaim *baggageClaim = (BaggageClaim *)arg;
    for (int i = 0; i < MAX_BAGGAGE; ++i) {
        Baggage bag;
        snprintf(bag.id, sizeof(bag.id), "BAG%02d", i + 1);
        snprintf(bag.owner, sizeof(bag.owner), "Owner%02d", i + 1);
        bag.weight = rand() % 50 + 1;  // Random weight between 1 and 50

        sem_wait(&baggageClaim->empty);
        pthread_mutex_lock(&baggageClaim->mutex);
    
        baggageClaim->baggage[baggageClaim->count] = bag;
        baggageClaim->count++;
        printf("Baggage Handled: %s | Owner: %s | Weight: %dkg\n", bag.id, bag.owner, bag.weight);
        logEvent("Baggage has been handled.");

        pthread_mutex_unlock(&baggageClaim->mutex);
        sem_post(&baggageClaim->full);
        sleep(rand() % 3); // Simulating time taken to process the baggage
    }
    return NULL;
}

void *baggageClaimant(void *arg) {
    BaggageClaim *baggageClaim = (BaggageClaim *)arg;
    for (int i = 0; i < MAX_BAGGAGE; ++i) {
        sem_wait(&baggageClaim->full);
        pthread_mutex_lock(&baggageClaim->mutex);
        
        Baggage bag = baggageClaim->baggage[baggageClaim->count - 1];
        baggageClaim->count--;
        printf("Baggage Collected: %s | Owner: %s\n", bag.id, bag.owner);
        logEvent("Baggage has been collected.");

        pthread_mutex_unlock(&baggageClaim->mutex);
        sem_post(&baggageClaim->empty);
        sleep(rand() % 3); // Simulating time taken by the claimant
    }
    return NULL;
}

void printEventHistory() {
    pthread_mutex_lock(&logMutex);
    printf("\n--- Event History ---\n");
    for (int i = 0; i < eventCount; ++i) {
        printf("[%s] %s\n", eventHistory[i].time, eventHistory[i].description);
    }
    pthread_mutex_unlock(&logMutex);
}

int main() {
    srand(time(NULL));
    BaggageClaim baggageClaim;
    baggageClaim.count = 0;
    sem_init(&baggageClaim.empty, 0, MAX_BAGGAGE);
    sem_init(&baggageClaim.full, 0, 0);
    pthread_mutex_init(&baggageClaim.mutex, NULL);
    pthread_mutex_init(&logMutex, NULL);

    pthread_t handlerThread, claimantThread;
    
    pthread_create(&handlerThread, NULL, baggageHandler, &baggageClaim);
    pthread_create(&claimantThread, NULL, baggageClaimant, &baggageClaim);

    pthread_join(handlerThread, NULL);
    pthread_join(claimantThread, NULL);

    printEventHistory();

    sem_destroy(&baggageClaim.empty);
    sem_destroy(&baggageClaim.full);
    pthread_mutex_destroy(&baggageClaim.mutex);
    pthread_mutex_destroy(&logMutex);
    
    return 0;
}