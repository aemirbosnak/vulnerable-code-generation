//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost Ghost;
struct Ghost {
    char name[20];
    int room;
    int actions;
    int health;
    Ghost* next;
};

Ghost* createGhost(char* name, int room, int actions, int health) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->room = room;
    ghost->actions = actions;
    ghost->health = health;
    ghost->next = NULL;
    return ghost;
}

void haunt(Ghost* ghost) {
    switch (ghost->actions) {
        case 1:
            printf("You hear a whisper in the hallway.\n");
            break;
        case 2:
            printf("You see a ghostly figure moving through the halls.\n");
            break;
        case 3:
            printf("You feel a cold hand brush against your skin.\n");
            break;
        case 4:
            printf("You hear footsteps coming up the stairs.\n");
            break;
        case 5:
            printf("You see a ghostly figure standing in the doorway to your room.\n");
            break;
    }
}

int main() {
    time_t t;
    srand(time(NULL));

    Ghost* head = createGhost("Jack", 1, 2, 100);
    head = createGhost("Mary", 2, 3, 80);
    head = createGhost("Peter", 3, 1, 60);

    while (1) {
        t = time(NULL);
        sleep(rand() % 3);
        haunt(head);
    }

    return 0;
}