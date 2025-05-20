//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 20

typedef struct Room
{
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
    char name[20];
    int isVisited;
} Room;

Room* createRoom(char* name)
{
    Room* newRoom = malloc(sizeof(Room));
    newRoom->north = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;
    newRoom->west = NULL;
    strcpy(newRoom->name, name);
    newRoom->isVisited = 0;
    return newRoom;
}

void generateMaze(int numRooms)
{
    srand(time(NULL));

    Room* rooms[numRooms];
    for(int i = 0; i < numRooms; i++)
    {
        rooms[i] = createRoom(NULL);
    }

    for(int i = 0; i < numRooms; i++)
    {
        int randomDoor = rand() % 4;

        switch(randomDoor)
        {
            case 0:
                rooms[i]->north = rooms[rand() % numRooms];
                break;
            case 1:
                rooms[i]->south = rooms[rand() % numRooms];
                break;
            case 2:
                rooms[i]->east = rooms[rand() % numRooms];
                break;
            case 3:
                rooms[i]->west = rooms[rand() % numRooms];
                break;
        }
    }

    // Connect the first and last rooms
    rooms[0]->south = rooms[numRooms - 1];
    rooms[numRooms - 1]->north = rooms[0];
}

int main()
{
    generateMaze(MAX_Rooms);

    return 0;
}