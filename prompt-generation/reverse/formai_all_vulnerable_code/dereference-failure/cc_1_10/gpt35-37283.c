//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4 // number of threads to use for calculation
#define MAX_PLANETS 100 // maximum number of planets to consider
#define MAX_DIST 10000 // maximum distance to consider

typedef struct {
    int thread_id;
    int num_planets;
    int* planet_distances;
    float* prob_invasion;
} ThreadArgs;

float calculate_probability(int num_planets, int* planet_distances) {
    float distance_sum = 0.0;
    for(int i = 0; i < num_planets; i++) {
        distance_sum += planet_distances[i];
    }

    float avg_distance = distance_sum / num_planets;
    float probability = (avg_distance / MAX_DIST) * 100;

    return probability;
}

void* calculate_thread(void* args) {
    ThreadArgs* t_args = (ThreadArgs*) args;
    int start = t_args->thread_id * t_args->num_planets / NUM_THREADS;
    int end = (t_args->thread_id + 1) * t_args->num_planets / NUM_THREADS;

    for(int i = start; i < end; i++) {
        float probability = calculate_probability(t_args->num_planets, &t_args->planet_distances[i * t_args->num_planets]);
        t_args->prob_invasion[i] = probability;
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int num_planets = rand() % MAX_PLANETS + 1;
    int* planet_distances = (int*) malloc(sizeof(int) * num_planets * num_planets);
    float* prob_invasion = (float*) malloc(sizeof(float) * num_planets);

    // randomly generate planet distances
    for(int i = 0; i < num_planets; i++) {
        for(int j = 0; j < num_planets; j++) {
            if(i == j) {
                planet_distances[i * num_planets + j] = 0;
            }
            else {
                planet_distances[i * num_planets + j] = rand() % MAX_DIST + 1;
            }
        }
    }

    // print planet distances
    printf("Planet distances:\n");
    for(int i = 0; i < num_planets * num_planets; i++) {
        printf("%d\t", planet_distances[i]);
        if((i + 1) % num_planets == 0) {
            printf("\n");
        }
    }

    pthread_t threads[NUM_THREADS];
    ThreadArgs t_args[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++) {
        t_args[i].thread_id = i;
        t_args[i].num_planets = num_planets;
        t_args[i].planet_distances = planet_distances;
        t_args[i].prob_invasion = prob_invasion;
        pthread_create(&threads[i], NULL, calculate_thread, (void*) &t_args[i]);
    }

    // wait for threads to finish execution
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print probability of invasion for each planet
    printf("\nProbability of invasion:\n");
    for(int i = 0; i < num_planets; i++) {
        printf("Planet %d: %.2f%%\n", i+1, prob_invasion[i]);
    }

    free(planet_distances);
    free(prob_invasion);

    return 0;
}