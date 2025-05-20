//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_BAGS 20
#define NUM_FLIGHTS 5
#define BAGS_PER_FLIGHT NUM_BAGS/NUM_FLIGHTS

typedef struct Baggage{
    int id;
    int weight;
} Baggage;

typedef struct Flight{
    int id;
    int bagsHandeled;
    Baggage *bags[BAGS_PER_FLIGHT];
} Flight;

pthread_mutex_t baggageMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t printMutex = PTHREAD_MUTEX_INITIALIZER;

Baggage *baggageList[NUM_BAGS];
Flight *flightList[NUM_FLIGHTS];

void *worker(void *id){
    int tid = *((int *)id);
    int assignedFlight = tid % NUM_FLIGHTS;
    int bagsHandeled = 0;

    pthread_mutex_lock(&baggageMutex);
    for(int i = 0; i < BAGS_PER_FLIGHT; i++){
        Baggage *bag = baggageList[(assignedFlight*BAGS_PER_FLIGHT)+i];
        flightList[assignedFlight]->bags[i] = bag;
        bagsHandeled++;
    }
    pthread_mutex_unlock(&baggageMutex);

    pthread_mutex_lock(&printMutex);
    printf("Worker %d handled %d bags for flight %d\n", tid, bagsHandeled, assignedFlight);
    pthread_mutex_unlock(&printMutex);

    flightList[assignedFlight]->bagsHandeled = bagsHandeled;

    pthread_exit(NULL);
}

int main(){
    pthread_t workers[NUM_BAGS];
    int workerIds[NUM_BAGS];

    for(int i=0; i<NUM_BAGS; i++){
        Baggage *bag = malloc(sizeof(Baggage));
        bag->id = i;
        bag->weight = rand() % 21 + 10;
        baggageList[i] = bag;
    }

    for(int i=0; i<NUM_FLIGHTS; i++){
        Flight *flight = malloc(sizeof(Flight));
        flight->id = i;
        flight->bagsHandeled = 0;
        flightList[i] = flight;
    }

    for(int i=0; i<NUM_BAGS; i++){
        workerIds[i] = i;
        pthread_create(&workers[i], NULL, worker, &workerIds[i]);
    }

    for(int i=0; i<NUM_BAGS; i++){
        pthread_join(workers[i], NULL);
    }

    int totalBagsHandled = 0;
    for(int i=0; i<NUM_FLIGHTS; i++){
        totalBagsHandled += flightList[i]->bagsHandeled;
    }

    printf("\nBags handled for each flight:\n");
    for(int i=0; i<NUM_FLIGHTS; i++){
        printf("Flight %d: %d bags\n", i, flightList[i]->bagsHandeled);
    }

    printf("\nTotal bags handled: %d\n", totalBagsHandled);

    return 0;
}