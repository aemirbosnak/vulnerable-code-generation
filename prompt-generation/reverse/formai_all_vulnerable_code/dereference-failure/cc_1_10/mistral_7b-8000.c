//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_STARS 1000000
#define NUM_EARTHLIKE_PLANETS 100
#define NUM_ALIEN_SHIPS 50
#define NUM_PROB_FACTORS 3

typedef struct {
    double x;
    double y;
} planet_t;

double factor1() {
    return (double) rand() / RAND_MAX;
}

double factor2() {
    return pow(factor1(), 2);
}

double factor3() {
    return pow(factor1(), 3);
}

double alien_invasion_probability(planet_t * planets, int num_planets) {
    double probability = 0;
    int i;

    for (i = 0; i < num_planets; i++) {
        probability += planets[i].x * planets[i].y * factor1() * factor2() * factor3();
    }

    return probability;
}

int main() {
    srand(time(NULL));
    planet_t * planets = malloc(NUM_EARTHLIKE_PLANETS * sizeof(planet_t));

    for (int i = 0; i < NUM_EARTHLIKE_PLANETS; i++) {
        planets[i].x = (double) rand() / RAND_MAX;
        planets[i].y = (double) rand() / RAND_MAX;
    }

    double probability = alien_invasion_probability(planets, NUM_EARTHLIKE_PLANETS);
    printf("Alien invasion probability: %lf\n", probability);

    free(planets);

    return 0;
}