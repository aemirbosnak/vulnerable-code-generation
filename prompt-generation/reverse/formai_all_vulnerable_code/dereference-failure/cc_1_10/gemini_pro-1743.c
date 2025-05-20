//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    char symbol;
} Entity;

typedef struct {
    Entity *entities;
    int num_entities;
    int width, height;
} World;

void init_world(World *world, int width, int height) {
    world->width = width;
    world->height = height;
    world->entities = malloc(sizeof(Entity) * 100);
    world->num_entities = 0;
}

void free_world(World *world) {
    free(world->entities);
}

void add_entity(World *world, Entity entity) {
    world->entities[world->num_entities++] = entity;
}

void draw_world(World *world) {
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++) {
            bool found_entity = false;
            for (int i = 0; i < world->num_entities; i++) {
                if (world->entities[i].pos.x == x && world->entities[i].pos.y == y) {
                    printf("%c", world->entities[i].symbol);
                    found_entity = true;
                    break;
                }
            }
            if (!found_entity) {
                printf(".");
            }
        }
        printf("\n");
    }
}

void update_world(World *world) {
    // Update entities.
    for (int i = 0; i < world->num_entities; i++) {
        // Move entities randomly.
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        world->entities[i].pos.x = (world->entities[i].pos.x + dx + world->width) % world->width;
        world->entities[i].pos.y = (world->entities[i].pos.y + dy + world->height) % world->height;
    }
}

int main() {
    srand(time(NULL));

    World world;
    init_world(&world, 80, 25);

    // Add player.
    Entity player = {{0, 0}, '@'};
    add_entity(&world, player);

    // Add monsters.
    for (int i = 0; i < 10; i++) {
        Entity monster = {{rand() % world.width, rand() % world.height}, 'M'};
        add_entity(&world, monster);
    }

    // Game loop.
    while (true) {
        // Draw world.
        draw_world(&world);

        // Update world.
        update_world(&world);

        // Handle input.
        char input = getchar();
        switch (input) {
            case 'w':
                player.pos.y--;
                break;
            case 's':
                player.pos.y++;
                break;
            case 'a':
                player.pos.x--;
                break;
            case 'd':
                player.pos.x++;
                break;
            case 'q':
                return 0;
        }
    }

    free_world(&world);
    return 0;
}