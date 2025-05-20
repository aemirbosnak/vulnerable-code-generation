//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define NUM_TRAVELLERS 5
#define TIMELINE_LENGTH 10

typedef struct {
    int id;
    int target_year;
} TimeTraveller;

typedef struct {
    char event_description[50];
    int year;
} TimeEvent;

TimeEvent timeline[TIMELINE_LENGTH];
pthread_mutex_t timeline_mutex;

void* travel(void* arg) {
    TimeTraveller* traveller = (TimeTraveller*)arg;

    // Simulating time travel
    printf("Time traveller %d is traveling to the year %d...\n", traveller->id, traveller->target_year);
    
    sleep(1); // Simulate time passing

    pthread_mutex_lock(&timeline_mutex);
    
    // Randomly select an event for the timeline
    int event_index = rand() % TIMELINE_LENGTH;
    snprintf(timeline[event_index].event_description, sizeof(timeline[event_index].event_description), "Traveller %d visited", traveller->id);
    timeline[event_index].year = traveller->target_year;
    
    printf("Traveller %d recorded event: \"%s\" in the year %d\n", traveller->id, timeline[event_index].event_description, traveller->target_year);
    
    pthread_mutex_unlock(&timeline_mutex);
    
    free(traveller);
    return NULL;
}

void display_timeline() {
    printf("\nTimeline of Events:\n");
    for (int i = 0; i < TIMELINE_LENGTH; i++) {
        if (timeline[i].year != 0) {
            printf("Year %d: %s\n", timeline[i].year, timeline[i].event_description);
        }
    }
}

int main() {
    srand(time(NULL));
    pthread_t travellers[NUM_TRAVELLERS];
    pthread_mutex_init(&timeline_mutex, NULL);

    // Initialize timeline
    for (int i = 0; i < TIMELINE_LENGTH; i++) {
        timeline[i].year = 0; // Set initial year value to 0 indicating no event
    }

    // Create and launch travelers
    for (int i = 0; i < NUM_TRAVELLERS; i++) {
        TimeTraveller* traveller = malloc(sizeof(TimeTraveller));
        traveller->id = i + 1;
        traveller->target_year = 2000 + rand() % 21; // Random year between 2000 and 2020

        if (pthread_create(&travellers[i], NULL, travel, (void*)traveller) != 0) {
            perror("Failed to create thread");
            free(traveller);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_TRAVELLERS; i++) {
        pthread_join(travellers[i], NULL);
    }

    display_timeline();

    pthread_mutex_destroy(&timeline_mutex);
    return 0;
}