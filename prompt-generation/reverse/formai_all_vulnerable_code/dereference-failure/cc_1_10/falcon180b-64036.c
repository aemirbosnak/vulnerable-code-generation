//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// Global variables shared between threads
int drone_status = 0;
int drone_speed = 0;
int drone_direction = 0;

// Function prototypes
void *drone_thread(void *param);
void set_drone_status(int status);
void set_drone_speed(int speed);
void set_drone_direction(int direction);

int main() {
    pthread_t thread_id[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_id[i], NULL, drone_thread, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}

void *drone_thread(void *param) {
    int thread_num = *((int *) param);

    // Do some work
    printf("Thread %d is working...\n", thread_num);

    // Randomly change drone status, speed, and direction
    int rand_status = rand() % 3;
    set_drone_status(rand_status);

    int rand_speed = rand() % 5;
    set_drone_speed(rand_speed);

    int rand_direction = rand() % 2;
    set_drone_direction(rand_direction);

    return NULL;
}

void set_drone_status(int status) {
    drone_status = status;
    printf("Drone status changed to %d\n", drone_status);
}

void set_drone_speed(int speed) {
    drone_speed = speed;
    printf("Drone speed changed to %d\n", drone_speed);
}

void set_drone_direction(int direction) {
    drone_direction = direction;
    printf("Drone direction changed to %d\n", drone_direction);
}