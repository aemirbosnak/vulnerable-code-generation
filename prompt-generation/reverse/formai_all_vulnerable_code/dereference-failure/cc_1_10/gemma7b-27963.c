//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5
#define MAX_ITEM_NUM 10

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Item* items;
} Room;

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

void createRoom(Room** head, char* name) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->items = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

void createItem(Item** head, char* name, int quantity) {
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

int main() {
    Room* rooms = NULL;
    Item* items = NULL;

    createRoom(&rooms, "The Hall");
    createRoom(&rooms, "The Kitchen");
    createRoom(&rooms, "The Living Room");

    createItem(&items, "Sword", 5);
    createItem(&items, "Shield", 2);
    createItem(&items, "Potion", 3);

    printf("Welcome to the game!\n");
    printf("You are in %s.\n", rooms->name);

    // Game logic here
    // ...

    return 0;
}