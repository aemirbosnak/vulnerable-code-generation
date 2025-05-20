//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define MAX_DELAY 30

void *traffic_light_controller(void *arg);

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, traffic_light_controller, (void *)i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *traffic_light_controller(void *arg) {
    int id = *((int *) arg);
    int delay = rand() % MAX_DELAY;

    printf("Thread %d started\n", id);

    switch (id) {
        case 0:
            printf("Thread %d is controlling the red light\n", id);
            break;
        case 1:
            printf("Thread %d is controlling the yellow light\n", id);
            break;
        case 2:
            printf("Thread %d is controlling the green light\n", id);
            break;
        default:
            printf("Invalid thread id\n");
            return NULL;
    }

    printf("Thread %d is waiting for %d seconds\n", id, delay);
    sleep(delay);

    printf("Thread %d finished\n", id);

    return NULL;
}