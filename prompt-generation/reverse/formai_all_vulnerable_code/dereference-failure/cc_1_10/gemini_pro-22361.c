//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define the structure of a space object
typedef struct {
    char *name;
    int x, y, z;
    int dx, dy, dz;
    int mass;
} space_object;

// Define the structure of a star system
typedef struct {
    char *name;
    int num_planets;
    space_object *planets;
} star_system;

// Define the function to create a new space object
space_object *create_space_object(char *name, int x, int y, int z, int dx, int dy, int dz, int mass) {
    space_object *object = malloc(sizeof(space_object));
    object->name = strdup(name);
    object->x = x;
    object->y = y;
    object->z = z;
    object->dx = dx;
    object->dy = dy;
    object->dz = dz;
    object->mass = mass;
    return object;
}

// Define the function to create a new star system
star_system *create_star_system(char *name, int num_planets) {
    star_system *system = malloc(sizeof(star_system));
    system->name = strdup(name);
    system->num_planets = num_planets;
    system->planets = malloc(sizeof(space_object) * num_planets);
    return system;
}

// Define the function to print the information about a space object
void print_space_object(space_object *object) {
    printf("Name: %s\n", object->name);
    printf("Position: (%d, %d, %d)\n", object->x, object->y, object->z);
    printf("Velocity: (%d, %d, %d)\n", object->dx, object->dy, object->dz);
    printf("Mass: %d\n\n", object->mass);
}

// Define the function to print the information about a star system
void print_star_system(star_system *system) {
    printf("Name: %s\n", system->name);
    printf("Number of planets: %d\n\n", system->num_planets);
    for (int i = 0; i < system->num_planets; i++) {
        print_space_object(&system->planets[i]);
    }
}

// Define the main function
int main() {
    // Create a new star system
    star_system *system = create_star_system("Sol", 8);

    // Create the planets in the Sol system
    system->planets[0] = *create_space_object("Mercury", 57910000, 0, 0, 0, 47400, 0, 3301043);
    system->planets[1] = *create_space_object("Venus", 108200000, 0, 0, 0, 35020, 0, 4867520);
    system->planets[2] = *create_space_object("Earth", 149600000, 0, 0, 0, 30750, 0, 5972190);
    system->planets[3] = *create_space_object("Mars", 227900000, 0, 0, 0, 24070, 0, 6416930);
    system->planets[4] = *create_space_object("Jupiter", 778500000, 0, 0, 0, 13070, 0, 189860000);
    system->planets[5] = *create_space_object("Saturn", 1433500000, 0, 0, 0, 9690, 0, 56846000);
    system->planets[6] = *create_space_object("Uranus", 2872500000, 0, 0, 0, 6830, 0, 86832000);
    system->planets[7] = *create_space_object("Neptune", 4504500000, 0, 0, 0, 5430, 0, 102413000);

    // Print the information about the Sol system
    print_star_system(system);

    // Free the memory allocated for the star system
    free(system->name);
    for (int i = 0; i < system->num_planets; i++) {
        free(system->planets[i].name);
    }
    free(system->planets);
    free(system);

    return 0;
}