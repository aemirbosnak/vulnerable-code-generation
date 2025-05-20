//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <signal.h>

#define NUM_CARS 10
#define NUM_LANES 2
#define MAX_WAIT_TIME 5
#define SLEEP_TIME 1

typedef struct {
    int id;
    int lane;
    int wait_time;
} Car;

sem_t lanes[NUM_LANES];

void* drive(void* arg) {
    Car* car = (Car*)arg;
    int lane = car->lane;

    printf("Car %d is waiting to enter Lane %d\n", car->id, lane);

    if (sem_wait(&lanes[lane]) == -1) {
        perror("sem_wait");
        free(car);
        return NULL;
    }

    printf("Car %d has entered Lane %d\n", car->id, lane);

    sleep(car->wait_time);
    printf("Car %d is leaving Lane %d\n", car->id, lane);

    sem_post(&lanes[lane]);
    free(car);
    return NULL;
}

void createCars(int car_count) {
    for (int i = 0; i < car_count; i++) {
        Car* car = malloc(sizeof(Car));
        car->id = i + 1;
        car->lane = rand() % NUM_LANES;
        car->wait_time = rand() % MAX_WAIT_TIME + 1;

        pthread_t thread;
        if (pthread_create(&thread, NULL, drive, (void*)car) != 0) {
            perror("pthread_create");
            free(car);
            return;
        }
        pthread_detach(thread);
        sleep(SLEEP_TIME);
    }
}

void cleanup() {
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lanes[i]);
    }
}

void signalHandler(int sig) {
    cleanup();
    exit(0);
}

int main() {
    srand(time(NULL));
    signal(SIGINT, signalHandler);
    
    for (int i = 0; i < NUM_LANES; i++) {
        if (sem_init(&lanes[i], 0, 1) != 0) {
            perror("sem_init");
            return 1;
        }
    }

    printf("Traffic Flow Simulation Started...\n");

    // Creating cars to simulate traffic
    createCars(NUM_CARS);
    
    // Keep the main thread alive
    while (1) {
        sleep(1);
    }

    cleanup();
    return 0;
}