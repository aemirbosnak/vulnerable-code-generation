//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define MAX_BAGS 10
#define NUM_CONVEYORS 3

typedef struct {
    int bag_id;
    int conveyor_belt_id;
} Bag;

Bag* baggage_system[MAX_BAGS];
sem_t bag_sem;
pthread_mutex_t bag_mutex;
int bag_counter = 0;

void* conveyor_belt(void* arg) {
    int id = *((int*)arg);
    while (1) {
        sem_wait(&bag_sem);
        pthread_mutex_lock(&bag_mutex);
        
        if (bag_counter > 0) {
            Bag* bag = baggage_system[--bag_counter];
            printf("Conveyor %d processing bag %d\n", id, bag->bag_id);
            free(bag);
        }
        
        pthread_mutex_unlock(&bag_mutex);
        sleep(rand() % 3); // simulate bag processing time
    }
    return NULL;
}

void* baggage_claim_area() {
    while (1) {
        if (bag_counter >= MAX_BAGS) {
            printf("Baggage claim area full. Waiting for space...\n");
            sleep(1);
            continue;
        }

        pthread_mutex_lock(&bag_mutex);
        Bag* new_bag = malloc(sizeof(Bag));
        new_bag->bag_id = bag_counter + 1;
        new_bag->conveyor_belt_id = rand() % NUM_CONVEYORS;

        baggage_system[bag_counter++] = new_bag;

        printf("New bag %d added to conveyor %d\n", new_bag->bag_id, new_bag->conveyor_belt_id);

        sem_post(&bag_sem);
        pthread_mutex_unlock(&bag_mutex);
        sleep(rand() % 3 + 1); // simulate new bag arrival time
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t conveyors[NUM_CONVEYORS];
    pthread_t claim_area;

    sem_init(&bag_sem, 0, 0);
    pthread_mutex_init(&bag_mutex, NULL);

    for (int i = 0; i < NUM_CONVEYORS; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&conveyors[i], NULL, conveyor_belt, id);
    }

    pthread_create(&claim_area, NULL, baggage_claim_area, NULL);

    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_join(conveyors[i], NULL);
    }

    pthread_join(claim_area, NULL);

    sem_destroy(&bag_sem);
    pthread_mutex_destroy(&bag_mutex);
    return 0;
}