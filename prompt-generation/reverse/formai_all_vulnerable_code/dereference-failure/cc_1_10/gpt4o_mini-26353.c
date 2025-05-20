//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 5

typedef struct CelestialBody {
    char name[30];
    float distance_from_sun; // distance from the sun in million km
    float orbit_period; // in Earth years
    struct CelestialBody *children[MAX_CHILDREN];
    int num_children;
} CelestialBody;

CelestialBody* create_body(const char *name, float distance, float period) {
    CelestialBody *body = (CelestialBody *)malloc(sizeof(CelestialBody));
    strcpy(body->name, name);
    body->distance_from_sun = distance;
    body->orbit_period = period;
    body->num_children = 0;
    return body;
}

void add_moon(CelestialBody *planet, CelestialBody *moon) {
    if (planet->num_children < MAX_CHILDREN) {
        planet->children[planet->num_children++] = moon;
    } else {
        printf("Maximum number of moons reached for %s.\n", planet->name);
    }
}

void simulate_orbit(const CelestialBody *body, int depth) {
    for (int i = 0; i < depth; ++i) {
        printf("\t");
    }

    printf("Simulating %s:\n", body->name);
    for (int i = 0; i < depth; ++i) {
        printf("\t");
    }
    printf("Distance from Sun: %.2f million km, Orbit Period: %.2f years\n",
           body->distance_from_sun, body->orbit_period);

    for (int i = 0; i < body->num_children; i++) {
        simulate_orbit(body->children[i], depth + 1);
    }
}

void free_celestial_body(CelestialBody *body) {
    for (int i = 0; i < body->num_children; i++) {
        free_celestial_body(body->children[i]);
    }
    free(body);
}

int main() {
    CelestialBody *sun = create_body("Sun", 0, 0);
    CelestialBody *earth = create_body("Earth", 149.6, 1);
    CelestialBody *moon = create_body("Moon", 0.384, 0.075);
    CelestialBody *mars = create_body("Mars", 227.9, 1.88);

    add_moon(earth, moon);

    printf("Starting simulation of the Solar System:\n");
    simulate_orbit(sun, 0);
    simulate_orbit(earth, 1);
    simulate_orbit(mars, 1);

    free_celestial_body(sun);
    free_celestial_body(earth);
    free_celestial_body(mars);

    return 0;
}