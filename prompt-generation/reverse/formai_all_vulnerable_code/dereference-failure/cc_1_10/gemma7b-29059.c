//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int id;
    float location[2];
    int movement_direction;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int id, float* location, int direction) {
    Ghost* ghost = malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->id = id;
    ghost->location[0] = location[0];
    ghost->location[1] = location[1];
    ghost->movement_direction = direction;
    ghost->next = NULL;
    return ghost;
}

void moveGhost(Ghost* ghost) {
    switch (ghost->movement_direction) {
        case 0:
            ghost->location[0]++;
            break;
        case 1:
            ghost->location[0]--;
            break;
        case 2:
            ghost->location[1]++;
            break;
        case 3:
            ghost->location[1]--;
            break;
    }
}

void hauntHouse(Ghost* ghosts) {
    while (ghosts) {
        moveGhost(ghosts);
        printf("%s moved to (%f, %f)\n", ghosts->name, ghosts->location[0], ghosts->location[1]);
        ghosts = ghosts->next;
    }
}

int main() {
    srand(time(NULL));

    // Create a list of ghosts
    Ghost* ghosts = createGhost("Mr. Jones", 0, (float[]){0.0, 0.0}, rand() % 4);
    ghosts = createGhost("Mrs. Smith", 1, (float[]){1.0, 0.0}, rand() % 4);
    ghosts = createGhost("Mr. Brown", 2, (float[]){1.0, 1.0}, rand() % 4);

    // Haunt the house
    hauntHouse(ghosts);

    return 0;
}