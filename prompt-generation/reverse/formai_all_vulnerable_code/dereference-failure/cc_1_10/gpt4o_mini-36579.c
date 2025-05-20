//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_FAIRIES 5
#define NUM_FLOWERS 10

pthread_mutex_t log_mutex;  // Mutex for logging
pthread_mutex_t nectar_mutex; // Mutex for controlling nectar availability
int nectar_available = 0; // Amount of nectar in the garden

// Function to log activity
void log_activity(const char* activity) {
    pthread_mutex_lock(&log_mutex);
    printf("%s\n", activity);
    pthread_mutex_unlock(&log_mutex);
}

// Function for fairy to collect nectar from flowers
void* collect_nectar(void* arg) {
    int fairy_id = *((int*)arg);
    free(arg);
    
    while (1) {
        pthread_mutex_lock(&nectar_mutex);
        
        if (nectar_available > 0) {
            nectar_available--;
            char activity[100];
            snprintf(activity, sizeof(activity), "Fairy %d collected nectar! Nectar left: %d", fairy_id, nectar_available);
            log_activity(activity);
        } else {
            pthread_mutex_unlock(&nectar_mutex);
            log_activity("Nectar is not available. The fairies are waiting...");
            sleep(rand() % 3 + 1);  // Fairies sleep for some time
            continue;
        }
        
        pthread_mutex_unlock(&nectar_mutex);
        sleep(rand() % 2 + 1);  // Sleep a little between collection
    }
    
    return NULL;
}

// Function to occasionally add nectar to the garden
void* add_nectar(void* arg) {
    while (1) {
        sleep(rand() % 5 + 3);  // Wait for some time before adding nectar
        
        pthread_mutex_lock(&nectar_mutex);
        int nectar_to_add = rand() % 5 + 1; // Add between 1 and 5 nectar
        nectar_available += nectar_to_add;
        
        char activity[100];
        snprintf(activity, sizeof(activity), "Added %d nectar to the garden. Total nectar: %d", nectar_to_add, nectar_available);
        log_activity(activity);
        
        pthread_mutex_unlock(&nectar_mutex);
    }
    
    return NULL;
}

int main() {
    srand(time(NULL));  // Seed random number generator
    pthread_t fairies[NUM_FAIRIES];
    pthread_t nectar_thread;
    
    // Initialize mutexes
    pthread_mutex_init(&log_mutex, NULL);
    pthread_mutex_init(&nectar_mutex, NULL);
    
    // Create nectar adding thread
    pthread_create(&nectar_thread, NULL, add_nectar, NULL);

    // Create fairy threads
    for (int i = 0; i < NUM_FAIRIES; i++) {
        int* arg = malloc(sizeof(*arg));
        *arg = i + 1; // Fairy IDs start from 1
        pthread_create(&fairies[i], NULL, collect_nectar, arg);
    }
    
    // Wait for fairy threads to finish (they never will in this example)
    for (int i = 0; i < NUM_FAIRIES; i++) {
        pthread_join(fairies[i], NULL);
    }
    
    // Clean up
    pthread_mutex_destroy(&log_mutex);
    pthread_mutex_destroy(&nectar_mutex);
    
    return 0;
}