//GPT-4o-mini DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5
#define MAX_DESCRIPTION_LENGTH 256

typedef struct Item {
    char name[20];
} Item;

typedef struct Room {
    char name[20];
    char description[MAX_DESCRIPTION_LENGTH];
    Item items[MAX_ITEMS];
    int itemCount;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

Room *createRoom(const char *name, const char *description) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    strcpy(newRoom->description, description);
    newRoom->itemCount = 0;
    newRoom->north = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;
    newRoom->west = NULL;
    return newRoom;
}

void addItemToRoom(Room *room, const char *itemName) {
    if(room->itemCount < MAX_ITEMS) {
        strcpy(room->items[room->itemCount].name, itemName);
        room->itemCount++;
    }
}

void printRoomDetails(Room *room) {
    printf("\nRoom: %s\n", room->name);
    printf("Description: %s\n", room->description);
    printf("Items in this room:\n");
    for(int i = 0; i < room->itemCount; i++) {
        printf("- %s\n", room->items[i].name);
    }
}

void freeRooms(Room *room) {
    if(room) {
        freeRooms(room->north);
        freeRooms(room->south);
        freeRooms(room->east);
        freeRooms(room->west);
        free(room);
    }
}

void moveToRoom(Room **currentRoom, const char *direction) {
    if (strcmp(direction, "north") == 0 && (*currentRoom)->north != NULL) {
        *currentRoom = (*currentRoom)->north;
    } else if (strcmp(direction, "south") == 0 && (*currentRoom)->south != NULL) {
        *currentRoom = (*currentRoom)->south;
    } else if (strcmp(direction, "east") == 0 && (*currentRoom)->east != NULL) {
        *currentRoom = (*currentRoom)->east;
    } else if (strcmp(direction, "west") == 0 && (*currentRoom)->west != NULL) {
        *currentRoom = (*currentRoom)->west;
    } else {
        printf("You can't go that way.\n");
    }
}

int main() {
    // Create rooms
    Room *room1 = createRoom("Entrance", "You are at the entrance of a dark cave.");
    Room *room2 = createRoom("Hallway", "A long, dimly lit hallway.");
    Room *room3 = createRoom("Treasure Room", "You found a room full of treasure!");
    
    // Link rooms
    room1->east = room2;
    room2->west = room1;
    room2->north = room3;
    room3->south = room2;

    // Add items
    addItemToRoom(room1, "Lantern");
    addItemToRoom(room2, "Old Map");
    addItemToRoom(room3, "Gold Coins");

    // Game loop
    Room *currentRoom = room1;
    char command[50];
    printf("Welcome to the adventure game!\n");
    
    while (1) {
        printRoomDetails(currentRoom);
        
        printf("What would you like to do? (move [direction] / quit): ");
        fgets(command, sizeof(command), stdin);
        
        // Remove new line character from input
        command[strcspn(command, "\n")] = 0;
        
        if (strcmp(command, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else if (strncmp(command, "move", 4) == 0) {
            moveToRoom(&currentRoom, command + 5);
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    freeRooms(room1);
    return 0;
}