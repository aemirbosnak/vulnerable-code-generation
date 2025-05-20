//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int activity_level;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int room_num, int activity_level) {
    Ghost* newGhost = malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->room_num = room_num;
    newGhost->activity_level = activity_level;
    newGhost->next = NULL;
    return newGhost;
}

void addGhost(Ghost* head, Ghost* newGhost) {
    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
        head = newGhost;
    }
}

void scare(Ghost* ghost) {
    switch (ghost->activity_level) {
        case 1:
            printf("You hear a soft whisper in the hallway.\n");
            break;
        case 2:
            printf("You see a flickering shadow move across the room.\n");
            break;
        case 3:
            printf("You hear footsteps approaching your room.\n");
            break;
        case 4:
            printf("You feel a cold hand brush against your skin.\n");
            break;
        case 5:
            printf("You see a ghostly figure standing in the doorway to your room.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    Ghost* head = NULL;

    // Create a list of ghosts
    for (int i = 0; i < MAX_GHOSTS; i++) {
        addGhost(head, createGhost("Ghost", rand() % 5 + 1, rand() % 5 + 1));
    }

    // Scares the player
    scare(head);

    return 0;
}