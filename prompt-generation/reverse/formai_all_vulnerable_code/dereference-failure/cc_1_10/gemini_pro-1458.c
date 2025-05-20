//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star System Structure
typedef struct star_system {
    char name[20];
    int num_planets;
    struct planet *planets;
} star_system;

// Planet Structure
typedef struct planet {
    char name[20];
    int size;
    int distance_from_star;
} planet;

// Generate a random star system
star_system generate_star_system() {
    star_system system;
    system.num_planets = rand() % 10 + 1;
    system.planets = malloc(sizeof(planet) * system.num_planets);
    for (int i = 0; i < system.num_planets; i++) {
        snprintf(system.planets[i].name, 20, "Planet %d", i + 1);
        system.planets[i].size = rand() % 1000 + 1;
        system.planets[i].distance_from_star = rand() % 10000 + 1;
    }
    return system;
}

// Print a star system
void print_star_system(star_system system) {
    printf("Star System: %s\n", system.name);
    printf("Number of Planets: %d\n", system.num_planets);
    for (int i = 0; i < system.num_planets; i++) {
        printf("Planet %d:\n", i + 1);
        printf("\tName: %s\n", system.planets[i].name);
        printf("\tSize: %d\n", system.planets[i].size);
        printf("\tDistance from Star: %d\n", system.planets[i].distance_from_star);
    }
}

// Main function
int main() {
    srand(time(NULL));
    star_system system = generate_star_system();
    print_star_system(system);
    return 0;
}