//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int haunt_frequency;
    int room_number;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int haunt_frequency, int room_number) {
    Ghost* ghost = malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->haunt_frequency = haunt_frequency;
    ghost->room_number = room_number;
    ghost->next = NULL;
    return ghost;
}

void haunt(Ghost* ghost) {
    srand(time(NULL));
    int haunt_chance = rand() % ghost->haunt_frequency;
    if (haunt_chance == 0) {
        switch (ghost->room_number) {
            case 1:
                printf("You hear a shuffling sound in the hallway.\n");
                break;
            case 2:
                printf("You smell the stench of decay in the kitchen.\n");
                break;
            case 3:
                printf("You see a ghostly figure hovering near the fireplace.\n");
                break;
            default:
                printf("Something sinister happens.\n");
                break;
        }
    }
}

int main() {
    Ghost* head = createGhost("Mr. Jones", 3, 1);
    head = createGhost("Mrs. Smith", 2, 2);
    head = createGhost("Mr. Brown", 4, 3);

    haunt(head);

    return 0;
}