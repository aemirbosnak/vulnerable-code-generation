//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    double x, y, z;
} vec3d;

typedef struct {
    char *name;
    vec3d pos;
    vec3d vel;
    double mass;
} ship;

typedef struct {
    int n_ships;
    ship *ships;
} galaxy;

galaxy *create_galaxy(int n_ships) {
    galaxy *g = malloc(sizeof(galaxy));
    g->n_ships = n_ships;
    g->ships = malloc(n_ships * sizeof(ship));
    for (int i = 0; i < n_ships; i++) {
        g->ships[i].name = malloc(16);
        sprintf(g->ships[i].name, "Ship %d", i);
        g->ships[i].pos.x = rand() / (double)RAND_MAX * 1000;
        g->ships[i].pos.y = rand() / (double)RAND_MAX * 1000;
        g->ships[i].pos.z = rand() / (double)RAND_MAX * 1000;
        g->ships[i].vel.x = rand() / (double)RAND_MAX * 10;
        g->ships[i].vel.y = rand() / (double)RAND_MAX * 10;
        g->ships[i].vel.z = rand() / (double)RAND_MAX * 10;
        g->ships[i].mass = rand() / (double)RAND_MAX * 1000;
    }
    return g;
}

void destroy_galaxy(galaxy *g) {
    for (int i = 0; i < g->n_ships; i++) {
        free(g->ships[i].name);
    }
    free(g->ships);
    free(g);
}

void update_galaxy(galaxy *g, double dt) {
    for (int i = 0; i < g->n_ships; i++) {
        g->ships[i].pos.x += g->ships[i].vel.x * dt;
        g->ships[i].pos.y += g->ships[i].vel.y * dt;
        g->ships[i].pos.z += g->ships[i].vel.z * dt;
    }
}

void print_galaxy(galaxy *g) {
    for (int i = 0; i < g->n_ships; i++) {
        printf("%s: (%f, %f, %f)\n", g->ships[i].name, g->ships[i].pos.x, g->ships[i].pos.y, g->ships[i].pos.z);
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int n_ships = 10;
    if (argc > 1) {
        n_ships = atoi(argv[1]);
    }
    galaxy *g = create_galaxy(n_ships);
    print_galaxy(g);
    update_galaxy(g, 1.0);
    print_galaxy(g);
    destroy_galaxy(g);
    return 0;
}