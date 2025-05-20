//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_HAUNTED_ROOMS 5
#define MAX_GHOUL_COUNT 10

typedef struct Room {
    char name[20];
    int ghostly_presence;
    struct Room* next;
} Room;

Room* createRoom(char* name, int ghostlyPresence) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->ghostly_presence = ghostlyPresence;
    newRoom->next = NULL;
    return newRoom;
}

void hauntHouse(Room* currentRoom) {
    if (currentRoom->ghostly_presence) {
        int numGhosts = rand() % MAX_GHOUL_COUNT;
        for (int i = 0; i < numGhosts; i++) {
            printf("A ghostly presence in %s!\n", currentRoom->name);
        }
    }
}

int main() {
    // Create a haunted house
    Room* firstRoom = createRoom("The Living Room", 3);
    Room* secondRoom = createRoom("The Dining Room", 2);
    Room* thirdRoom = createRoom("The Bedroom", 4);
    Room* fourthRoom = createRoom("The Kitchen", 1);
    Room* fifthRoom = createRoom("The Basement", 5);

    // Link the rooms together
    firstRoom->next = secondRoom;
    secondRoom->next = thirdRoom;
    thirdRoom->next = fourthRoom;
    fourthRoom->next = fifthRoom;

    // Haunt the house
    hauntHouse(firstRoom);

    return 0;
}