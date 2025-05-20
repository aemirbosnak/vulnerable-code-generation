//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { HUMAN, CYBORG, ROBOT } Species;

typedef struct {
    Species species;
    char *name;
    int age;
    int health;
    int strength;
    int intelligence;
} Entity;

Entity *createEntity(Species species, char *name, int age, int health, int strength, int intelligence) {
    Entity *entity = malloc(sizeof(Entity));
    if (!entity) {
        fprintf(stderr, "Error: Could not allocate memory for entity.\n");
        return NULL;
    }

    entity->species = species;
    entity->name = strdup(name);
    entity->age = age;
    entity->health = health;
    entity->strength = strength;
    entity->intelligence = intelligence;

    return entity;
}

void destroyEntity(Entity *entity) {
    free(entity->name);
    free(entity);
}

void printEntity(Entity *entity) {
    printf("Entity: %s\n", entity->name);
    printf("Species: %s\n", entity->species == HUMAN ? "Human" : entity->species == CYBORG ? "Cyborg" : "Robot");
    printf("Age: %d\n", entity->age);
    printf("Health: %d\n", entity->health);
    printf("Strength: %d\n", entity->strength);
    printf("Intelligence: %d\n", entity->intelligence);
}

int main() {
    Entity *human = createEntity(HUMAN, "John Smith", 25, 100, 50, 75);
    Entity *cyborg = createEntity(CYBORG, "Jane Doe", 30, 150, 75, 100);
    Entity *robot = createEntity(ROBOT, "R2-D2", 50, 200, 100, 125);

    printEntity(human);
    printEntity(cyborg);
    printEntity(robot);

    destroyEntity(human);
    destroyEntity(cyborg);
    destroyEntity(robot);

    return 0;
}