//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y, z;
} vec3;

typedef struct {
    vec3 pos;
    int rot;
    int vel;
} ship;

typedef struct {
    int x, y, z, r;
} celestial_body;

typedef struct {
    int n_ships;
    ship *ships;
    int n_celestial_bodies;
    celestial_body *celestial_bodies;
} universe;

void init_universe(universe *u) {
    u->n_ships = rand() % 100;
    u->ships = malloc(sizeof(ship) * u->n_ships);
    for (int i = 0; i < u->n_ships; i++) {
        u->ships[i].pos.x = rand() % 1000;
        u->ships[i].pos.y = rand() % 1000;
        u->ships[i].pos.z = rand() % 1000;
        u->ships[i].rot = rand() % 360;
        u->ships[i].vel = rand() % 10;
    }
    u->n_celestial_bodies = rand() % 100;
    u->celestial_bodies = malloc(sizeof(celestial_body) * u->n_celestial_bodies);
    for (int i = 0; i < u->n_celestial_bodies; i++) {
        u->celestial_bodies[i].x = rand() % 1000;
        u->celestial_bodies[i].y = rand() % 1000;
        u->celestial_bodies[i].z = rand() % 1000;
        u->celestial_bodies[i].r = rand() % 100;
    }
}

void free_universe(universe *u) {
    free(u->ships);
    free(u->celestial_bodies);
}

void update_universe(universe *u, int dt) {
    for (int i = 0; i < u->n_ships; i++) {
        u->ships[i].pos.x += u->ships[i].vel * dt;
        u->ships[i].pos.y += u->ships[i].vel * dt;
        u->ships[i].pos.z += u->ships[i].vel * dt;
    }
}

void render_universe(universe *u) {
    for (int i = 0; i < u->n_ships; i++) {
        printf("Ship %d: (%d, %d, %d)\n", i, u->ships[i].pos.x, u->ships[i].pos.y, u->ships[i].pos.z);
    }
    for (int i = 0; i < u->n_celestial_bodies; i++) {
        printf("Celestial body %d: (%d, %d, %d), r=%d\n", i, u->celestial_bodies[i].x, u->celestial_bodies[i].y, u->celestial_bodies[i].z, u->celestial_bodies[i].r);
    }
}

int main() {
    srand(time(NULL));
    universe u;
    init_universe(&u);
    update_universe(&u, 10);
    render_universe(&u);
    free_universe(&u);
    return 0;
}