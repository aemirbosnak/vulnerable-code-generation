//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct Room
{
    char name[20];
    struct Room* next;
} Room;

Room* createRoom(char* name)
{
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

void connectRooms(Room* room1, Room* room2)
{
    room1->next = room2;
}

void playGame()
{
    Room* currentRoom = createRoom("The Entrance");
    Room* otherRooms[MAX_ROOMS];

    for (int i = 0; i < MAX_ROOMS; i++)
    {
        otherRooms[i] = NULL;
    }

    connectRooms(currentRoom, otherRooms[0] = createRoom("The Living Room"));
    connectRooms(currentRoom, otherRooms[1] = createRoom("The Kitchen"));
    connectRooms(otherRooms[0], otherRooms[2] = createRoom("The Dining Room"));
    connectRooms(otherRooms[1], otherRooms[3] = createRoom("The Bedroom"));

    printf("You are in %s.\n", currentRoom->name);

    char command[20];
    scanf("%s", command);

    if (strcmp(command, "go") == 0)
    {
        char direction[20];
        scanf("%s", direction);

        if (direction == "north")
        {
            if (otherRooms[0] != NULL)
            {
                currentRoom = otherRooms[0];
                printf("You are now in %s.\n", currentRoom->name);
            }
            else
            {
                printf("There is no room to the north.\n");
            }
        }
        else if (direction == "south")
        {
            if (currentRoom->next != NULL)
            {
                currentRoom = currentRoom->next;
                printf("You are now in %s.\n", currentRoom->name);
            }
            else
            {
                printf("There is no room to the south.\n");
            }
        }
        else
        {
            printf("Invalid direction.\n");
        }
    }
    else
    {
        printf("Invalid command.\n");
    }
}

int main()
{
    playGame();

    return 0;
}