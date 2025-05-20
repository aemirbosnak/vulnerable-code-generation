//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point position;
    int radius;
} planet;

typedef struct {
    point position;
    point velocity;
} ship;

// Create a new planet.
planet* create_planet(int x, int y, int radius) {
    planet* p = malloc(sizeof(planet));
    p->position.x = x;
    p->position.y = y;
    p->radius = radius;
    return p;
}

// Create a new ship.
ship* create_ship(int x, int y, int vx, int vy) {
    ship* s = malloc(sizeof(ship));
    s->position.x = x;
    s->position.y = y;
    s->velocity.x = vx;
    s->velocity.y = vy;
    return s;
}

// Move the ship.
void move_ship(ship* s) {
    s->position.x += s->velocity.x;
    s->position.y += s->velocity.y;
}

// Check if the ship is colliding with a planet.
int is_colliding(ship* s, planet* p) {
    int dx = s->position.x - p->position.x;
    int dy = s->position.y - p->position.y;
    return dx * dx + dy * dy < p->radius * p->radius;
}

// Main game loop.
int main() {
    srand(time(NULL));

    // Create a list of planets.
    planet* planets[10];
    for (int i = 0; i < 10; i++) {
        int x = rand() % 1000;
        int y = rand() % 1000;
        int radius = rand() % 100;
        planets[i] = create_planet(x, y, radius);
    }

    // Create a ship.
    ship* s = create_ship(500, 500, 0, 0);

    // Game loop.
    while (1) {
        // Move the ship.
        move_ship(s);

        // Check for collisions with planets.
        for (int i = 0; i < 10; i++) {
            if (is_colliding(s, planets[i])) {
                // Game over!
                printf("Game over!\n");
                return 0;
            }
        }

        // Draw the game.
        printf("Ship: (%d, %d)\n", s->position.x, s->position.y);
        for (int i = 0; i < 10; i++) {
            printf("Planet %d: (%d, %d), radius %d\n", i, planets[i]->position.x, planets[i]->position.y, planets[i]->radius);
        }

        // Wait for the user to press a key.
        getchar();
    }

    return 0;
}