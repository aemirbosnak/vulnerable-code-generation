//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

// Define the traffic light states
typedef enum {
    TL_RED,
    TL_YELLOW,
    TL_GREEN
} tl_state_t;

// Define the traffic light configuration
typedef struct {
    int num_cars;           // Number of cars waiting for each direction
    int wait_time;          // Time (in seconds) that each car waits
    int green_time;         // Time (in seconds) that the green light stays on
    int yellow_time;        // Time (in seconds) that the yellow light stays on
} tl_config_t;

// Global variables
tl_state_t tl_state = TL_RED;        // Current traffic light state
tl_config_t tl_config;                // Traffic light configuration
pthread_mutex_t tl_mutex;             // Mutex to protect the traffic light state
pthread_cond_t tl_cond;               // Condition variable to wait for a state change

// Thread function to simulate cars waiting for the green light
void *car_thread(void *arg) {
    int i = (int)arg;              // Get the car's ID

    // Wait for the green light
    pthread_mutex_lock(&tl_mutex);
    while (tl_state != TL_GREEN) {
        pthread_cond_wait(&tl_cond, &tl_mutex);
    }
    pthread_mutex_unlock(&tl_mutex);

    // Drive through the intersection
    printf("Car %d driving through the intersection\n", i);
    sleep(1);

    // Notify the traffic light controller that the car has left
    pthread_mutex_lock(&tl_mutex);
    tl_config.num_cars--;
    pthread_mutex_unlock(&tl_mutex);

    return NULL;
}

// Thread function to simulate the traffic light controller
void *tl_thread(void *arg) {
    while (1) {
        // Change the traffic light state
        pthread_mutex_lock(&tl_mutex);
        switch (tl_state) {
            case TL_RED:
                tl_state = TL_GREEN;
                printf("Green light on\n");
                break;
            case TL_GREEN:
                tl_state = TL_YELLOW;
                printf("Yellow light on\n");
                break;
            case TL_YELLOW:
                tl_state = TL_RED;
                printf("Red light on\n");
                break;
        }
        pthread_cond_broadcast(&tl_cond);
        pthread_mutex_unlock(&tl_mutex);

        // Sleep for the appropriate amount of time
        sleep(tl_config.wait_time);
    }

    return NULL;
}

// Signal handler to terminate the program
void sigint_handler(int signum) {
    printf("Terminating program\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    // Initialize the traffic light configuration
    tl_config.num_cars = 10;
    tl_config.wait_time = 5;
    tl_config.green_time = 10;
    tl_config.yellow_time = 5;

    // Parse the command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            tl_config.num_cars = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-w") == 0) {
            tl_config.wait_time = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-g") == 0) {
            tl_config.green_time = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-y") == 0) {
            tl_config.yellow_time = atoi(argv[++i]);
        }
    }

    // Initialize the mutex and condition variable
    pthread_mutex_init(&tl_mutex, NULL);
    pthread_cond_init(&tl_cond, NULL);

    // Create the traffic light controller thread
    pthread_t tl_thread_id;
    pthread_create(&tl_thread_id, NULL, tl_thread, NULL);

    // Create the car threads
    pthread_t car_thread_id[tl_config.num_cars];
    for (int i = 0; i < tl_config.num_cars; i++) {
        pthread_create(&car_thread_id[i], NULL, car_thread, (void *)i);
    }

    // Register the signal handler
    signal(SIGINT, sigint_handler);

    // Join the threads
    pthread_join(tl_thread_id, NULL);
    for (int i = 0; i < tl_config.num_cars; i++) {
        pthread_join(car_thread_id[i], NULL);
    }

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&tl_mutex);
    pthread_cond_destroy(&tl_cond);

    return 0;
}