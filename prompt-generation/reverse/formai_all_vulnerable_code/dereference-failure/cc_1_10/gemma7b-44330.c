//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STARS 1000
#define MAX_ROCKS 50

typedef struct CelestialObject {
    char type;
    int x, y, z;
    struct CelestialObject* next;
} CelestialObject;

CelestialObject* create_star(int x, int y, int z) {
    CelestialObject* star = malloc(sizeof(CelestialObject));
    star->type = 'S';
    star->x = x;
    star->y = y;
    star->z = z;
    star->next = NULL;
    return star;
}

CelestialObject* create_rock(int x, int y, int z) {
    CelestialObject* rock = malloc(sizeof(CelestialObject));
    rock->type = 'R';
    rock->x = x;
    rock->y = y;
    rock->z = z;
    rock->next = NULL;
    return rock;
}

int main() {
    srand(time(NULL));

    CelestialObject* head = NULL;

    // Create MAX_STARS stars
    for (int i = 0; i < MAX_STARS; i++) {
        create_star(rand() % 1000, rand() % 1000, rand() % 1000);
    }

    // Create MAX_ROCKS rocks
    for (int i = 0; i < MAX_ROCKS; i++) {
        create_rock(rand() % 1000, rand() % 1000, rand() % 1000);
    }

    // Print stars and rocks
    CelestialObject* current = head;
    while (current) {
        switch (current->type) {
            case 'S':
                printf("Star at (%d, %d, %d)\n", current->x, current->y, current->z);
                break;
            case 'R':
                printf("Rock at (%d, %d, %d)\n", current->x, current->y, current->z);
                break;
        }
        current = current->next;
    }

    return 0;
}