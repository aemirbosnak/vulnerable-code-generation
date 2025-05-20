//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
// Procedural Space Adventure Engine
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data structures
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Entity;

typedef struct {
    Entity *entities[10];
    int num_entities;
} Scene;

// Functions
Scene *create_scene(void) {
    Scene *scene = malloc(sizeof(Scene));
    scene->num_entities = 0;
    return scene;
}

void destroy_scene(Scene *scene) {
    for (int i = 0; i < scene->num_entities; i++) {
        free(scene->entities[i]);
    }
    free(scene);
}

Entity *create_entity(char *name, int health, int attack, int defense) {
    Entity *entity = malloc(sizeof(Entity));
    entity->name = strdup(name);
    entity->health = health;
    entity->attack = attack;
    entity->defense = defense;
    return entity;
}

void destroy_entity(Entity *entity) {
    free(entity->name);
    free(entity);
}

void add_entity_to_scene(Scene *scene, Entity *entity) {
    scene->entities[scene->num_entities++] = entity;
}

void remove_entity_from_scene(Scene *scene, Entity *entity) {
    for (int i = 0; i < scene->num_entities; i++) {
        if (scene->entities[i] == entity) {
            scene->entities[i] = scene->entities[scene->num_entities - 1];
            scene->num_entities--;
            break;
        }
    }
}

void print_scene(Scene *scene) {
    for (int i = 0; i < scene->num_entities; i++) {
        printf("%s (%d health, %d attack, %d defense)\n",
            scene->entities[i]->name,
            scene->entities[i]->health,
            scene->entities[i]->attack,
            scene->entities[i]->defense);
    }
}

int main(void) {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new scene
    Scene *scene = create_scene();

    // Create some entities
    Entity *player = create_entity("Player", 100, 10, 5);
    Entity *goblin = create_entity("Goblin", 50, 5, 2);
    Entity *dragon = create_entity("Dragon", 1000, 50, 20);

    // Add the entities to the scene
    add_entity_to_scene(scene, player);
    add_entity_to_scene(scene, goblin);
    add_entity_to_scene(scene, dragon);

    // Print the scene
    print_scene(scene);

    // Destroy the entities
    destroy_entity(player);
    destroy_entity(goblin);
    destroy_entity(dragon);

    // Destroy the scene
    destroy_scene(scene);

    return 0;
}