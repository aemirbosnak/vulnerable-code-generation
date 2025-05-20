//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float x, y, z;
} vec3;

typedef struct {
    vec3 position;
    vec3 velocity;
    float radius;
} body;

typedef struct {
    int nbodies;
    body *bodies;
} universe;

universe *create_universe(int nbodies) {
    universe *u = malloc(sizeof(universe));
    u->nbodies = nbodies;
    u->bodies = malloc(nbodies * sizeof(body));
    for (int i = 0; i < nbodies; i++) {
        u->bodies[i].position.x = (float)rand() / RAND_MAX * 2000 - 1000;
        u->bodies[i].position.y = (float)rand() / RAND_MAX * 2000 - 1000;
        u->bodies[i].position.z = (float)rand() / RAND_MAX * 2000 - 1000;
        u->bodies[i].velocity.x = (float)rand() / RAND_MAX * 100 - 50;
        u->bodies[i].velocity.y = (float)rand() / RAND_MAX * 100 - 50;
        u->bodies[i].velocity.z = (float)rand() / RAND_MAX * 100 - 50;
        u->bodies[i].radius = (float)rand() / RAND_MAX * 100 + 50;
    }
    return u;
}

void update_universe(universe *u, float dt) {
    for (int i = 0; i < u->nbodies; i++) {
        u->bodies[i].position.x += u->bodies[i].velocity.x * dt;
        u->bodies[i].position.y += u->bodies[i].velocity.y * dt;
        u->bodies[i].position.z += u->bodies[i].velocity.z * dt;
    }
}

void draw_universe(universe *u) {
    for (int i = 0; i < u->nbodies; i++) {
        printf("Body %d: (%.2f, %.2f, %.2f)\n", i, u->bodies[i].position.x, u->bodies[i].position.y, u->bodies[i].position.z);
    }
}

int main() {
    srand(time(NULL));
    universe *u = create_universe(100);
    draw_universe(u);
    for (int i = 0; i < 1000; i++) {
        update_universe(u, 0.1);
    }
    draw_universe(u);
    return 0;
}