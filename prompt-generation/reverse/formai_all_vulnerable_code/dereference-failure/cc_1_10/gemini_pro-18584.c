//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
// Alien Invasion Probability Calculator using Multi-Threading

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold the parameters for each thread
typedef struct {
    int num_planets;
    int num_aliens_per_planet;
} ThreadParam;

// Function to calculate the probability of an alien invasion for a single planet
double calculate_probability(int num_aliens) {
    double probability = 0.0;

    // Calculate the probability using the formula:
    // P(invasion) = 1 - (1 - p)^n
    // Where p is the probability of an alien sighting on a planet and n is the number of aliens
    for (int i = 0; i < num_aliens; i++) {
        probability += (1.0 / (num_aliens + 1));
    }
    probability = 1 - pow((1 - probability), num_aliens);

    return probability;
}

// Thread function to calculate the probability for a set of planets
void *thread_func(void *arg) {
    ThreadParam *param = (ThreadParam *)arg;

    // Calculate the total probability of invasion for all planets
    double total_probability = 0.0;
    for (int i = 0; i < param->num_planets; i++) {
        total_probability += calculate_probability(param->num_aliens_per_planet);
    }

    // Print the total probability
    printf("Total probability of invasion: %lf\n", total_probability);

    // Free the allocated memory
    free(param);

    return NULL;
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the number of planets and aliens per planet from the user
    int num_planets, num_aliens_per_planet;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);
    printf("Enter the number of aliens per planet: ");
    scanf("%d", &num_aliens_per_planet);

    // Create a thread for each planet
    pthread_t *threads = malloc(num_planets * sizeof(pthread_t));
    for (int i = 0; i < num_planets; i++) {
        ThreadParam *param = malloc(sizeof(ThreadParam));
        param->num_planets = 1;
        param->num_aliens_per_planet = num_aliens_per_planet;

        // Create the thread
        pthread_create(&threads[i], NULL, thread_func, param);
    }

    // Join all threads
    for (int i = 0; i < num_planets; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the allocated memory
    free(threads);

    return 0;
}