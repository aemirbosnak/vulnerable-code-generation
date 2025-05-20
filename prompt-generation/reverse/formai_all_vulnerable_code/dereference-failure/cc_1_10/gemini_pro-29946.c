//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star system data
typedef struct star_system {
    char name[32];
    int x, y, z;
    int num_planets;
    struct planet *planets;
} star_system;

// Planet data
typedef struct planet {
    char name[32];
    int x, y, z;
    int size;
    int type;
} planet;

// Generate a random star system
star_system *generate_star_system() {
    // Create a new star system
    star_system *system = malloc(sizeof(star_system));
    
    // Generate a random name for the star system
    sprintf(system->name, "System %d", rand() % 100);
    
    // Generate a random position for the star system
    system->x = rand() % 100;
    system->y = rand() % 100;
    system->z = rand() % 100;
    
    // Generate a random number of planets for the star system
    system->num_planets = rand() % 10;
    
    // Create an array of planets for the star system
    system->planets = malloc(sizeof(planet) * system->num_planets);
    
    // Generate a random planet for each planet in the star system
    for (int i = 0; i < system->num_planets; i++) {
        // Generate a random name for the planet
        sprintf(system->planets[i].name, "Planet %d", i);
        
        // Generate a random position for the planet
        system->planets[i].x = rand() % 100;
        system->planets[i].y = rand() % 100;
        system->planets[i].z = rand() % 100;
        
        // Generate a random size for the planet
        system->planets[i].size = rand() % 10;
        
        // Generate a random type for the planet
        system->planets[i].type = rand() % 10;
    }
    
    // Return the star system
    return system;
}

// Print a star system
void print_star_system(star_system *system) {
    // Print the star system name
    printf("Star system: %s\n", system->name);
    
    // Print the star system position
    printf("Position: (%d, %d, %d)\n", system->x, system->y, system->z);
    
    // Print the number of planets in the star system
    printf("Number of planets: %d\n", system->num_planets);
    
    // Print the planets in the star system
    for (int i = 0; i < system->num_planets; i++) {
        // Print the planet name
        printf("Planet %d: %s\n", i, system->planets[i].name);
        
        // Print the planet position
        printf("Position: (%d, %d, %d)\n", system->planets[i].x, system->planets[i].y, system->planets[i].z);
        
        // Print the planet size
        printf("Size: %d\n", system->planets[i].size);
        
        // Print the planet type
        printf("Type: %d\n", system->planets[i].type);
    }
}

// Free a star system
void free_star_system(star_system *system) {
    // Free the planets in the star system
    free(system->planets);
    
    // Free the star system
    free(system);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Generate a random star system
    star_system *system = generate_star_system();
    
    // Print the star system
    print_star_system(system);
    
    // Free the star system
    free_star_system(system);
    
    return 0;
}