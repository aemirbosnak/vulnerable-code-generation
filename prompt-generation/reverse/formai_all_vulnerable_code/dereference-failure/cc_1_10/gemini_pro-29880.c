//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 100
#define MAX_Y 100
#define MAX_Z 100

#define NUM_STARS 1000
#define NUM_PLANETS 100
#define NUM_SHIPS 10

typedef struct {
    float x, y, z;
} vector3f;

typedef struct {
    vector3f position;
    vector3f velocity;
    float mass;
    float radius;
} star;

typedef struct {
    vector3f position;
    vector3f velocity;
    float mass;
    float radius;
    star* star;
} planet;

typedef struct {
    vector3f position;
    vector3f velocity;
    float mass;
    float radius;
    planet* planet;
} ship;

star* stars[NUM_STARS];
planet* planets[NUM_PLANETS];
ship* ships[NUM_SHIPS];

void init_universe() {
    srand(time(NULL));

    for (int i = 0; i < NUM_STARS; i++) {
        stars[i] = malloc(sizeof(star));
        stars[i]->position.x = (float)rand() / RAND_MAX * MAX_X;
        stars[i]->position.y = (float)rand() / RAND_MAX * MAX_Y;
        stars[i]->position.z = (float)rand() / RAND_MAX * MAX_Z;
        stars[i]->velocity.x = 0.0f;
        stars[i]->velocity.y = 0.0f;
        stars[i]->velocity.z = 0.0f;
        stars[i]->mass = (float)rand() / RAND_MAX * 1000000.0f;
        stars[i]->radius = (float)rand() / RAND_MAX * 100.0f;
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i] = malloc(sizeof(planet));
        planets[i]->position.x = (float)rand() / RAND_MAX * MAX_X;
        planets[i]->position.y = (float)rand() / RAND_MAX * MAX_Y;
        planets[i]->position.z = (float)rand() / RAND_MAX * MAX_Z;
        planets[i]->velocity.x = (float)rand() / RAND_MAX * 100.0f;
        planets[i]->velocity.y = (float)rand() / RAND_MAX * 100.0f;
        planets[i]->velocity.z = (float)rand() / RAND_MAX * 100.0f;
        planets[i]->mass = (float)rand() / RAND_MAX * 100000.0f;
        planets[i]->radius = (float)rand() / RAND_MAX * 100.0f;
        planets[i]->star = stars[rand() % NUM_STARS];
    }

    for (int i = 0; i < NUM_SHIPS; i++) {
        ships[i] = malloc(sizeof(ship));
        ships[i]->position.x = (float)rand() / RAND_MAX * MAX_X;
        ships[i]->position.y = (float)rand() / RAND_MAX * MAX_Y;
        ships[i]->position.z = (float)rand() / RAND_MAX * MAX_Z;
        ships[i]->velocity.x = (float)rand() / RAND_MAX * 100.0f;
        ships[i]->velocity.y = (float)rand() / RAND_MAX * 100.0f;
        ships[i]->velocity.z = (float)rand() / RAND_MAX * 100.0f;
        ships[i]->mass = (float)rand() / RAND_MAX * 10000.0f;
        ships[i]->radius = (float)rand() / RAND_MAX * 10.0f;
        ships[i]->planet = planets[rand() % NUM_PLANETS];
    }
}

void update_universe(float dt) {
    for (int i = 0; i < NUM_STARS; i++) {
        stars[i]->position.x += stars[i]->velocity.x * dt;
        stars[i]->position.y += stars[i]->velocity.y * dt;
        stars[i]->position.z += stars[i]->velocity.z * dt;
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i]->position.x += planets[i]->velocity.x * dt;
        planets[i]->position.y += planets[i]->velocity.y * dt;
        planets[i]->position.z += planets[i]->velocity.z * dt;
    }

    for (int i = 0; i < NUM_SHIPS; i++) {
        ships[i]->position.x += ships[i]->velocity.x * dt;
        ships[i]->position.y += ships[i]->velocity.y * dt;
        ships[i]->position.z += ships[i]->velocity.z * dt;
    }
}

void render_universe() {
    for (int i = 0; i < NUM_STARS; i++) {
        printf("Star %d: %.2f, %.2f, %.2f\n", i, stars[i]->position.x, stars[i]->position.y, stars[i]->position.z);
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: %.2f, %.2f, %.2f\n", i, planets[i]->position.x, planets[i]->position.y, planets[i]->position.z);
    }

    for (int i = 0; i < NUM_SHIPS; i++) {
        printf("Ship %d: %.2f, %.2f, %.2f\n", i, ships[i]->position.x, ships[i]->position.y, ships[i]->position.z);
    }
}

int main() {
    init_universe();

    float dt = 0.01f;

    while (1) {
        update_universe(dt);
        render_universe();
    }

    return 0;
}