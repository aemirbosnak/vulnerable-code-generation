//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4 // Number of threads to be used
#define MAX_X_COORDINATE 100 // Maximum x coordinate value
#define MAX_Y_COORDINATE 100 // Maximum y coordinate value
#define ALIEN_PROBABILITY 0.05 // Probability of alien invasion

// Structure to hold the x and y coordinates of a point
struct Point {
    int x;
    int y;
};

// Function to generate a random point
void *generate_point(void *thread_id) {
    int id = (long) thread_id;
    srand(time(NULL) + id); // Seed the random number generator
    
    struct Point *point = malloc(sizeof(struct Point));
    point->x = rand() % MAX_X_COORDINATE;
    point->y = rand() % MAX_Y_COORDINATE;
    
    printf("Thread %ld generated point: (%d, %d)\n", id, point->x, point->y);
    pthread_exit(point);
}

// Function to calculate the probability of alien invasion based on the generated points
void *calculate_probability(void *points) {
    struct Point *point_array = (struct Point *) points;
    
    int num_points = sizeof(point_array)/sizeof(*point_array); // Calculate number of generated points
    
    int num_aliens = 0; // Counter for number of points with alien invasion
    for (int i=0; i<num_points; i++) {
        float random_number = ((float) rand() / RAND_MAX); // Generate a random float between 0 and 1
        if (random_number <= ALIEN_PROBABILITY) {
            num_aliens++;
            printf("Point (%d, %d) has been invaded by aliens!\n", point_array[i].x, point_array[i].y);
        }
    }
    
    float probability = (float) num_aliens / num_points;
    
    printf("The probability of an alien invasion is %f\n", probability);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct Point *points[NUM_THREADS];
    
    for (long i=0; i<NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_point, (void *) i); // Create threads to generate points
    }
    
    for (long i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], (void *) &points[i]); // Wait for threads to finish and add generated points to array
    }
    
    pthread_t probability_thread;
    pthread_create(&probability_thread, NULL, calculate_probability, (void *) points); // Create thread to calculate probability
    pthread_join(probability_thread, NULL); // Wait for probability thread to finish
    
    return 0;
}