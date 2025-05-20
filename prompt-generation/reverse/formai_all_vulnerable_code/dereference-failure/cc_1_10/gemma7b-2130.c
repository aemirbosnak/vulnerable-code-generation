//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ephemeral
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_ROOM_COUNT 10

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
    char description[256];
} Room;

Room** generateRooms(int roomCount) {
    srand(time(NULL));

    Room** rooms = malloc(roomCount * sizeof(Room*));

    for (int i = 0; i < roomCount; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->x = rand() % 20;
        rooms[i]->y = rand() % 20;
        rooms[i]->north = NULL;
        rooms[i]->south = NULL;
        rooms[i]->east = NULL;
        rooms[i]->west = NULL;
        rooms[i]->description[0] = '\0';
    }

    return rooms;
}

void connectRooms(Room** rooms, int roomCount) {
    for (int i = 0; i < roomCount; i++) {
        int direction = rand() % 4;

        switch (direction) {
            case 0:
                rooms[i]->north = rooms[rand() % roomCount];
                break;
            case 1:
                rooms[i]->south = rooms[rand() % roomCount];
                break;
            case 2:
                rooms[i]->east = rooms[rand() % roomCount];
                break;
            case 3:
                rooms[i]->west = rooms[rand() % roomCount];
                break;
        }
    }
}

int main() {
    int roomCount = rand() % MAX_ROOM_COUNT + 1;

    Room** rooms = generateRooms(roomCount);
    connectRooms(rooms, roomCount);

    // Play the game...

    return 0;
}