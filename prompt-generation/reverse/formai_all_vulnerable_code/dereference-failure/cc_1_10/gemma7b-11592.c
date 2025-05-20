//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int active;
    int sound;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int room, int active, int sound) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->room = room;
    ghost->active = active;
    ghost->sound = sound;
    ghost->next = NULL;
    return ghost;
}

void addGhost(Ghost* head, Ghost* newGhost) {
    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
        head = newGhost;
    }
}

int main() {
    srand(time(NULL));
    Ghost* head = NULL;

    // Create 5 ghosts
    Ghost* ghost1 = createGhost("Mr. Jones", 1, 1, 5);
    Ghost* ghost2 = createGhost("Mrs. Smith", 2, 0, 3);
    Ghost* ghost3 = createGhost("Mr. Brown", 3, 1, 2);
    Ghost* ghost4 = createGhost("Ms. Green", 4, 0, 4);
    Ghost* ghost5 = createGhost("Mr. White", 5, 1, 6);

    // Add ghosts to the head
    addGhost(head, ghost1);
    addGhost(head, ghost2);
    addGhost(head, ghost3);
    addGhost(head, ghost4);
    addGhost(head, ghost5);

    // Simulate haunted house
    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (head->active) {
            printf("%s is lurking in room %d...\n", head->name, head->room);
            printf("Suddenly, you hear a %d sound...\n", head->sound);
            sleep(rand() % 3);
        }
        head = head->next;
    }

    return 0;
}