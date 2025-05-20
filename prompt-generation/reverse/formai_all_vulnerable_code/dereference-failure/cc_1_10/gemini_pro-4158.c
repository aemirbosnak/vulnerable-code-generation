//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point position;
    int health;
    int attack;
} spaceship;

typedef struct {
    int width, height;
    spaceship* ships[100];
    int num_ships;
} galaxy;

galaxy* create_galaxy(int width, int height) {
    galaxy* g = malloc(sizeof(galaxy));
    g->width = width;
    g->height = height;
    g->num_ships = 0;
    return g;
}

void destroy_galaxy(galaxy* g) {
    for (int i = 0; i < g->num_ships; i++) {
        free(g->ships[i]);
    }
    free(g);
}

spaceship* create_spaceship(int x, int y, int health, int attack) {
    spaceship* s = malloc(sizeof(spaceship));
    s->position.x = x;
    s->position.y = y;
    s->health = health;
    s->attack = attack;
    return s;
}

void destroy_spaceship(spaceship* s) {
    free(s);
}

void add_spaceship(galaxy* g, spaceship* s) {
    g->ships[g->num_ships++] = s;
}

void move_spaceship(spaceship* s, int dx, int dy) {
    s->position.x += dx;
    s->position.y += dy;
}

void attack_spaceship(spaceship* s1, spaceship* s2) {
    s2->health -= s1->attack;
}

void update_galaxy(galaxy* g) {
    // Move all ships
    for (int i = 0; i < g->num_ships; i++) {
        spaceship* s = g->ships[i];
        int dx = 2 * (rand() % 3 - 1);
        int dy = 2 * (rand() % 3 - 1);
        move_spaceship(s, dx, dy);
    }

    // Check for collisions
    for (int i = 0; i < g->num_ships; i++) {
        spaceship* s1 = g->ships[i];
        for (int j = i + 1; j < g->num_ships; j++) {
            spaceship* s2 = g->ships[j];
            if (s1->position.x == s2->position.x && s1->position.y == s2->position.y) {
                attack_spaceship(s1, s2);
                attack_spaceship(s2, s1);
            }
        }
    }

    // Remove dead ships
    for (int i = 0; i < g->num_ships; i++) {
        spaceship* s = g->ships[i];
        if (s->health <= 0) {
            destroy_spaceship(s);
            for (int j = i; j < g->num_ships - 1; j++) {
                g->ships[j] = g->ships[j + 1];
            }
            g->num_ships--;
            i--;
        }
    }
}

void print_galaxy(galaxy* g) {
    for (int y = 0; y < g->height; y++) {
        for (int x = 0; x < g->width; x++) {
            int found = 0;
            for (int i = 0; i < g->num_ships; i++) {
                spaceship* s = g->ships[i];
                if (s->position.x == x && s->position.y == y) {
                    found = 1;
                    printf("S");
                    break;
                }
            }
            if (!found) {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    galaxy* g = create_galaxy(80, 25);

    for (int i = 0; i < 100; i++) {
        int x = rand() % g->width;
        int y = rand() % g->height;
        int health = rand() % 100 + 1;
        int attack = rand() % 10 + 1;
        spaceship* s = create_spaceship(x, y, health, attack);
        add_spaceship(g, s);
    }

    while (1) {
        update_galaxy(g);
        print_galaxy(g);
        getchar();
    }

    destroy_galaxy(g);

    return 0;
}