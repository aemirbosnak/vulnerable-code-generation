//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 10
#define NUM_ALIEN_SHIPS 50
#define NUM_HUMAN_SHIPS 10
#define MIN_ALIEN_PROBABILITY 0.1
#define MAX_ALIEN_PROBABILITY 0.9

typedef struct {
    double longitude;
    double latitude;
    double probability;
} planet_t;

typedef struct {
    int x;
    int y;
} coordinate_t;

typedef struct {
    planet_t planets[NUM_PLANETS];
    coordinate_t alien_ships_locations[NUM_ALIEN_SHIPS];
    coordinate_t human_ships_locations[NUM_HUMAN_SHIPS];
} galaxy_t;

galaxy_t* initialize_galaxy() {
    galaxy_t* galaxy = malloc(sizeof(galaxy_t));
    srand(time(NULL));

    for (int i = 0; i < NUM_PLANETS; i++) {
        planet_t* planet = &galaxy->planets[i];
        planet->longitude = (double)rand() / RAND_MAX * 360;
        planet->latitude = (double)rand() / RAND_MAX * 180;
        planet->probability = ((double)rand() / RAND_MAX + MIN_ALIEN_PROBABILITY) * (MAX_ALIEN_PROBABILITY - MIN_ALIEN_PROBABILITY) + MIN_ALIEN_PROBABILITY;
    }

    for (int i = 0; i < NUM_ALIEN_SHIPS; i++) {
        galaxy->alien_ships_locations[i].x = (int)(pow(RAND_MAX, 0.5) * cos(2 * M_PI * ((double)rand() / RAND_MAX)));
        galaxy->alien_ships_locations[i].y = (int)(pow(RAND_MAX, 0.5) * sin(2 * M_PI * ((double)rand() / RAND_MAX)));
    }

    for (int i = 0; i < NUM_HUMAN_SHIPS; i++) {
        galaxy->human_ships_locations[i].x = 0;
        galaxy->human_ships_locations[i].y = 0;
    }

    return galaxy;
}

void print_galaxy(galaxy_t* galaxy) {
    printf("===== GALAXY STATUS =====\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        planet_t* planet = &galaxy->planets[i];
        printf("Planet %d: Longitude %lf, Latitude %lf, Alien Probability %lf\n", i + 1, planet->longitude, planet->latitude, planet->probability);
    }

    printf("\nAlien Ships:\n");
    for (int i = 0; i < NUM_ALIEN_SHIPS; i++) {
        printf("Ship %d: X %d, Y %d\n", i + 1, galaxy->alien_ships_locations[i].x, galaxy->alien_ships_locations[i].y);
    }

    printf("\nHuman Ships:\n");
    for (int i = 0; i < NUM_HUMAN_SHIPS; i++) {
        printf("Ship %d: X %d, Y %d\n", i + 1, galaxy->human_ships_locations[i].x, galaxy->human_ships_locations[i].y);
    }
}

int main() {
    galaxy_t* galaxy = initialize_galaxy();
    print_galaxy(galaxy);

    free(galaxy);
    return 0;
}