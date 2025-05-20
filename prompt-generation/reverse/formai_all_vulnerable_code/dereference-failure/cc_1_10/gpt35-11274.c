//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex_lock;
pthread_cond_t  plane_arrival_cond;
pthread_cond_t  baggage_load_cond;

int num_bags[NUM_THREADS] = {0};
int total_bags = 0;

void *p_handler(void *threadid) {
    while (1) {
        pthread_mutex_lock(&mutex_lock);
        pthread_cond_wait(&plane_arrival_cond, &mutex_lock);

        printf("Baggage handling for plane: %ld\n", (long)threadid);
        int num_bags_for_plane = rand() % 101 + 100;
        num_bags[(long)threadid] = num_bags_for_plane;
        total_bags += num_bags_for_plane;

        printf("Bags for plane %ld: %d\n", (long)threadid, num_bags_for_plane);

        pthread_cond_signal(&baggage_load_cond);
        pthread_mutex_unlock(&mutex_lock);
        sleep(5);
    }
    pthread_exit(NULL);
}

void *l_handler(void *threadid) {
    while(1) {
        pthread_mutex_lock(&mutex_lock);
        pthread_cond_wait(&baggage_load_cond, &mutex_lock);

        int bags_loaded = 0;
        printf("Loading bags for plane: %ld\n", (long)threadid);
        for (int i = 1; i <= NUM_THREADS; i++) {
            printf("Loading bags for plane %ld from station %d\n", (long)threadid, i);
            bags_loaded += num_bags[i];
            num_bags[i] = 0;
        }
        printf("Total bags loaded for plane %ld: %d\n", (long)threadid, bags_loaded);

        pthread_cond_signal(&plane_arrival_cond);
        pthread_mutex_unlock(&mutex_lock);
        sleep(5);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    pthread_mutex_init(&mutex_lock, NULL);
    pthread_cond_init(&plane_arrival_cond, NULL);
    pthread_cond_init(&baggage_load_cond, NULL);

    for (t = 1; t <= NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, p_handler, (void *)t);
        if (rc) {
            perror("Unable to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (t = 1; t <= NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, l_handler, (void *)t);
        if (rc) {
            perror("Unable to create thread");
            exit(EXIT_FAILURE);
        }
    }

    pthread_cond_signal(&plane_arrival_cond);

    pthread_exit(NULL);
}