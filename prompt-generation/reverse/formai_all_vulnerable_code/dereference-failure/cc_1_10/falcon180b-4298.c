//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 3

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variables for each light
pthread_cond_t red_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t yellow_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t green_cond = PTHREAD_COND_INITIALIZER;

// Thread IDs
pthread_t thread_ids[NUM_THREADS];

// Function prototypes
void *traffic_light(void *arg);
void change_light(int light);

int main() {
    int i;

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_ids[i], NULL, traffic_light, NULL);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    return 0;
}

// Traffic light thread
void *traffic_light(void *arg) {
    int light_num = *(int *) arg;

    while (1) {
        // Wait for current light to turn off
        pthread_mutex_lock(&mutex);
        change_light(light_num);
        pthread_cond_wait(&red_cond, &mutex);
        pthread_mutex_unlock(&mutex);

        // Sleep for a random amount of time
        srand(time(NULL));
        int sleep_time = rand() % 5 + 1;
        sleep(sleep_time);
    }

    return NULL;
}

// Change the current light
void change_light(int light) {
    pthread_mutex_lock(&mutex);

    switch (light) {
        case 1:
            printf("Red light is on\n");
            pthread_cond_signal(&red_cond);
            break;
        case 2:
            printf("Yellow light is on\n");
            pthread_cond_signal(&yellow_cond);
            break;
        case 3:
            printf("Green light is on\n");
            pthread_cond_signal(&green_cond);
            break;
        default:
            printf("Invalid light number\n");
            break;
    }

    pthread_mutex_unlock(&mutex);
}