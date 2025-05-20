//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int active;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Sarah", 1, 1},
    {"John", 2, 1},
    {"Mary", 3, 1},
    {"Peter", 4, 1},
    {"Alice", 5, 1}
};

void spawnGhost(int room) {
    time_t t = time(NULL);
    srand(t);
    int index = rand() % MAX_GHOSTS;
    ghosts[index].active = 1;
    ghosts[index].room = room;
}

int main() {
    int i;
    for (i = 0; i < MAX_GHOSTS; i++) {
        spawnGhost(ghosts[i].room);
    }

    printf("Welcome to the Haunted House!\n");
    printf("Please enter the room number you want to visit: ");
    int roomNumber = atoi(stdin);

    if (ghosts[0].active && ghosts[0].room == roomNumber) {
        printf("The door creaks open... and you hear a whisper in your ear...\n");
    } else if (ghosts[1].active && ghosts[1].room == roomNumber) {
        printf("You hear a shuffling sound and feel a cold hand brush against your back...\n");
    } else if (ghosts[2].active && ghosts[2].room == roomNumber) {
        printf("A disembodied voice echoes through the halls...\n");
    } else if (ghosts[3].active && ghosts[3].room == roomNumber) {
        printf("The air thickens with the scent of decay and blood...\n");
    } else if (ghosts[4].active && ghosts[4].room == roomNumber) {
        printf("You hear a bell ringing and see a ghostly figure standing at the end of the hall...\n");
    } else {
        printf("There is nothing in that room.\n");
    }

    return 0;
}