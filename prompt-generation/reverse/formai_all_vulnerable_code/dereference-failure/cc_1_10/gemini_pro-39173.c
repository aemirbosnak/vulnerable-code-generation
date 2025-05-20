//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORLD_WIDTH 100
#define WORLD_HEIGHT 100

struct vehicle {
    int x;
    int y;
    char *name;
};

struct world {
    char **grid;
    struct vehicle *vehicles;
    int num_vehicles;
};

struct world *create_world() {
    struct world *world = malloc(sizeof(struct world));
    world->grid = malloc(sizeof(char *) * WORLD_HEIGHT);
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        world->grid[i] = malloc(sizeof(char) * WORLD_WIDTH);
        for (int j = 0; j < WORLD_WIDTH; j++) {
            world->grid[i][j] = '.';
        }
    }
    world->vehicles = malloc(sizeof(struct vehicle) * 10);
    world->num_vehicles = 0;
    return world;
}

void destroy_world(struct world *world) {
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        free(world->grid[i]);
    }
    free(world->grid);
    free(world->vehicles);
    free(world);
}

void print_world(struct world *world) {
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        for (int j = 0; j < WORLD_WIDTH; j++) {
            printf("%c", world->grid[i][j]);
        }
        printf("\n");
    }
}

void add_vehicle(struct world *world, struct vehicle *vehicle) {
    world->vehicles[world->num_vehicles++] = *vehicle;
}

void move_vehicle(struct world *world, struct vehicle *vehicle, int dx, int dy) {
    if (vehicle->x + dx < 0 || vehicle->x + dx >= WORLD_WIDTH || vehicle->y + dy < 0 || vehicle->y + dy >= WORLD_HEIGHT) {
        return;
    }
    world->grid[vehicle->y][vehicle->x] = '.';
    vehicle->x += dx;
    vehicle->y += dy;
    world->grid[vehicle->y][vehicle->x] = vehicle->name[0];
}

int main() {
    srand(time(NULL));

    struct world *world = create_world();

    struct vehicle vehicle1 = { .x = 0, .y = 0, .name = "A" };
    add_vehicle(world, &vehicle1);
    struct vehicle vehicle2 = { .x = WORLD_WIDTH - 1, .y = WORLD_HEIGHT - 1, .name = "B" };
    add_vehicle(world, &vehicle2);

    while (1) {
        print_world(world);

        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        move_vehicle(world, &vehicle1, dx, dy);

        dx = rand() % 3 - 1;
        dy = rand() % 3 - 1;
        move_vehicle(world, &vehicle2, dx, dy);

        printf("\n");
    }

    destroy_world(world);

    return 0;
}