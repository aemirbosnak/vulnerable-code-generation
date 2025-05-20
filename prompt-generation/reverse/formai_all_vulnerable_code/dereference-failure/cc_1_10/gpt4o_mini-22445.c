//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define NUM_BAGGAGE_CAROUSELS 3
#define MAX_BAGS 10

typedef struct {
    int bag_id;
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGS];
    int count;
    sem_t semaphore;
    pthread_mutex_t lock;
} BaggageCarousel;

BaggageCarousel carousels[NUM_BAGGAGE_CAROUSELS];

void* baggage_handler(void* arg) {
    int carousel_id = *(int*)arg;
    free(arg);
    while (1) {
        sem_wait(&carousels[carousel_id].semaphore);
        pthread_mutex_lock(&carousels[carousel_id].lock);

        if (carousels[carousel_id].count > 0) {
            Baggage bag = carousels[carousel_id].bags[--carousels[carousel_id].count];
            printf("Handler at Carousel %d processing bag ID: %d\n", carousel_id, bag.bag_id);
            pthread_mutex_unlock(&carousels[carousel_id].lock);
            sleep(rand() % 3 + 1); // Simulate time taken to handle the bag
        } else {
            pthread_mutex_unlock(&carousels[carousel_id].lock);
        }
    }
    return NULL;
}

void* baggage_arrival(void* arg) {
    int carousel_id = *(int*)arg;
    free(arg);
    for (int i = 0; i < 20; i++) { // Simulate 20 bags arriving
        sleep(rand() % 2 + 1); // Random time interval between arrivals
        int bag_id = rand() % 1000 + 1;
        pthread_mutex_lock(&carousels[carousel_id].lock);
        if (carousels[carousel_id].count < MAX_BAGS) {
            carousels[carousel_id].bags[carousels[carousel_id].count++] = (Baggage){ bag_id };
            printf("Bag ID: %d arriving at Carousel %d\n", bag_id, carousel_id);
            sem_post(&carousels[carousel_id].semaphore);
        } else {
            printf("Carousel %d is full! Bag ID %d could not be added.\n", carousel_id, bag_id);
        }
        pthread_mutex_unlock(&carousels[carousel_id].lock);
    }
    return NULL;
}

void initialize_carousels() {
    for (int i = 0; i < NUM_BAGGAGE_CAROUSELS; i++) {
        carousels[i].count = 0;
        sem_init(&carousels[i].semaphore, 0, 0);
        pthread_mutex_init(&carousels[i].lock, NULL);
    }
}

int main() {
    srand(time(NULL));
    initialize_carousels();

    pthread_t handlers[NUM_BAGGAGE_CAROUSELS];
    for (int i = 0; i < NUM_BAGGAGE_CAROUSELS; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&handlers[i], NULL, baggage_handler, id);
    }

    pthread_t arrival_threads[NUM_BAGGAGE_CAROUSELS];
    for (int i = 0; i < NUM_BAGGAGE_CAROUSELS; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&arrival_threads[i], NULL, baggage_arrival, id);
    }

    for (int i = 0; i < NUM_BAGGAGE_CAROUSELS; i++) {
        pthread_join(arrival_threads[i], NULL);
    }
    
    // Clean up
    for (int i = 0; i < NUM_BAGGAGE_CAROUSELS; i++) {
        sem_destroy(&carousels[i].semaphore);
        pthread_mutex_destroy(&carousels[i].lock);
    }

    return 0;
}