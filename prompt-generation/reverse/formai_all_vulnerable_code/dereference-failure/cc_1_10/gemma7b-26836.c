//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 10
#define MAX_ITEM_NUM 5

typedef struct Room
{
    int x, y;
    char name[20];
    struct Room* north, *south, *east, *west;
    int items[MAX_ITEM_NUM];
} Room;

typedef struct Item
{
    char name[20];
    int quantity;
} Item;

Room** generateRooms(int numRooms)
{
    Room** rooms = malloc(numRooms * sizeof(Room*));
    for (int i = 0; i < numRooms; i++)
    {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->x = rand() % MAX_ROOM_NUM;
        rooms[i]->y = rand() % MAX_ROOM_NUM;
        rooms[i]->name[0] = 'A' + i;
        rooms[i]->north = NULL;
        rooms[i]->south = NULL;
        rooms[i]->east = NULL;
        rooms[i]->west = NULL;
        rooms[i]->items[0] = rand() % MAX_ITEM_NUM;
    }
    return rooms;
}

Item** generateItems(int numItems)
{
    Item** items = malloc(numItems * sizeof(Item*));
    for (int i = 0; i < numItems; i++)
    {
        items[i] = malloc(sizeof(Item));
        items[i]->name[0] = 'a' + i;
        items[i]->quantity = rand() % 10 + 1;
    }
    return items;
}

int main()
{
    int numRooms = 5;
    int numItems = 3;

    Room** rooms = generateRooms(numRooms);
    Item** items = generateItems(numItems);

    // Use rooms and items for game logic

    free(rooms);
    free(items);

    return 0;
}