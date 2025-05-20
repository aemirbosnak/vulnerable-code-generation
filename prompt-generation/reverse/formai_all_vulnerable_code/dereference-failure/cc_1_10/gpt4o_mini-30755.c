//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_BAGS 20
#define TERMINALS 3

typedef struct {
    int id;
    int terminal;
    char status[20];
} Baggage;

Baggage baggageList[MAX_BAGS];
pthread_mutex_t lock;

void* checkInBaggage(void* arg) {
    int id = *(int*)arg;
    free(arg);
    
    for (int i = 0; i < MAX_BAGS; i++) {
        pthread_mutex_lock(&lock);
        
        if (baggageList[i].id == 0) { // If the bag slot is empty
            baggageList[i].id = id;
            baggageList[i].terminal = rand() % TERMINALS + 1; // Random terminal
            strcpy(baggageList[i].status, "Checked In");
            printf("Baggage ID %d checked in at Terminal %d.\n", id, baggageList[i].terminal);
            pthread_mutex_unlock(&lock);
            return NULL;
        }
        
        pthread_mutex_unlock(&lock);
    }
    return NULL; // No available baggage slot
}

void* loadBaggage(void* arg) {
    pthread_mutex_lock(&lock);

    for (int i = 0; i < MAX_BAGS; i++) {
        if (baggageList[i].id > 0 && strcmp(baggageList[i].status, "Checked In") == 0) {
            strcpy(baggageList[i].status, "Loaded");
            printf("Baggage ID %d loaded from Terminal %d.\n", baggageList[i].id, baggageList[i].terminal);
            break;
        }
    }
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* unloadBaggage(void* arg) {
    pthread_mutex_lock(&lock);

    for (int i = 0; i < MAX_BAGS; i++) {
        if (baggageList[i].id > 0 && strcmp(baggageList[i].status, "Loaded") == 0) {
            strcpy(baggageList[i].status, "Unloaded");
            printf("Baggage ID %d unloaded at Terminal %d.\n", baggageList[i].id, baggageList[i].terminal);
            baggageList[i].id = 0; // Mark as empty
            break;
        }
    }
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

void displayBaggageRecords() {
    printf("\nBaggage Records:\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        if (baggageList[i].id > 0) {
            printf("Baggage ID: %d, Terminal: %d, Status: %s\n", baggageList[i].id, baggageList[i].terminal, baggageList[i].status);
        }
    }
}

int main() {
    pthread_t threads[100];
    int bagCount = 0;

    memset(baggageList, 0, sizeof(baggageList));
    pthread_mutex_init(&lock, NULL);

    // Simulate check-in of baggage
    for (int i = 1; i <= 10; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[bagCount++], NULL, checkInBaggage, id);
        sleep(1); // Simulate delay
    }

    sleep(5); // Wait for check-in to complete

    // Simulate baggage loading
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[bagCount++], NULL, loadBaggage, NULL);
        sleep(1); // Simulate loading delay
    }

    sleep(3); // Wait for loading

    // Simulate baggage unloading
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[bagCount++], NULL, unloadBaggage, NULL);
        sleep(1); // Simulate unloading delay
    }

    // Wait for all threads to finish
    for (int i = 0; i < bagCount; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display final baggage records
    displayBaggageRecords();

    pthread_mutex_destroy(&lock);
    return 0;
}