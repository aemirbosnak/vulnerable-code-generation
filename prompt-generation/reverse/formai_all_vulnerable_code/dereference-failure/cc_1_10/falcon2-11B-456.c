//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

int light_state[NUM_THREADS];
int temperature_state[NUM_THREADS];

void* light_control_thread(void* arg) {
    int thread_id = (int)arg;
    for (int i = 0; i < 100000; i++) {
        light_state[thread_id] = 1;
        sleep(1);
        light_state[thread_id] = 0;
        sleep(1);
    }
    return NULL;
}

void* temperature_control_thread(void* arg) {
    int thread_id = (int)arg;
    for (int i = 0; i < 100000; i++) {
        temperature_state[thread_id] = 30;
        sleep(1);
        temperature_state[thread_id] = 20;
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, light_control_thread, (void*)i);
        pthread_create(&threads[i+NUM_THREADS], NULL, temperature_control_thread, (void*)i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        pthread_join(threads[i+NUM_THREADS], NULL);
    }

    printf("Light state: %d\n", light_state[0]);
    printf("Temperature state: %d\n", temperature_state[0]);

    return 0;
}