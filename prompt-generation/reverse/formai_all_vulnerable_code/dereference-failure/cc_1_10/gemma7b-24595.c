//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Item* items;
} Room;

typedef struct Item {
    char name[20];
    struct Item* next;
} Item;

Room* CreateRoom(char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->items = NULL;
    return newRoom;
}

Item* CreateItem(char* name) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->next = NULL;
    return newItem;
}

void AddItemToRoom(Room* room, Item* item) {
    room->items = CreateItem(item->name);
}

void TravelToRoom(Room* currentRoom, Room* nextRoom) {
    currentRoom = nextRoom;
}

int main() {
    Room* rooms = CreateRoom("The Main Hall");
    rooms = CreateRoom("The Kitchen");
    rooms = CreateRoom("The Bedroom");

    Item* items = CreateItem("A Sword");
    items = CreateItem("A Potion");
    items = CreateItem("A Treasure Map");

    AddItemToRoom(rooms->next, items->next);
    AddItemToRoom(rooms, items);

    TravelToRoom(rooms, rooms->next);

    printf("You are in %s. You have %s.", rooms->next->name, rooms->next->items->name);

    return 0;
}