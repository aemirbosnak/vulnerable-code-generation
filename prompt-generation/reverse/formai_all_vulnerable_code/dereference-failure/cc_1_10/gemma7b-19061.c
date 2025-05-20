//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int type;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(int room, int type) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, "Ghost");
    ghost->room = room;
    ghost->type = type;
    ghost->next = NULL;
    return ghost;
}

void addGhost(Ghost* head, int room, int type) {
    Ghost* newGhost = createGhost(room, type);
    if (head == NULL) {
        head = newGhost;
    } else {
        newGhost->next = head;
        head = newGhost;
    }
}

void hauntHouse(Ghost* head) {
    while (head) {
        printf("%s haunts the room %d.\n", head->name, head->room);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));

    Ghost* head = NULL;
    addGhost(head, 1, 1);
    addGhost(head, 2, 2);
    addGhost(head, 3, 1);
    addGhost(head, 4, 2);

    hauntHouse(head);

    return 0;
}