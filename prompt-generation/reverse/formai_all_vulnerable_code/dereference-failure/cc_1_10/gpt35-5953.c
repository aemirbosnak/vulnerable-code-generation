//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TOTAL_BAGS 20
#define MAX_BAG_SIZE 50

typedef struct bagStruct {
    int id;
    int weight;
} Bag;

typedef struct conveyorBelt {
    Bag** bags;
    int numOfBags;
    int maxCapacity;
    int currentWeight;
    int scannerStatus; // 1 for working, 0 for not working
    int conveyorStatus; // 1 for on, 0 for off
    pthread_mutex_t conveyorLock;
    pthread_mutex_t scannerLock;
} Conveyor;

void* conveyorHandler(void* arg);
void* scannerHandler(void* arg);
void* loaderHandler(void* arg);

int main() {
    srand(time(NULL));

    Conveyor* conveyor = (Conveyor*) malloc(sizeof(Conveyor));
    conveyor->bags = (Bag**) malloc(TOTAL_BAGS * sizeof(Bag*));
    conveyor->numOfBags = 0;
    conveyor->maxCapacity = TOTAL_BAGS;
    conveyor->currentWeight = 0;
    conveyor->scannerStatus = 1;
    conveyor->conveyorStatus = 1;

    pthread_mutex_init(&(conveyor->conveyorLock), NULL);
    pthread_mutex_init(&(conveyor->scannerLock), NULL);

    pthread_t conveyorThread, scannerThread, loaderThread;

    pthread_create(&conveyorThread, NULL, conveyorHandler, (void*) conveyor);
    pthread_create(&scannerThread, NULL, scannerHandler, (void*) conveyor);
    pthread_create(&loaderThread, NULL, loaderHandler, (void*) conveyor);

    pthread_join(conveyorThread, NULL);
    pthread_join(scannerThread, NULL);
    pthread_join(loaderThread, NULL);

    free(conveyor->bags);
    free(conveyor);
}

void* conveyorHandler(void* arg) {
    Conveyor* conveyor = (Conveyor*) arg;
    while(1) {
        pthread_mutex_lock(&(conveyor->conveyorLock));
        if(conveyor->conveyorStatus == 0) {
            pthread_mutex_unlock(&(conveyor->conveyorLock));
            break;
        }

        if(conveyor->numOfBags < conveyor->maxCapacity) {
            int weight = (rand() % MAX_BAG_SIZE) + 1;
            Bag* newBag = (Bag*) malloc(sizeof(Bag));
            newBag->id = conveyor->numOfBags + 1;
            newBag->weight = weight;

            conveyor->bags[conveyor->numOfBags++] = newBag;
            conveyor->currentWeight += weight;
            printf("Loaded bag %d onto conveyor. Current conveyor weight: %d\n", newBag->id, conveyor->currentWeight);
        }

        pthread_mutex_unlock(&(conveyor->conveyorLock));
        usleep(500000);
    }

    pthread_exit(NULL);
}

void* scannerHandler(void* arg) {
    Conveyor* conveyor = (Conveyor*) arg;
    while(1) {
        pthread_mutex_lock(&(conveyor->scannerLock));
        if(conveyor->scannerStatus == 0) {
            pthread_mutex_unlock(&(conveyor->scannerLock));
            break;
        }

        for(int i = 0; i < conveyor->numOfBags; i++) {
            if((rand() % 10) < 2) { // 20% chance of bag being lost
                printf("Bag %d lost!\n", conveyor->bags[i]->id);
                conveyor->currentWeight -= conveyor->bags[i]->weight;
                free(conveyor->bags[i]);
                conveyor->numOfBags--;
                for(int j = i; j < conveyor->numOfBags; j++) {
                    conveyor->bags[j] = conveyor->bags[j + 1];
                }
                i--;
            }
            else {
                printf("Bag %d scanned successfully.\n", conveyor->bags[i]->id);
            }
        }

        pthread_mutex_unlock(&(conveyor->scannerLock));
        usleep(2000000);
    }

    pthread_exit(NULL);
}

void* loaderHandler(void* arg) {
    Conveyor* conveyor = (Conveyor*) arg;
    while(1) {
        char input[10];
        printf("Enter 's' to stop conveyor, 'r' to resume conveyor, 'q' to quit: ");
        scanf("%s", input);

        if(input[0] == 's') {
            pthread_mutex_lock(&(conveyor->conveyorLock));
            conveyor->conveyorStatus = 0;
            pthread_mutex_unlock(&(conveyor->conveyorLock));
        }
        else if(input[0] == 'r') {
            pthread_mutex_lock(&(conveyor->conveyorLock));
            conveyor->conveyorStatus = 1;
            pthread_mutex_unlock(&(conveyor->conveyorLock));
        }
        else if(input[0] == 'q') {
            pthread_mutex_lock(&(conveyor->conveyorLock));
            pthread_mutex_lock(&(conveyor->scannerLock));
            conveyor->conveyorStatus = 0;
            conveyor->scannerStatus = 0;
            pthread_mutex_unlock(&(conveyor->scannerLock));
            pthread_mutex_unlock(&(conveyor->conveyorLock));
            break;
        }
    }

    pthread_exit(NULL);
}