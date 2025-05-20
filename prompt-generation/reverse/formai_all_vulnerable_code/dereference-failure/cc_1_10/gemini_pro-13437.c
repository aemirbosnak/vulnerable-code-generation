//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int size;
} Entity;

typedef struct {
    Entity *entities;
    int num_entities;
} World;

World *world_new() {
    World *world = malloc(sizeof(World));
    world->entities = NULL;
    world->num_entities = 0;
    return world;
}

void world_free(World *world) {
    free(world->entities);
    free(world);
}

void world_add_entity(World *world, Entity *entity) {
    world->entities = realloc(world->entities, sizeof(Entity) * (world->num_entities + 1));
    world->entities[world->num_entities++] = *entity;
}

void world_update(World *world) {
    for (int i = 0; i < world->num_entities; i++) {
        Entity *entity = &world->entities[i];
        entity->pos.x += rand() % 3 - 1;
        entity->pos.y += rand() % 3 - 1;
        if (entity->pos.x < 0) entity->pos.x = 0;
        if (entity->pos.y < 0) entity->pos.y = 0;
        if (entity->pos.x >= WIDTH) entity->pos.x = WIDTH - 1;
        if (entity->pos.y >= HEIGHT) entity->pos.y = HEIGHT - 1;
    }
}

void world_draw(World *world) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int found = 0;
            for (int i = 0; i < world->num_entities; i++) {
                Entity *entity = &world->entities[i];
                if (entity->pos.x == x && entity->pos.y == y) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                printf("@");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    World *world = world_new();

    for (int i = 0; i < 100; i++) {
        Entity entity;
        entity.pos.x = rand() % WIDTH;
        entity.pos.y = rand() % HEIGHT;
        entity.size = rand() % 10 + 1;
        world_add_entity(world, &entity);
    }

    while (1) {
        world_update(world);
        world_draw(world);
        usleep(100000);
    }

    world_free(world);

    return 0;
}