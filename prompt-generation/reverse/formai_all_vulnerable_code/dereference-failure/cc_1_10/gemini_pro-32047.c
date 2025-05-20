//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} point_t;

typedef struct {
    point_t pos;
    char symbol;
} entity_t;

typedef struct {
    int width, height;
    char **grid;
    entity_t *player;
    entity_t **entities;
    int num_entities;
} world_t;

world_t *world_new(int width, int height) {
    world_t *world = malloc(sizeof(world_t));
    world->width = width;
    world->height = height;
    world->grid = malloc(sizeof(char *) * height);
    for (int y = 0; y < height; y++) {
        world->grid[y] = malloc(sizeof(char) * width);
    }
    world->player = malloc(sizeof(entity_t));
    world->player->pos.x = width / 2;
    world->player->pos.y = height / 2;
    world->player->symbol = '@';
    world->entities = malloc(sizeof(entity_t *) * 100);
    world->num_entities = 0;
    return world;
}

void world_free(world_t *world) {
    for (int y = 0; y < world->height; y++) {
        free(world->grid[y]);
    }
    free(world->grid);
    free(world->player);
    for (int i = 0; i < world->num_entities; i++) {
        free(world->entities[i]);
    }
    free(world->entities);
    free(world);
}

void world_generate(world_t *world) {
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++) {
            if (rand() % 100 < 50) {
                world->grid[y][x] = '#';
            } else {
                world->grid[y][x] = '.';
            }
        }
    }
}

void world_add_entity(world_t *world, entity_t *entity) {
    world->entities[world->num_entities++] = entity;
}

void world_draw(world_t *world) {
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++) {
            if (world->player->pos.x == x && world->player->pos.y == y) {
                printf("@");
            } else {
                printf("%c", world->grid[y][x]);
            }
        }
        printf("\n");
    }
}

void world_update(world_t *world) {
    for (int i = 0; i < world->num_entities; i++) {
        entity_t *entity = world->entities[i];
        if (rand() % 100 < 50) {
            entity->pos.x += rand() % 3 - 1;
        }
        if (rand() % 100 < 50) {
            entity->pos.y += rand() % 3 - 1;
        }
    }
}

int main() {
    srand(time(NULL));
    world_t *world = world_new(80, 25);
    world_generate(world);
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos.x = 10;
    entity->pos.y = 10;
    entity->symbol = 'X';
    world_add_entity(world, entity);
    while (1) {
        world_draw(world);
        world_update(world);
    }
    world_free(world);
    return 0;
}