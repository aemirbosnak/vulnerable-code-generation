//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_BAGS 10
#define NUM_AIRPLANES 3

typedef struct {
    int id;
    char destination[50];
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGS];
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} BaggageArea;

BaggageArea baggageArea = {.count = 0, .mutex = PTHREAD_MUTEX_INITIALIZER, .cond = PTHREAD_COND_INITIALIZER};

void* check_in_bag(void* arg) {
    Baggage bag;
    bag.id = *(int*)arg;
    snprintf(bag.destination, sizeof(bag.destination), "Destination_%d", bag.id + 1);
    
    pthread_mutex_lock(&baggageArea.mutex);
    
    while (baggageArea.count >= MAX_BAGS) {
        pthread_cond_wait(&baggageArea.cond, &baggageArea.mutex);
    }
    
    baggageArea.bags[baggageArea.count++] = bag;
    printf("Checked in bag ID: %d, destination: %s\n", bag.id, bag.destination);
    
    pthread_cond_signal(&baggageArea.cond);
    pthread_mutex_unlock(&baggageArea.mutex);
    
    return NULL;
}

void* sort_bags(void* arg) {
    while (1) {
        pthread_mutex_lock(&baggageArea.mutex);
        
        while (baggageArea.count == 0) {
            pthread_cond_wait(&baggageArea.cond, &baggageArea.mutex);
        }
        
        Baggage bag = baggageArea.bags[--baggageArea.count];
        printf("Sorting bag ID: %d for %s\n", bag.id, bag.destination);
        
        pthread_cond_signal(&baggageArea.cond);
        pthread_mutex_unlock(&baggageArea.mutex);
        
        sleep(1); // Simulate the time taken for sorting
    }
    
    return NULL;
}

void* load_bags(void* arg) {
    int airplane_id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&baggageArea.mutex);
        
        while (baggageArea.count == 0) {
            pthread_cond_wait(&baggageArea.cond, &baggageArea.mutex);
        }
        
        Baggage bag = baggageArea.bags[--baggageArea.count];
        printf("Loading bag ID: %d onto Airplane %d for %s\n", bag.id, airplane_id, bag.destination);
        
        pthread_cond_signal(&baggageArea.cond);
        pthread_mutex_unlock(&baggageArea.mutex);
        
        sleep(1); // Simulate the time taken for loading
    }
    
    return NULL;
}

int main() {
    pthread_t checkInThreads[10];
    pthread_t sorterThread;
    pthread_t loaderThreads[NUM_AIRPLANES];
    
    for (int i = 0; i < 10; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&checkInThreads[i], NULL, check_in_bag, id);
    }
    
    pthread_create(&sorterThread, NULL, sort_bags, NULL);
    
    for (int i = 0; i < NUM_AIRPLANES; i++) {
        int* airplane_id = malloc(sizeof(int));
        *airplane_id = i + 1;
        pthread_create(&loaderThreads[i], NULL, load_bags, airplane_id);
    }
    
    for (int i = 0; i < 10; i++) {
        pthread_join(checkInThreads[i], NULL);
    }
    
    // Let the sorter and loaders run for a while
    sleep(5);
    
    // Termination (using a workaround, in real scenarios, threads would join or terminate gracefully)
    printf("Closing operations at the baggage handling system. Thank you for flying with us!\n");
    
    pthread_cancel(sorterThread);
    for (int i = 0; i < NUM_AIRPLANES; i++) {
        pthread_cancel(loaderThreads[i]);
    }

    // Cleanup - not necessary but good practice
    pthread_mutex_destroy(&baggageArea.mutex);
    pthread_cond_destroy(&baggageArea.cond);
    
    return 0;
}