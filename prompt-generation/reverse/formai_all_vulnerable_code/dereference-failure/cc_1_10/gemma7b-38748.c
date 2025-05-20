//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOM_NUMBER 10

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

void addRoom(Room* currentRoom, char* name)
{
    Room* newRoom = createRoom(name);
    if (currentRoom->next == NULL)
    {
        currentRoom->next = newRoom;
    }
    else
    {
        currentRoom->next->next = newRoom;
    }
}

int main()
{
    srand(time(NULL));

    // Create a list of rooms
    Room* head = createRoom("The Sprawl");
    addRoom(head, "The Crumbling Tower");
    addRoom(head, "The Acid Bath");
    addRoom(head, "The Twisted Tower");
    addRoom(head, "The Bloodstained Bridge");

    // Get the player's starting room
    Room* currentRoom = head;
    char* currentRoomName = currentRoom->name;

    // Start the adventure
    printf("You are in %s.\n", currentRoomName);

    // Generate a list of possible actions
    char* actions[] = {"Explore", "Search", "Talk to NPC", "Attack"};

    // Get the player's choice
    int choice = rand() % 4;

    // Perform the chosen action
    switch (choice)
    {
        case 0:
            printf("You explored the room and found a secret passage.\n");
            currentRoom = currentRoom->next;
            currentRoomName = currentRoom->name;
            break;
        case 1:
            printf("You searched the room and found a hidden item.\n");
            break;
        case 2:
            printf("You talked to the NPC and learned a secret.\n");
            break;
        case 3:
            printf("You attacked the NPC and killed them.\n");
            break;
    }

    // Print the player's new location
    printf("You are now in %s.\n", currentRoomName);

    return 0;
}