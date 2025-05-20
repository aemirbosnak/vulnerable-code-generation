//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GALAXY_SIZE 100
#define SOLAR_SYSTEM_SIZE 10
#define PLANET_SIZE 10

typedef struct {
    int x;
    int y;
    int z;
} Point;

typedef struct {
    Point position;
    char *name;
    int size;
    int population;
} Planet;

typedef struct {
    Point position;
    char *name;
    int num_planets;
    Planet *planets;
} SolarSystem;

typedef struct {
    Point position;
    char *name;
    int num_solar_systems;
    SolarSystem *solar_systems;
} Galaxy;

Galaxy *generate_galaxy() {
    Galaxy *galaxy = malloc(sizeof(Galaxy));
    galaxy->position.x = 0;
    galaxy->position.y = 0;
    galaxy->position.z = 0;
    galaxy->name = "Milky Way";
    galaxy->num_solar_systems = GALAXY_SIZE;
    galaxy->solar_systems = malloc(sizeof(SolarSystem) * GALAXY_SIZE);

    for (int i = 0; i < GALAXY_SIZE; i++) {
        galaxy->solar_systems[i].position.x = rand() % 1000;
        galaxy->solar_systems[i].position.y = rand() % 1000;
        galaxy->solar_systems[i].position.z = rand() % 1000;
        galaxy->solar_systems[i].name = malloc(10);
        sprintf(galaxy->solar_systems[i].name, "Solar System %d", i + 1);
        galaxy->solar_systems[i].num_planets = SOLAR_SYSTEM_SIZE;
        galaxy->solar_systems[i].planets = malloc(sizeof(Planet) * SOLAR_SYSTEM_SIZE);

        for (int j = 0; j < SOLAR_SYSTEM_SIZE; j++) {
            galaxy->solar_systems[i].planets[j].position.x = rand() % 100;
            galaxy->solar_systems[i].planets[j].position.y = rand() % 100;
            galaxy->solar_systems[i].planets[j].position.z = rand() % 100;
            galaxy->solar_systems[i].planets[j].name = malloc(10);
            sprintf(galaxy->solar_systems[i].planets[j].name, "Planet %d", j + 1);
            galaxy->solar_systems[i].planets[j].size = rand() % 10;
            galaxy->solar_systems[i].planets[j].population = rand() % 1000000;
        }
    }
    return galaxy;
}

void print_galaxy(Galaxy *galaxy) {
    printf("Galaxy: %s\n", galaxy->name);
    for (int i = 0; i < galaxy->num_solar_systems; i++) {
        printf("  Solar System: %s\n", galaxy->solar_systems[i].name);
        for (int j = 0; j < galaxy->solar_systems[i].num_planets; j++) {
            printf("    Planet: %s\n", galaxy->solar_systems[i].planets[j].name);
            printf("      Position: (%d, %d, %d)\n", galaxy->solar_systems[i].planets[j].position.x, galaxy->solar_systems[i].planets[j].position.y, galaxy->solar_systems[i].planets[j].position.z);
            printf("      Size: %d\n", galaxy->solar_systems[i].planets[j].size);
            printf("      Population: %d\n", galaxy->solar_systems[i].planets[j].population);
        }
    }
}

int main() {
    srand(time(NULL));
    Galaxy *galaxy = generate_galaxy();
    print_galaxy(galaxy);
    return 0;
}