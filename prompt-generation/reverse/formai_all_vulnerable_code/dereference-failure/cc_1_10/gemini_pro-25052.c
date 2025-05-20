//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
} Ship;

typedef struct {
    int width;
    int height;
    Ship *ships;
    int num_ships;
} Universe;

Universe *create_universe(int width, int height, int num_ships) {
    Universe *universe = malloc(sizeof(Universe));
    universe->width = width;
    universe->height = height;
    universe->num_ships = num_ships;
    universe->ships = malloc(sizeof(Ship) * num_ships);

    for (int i = 0; i < num_ships; i++) {
        universe->ships[i].position.x = rand() % width;
        universe->ships[i].position.y = rand() % height;
        universe->ships[i].velocity.x = rand() % 10;
        universe->ships[i].velocity.y = rand() % 10;
    }

    return universe;
}

void update_universe(Universe *universe) {
    for (int i = 0; i < universe->num_ships; i++) {
        universe->ships[i].position.x += universe->ships[i].velocity.x;
        universe->ships[i].position.y += universe->ships[i].velocity.y;

        if (universe->ships[i].position.x < 0) {
            universe->ships[i].position.x = universe->width - 1;
        } else if (universe->ships[i].position.x >= universe->width) {
            universe->ships[i].position.x = 0;
        }

        if (universe->ships[i].position.y < 0) {
            universe->ships[i].position.y = universe->height - 1;
        } else if (universe->ships[i].position.y >= universe->height) {
            universe->ships[i].position.y = 0;
        }
    }
}

void draw_universe(Universe *universe) {
    for (int y = 0; y < universe->height; y++) {
        for (int x = 0; x < universe->width; x++) {
            int ship_found = 0;
            for (int i = 0; i < universe->num_ships; i++) {
                if (universe->ships[i].position.x == x && universe->ships[i].position.y == y) {
                    printf("*");
                    ship_found = 1;
                    break;
                }
            }
            if (!ship_found) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Universe *universe = create_universe(80, 25, 10);

    while (1) {
        update_universe(universe);
        draw_universe(universe);
        sleep(1);
    }

    free(universe->ships);
    free(universe);

    return 0;
}