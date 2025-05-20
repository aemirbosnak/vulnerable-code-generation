//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct Room
{
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room* CreateRoom(int x, int y)
{
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

void ConnectRooms(Room* a, Room* b)
{
    a->east = b;
    b->west = a;
}

void GenerateMap()
{
    int x, y;
    srand(time(NULL));
    for (x = 0; x < MAP_WIDTH; x++)
    {
        for (y = 0; y < MAP_HEIGHT; y++)
        {
            int r = rand() % 3;
            switch (r)
            {
                case 0:
                    CreateRoom(x, y);
                    break;
                case 1:
                    ConnectRooms(CreateRoom(x, y), CreateRoom(x + 1, y));
                    break;
                case 2:
                    ConnectRooms(CreateRoom(x, y), CreateRoom(x, y + 1));
                    break;
            }
        }
    }
}

int main()
{
    GenerateMap();
    return 0;
}