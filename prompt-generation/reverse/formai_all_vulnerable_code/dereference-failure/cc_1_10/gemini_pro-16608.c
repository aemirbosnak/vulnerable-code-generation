//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Universe and procedurally generated objects
typedef struct {
    int size;
    int galaxies;
    int stars;
    int planets;
} universe;

typedef struct {
    char *name;
    int size;
    float mass;
    int stars;
} galaxy;

typedef struct {
    char *name;
    float radius;
    float mass;
    float temperature;
    int planets;
} star;

typedef struct {
    char *name;
    float radius;
    float mass;
    float temperature;
    int moons;
} planet;

typedef struct {
    char *name;
    float radius;
    float mass;
    float temperature;
} moon;

// Function to generate a random universe
universe generate_universe(int size) {
    universe u;
    u.size = size;
    u.galaxies = rand() % 1000;
    u.stars = rand() % 100000;
    u.planets = rand() % 1000000;
    return u;
}

// Function to generate a random galaxy
galaxy generate_galaxy(int size) {
    galaxy g;
    g.name = malloc(sizeof(char) * 10);
    sprintf(g.name, "Galaxy %d", rand() % 1000);
    g.size = size;
    g.mass = rand() % 1000000000;
    g.stars = rand() % 100000;
    return g;
}

// Function to generate a random star
star generate_star(int size) {
    star s;
    s.name = malloc(sizeof(char) * 10);
    sprintf(s.name, "Star %d", rand() % 100000);
    s.radius = rand() % 1000000;
    s.mass = rand() % 1000000000;
    s.temperature = rand() % 10000;
    s.planets = rand() % 100;
    return s;
}

// Function to generate a random planet
planet generate_planet(int size) {
    planet p;
    p.name = malloc(sizeof(char) * 10);
    sprintf(p.name, "Planet %d", rand() % 100000);
    p.radius = rand() % 100000;
    p.mass = rand() % 1000000000;
    p.temperature = rand() % 10000;
    p.moons = rand() % 100;
    return p;
}

// Function to generate a random moon
moon generate_moon(int size) {
    moon m;
    m.name = malloc(sizeof(char) * 10);
    sprintf(m.name, "Moon %d", rand() % 100000);
    m.radius = rand() % 100000;
    m.mass = rand() % 1000000000;
    m.temperature = rand() % 10000;
    return m;
}

// Function to print the universe
void print_universe(universe u) {
    printf("Universe: %d\n", u.size);
    printf("Galaxies: %d\n", u.galaxies);
    printf("Stars: %d\n", u.stars);
    printf("Planets: %d\n", u.planets);
}

// Function to print the galaxy
void print_galaxy(galaxy g) {
    printf("Galaxy: %s\n", g.name);
    printf("Size: %d\n", g.size);
    printf("Mass: %f\n", g.mass);
    printf("Stars: %d\n", g.stars);
}

// Function to print the star
void print_star(star s) {
    printf("Star: %s\n", s.name);
    printf("Radius: %f\n", s.radius);
    printf("Mass: %f\n", s.mass);
    printf("Temperature: %f\n", s.temperature);
    printf("Planets: %d\n", s.planets);
}

// Function to print the planet
void print_planet(planet p) {
    printf("Planet: %s\n", p.name);
    printf("Radius: %f\n", p.radius);
    printf("Mass: %f\n", p.mass);
    printf("Temperature: %f\n", p.temperature);
    printf("Moons: %d\n", p.moons);
}

// Function to print the moon
void print_moon(moon m) {
    printf("Moon: %s\n", m.name);
    printf("Radius: %f\n", m.radius);
    printf("Mass: %f\n", m.mass);
    printf("Temperature: %f\n", m.temperature);
}

int main() {
    srand(time(NULL));

    // Generate a universe
    universe u = generate_universe(1000000);

    // Print the universe
    print_universe(u);

    // Generate a galaxy
    galaxy g = generate_galaxy(100000);

    // Print the galaxy
    print_galaxy(g);

    // Generate a star
    star s = generate_star(10000);

    // Print the star
    print_star(s);

    // Generate a planet
    planet p = generate_planet(10000);

    // Print the planet
    print_planet(p);

    // Generate a moon
    moon m = generate_moon(10000);

    // Print the moon
    print_moon(m);

    return 0;
}