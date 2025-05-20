//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 10
#define NUM_TERMINALS 3
#define NUM_CONVEYORS 2

typedef struct {
    int id;
    int terminal;
} Bag;

Bag* baggage[MAX_BAGS];
sem_t bagSem;
pthread_mutex_t mutex;

void* conveyor_belt(void* arg) {
    int conveyor_id = *(int*)arg;

    while (1) {
        sem_wait(&bagSem);
        pthread_mutex_lock(&mutex);

        for (int i = 0; i < MAX_BAGS; i++) {
            if (baggage[i] != NULL) {
                printf("Conveyor %d processing bag id %d at terminal %d\n", conveyor_id, baggage[i]->id, baggage[i]->terminal);
                free(baggage[i]);
                baggage[i] = NULL;
                break;
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* terminal(void* arg) {
    int terminal_id = *(int*)arg;

    for (int i = 0; i < MAX_BAGS; i++) {
        pthread_mutex_lock(&mutex);

        if (baggage[i] == NULL) {
            Bag* new_bag = (Bag*)malloc(sizeof(Bag));
            new_bag->id = i + 1; // Bag IDs start from 1
            new_bag->terminal = terminal_id;
            baggage[i] = new_bag;

            printf("Terminal %d added bag id %d\n", terminal_id, new_bag->id);
            sem_post(&bagSem);
            break;
        }
        pthread_mutex_unlock(&mutex);
        usleep(rand() % 500000); // Simulate time taken to add a bag
    }
    
    return NULL;
}

int main() {
    pthread_t conveyors[NUM_CONVEYORS], terminals[NUM_TERMINALS];
    int conveyor_ids[NUM_CONVEYORS] = {1, 2};
    int terminal_ids[NUM_TERMINALS] = {1, 2, 3};
    
    sem_init(&bagSem, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_create(&conveyors[i], NULL, conveyor_belt, &conveyor_ids[i]);
    }

    for (int i = 0; i < NUM_TERMINALS; i++) {
        pthread_create(&terminals[i], NULL, terminal, &terminal_ids[i]);
    }
    
    for (int i = 0; i < NUM_TERMINALS; i++) {
        pthread_join(terminals[i], NULL);
    }

    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_cancel(conveyors[i]);
    }

    sem_destroy(&bagSem);
    pthread_mutex_destroy(&mutex);
    
    printf("Simulation complete.\n");
    return 0;
}