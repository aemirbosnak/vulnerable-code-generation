//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point pos;
    char *name;
} planet;

typedef struct {
    planet *planets;
    int num_planets;
} galaxy;

galaxy *create_galaxy(int num_planets) {
    galaxy *g = malloc(sizeof(galaxy));
    g->planets = malloc(sizeof(planet) * num_planets);
    g->num_planets = num_planets;

    for (int i = 0; i < num_planets; i++) {
        g->planets[i].pos.x = rand() % 100;
        g->planets[i].pos.y = rand() % 100;
        g->planets[i].name = malloc(10);
        sprintf(g->planets[i].name, "Planet%d", i);
    }

    return g;
}

void destroy_galaxy(galaxy *g) {
    for (int i = 0; i < g->num_planets; i++) {
        free(g->planets[i].name);
    }
    free(g->planets);
    free(g);
}

void print_galaxy(galaxy *g) {
    for (int i = 0; i < g->num_planets; i++) {
        printf("%s: (%d, %d)\n", g->planets[i].name, g->planets[i].pos.x, g->planets[i].pos.y);
    }
}

int main() {
    srand(time(NULL));

    galaxy *g = create_galaxy(10);

    print_galaxy(g);

    destroy_galaxy(g);

    return 0;
}