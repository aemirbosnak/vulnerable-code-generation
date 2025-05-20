//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    char symbol;
    int health;
} Entity;

typedef struct {
    char **tiles;
    Entity *entities;
    int num_entities;
} World;

World *create_world() {
    World *world = malloc(sizeof(World));
    world->tiles = malloc(sizeof(char *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        world->tiles[i] = malloc(sizeof(char) * WIDTH);
    }
    world->entities = malloc(sizeof(Entity) * 100);
    world->num_entities = 0;
    return world;
}

void free_world(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        free(world->tiles[i]);
    }
    free(world->tiles);
    free(world->entities);
    free(world);
}

void generate_dungeon(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            world->tiles[i][j] = (rand() % 10 == 0) ? '#' : ' ';
        }
    }
}

void place_entities(World *world) {
    for (int i = 0; i < 10; i++) {
        Entity entity;
        entity.pos.x = rand() % WIDTH;
        entity.pos.y = rand() % HEIGHT;
        entity.symbol = 'G';
        entity.health = 10;
        world->entities[world->num_entities++] = entity;
    }
}

void print_world(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", world->tiles[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    World *world = create_world();
    generate_dungeon(world);
    place_entities(world);
    print_world(world);

    free_world(world);

    return 0;
}