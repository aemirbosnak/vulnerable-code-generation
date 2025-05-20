//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BAGGAGE 100
#define MAX_TICKETS 50

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct luggage {
    char name[20];
    int weight;
};

struct passenger {
    char name[20];
    int tickets;
    struct luggage luggage[MAX_BAGGAGE];
    int luggage_count;
};

struct conveyor_belt {
    struct luggage conveyorbelt[MAX_BAGGAGE];
    int conveyor_count;
};

struct ticket_counter {
    int tickets_count;
};

void *passenger_thread(void *arg) { 
    struct passenger *passenger = (struct passenger*)arg;

    printf("Passenger %s arrived with %d tickets\n", passenger->name, passenger->tickets);
    
    for (int i = 0; i < passenger->tickets; i++) {
        pthread_mutex_lock(&mutex);
        while (passenger->luggage_count >= MAX_BAGGAGE) {
            pthread_cond_wait(&cond, &mutex); 
        }
        struct luggage *luggage = &passenger->luggage[passenger->luggage_count++];
        luggage->weight = rand() % 50 + 1; 
        sprintf(luggage->name, "Luggage-%d", passenger->luggage_count); 
        printf("Passenger %s checked-in luggage %s weighing %d kg\n", passenger->name, luggage->name, luggage->weight);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    free(passenger);
    return NULL;
}

void *conveyor_thread(void *arg) { 
    struct conveyor_belt *conveyor_belt = (struct conveyor_belt*)arg;

    while (1) {
        pthread_mutex_lock(&mutex);
        while (conveyor_belt->conveyor_count >= MAX_BAGGAGE) {
            pthread_cond_wait(&cond, &mutex); 
        }
        struct luggage *luggage = &conveyor_belt->conveyorbelt[conveyor_belt->conveyor_count++]; 
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        printf("Added luggage %s to conveyor belt\n", luggage->name);
        sleep(rand() % 3 + 1);
    }
    return NULL;
}

void *checkin_thread(void *arg) { 
    struct ticket_counter *ticket_counter = (struct ticket_counter*)arg;

    while (ticket_counter->tickets_count < MAX_TICKETS) {
        pthread_mutex_lock(&mutex); 
        while (ticket_counter->tickets_count >= MAX_TICKETS) {
            pthread_cond_wait(&cond, &mutex);
        }
        ticket_counter->tickets_count++;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        printf("Ticket counter issued ticket %d\n", ticket_counter->tickets_count);
        sleep(rand() % 2 + 1);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t passengers[10], conveyor, checkin;
    struct ticket_counter ticket_counter = { 0 };
    struct conveyor_belt conveyor_belt = { 0 };

    pthread_create(&conveyor, NULL, conveyor_thread, &conveyor_belt); 
    pthread_create(&checkin, NULL, checkin_thread, &ticket_counter);

    for (int i = 0; i < 10; i++) {
        struct passenger *passenger = malloc(sizeof(struct passenger));
        sprintf(passenger->name, "Passenger-%d", i+1);
        passenger->tickets = rand() % 7 + 1; 
        passenger->luggage_count = 0; 
        pthread_create(&passengers[i], NULL, passenger_thread, passenger);
    }

    pthread_join(checkin, NULL);

    for (int i = 0; i < 10; i++) {
        pthread_join(passengers[i], NULL); 
    }

    pthread_cancel(conveyor);

    printf("All luggage has been checked in\n");

    return 0;
}