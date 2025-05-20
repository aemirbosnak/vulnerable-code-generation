//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_CARS 10
#define GREEN_LIGHT_DURATION 5
#define RED_LIGHT_DURATION 3

sem_t intersection; // Semaphore representing the intersection
pthread_mutex_t mutex; // Mutex for printing output

typedef struct {
    int car_id;
} Car;

void* car_simulation(void* arg) {
    Car* car = (Car*)arg;

    // Generate a random time before arriving at the intersection
    int wait_time = rand() % 10 + 1; // Waits between 1 to 10 seconds
    sleep(wait_time);
    
    printf("Car %d is approaching the intersection after %d seconds.\n", car->car_id, wait_time);
    
    // Car requests to enter the intersection
    sem_wait(&intersection);
    
    pthread_mutex_lock(&mutex);
    printf("Car %d is passing through the intersection.\n", car->car_id);
    pthread_mutex_unlock(&mutex);
    
    // Simulate the time taken to pass
    sleep(GREEN_LIGHT_DURATION);
    
    pthread_mutex_lock(&mutex);
    printf("Car %d has cleared the intersection.\n", car->car_id);
    pthread_mutex_unlock(&mutex);
    
    // Release the intersection
    sem_post(&intersection);
    
    free(car);
    return NULL;
}

int main() {
    srand(time(NULL));
    sem_init(&intersection, 0, 1); // Initialize semaphore with 1
    pthread_mutex_init(&mutex, NULL); // Initialize mutex

    pthread_t threads[NUM_CARS];

    // Create car threads
    for (int i = 0; i < NUM_CARS; i++) {
        Car* car = malloc(sizeof(Car));
        car->car_id = i + 1;
        pthread_create(&threads[i], NULL, car_simulation, car);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    sem_destroy(&intersection);
    pthread_mutex_destroy(&mutex);

    printf("All cars have passed through the intersection.\n");
    
    return 0;
}