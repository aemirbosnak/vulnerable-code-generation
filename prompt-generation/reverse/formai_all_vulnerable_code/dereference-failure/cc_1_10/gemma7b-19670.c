//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int scare_level;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int scare_level) {
    Ghost* new_ghost = malloc(sizeof(Ghost));
    strcpy(new_ghost->name, name);
    new_ghost->room_num = room_num;
    new_ghost->scare_level = scare_level;
    new_ghost->next = NULL;
    return new_ghost;
}

void wander_ghosts(Ghost* ghosts) {
    while (ghosts) {
        int room_num = ghosts->room_num;
        printf("Ghost %s is wandering through room %d...\n", ghosts->name, room_num);
        ghosts = ghosts->next;
    }
}

void interact_with_ghosts(Ghost* ghosts) {
    while (ghosts) {
        int scare_level = ghosts->scare_level;
        printf("You encountered Ghost %s! Prepare for a scare...\n", ghosts->name);
        if (scare_level > 5) {
            printf("BOO!\n");
            exit(0);
        } else {
            printf("Ghost %s has retreated.\n", ghosts->name);
        }
        ghosts = ghosts->next;
    }
}

int main() {
    srand(time(NULL));

    Ghost* ghosts = create_ghost("John Doe", 1, 8);
    ghosts = create_ghost("Mary Smith", 3, 6);
    ghosts = create_ghost("Peter Pan", 5, 7);

    wander_ghosts(ghosts);
    interact_with_ghosts(ghosts);

    return 0;
}