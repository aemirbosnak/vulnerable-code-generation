//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>

#define MAX_CYBER_UNITS 100
#define MAX_HACKERS 10
#define DATA_LENGTH 256

typedef struct {
    int id;
    char data[DATA_LENGTH];
} CyberUnit;

typedef struct {
    CyberUnit units[MAX_CYBER_UNITS];
    int count;
    sem_t mutex;
    sem_t empty;
    sem_t full;
} DataBuffer;

typedef struct {
    int id;
    DataBuffer *buffer;
} Hacker;

DataBuffer cyberBuffer;

void* hacker_thread(void* arg) {
    Hacker *hacker = (Hacker*)arg;
    char tempData[DATA_LENGTH];
    
    while (1) {
        sprintf(tempData, "Hack %d: Stealing data from the grid.", hacker->id);
        
        // Wait for an empty spot in the buffer
        sem_wait(&hacker->buffer->empty);
        sem_wait(&hacker->buffer->mutex);
        
        // Simulate data injection
        if (hacker->buffer->count < MAX_CYBER_UNITS) {
            CyberUnit newUnit;
            newUnit.id = hacker->buffer->count + 1;
            strncpy(newUnit.data, tempData, DATA_LENGTH);
            hacker->buffer->units[hacker->buffer->count++] = newUnit;
            printf("Hacker %d injected data unit %d: %s\n", hacker->id, newUnit.id, newUnit.data);
        }
        
        sem_post(&hacker->buffer->mutex);
        sem_post(&hacker->buffer->full);
        
        usleep(rand() % 500000);  // Random sleep for hacker activity
    }
    return NULL;
}

void* cyber_monitor(void* arg) {
    while (1) {
        // Wait until there is a unit available
        sem_wait(&cyberBuffer.full);
        sem_wait(&cyberBuffer.mutex);
        
        if (cyberBuffer.count > 0) {
            CyberUnit unit = cyberBuffer.units[--cyberBuffer.count];
            printf("Cyber Monitor: Processed data unit %d: %s\n", unit.id, unit.data);
        }
        
        sem_post(&cyberBuffer.mutex);
        sem_post(&cyberBuffer.empty);
        
        usleep(rand() % 1000000);  // Random monitor processing time
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t hackers[MAX_HACKERS], monitor;

    // Initialize the data buffer
    cyberBuffer.count = 0;
    sem_init(&cyberBuffer.mutex, 0, 1);
    sem_init(&cyberBuffer.empty, 0, MAX_CYBER_UNITS);
    sem_init(&cyberBuffer.full, 0, 0);

    // Create hacker threads
    for (int i = 0; i < MAX_HACKERS; i++) {
        Hacker *hacker = malloc(sizeof(Hacker));
        hacker->id = i+1;
        hacker->buffer = &cyberBuffer;
        pthread_create(&hackers[i], NULL, hacker_thread, hacker);
    }

    // Create a monitor thread
    pthread_create(&monitor, NULL, cyber_monitor, NULL);

    // Let the system run for a while
    sleep(10);

    // Cleanup: Cancel threads
    for (int i = 0; i < MAX_HACKERS; i++) {
        pthread_cancel(hackers[i]);
    }
    pthread_cancel(monitor);

    // Cleanup semaphores
    sem_destroy(&cyberBuffer.mutex);
    sem_destroy(&cyberBuffer.empty);
    sem_destroy(&cyberBuffer.full);

    printf("Cyber operations concluded.\n");
    return 0;
}