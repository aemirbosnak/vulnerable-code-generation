//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_COUNT 10

typedef struct Room
{
    int x, y;
    struct Room* north, *south, *east, *west;
    char description[256];
} Room;

Room* createRoom(int x, int y)
{
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    room->description[0] = '\0';
    return room;
}

void generateRooms(Room* room, int roomCount)
{
    if (roomCount <= MAX_ROOM_COUNT)
    {
        generateRooms(room, roomCount + 1);

        room->north = createRoom(room->x, room->y - 1);
        room->south = createRoom(room->x, room->y + 1);
        room->east = createRoom(room->x + 1, room->y);
        room->west = createRoom(room->x - 1, room->y);

        room->description[0] = 'A';
        sprintf(room->description + 1, "You are in a %s room.", "small");
    }
}

int main()
{
    Room* start = createRoom(0, 0);
    generateRooms(start, 1);

    printf("%s\n", start->description);

    return 0;
}