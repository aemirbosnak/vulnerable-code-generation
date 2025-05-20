//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_VEHICLES 10

sem_t north, south, east, west;

typedef struct Vehicle {
    int id;
    char direction;
} Vehicle;

void* simulateTraffic(void* arg) {
    Vehicle* vehicle = (Vehicle*)arg;
    char dir = vehicle->direction;

    switch (dir) {
        case 'N':
            sem_wait(&north);
            printf("Vehicle %d going North is passing through the intersection.\n", vehicle->id);
            sleep(1);
            sem_post(&north);
            break;
        case 'S':
            sem_wait(&south);
            printf("Vehicle %d going South is passing through the intersection.\n", vehicle->id);
            sleep(1);
            sem_post(&south);
            break;
        case 'E':
            sem_wait(&east);
            printf("Vehicle %d going East is passing through the intersection.\n", vehicle->id);
            sleep(1);
            sem_post(&east);
            break;
        case 'W':
            sem_wait(&west);
            printf("Vehicle %d going West is passing through the intersection.\n", vehicle->id);
            sleep(1);
            sem_post(&west);
            break;
    }

    free(vehicle);
    return NULL;
}

int main() {
    pthread_t vehicles[MAX_VEHICLES];
    sem_init(&north, 0, 1);
    sem_init(&south, 0, 1);
    sem_init(&east, 0, 1);
    sem_init(&west, 0, 1);

    char directions[MAX_VEHICLES] = {'N', 'S', 'E', 'W', 'N', 'S', 'E', 'W', 'N', 'S'};
    
    for (int i = 0; i < MAX_VEHICLES; i++) {
        Vehicle* vehicle = (Vehicle*)malloc(sizeof(Vehicle));
        vehicle->id = i + 1;
        vehicle->direction = directions[i];
        
        if (pthread_create(&vehicles[i], NULL, simulateTraffic, (void*)vehicle) != 0) {
            perror("Failed to create thread");
            free(vehicle);
            exit(EXIT_FAILURE);
        }
        
        sleep(1); // Control the vehicle arrival rate
    }

    for (int i = 0; i < MAX_VEHICLES; i++) {
        pthread_join(vehicles[i], NULL);
    }

    sem_destroy(&north);
    sem_destroy(&south);
    sem_destroy(&east);
    sem_destroy(&west);

    return 0;
}