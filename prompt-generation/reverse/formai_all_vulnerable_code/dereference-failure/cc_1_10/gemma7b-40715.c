//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room;
    int action;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int room, int action) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->room = room;
    ghost->action = action;
    ghost->next = NULL;
    return ghost;
}

void addGhost(Ghost* head, char* name, int room, int action) {
    Ghost* newGhost = createGhost(name, room, action);
    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
    }
}

void haunt(Ghost* head) {
    while (head) {
        switch (head->action) {
            case 0:
                printf("%s haunts the %dth room.\n", head->name, head->room);
                break;
            case 1:
                printf("%s whispers secrets in your ear.\n", head->name);
                break;
            case 2:
                printf("%s throws a ghostly hand at you.\n", head->name);
                break;
            case 3:
                printf("%s tries to pull you into the void.\n", head->name);
                break;
            default:
                break;
        }
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;
    addGhost(head, "Anna", 1, 0);
    addGhost(head, "Billy", 2, 1);
    addGhost(head, "Charlie", 3, 2);
    addGhost(head, "Dave", 4, 3);
    addGhost(head, "Emily", 5, 0);

    haunt(head);

    return 0;
}