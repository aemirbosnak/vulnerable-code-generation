//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room;
    int type;
    struct Ghost* next;
} Ghost;

Ghost* CreateGhost(char* name, int room, int type) {
    Ghost* ghost = malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->room = room;
    ghost->type = type;
    ghost->next = NULL;
    return ghost;
}

void AddGhost(Ghost* head, char* name, int room, int type) {
    Ghost* newGhost = CreateGhost(name, room, type);
    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
    }
}

void HauntedHouse(Ghost* head) {
    srand(time(NULL));
    int numGhosts = rand() % MAX_GHOSTS + 1;
    for (int i = 0; i < numGhosts; i++) {
        int room = rand() % 5 + 1;
        switch (rand() % 3) {
            case 0:
                AddGhost(head, "Mr. Squibbles", room, 0);
                break;
            case 1:
                AddGhost(head, "The Disembodied", room, 1);
                break;
            case 2:
                AddGhost(head, "The Blood Countess", room, 2);
                break;
        }
    }

    for (Ghost* ghost = head; ghost; ghost = ghost->next) {
        printf("Name: %s, Room: %d, Type: %d\n", ghost->name, ghost->room, ghost->type);
    }
}

int main() {
    HauntedHouse(NULL);
    return 0;
}