//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: shocked
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int id;
    int mass;
    int radius;
    char name[20];
} planet;

typedef struct {
    int id;
    planet* planets;
} solar_system;

int main() {
    int num_planets = 8;
    solar_system* system = malloc(num_planets * sizeof(solar_system));

    for (int i = 0; i < num_planets; i++) {
        system[i].id = i + 1;
        system[i].planets = malloc(i + 1 * sizeof(planet));

        system[i].planets[0].id = 1;
        system[i].planets[0].mass = 1;
        system[i].planets[0].radius = 1;
        strcpy(system[i].planets[0].name, "Mercury");

        system[i].planets[1].id = 2;
        system[i].planets[1].mass = 3.30;
        system[i].planets[1].radius = 2440;
        strcpy(system[i].planets[1].name, "Venus");

        system[i].planets[2].id = 3;
        system[i].planets[2].mass = 4.87;
        system[i].planets[2].radius = 6052;
        strcpy(system[i].planets[2].name, "Earth");

        system[i].planets[3].id = 4;
        system[i].planets[3].mass = 0.000492;
        system[i].planets[3].radius = 7373;
        strcpy(system[i].planets[3].name, "Mars");

        system[i].planets[4].id = 5;
        system[i].planets[4].mass = 0.0000003;
        system[i].planets[4].radius = 3485;
        strcpy(system[i].planets[4].name, "Jupiter");

        system[i].planets[5].id = 6;
        system[i].planets[5].mass = 0.000001;
        system[i].planets[5].radius = 3969;
        strcpy(system[i].planets[5].name, "Saturn");

        system[i].planets[6].id = 7;
        system[i].planets[6].mass = 0.0000000000000001;
        system[i].planets[6].radius = 3380;
        strcpy(system[i].planets[6].name, "Uranus");

        system[i].planets[7].id = 8;
        system[i].planets[7].mass = 0.0000000000000000000001;
        system[i].planets[7].radius = 3915;
        strcpy(system[i].planets[7].name, "Neptune");
    }

    printf("Solar System Simulation\n");
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d:\n", system[i].id);
        printf("Mass: %d\n", system[i].planets[0].mass);
        printf("Radius: %d\n", system[i].planets[0].radius);
        printf("Name: %s\n", system[i].planets[0].name);
        printf("\n");
    }

    free(system);
    return 0;
}