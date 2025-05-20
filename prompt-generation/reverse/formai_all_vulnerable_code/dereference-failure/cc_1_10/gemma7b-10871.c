//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 5
#define GHOST_COUNT 3

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Ghost* ghosts;
} Room;

typedef struct Ghost {
    char name[20];
    int haunt_frequency;
    struct Ghost* next;
} Ghost;

Room* createRoom(char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->ghosts = NULL;
    return newRoom;
}

Ghost* createGhost(char* name, int haunt_frequency) {
    Ghost* newGhost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->haunt_frequency = haunt_frequency;
    newGhost->next = NULL;
    return newGhost;
}

void haunt(Room* room) {
    if (room->ghosts) {
        Ghost* ghost = room->ghosts;
        while (ghost) {
            if (rand() % ghost->haunt_frequency == 0) {
                printf("%s has appeared!\n", ghost->name);
            }
            ghost = ghost->next;
        }
    }
}

int main() {
    srand(time(NULL));

    Room* rooms = createRoom("The Grand Hall");
    rooms = createRoom("The Dining Room");
    rooms = createRoom("The Library");
    rooms = createRoom("The Ballroom");
    rooms = createRoom("The Haunted Attic");

    Ghost* ghosts = createGhost("The Bloody Lady", 20);
    ghosts = createGhost("The Cold One", 15);
    ghosts = createGhost("The Poltergeist", 10);

    rooms->ghosts = ghosts;

    haunt(rooms);

    return 0;
}