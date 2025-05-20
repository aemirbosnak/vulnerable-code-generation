//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int state;
    int actions[MAX_GHOSTS];
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Sarah", 1, 0, {0, 1, 2, 3}},
    {"John", 2, 1, {1, 2, 3, 4}},
    {"Mary", 3, 0, {0, 2, 3, 4}},
    {"Thomas", 4, 1, {0, 2, 3, 5}},
    {"Alice", 5, 0, {0, 1, 3, 5}}
};

void simulateGhost(int ghostIndex) {
    Ghost *ghost = &ghosts[ghostIndex];

    // Randomly choose an action
    int actionIndex = rand() % ghost->actions[ghostIndex];

    // Perform the action
    switch (actionIndex) {
        case 0:
            printf("The ghost %s whispers secrets in your ear.\n", ghost->name);
            break;
        case 1:
            printf("The ghost %s moves towards you.\n", ghost->name);
            break;
        case 2:
            printf("The ghost %s tries to scare you.\n", ghost->name);
            break;
        case 3:
            printf("The ghost %s tries to possess you.\n", ghost->name);
            break;
        case 4:
            printf("The ghost %s disappears.\n", ghost->name);
            break;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Simulate each ghost
    for (int i = 0; i < MAX_GHOSTS; i++) {
        simulateGhost(i);
    }

    return 0;
}