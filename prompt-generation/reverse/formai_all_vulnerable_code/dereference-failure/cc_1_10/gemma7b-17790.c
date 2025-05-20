//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 5

typedef struct Room
{
    char name[20];
    struct Room* next;
    int enemies;
    int treasures;
} Room;

Room* CreateRoom(char* name, int enemies, int treasures)
{
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->enemies = enemies;
    newRoom->treasures = treasures;
    return newRoom;
}

void Traverse(Room* currentRoom)
{
    printf("\nYou are in: %s\n", currentRoom->name);

    if (currentRoom->enemies)
    {
        printf("There are %d enemies here.\n", currentRoom->enemies);
    }

    if (currentRoom->treasures)
    {
        printf("There are %d treasures here.\n", currentRoom->treasures);
    }

    printf("What do you want to do? (move, attack, search, quit)\n");
    char input[20];
    scanf("%s", input);

    // Implement game logic based on input
}

int main()
{
    // Create a list of rooms
    Room* roomList = CreateRoom("The Crumbling Tower", 3, 2);
    roomList = CreateRoom("The Twisted Forest", 1, 4);
    roomList = CreateRoom("The Bloodstained Hall", 2, 1);

    // Traverse the rooms
    Traverse(roomList);

    return 0;
}