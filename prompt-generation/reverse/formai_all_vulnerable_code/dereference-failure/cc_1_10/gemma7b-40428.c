//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room* createRoom(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

void connectRooms(Room* r1, Room* r2) {
    r1->east = r2;
    r2->west = r1;
}

int main() {
    srand(time(NULL));

    Room* rooms = NULL;
    int numRooms = 0;

    // Generate rooms
    for (int i = 0; i < 10; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        Room* room = createRoom(x, y);
        connectRooms(rooms, room);
        rooms = room;
        numRooms++;
    }

    // Explore the dungeon
    Room* currentRoom = rooms;
    while (currentRoom) {
        // Do something with the current room
        printf("You are in room (%d, %d)\n", currentRoom->x, currentRoom->y);

        // Go to the next room
        if (currentRoom->north) {
            currentRoom = currentRoom->north;
        } else if (currentRoom->south) {
            currentRoom = currentRoom->south;
        } else if (currentRoom->east) {
            currentRoom = currentRoom->east;
        } else if (currentRoom->west) {
            currentRoom = currentRoom->west;
        } else {
            break;
        }
    }

    // Print the end message
    printf("You have reached the end of the dungeon!");

    return 0;
}