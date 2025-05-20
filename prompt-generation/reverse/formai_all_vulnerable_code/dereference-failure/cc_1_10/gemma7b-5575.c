//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int haunt_location;
    int frequency;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int haunt_location, int frequency) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->haunt_location = haunt_location;
    ghost->frequency = frequency;
    ghost->next = NULL;
    return ghost;
}

void haunt(Ghost* ghost) {
    switch (ghost->frequency) {
        case 1:
            printf("You hear a whisper in your ear.\n");
            break;
        case 2:
            printf("You see a flickering shadow out of the corner of your eye.\n");
            break;
        case 3:
            printf("You feel a cold hand brush against your skin.\n");
            break;
        case 4:
            printf("You hear footsteps behind you.\n");
            break;
        case 5:
            printf("You hear a scream and see a ghostly figure standing over you.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    Ghost* head = createGhost("John", 1, 2);
    head->next = createGhost("Mary", 2, 3);
    head->next->next = createGhost("Bob", 3, 4);
    head->next->next->next = createGhost("Alice", 4, 5);

    haunt(head);

    return 0;
}