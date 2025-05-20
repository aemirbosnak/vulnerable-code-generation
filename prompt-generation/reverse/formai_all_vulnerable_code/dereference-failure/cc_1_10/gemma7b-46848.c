//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int spectral_presence;
    struct Ghost *next;
} Ghost;

Ghost *head = NULL;

void addGhost(char *name, int room_num, int spectral_presence) {
    Ghost *newGhost = (Ghost *)malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->room_num = room_num;
    newGhost->spectral_presence = spectral_presence;
    newGhost->next = NULL;

    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
        head = newGhost;
    }
}

void haunt(int room_num) {
    Ghost *currentGhost = head;

    while (currentGhost) {
        if (currentGhost->room_num == room_num) {
            printf("%s has been spotted in room %d!\n", currentGhost->name, room_num);
            currentGhost->spectral_presence++;
        }
        currentGhost = currentGhost->next;
    }
}

int main() {
    addGhost("Mr. Jones", 1, 5);
    addGhost("Ms. Smith", 2, 3);
    addGhost("Mr. Brown", 3, 2);

    haunt(1);
    haunt(2);
    haunt(3);

    return 0;
}