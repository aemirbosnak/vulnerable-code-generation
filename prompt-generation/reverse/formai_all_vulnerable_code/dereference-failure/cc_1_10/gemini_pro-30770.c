//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Structure to represent a planet
typedef struct {
    char *name;
    int x;
    int y;
    int radius;
    char *type;
} Planet;

// Function to generate a random planet
Planet generate_planet(int min_x, int max_x, int min_y, int max_y) {
    Planet planet;

    // Generate a random name for the planet
    planet.name = malloc(100);
    sprintf(planet.name, "Planet-%d", rand());

    // Generate a random position for the planet
    planet.x = rand() % (max_x - min_x + 1) + min_x;
    planet.y = rand() % (max_y - min_y + 1) + min_y;

    // Generate a random radius for the planet
    planet.radius = rand() % 100 + 1;

    // Generate a random type for the planet
    int type = rand() % 3;
    switch (type) {
        case 0:
            planet.type = "Gas Giant";
            break;
        case 1:
            planet.type = "Terrestrial";
            break;
        case 2:
            planet.type = "Ice Giant";
            break;
    }

    return planet;
}

// Function to print a planet
void print_planet(Planet planet) {
    printf("Planet: %s\n", planet.name);
    printf("Position: (%d, %d)\n", planet.x, planet.y);
    printf("Radius: %d\n", planet.radius);
    printf("Type: %s\n", planet.type);
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL));

    // Generate 10 random planets
    Planet planets[10];
    for (int i = 0; i < 10; i++) {
        planets[i] = generate_planet(-1000, 1000, -1000, 1000);
    }

    // Print the planets
    for (int i = 0; i < 10; i++) {
        print_planet(planets[i]);
    }

    return 0;
}