//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_STARS 100
#define MAX_SHIPS 100

struct planet {
    char *name;
    int size;
    int population;
    int resources;
};

struct star {
    char *name;
    int size;
    int brightness;
    int temperature;
};

struct ship {
    char *name;
    int size;
    int speed;
    int range;
};

struct universe {
    struct planet planets[MAX_PLANETS];
    struct star stars[MAX_STARS];
    struct ship ships[MAX_SHIPS];
    int num_planets;
    int num_stars;
    int num_ships;
};

void generate_universe(struct universe *universe) {
    srand(time(NULL));

    universe->num_planets = rand() % MAX_PLANETS;
    universe->num_stars = rand() % MAX_STARS;
    universe->num_ships = rand() % MAX_SHIPS;

    for (int i = 0; i < universe->num_planets; i++) {
        universe->planets[i].name = malloc(10);
        sprintf(universe->planets[i].name, "Planet %d", i);
        universe->planets[i].size = rand() % 1000;
        universe->planets[i].population = rand() % 1000000;
        universe->planets[i].resources = rand() % 1000000;
    }

    for (int i = 0; i < universe->num_stars; i++) {
        universe->stars[i].name = malloc(10);
        sprintf(universe->stars[i].name, "Star %d", i);
        universe->stars[i].size = rand() % 1000;
        universe->stars[i].brightness = rand() % 1000;
        universe->stars[i].temperature = rand() % 1000;
    }

    for (int i = 0; i < universe->num_ships; i++) {
        universe->ships[i].name = malloc(10);
        sprintf(universe->ships[i].name, "Ship %d", i);
        universe->ships[i].size = rand() % 1000;
        universe->ships[i].speed = rand() % 1000;
        universe->ships[i].range = rand() % 1000;
    }
}

void print_universe(struct universe *universe) {
    printf("Planets:\n");
    for (int i = 0; i < universe->num_planets; i++) {
        printf("  %s: size %d, population %d, resources %d\n",
                universe->planets[i].name,
                universe->planets[i].size,
                universe->planets[i].population,
                universe->planets[i].resources);
    }

    printf("Stars:\n");
    for (int i = 0; i < universe->num_stars; i++) {
        printf("  %s: size %d, brightness %d, temperature %d\n",
                universe->stars[i].name,
                universe->stars[i].size,
                universe->stars[i].brightness,
                universe->stars[i].temperature);
    }

    printf("Ships:\n");
    for (int i = 0; i < universe->num_ships; i++) {
        printf("  %s: size %d, speed %d, range %d\n",
                universe->ships[i].name,
                universe->ships[i].size,
                universe->ships[i].speed,
                universe->ships[i].range);
    }
}

int main() {
    struct universe universe;

    generate_universe(&universe);
    print_universe(&universe);

    return 0;
}