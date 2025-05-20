//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 10
#define NUM_BELTS 3

typedef struct {
    int id;
    int weight;
} Baggage;

Baggage* baggageQueue[MAX_BAGS];
int front = 0, rear = -1, count = 0;
sem_t empty, full;
pthread_mutex_t mutex;

void* baggageProducer(void* arg) {
    for (int i = 0; i < MAX_BAGS; i++) {
        Baggage* bag = (Baggage*)malloc(sizeof(Baggage));
        bag->id = i + 1;
        bag->weight = rand() % 30 + 1; // weight between 1 and 30
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        
        rear = (rear + 1) % MAX_BAGS;
        baggageQueue[rear] = bag;
        count++;
        printf("Produced Bag ID: %d, Weight: %d kg\n", bag->id, bag->weight);
        
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(rand() % 3); // simulate time to produce a bag
    }
    return NULL;
}

void* baggageConsumer(void* arg) {
    int belt_id = *(int*)arg;
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        
        Baggage* bag = baggageQueue[front];
        front = (front + 1) % MAX_BAGS;
        count--;
        printf("Belt %d processing Bag ID: %d, Weight: %d kg\n", belt_id, bag->id, bag->weight);
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        
        // Simulating baggage handling time
        sleep(rand() % 4);
        
        free(bag);
        if (count == 0) break; // stop condition for the last consumer
    }
    return NULL;
}

int main() {
    pthread_t producer;
    pthread_t consumers[NUM_BELTS];
    int belt_ids[NUM_BELTS];

    sem_init(&empty, 0, MAX_BAGS);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    srand(time(NULL));
    pthread_create(&producer, NULL, baggageProducer, NULL);
    
    for (int i = 0; i < NUM_BELTS; i++) {
        belt_ids[i] = i + 1;
        pthread_create(&consumers[i], NULL, baggageConsumer, (void*)&belt_ids[i]);
    }

    pthread_join(producer, NULL);
    
    // Wait for consumers to finish processing
    for (int i = 0; i < NUM_BELTS; i++) {
        pthread_join(consumers[i], NULL);
    }
    
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    
    printf("Baggage handling simulation completed.\n");
    return 0;
}