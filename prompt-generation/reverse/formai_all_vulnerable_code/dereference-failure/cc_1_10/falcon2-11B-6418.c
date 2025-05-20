//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int direction;
    char name[50];
    int health;
} Entity;

typedef struct {
    int num_entities;
    Entity* entities;
} World;

void create_entity(World* world, int x, int y, char* name, int health) {
    world->num_entities++;
    Entity* entity = malloc(sizeof(Entity));
    entity->x = x;
    entity->y = y;
    entity->direction = 0;
    strcpy(entity->name, name);
    entity->health = health;
    world->entities = realloc(world->entities, sizeof(Entity) * world->num_entities);
    world->entities[world->num_entities-1] = *entity;
}

void move_entity(World* world, int entity_index, int x_offset, int y_offset) {
    Entity* entity = &(world->entities[entity_index]);
    entity->x += x_offset;
    entity->y += y_offset;
    if (entity->x < 0 || entity->x >= 1000 || entity->y < 0 || entity->y >= 1000) {
        entity->health -= 10;
    }
}

void print_entity(Entity* entity) {
    printf("Name: %s\n", entity->name);
    printf("X: %d\n", entity->x);
    printf("Y: %d\n", entity->y);
    printf("Direction: %d\n", entity->direction);
    printf("Health: %d\n\n", entity->health);
}

void print_world(World* world) {
    printf("Number of entities: %d\n", world->num_entities);
    printf("Entities:\n");
    for (int i = 0; i < world->num_entities; i++) {
        print_entity(&(world->entities[i]));
        printf("\n");
    }
}

int main() {
    World world;
    world.num_entities = 0;
    world.entities = NULL;
    srand(time(NULL));

    create_entity(&world, 500, 500, "Player", 100);
    create_entity(&world, 200, 200, "Enemy", 100);

    print_world(&world);

    move_entity(&world, 0, -1, 0);
    move_entity(&world, 1, 1, 1);

    print_world(&world);

    free(world.entities);
    return 0;
}