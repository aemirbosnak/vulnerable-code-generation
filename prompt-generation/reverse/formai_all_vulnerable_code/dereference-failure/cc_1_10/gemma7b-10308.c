//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 10

typedef struct Room
{
    char name[20];
    struct Room* next;
    int visited;
} Room;

Room* CreateRoom(char* name)
{
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->visited = 0;
    return newRoom;
}

void ConnectRooms(Room* room1, Room* room2)
{
    room1->next = room2;
}

int main()
{
    // Create a list of rooms
    Room* room1 = CreateRoom("The Rusty Ship");
    Room* room2 = CreateRoom("The Haunted Forest");
    Room* room3 = CreateRoom("The Twisted Tower");

    // Connect the rooms
    ConnectRooms(room1, room2);
    ConnectRooms(room2, room3);

    // Seed the random number generator
    srand(time(NULL));

    // Choose a random room to start in
    int startRoom = rand() % MAX_ROOM;

    // Visit the chosen room
    room1->visited = 1;
    printf("You are in %s.\n", room1->name);

    // Loop until the player has visited all rooms
    while (!room2->visited && !room3->visited)
    {
        // Generate a list of available rooms
        int availableRooms = 0;
        for (Room* currentRoom = room1; currentRoom; currentRoom = currentRoom->next)
        {
            if (!currentRoom->visited)
            {
                availableRooms++;
            }
        }

        // If there are no available rooms, the player has visited all rooms
        if (availableRooms == 0)
        {
            printf("You have visited all rooms.\n");
            break;
        }

        // Choose a random available room
        int destinationRoom = rand() % availableRooms;

        // Visit the chosen room
        room1->visited = 1;
        printf("You have traveled to %s.\n", room2->name);
    }

    return 0;
}