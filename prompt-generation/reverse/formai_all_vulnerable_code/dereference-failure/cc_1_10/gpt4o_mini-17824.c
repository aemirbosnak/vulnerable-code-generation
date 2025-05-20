//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_BAGS 5
#define CONVEYORS 2

typedef struct {
    int id;
} Bag;

Bag *belt[CONVEYORS][MAX_BAGS];
int belt_count[CONVEYORS] = {0};
pthread_mutex_t belt_mutex[CONVEYORS];
sem_t available_space[CONVEYORS];

void* baggage_arrival(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag *new_bag = (Bag*)malloc(sizeof(Bag));
        new_bag->id = i + 1;

        // Simulate arrival delay
        sleep(rand() % 3 + 1);
        printf("Bag %d arrived.\n", new_bag->id);

        // Place bag on a conveyor
        int conveyor_index = rand() % CONVEYORS;

        sem_wait(&available_space[conveyor_index]);
        pthread_mutex_lock(&belt_mutex[conveyor_index]);

        belt[conveyor_index][belt_count[conveyor_index]] = new_bag;
        belt_count[conveyor_index]++;
        printf("Bag %d loaded onto conveyor %d.\n", new_bag->id, conveyor_index + 1);

        pthread_mutex_unlock(&belt_mutex[conveyor_index]);
        sleep(rand() % 2 + 1); // Simulate processing time
    }

    free(arg);
    return NULL;
}

void* baggage_loading(void* arg) {
    int conveyor_index = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&belt_mutex[conveyor_index]);
        
        if (belt_count[conveyor_index] > 0) {
            Bag *bag_to_load = belt[conveyor_index][0];
            printf("Bag %d is being loaded from conveyor %d.\n", bag_to_load->id, conveyor_index + 1);
            
            // Shift remaining bags
            for (int j = 0; j < belt_count[conveyor_index] - 1; j++) {
                belt[conveyor_index][j] = belt[conveyor_index][j + 1];
            }
            belt[conveyor_index][belt_count[conveyor_index] - 1] = NULL;
            belt_count[conveyor_index]--;

            // Free the loaded bag
            free(bag_to_load);
            sem_post(&available_space[conveyor_index]);
        }

        pthread_mutex_unlock(&belt_mutex[conveyor_index]);
        sleep(rand() % 3 + 1); // Simulate loading time
    }
    return NULL;
}

int main() {
    // Initialize mutexes and semaphores
    for (int i = 0; i < CONVEYORS; i++) {
        pthread_mutex_init(&belt_mutex[i], NULL);
        sem_init(&available_space[i], 0, MAX_BAGS);
    }

    // Create threads for baggage arrival
    pthread_t arrival_thread;
    int *arrival_id = malloc(sizeof(int));
    *arrival_id = 1;
    pthread_create(&arrival_thread, NULL, baggage_arrival, arrival_id);

    // Create threads for baggage loading
    pthread_t loaders[CONVEYORS];
    for (int i = 0; i < CONVEYORS; i++) {
        int *conveyor_index = malloc(sizeof(int));
        *conveyor_index = i;
        pthread_create(&loaders[i], NULL, baggage_loading, conveyor_index);
    }

    // Join threads
    pthread_join(arrival_thread, NULL);
    for (int i = 0; i < CONVEYORS; i++) {
        pthread_join(loaders[i], NULL);
    }

    // Clean up mutexes and semaphores
    for (int i = 0; i < CONVEYORS; i++) {
        pthread_mutex_destroy(&belt_mutex[i]);
        sem_destroy(&available_space[i]);
    }

    return 0;
}