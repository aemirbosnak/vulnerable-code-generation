//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 3
#define GHOST_COUNT 2

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

Room* create_room(char* name) {
    Room* room = malloc(sizeof(Room));
    strcpy(room->name, name);
    room->next = NULL;
    room->ghosts = NULL;
    return room;
}

Ghost* create_ghost(char* name, int haunt_frequency) {
    Ghost* ghost = malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->haunt_frequency = haunt_frequency;
    ghost->next = NULL;
    return ghost;
}

void haunt_room(Room* room) {
    if (room->ghosts) {
        for (Ghost* ghost = room->ghosts; ghost; ghost = ghost->next) {
            int haunt_chance = rand() % ghost->haunt_frequency;
            if (haunt_chance == 0) {
                printf("%s has been haunted by %s!\n", room->name, ghost->name);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Room* rooms = create_room("The Foyer");
    rooms = create_room("The Living Room");
    rooms = create_room("The Kitchen");

    Ghost* ghosts = create_ghost("The Poltergeist", 3);
    ghosts = create_ghost("The Banshee", 5);

    rooms->ghosts = ghosts;

    haunt_room(rooms);

    return 0;
}