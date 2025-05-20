//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define MAX_TRAVELERS 5
#define TIME_PERIODS 3

sem_t semaphore;
int time_travelers = 0;

void *time_travel(void *arg) {
    int traveler_id = *((int *)arg);
    free(arg);
    
    // Simulate time travel waiting phase
    int wait_time = rand() % 5 + 1; // Random wait time between 1 and 5 seconds
    printf("Traveler %d is preparing to time travel (waiting %d seconds).\n", traveler_id, wait_time);
    sleep(wait_time);
    
    sem_wait(&semaphore);
    
    // Enter the time travel
    time_travelers++;
    printf("Traveler %d is traveling through time! (Current travelers: %d)\n", traveler_id, time_travelers);
    
    // Simulate time travel duration
    int travel_duration = rand() % 3 + 1; // Random travel duration between 1 and 3 seconds
    sleep(travel_duration);
    
    // Finishing time travel
    time_travelers--;
    printf("Traveler %d has finished traveling through time! (Remaining travelers: %d)\n", traveler_id, time_travelers);
    sem_post(&semaphore);
    
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t travelers[MAX_TRAVELERS];
    sem_init(&semaphore, 0, 1);
    
    printf("Welcome to the Time Travel Simulator!\n");
    
    for (int i = 0; i < MAX_TRAVELERS; i++) {
        int *traveler_id = malloc(sizeof(int));
        *traveler_id = i + 1; // Traveler IDs start from 1
        pthread_create(&travelers[i], NULL, time_travel, traveler_id);
        sleep(1); // New traveler starts every second
    }
    
    for (int i = 0; i < MAX_TRAVELERS; i++) {
        pthread_join(travelers[i], NULL);
    }
    
    sem_destroy(&semaphore);
    printf("All travelers have completed their journeys!\n");
    
    return 0;
}