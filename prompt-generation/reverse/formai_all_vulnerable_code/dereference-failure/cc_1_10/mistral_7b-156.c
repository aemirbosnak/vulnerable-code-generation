//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[32];
    int x, y;
    int isScary;
} Entity;

typedef struct {
    Entity *entities;
    int numEntities;
    int capacity;
} EntityManager;

EntityManager em;

void createEntity(const char *name, int x, int y, int isScary) {
    if (em.numEntities >= em.capacity) {
        em.capacity *= 2;
        em.entities = (Entity *)realloc(em.entities, sizeof(Entity) * em.capacity);
    }

    Entity *e = &em.entities[em.numEntities];
    strcpy(e->name, name);
    e->x = x;
    e->y = y;
    e->isScary = isScary;
    em.numEntities++;
}

void printEntities() {
    printf("Entities:\n");
    for (int i = 0; i < em.numEntities; i++) {
        Entity *e = &em.entities[i];
        printf(" %s (x: %d, y: %d, scary: %s)\n", e->name, e->x, e->y,
            e->isScary ? "yes" : "no");
    }
}

void hauntHouse() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int x = rand() % 10;
        int y = rand() % 10;
        createEntity("Ghost", x, y, 1);
    }

    printEntities();
}

int main() {
    em.entities = malloc(sizeof(Entity) * 4);
    em.numEntities = 0;
    em.capacity = 4;

    hauntHouse();

    for (int i = 0; i < em.numEntities; i++) {
        free(&em.entities[i]);
    }

    free(em.entities);

    return 0;
}