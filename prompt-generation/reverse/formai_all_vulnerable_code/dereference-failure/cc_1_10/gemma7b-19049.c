//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROOM_NUM 10
#define MAX_ITEM_NUM 20

typedef struct Room
{
    char name[20];
    struct Room* nextRoom;
    struct Item* items;
} Room;

typedef struct Item
{
    char name[20];
    int quantity;
    struct Item* nextItem;
} Item;

Room* createRoom(char* name)
{
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->nextRoom = NULL;
    newRoom->items = NULL;
    return newRoom;
}

Item* createItem(char* name, int quantity)
{
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->nextItem = NULL;
    return newItem;
}

void exploreRoom(Room* currentRoom)
{
    printf("You are in the %s.\n", currentRoom->name);
    printf("Items in the room:");
    for (Item* item = currentRoom->items; item; item = item->nextItem)
    {
        printf(" - %s (%d)\n", item->name, item->quantity);
    }
    printf("What do you want to do? (e.g. go north, take item)\n");
    char command[20];
    scanf("%s", command);

    // Implement commands here
}

int main()
{
    Room* startRoom = createRoom("The Starting Room");
    Room* endRoom = createRoom("The Final Room");

    // Connect rooms
    startRoom->nextRoom = endRoom;

    // Create items
    Item* healthPotion = createItem("Health Potion", 5);
    Item* weapon = createItem("Sword", 1);

    // Add items to rooms
    startRoom->items = healthPotion;
    endRoom->items = weapon;

    exploreRoom(startRoom);

    return 0;
}