//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

typedef struct Room
{
    char name[20];
    struct Room *next;
} Room;

Room *createRoom(char *name)
{
    Room *newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

void connectRooms(Room *room1, Room *room2)
{
    room1->next = room2;
}

int main()
{
    Room *rooms = createRoom("The Entrance");
    connectRooms(rooms, createRoom("The Kitchen"));
    connectRooms(rooms, createRoom("The Living Room"));
    connectRooms(rooms, createRoom("The Bedroom"));
    connectRooms(rooms, createRoom("The Bathroom"));

    printf("You are in %s. What would you like to do?", rooms->name);

    char input[20];
    scanf("%s", input);

    // Check if the input matches a valid command
    if (strcmp(input, "go north") == 0)
    {
        // Go to the north room
        rooms = rooms->next;
        printf("You are now in %s.", rooms->name);
    }
    else if (strcmp(input, "go south") == 0)
    {
        // Go to the south room
        rooms = rooms->next->next;
        printf("You are now in %s.", rooms->name);
    }
    else if (strcmp(input, "go east") == 0)
    {
        // Go to the east room
        rooms = rooms->next->next->next;
        printf("You are now in %s.", rooms->name);
    }
    else if (strcmp(input, "go west") == 0)
    {
        // Go to the west room
        rooms = rooms->next->next->next->next;
        printf("You are now in %s.", rooms->name);
    }
    else
    {
        // Invalid command
        printf("Invalid command. Please try again.");
    }

    return 0;
}