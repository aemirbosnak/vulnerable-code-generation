//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NUM 10
#define MAX_ITEM_NUM 5

typedef struct Room {
    char name[20];
    struct Room *next;
    struct Item *items;
} Room;

typedef struct Item {
    char name[20];
    int quantity;
    struct Item *next;
} Item;

Room *createRoom(char *name)
{
    Room *newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->items = NULL;
    return newRoom;
}

Item *createItem(char *name, int quantity)
{
    Item *newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = NULL;
    return newItem;
}

void playGame()
{
    Room *currentRoom = createRoom("The Hall");
    currentRoom->items = createItem("Sword", 1);

    Room *nextRoom = createRoom("The Kitchen");
    currentRoom->next = nextRoom;

    nextRoom = createRoom("The Bedroom");
    nextRoom->items = createItem("Gold Coin", 5);

    Room *finalRoom = createRoom("The Treasure Room");
    nextRoom->next = finalRoom;

    finalRoom->items = createItem("The Amulet", 1);

    char command[20];
    int roomNum = 0;

    printf("Welcome to the mysterious mansion!\n");
    printf("Please enter a command: ");

    scanf("%s", command);

    // Check if the command is valid
    if (strcmp(command, "go") == 0)
    {
        // Get the room number
        scanf("%d", &roomNum);

        // Move to the next room
        if (roomNum > 0 && roomNum <= MAX_ROOM_NUM)
        {
            currentRoom = currentRoom->next;
        }
    }

    // Check if the command is to pick up an item
    else if (strcmp(command, "pick") == 0)
    {
        // Get the item name
        char itemName[20];
        scanf("%s", itemName);

        // Pick up the item
        Item *item = currentRoom->items;
        while (item)
        {
            if (strcmp(item->name, itemName) == 0)
            {
                item->quantity++;
                printf("You picked up the %s.\n", item->name);
                break;
            }
            item = item->next;
        }
    }

    // Check if the command is to use an item
    else if (strcmp(command, "use") == 0)
    {
        // Get the item name
        char itemName[20];
        scanf("%s", itemName);

        // Use the item
        Item *item = currentRoom->items;
        while (item)
        {
            if (strcmp(item->name, itemName) == 0)
            {
                printf("You used the %s.\n", item->name);
                item->quantity--;
                if (item->quantity == 0)
                {
                    free(item);
                }
                break;
            }
            item = item->next;
        }
    }

    // Check if the command is to quit
    else if (strcmp(command, "quit") == 0)
    {
        printf("Thank you for playing!\n");
        exit(0);
    }

    // Invalid command
    else
    {
        printf("Invalid command.\n");
    }

    playGame();
}

int main()
{
    playGame();

    return 0;
}