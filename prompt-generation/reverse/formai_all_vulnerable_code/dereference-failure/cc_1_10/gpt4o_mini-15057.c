//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 5
#define QUEUE_SIZE 10

typedef struct {
    int id;
    char status[20];
} Bag;

Bag baggageQueue[QUEUE_SIZE];
int front = 0, rear = 0, count = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* checkIn(void* arg) {
    int bagId = *((int*)arg);
    free(arg);

    sem_wait(&empty);
    
    pthread_mutex_lock(&mutex);
    
    if (count < QUEUE_SIZE) {
        baggageQueue[rear].id = bagId;
        strcpy(baggageQueue[rear].status, "Checked In");
        rear = (rear + 1) % QUEUE_SIZE;
        count++;
        printf("Bag %d checked in successfully!\n", bagId);
    } else {
        printf("Bag %d cannot check in, queue full!\n", bagId);
    }
    
    pthread_mutex_unlock(&mutex);
    sem_post(&full);

    return NULL;
}

void* loadBags(void* arg) {
    while (1) {
        sem_wait(&full);
        
        pthread_mutex_lock(&mutex);
        
        if (count > 0) {
            Bag bag = baggageQueue[front];
            strcpy(baggageQueue[front].status, "Loaded");
            printf("Bag %d is being loaded onto the plane.\n", bag.id);
            front = (front + 1) % QUEUE_SIZE;
            count--;
            sleep(1);  // Simulate loading time
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main() {
    pthread_t checkInThreads[10];
    pthread_t loadingThread;
    int i;

    sem_init(&empty, 0, QUEUE_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create loading thread
    pthread_create(&loadingThread, NULL, loadBags, NULL);

    // Create check-in threads for 10 bags
    for (i = 0; i < 10; i++) {
        int* bagId = malloc(sizeof(int));
        *bagId = i + 1;
        pthread_create(&checkInThreads[i], NULL, checkIn, bagId);
        sleep(1); // Simulate delays in bag arrivals
    }

    // Join all check-in threads
    for (i = 0; i < 10; i++) {
        pthread_join(checkInThreads[i], NULL);
    }

    // Allow some time for remaining bags to be loaded
    sleep(5);

    // Cleanup
    pthread_cancel(loadingThread); // Stop loading thread
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    printf("Baggage processing complete. All bags handled.\n");
    return 0;
}