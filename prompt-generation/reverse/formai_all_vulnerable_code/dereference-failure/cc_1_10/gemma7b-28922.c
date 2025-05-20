//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

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
    Room* otherRoom = createRoom("The Kitchen");
    connectRooms(currentRoom, otherRoom);

    printf("You are in %s. What do you want to do? (go, examine, interact): ", currentRoom->name);
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "go") == 0)
    {
        if (currentRoom->next)
        {
            currentRoom = currentRoom->next;
            printf("You are now in %s. What do you want to do? (go, examine, interact): ", currentRoom->name);
            scanf("%s", command);
        }
        else
        {
            printf("There is no path in that direction.\n");
        }
    }
    else if (strcmp(command, "examine") == 0)
    {
        printf("You examine your surroundings.\n");
    }
    else if (strcmp(command, "interact") == 0)
    {
        printf("You interact with the objects in the room.\n");
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