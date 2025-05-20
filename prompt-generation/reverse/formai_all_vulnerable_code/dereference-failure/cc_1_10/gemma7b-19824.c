//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_SIZE 10
#define MAX_NUMBER_OF_ROOMS 20

typedef struct Room
{
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room* createRoom(int x, int y)
{
    Room* newRoom = malloc(sizeof(Room));
    newRoom->x = x;
    newRoom->y = y;
    newRoom->north = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;
    newRoom->west = NULL;

    return newRoom;
}

void generateMaze(int numRooms)
{
    srand(time(NULL));

    Room* firstRoom = createRoom(0, 0);
    Room* currentRoom = firstRoom;

    for (int i = 0; i < numRooms - 1; i++)
    {
        int direction = rand() % 4;

        switch (direction)
        {
            case 0:
                currentRoom->north = createRoom(currentRoom->x, currentRoom->y + 1);
                currentRoom = currentRoom->north;
                break;
            case 1:
                currentRoom->south = createRoom(currentRoom->x, currentRoom->y - 1);
                currentRoom = currentRoom->south;
                break;
            case 2:
                currentRoom->east = createRoom(currentRoom->x + 1, currentRoom->y);
                currentRoom = currentRoom->east;
                break;
            case 3:
                currentRoom->west = createRoom(currentRoom->x - 1, currentRoom->y);
                currentRoom = currentRoom->west;
                break;
        }
    }

    currentRoom->north = firstRoom;
}

int main()
{
    generateMaze(10);

    return 0;
}