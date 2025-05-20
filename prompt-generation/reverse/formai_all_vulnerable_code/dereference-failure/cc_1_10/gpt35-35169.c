//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>

// Define constants
#define maxSteps 50
#define maxInventory 5
#define maxRooms 10

// Define structures
typedef struct Item {
    char name[20];
    char description[100];
} Item;

typedef struct Room {
    char name[20];
    char description[100];
    Item items[maxInventory];
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

typedef struct Player {
    char name[20];
    Room* currentRoom;
    Item inventory[maxInventory];
} Player;

// Define global variables
Room* rooms[maxRooms];
Player player;

// Define functions
void initializeRooms();
void initializeItems();
void printCurrentRoom();
void printInventory();
void takeItem(char input[]);
void dropItem(char input[]);
void move(char input[]);

int main() {
    printf("Welcome to Adventure Game!\n\n");
    
    // Initialize rooms and items
    initializeRooms();
    initializeItems();
    
    // Initialize player
    strcpy(player.name, "Player");
    player.currentRoom = rooms[0];
    
    // Print starting room and inventory
    printCurrentRoom();
    printInventory();
    
    // Game loop
    char input[100];
    while(1) {
        printf("\nEnter a command: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0'; // Remove newline
        
        // Take or drop item
        if(strncmp(input, "take", 4) == 0) {
            takeItem(input);
        } else if(strncmp(input, "drop", 4) == 0) {
            dropItem(input);
        }
        // Move to new room
        else if(strncmp(input, "north", 5) == 0 || strncmp(input, "south", 5) == 0 ||
                strncmp(input, "east", 4) == 0 || strncmp(input, "west", 4) == 0) {
            move(input);
        }
        // Quit game
        else if(strncmp(input, "quit", 4) == 0) {
            printf("\nGoodbye!\n");
            break;
        }
        // Invalid command
        else {
            printf("\nInvalid command!\n");
        }
        
        // Check if player has won
        if(player.currentRoom == rooms[9] && player.inventory[0].name[0] != '\0') {
            printf("\nCongradulations, you have won!\n");
            break;
        }
    }
    
    return 0;
}

void initializeRooms() {
    // Initialize room 0
    rooms[0] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[0]->name, "Room 0");
    strcpy(rooms[0]->description, "You are in Room 0. There is a key on the ground.");
    rooms[0]->items[0].name[0] = '\0';
    rooms[0]->items[1].name[0] = '\0';
    rooms[0]->items[2].name[0] = '\0';
    rooms[0]->items[3].name[0] = '\0';
    rooms[0]->items[4].name[0] = '\0';
    strcpy(rooms[0]->items[0].name, "key");
    strcpy(rooms[0]->items[0].description, "A small, rusty key.");
    
    // Initialize room 1
    rooms[1] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[1]->name, "Room 1");
    strcpy(rooms[1]->description, "You are in Room 1. There is a door to the north and a door to the east.");
    rooms[1]->items[0].name[0] = '\0';
    rooms[1]->items[1].name[0] = '\0';
    rooms[1]->items[2].name[0] = '\0';
    rooms[1]->items[3].name[0] = '\0';
    rooms[1]->items[4].name[0] = '\0';
    rooms[1]->north = rooms[3];
    rooms[1]->east = rooms[2];
    
    // Initialize room 2
    rooms[2] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[2]->name, "Room 2");
    strcpy(rooms[2]->description, "You are in Room 2. There is a door to the west.");
    rooms[2]->items[0].name[0] = '\0';
    rooms[2]->items[1].name[0] = '\0';
    rooms[2]->items[2].name[0] = '\0';
    rooms[2]->items[3].name[0] = '\0';
    rooms[2]->items[4].name[0] = '\0';
    rooms[2]->west = rooms[1];
    
    // Initialize room 3
    rooms[3] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[3]->name, "Room 3");
    strcpy(rooms[3]->description, "You are in Room 3. There is a door to the north and a door to the east.");
    rooms[3]->items[0].name[0] = '\0';
    rooms[3]->items[1].name[0] = '\0';
    rooms[3]->items[2].name[0] = '\0';
    rooms[3]->items[3].name[0] = '\0';
    rooms[3]->items[4].name[0] = '\0';
    rooms[3]->north = rooms[6];
    rooms[3]->east = rooms[4];
    
    // Initialize room 4
    rooms[4] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[4]->name, "Room 4");
    strcpy(rooms[4]->description, "You are in Room 4. There is a door to the west and a door to the south.");
    rooms[4]->items[0].name[0] = '\0';
    rooms[4]->items[1].name[0] = '\0';
    rooms[4]->items[2].name[0] = '\0';
    rooms[4]->items[3].name[0] = '\0';
    rooms[4]->items[4].name[0] = '\0';
    rooms[4]->west = rooms[3];
    rooms[4]->south = rooms[5];
    
    // Initialize room 5
    rooms[5] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[5]->name, "Room 5");
    strcpy(rooms[5]->description, "You are in Room 5. There is a door to the north.");
    rooms[5]->items[0].name[0] = '\0';
    rooms[5]->items[1].name[0] = '\0';
    rooms[5]->items[2].name[0] = '\0';
    rooms[5]->items[3].name[0] = '\0';
    rooms[5]->items[4].name[0] = '\0';
    rooms[5]->north = rooms[4];
    
    // Initialize room 6
    rooms[6] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[6]->name, "Room 6");
    strcpy(rooms[6]->description, "You are in Room 6. There is a door to the south.");
    rooms[6]->items[0].name[0] = '\0';
    rooms[6]->items[1].name[0] = '\0';
    rooms[6]->items[2].name[0] = '\0';
    rooms[6]->items[3].name[0] = '\0';
    rooms[6]->items[4].name[0] = '\0';
    rooms[6]->south = rooms[3];
    
    // Initialize room 7
    rooms[7] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[7]->name, "Room 7");
    strcpy(rooms[7]->description, "You are in Room 7. There is a door to the east.");
    rooms[7]->items[0].name[0] = '\0';
    rooms[7]->items[1].name[0] = '\0';
    rooms[7]->items[2].name[0] = '\0';
    rooms[7]->items[3].name[0] = '\0';
    rooms[7]->items[4].name[0] = '\0';
    rooms[7]->east = rooms[8];
    
    // Initialize room 8
    rooms[8] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[8]->name, "Room 8");
    strcpy(rooms[8]->description, "You are in Room 8. There is a door to the west.");
    rooms[8]->items[0].name[0] = '\0';
    rooms[8]->items[1].name[0] = '\0';
    rooms[8]->items[2].name[0] = '\0';
    rooms[8]->items[3].name[0] = '\0';
    rooms[8]->items[4].name[0] = '\0';
    rooms[8]->west = rooms[7];
    
    // Initialize room 9
    rooms[9] = (Room*) malloc(sizeof(Room));
    strcpy(rooms[9]->name, "Room 9");
    strcpy(rooms[9]->description, "You are in Room 9. There is a locked door to the north.");
    rooms[9]->items[0].name[0] = '\0';
    rooms[9]->items[1].name[0] = '\0';
    rooms[9]->items[2].name[0] = '\0';
    rooms[9]->items[3].name[0] = '\0';
    rooms[9]->items[4].name[0] = '\0';
    rooms[9]->north = NULL;
}

void initializeItems() {
    for(int i = 0; i < maxInventory; i++) {
        player.inventory[i].name[0] = '\0';
        player.inventory[i].description[0] = '\0';
    }
}

void printCurrentRoom() {
    printf("\n%s\n", player.currentRoom->description);
    // Print room items
    printf("Items in room:");
    for(int i = 0; i < maxInventory; i++) {
        if(player.currentRoom->items[i].name[0] != '\0') {
            printf(" %s", player.currentRoom->items[i].name);
        }
    }
    printf("\n");
}

void printInventory() {
    printf("\nInventory:");
    for(int i = 0; i < maxInventory; i++) {
        if(player.inventory[i].name[0] != '\0') {
            printf(" %s", player.inventory[i].name);
        }
    }
    printf("\n");
}

void takeItem(char input[]) {
    // Find the item to take
    char item[20];
    sscanf(input, "%*s %s", item);
    int index = -1;
    for(int i = 0; i < maxInventory; i++) {
        if(player.currentRoom->items[i].name[0] != '\0' && strcmp(player.currentRoom->items[i].name, item) == 0) {
            index = i;
            break;
        }
    }
    // Item not found
    if(index == -1) {
        printf("\nItem not found!\n");
        return;
    }
    // Check if inventory is full
    int inventoryIndex = -1;
    for(int i = 0; i < maxInventory; i++) {
        if(player.inventory[i].name[0] == '\0') {
            inventoryIndex = i;
            break;
        }
    }
    if(inventoryIndex == -1) {
        printf("\nInventory is full!\n");
        return;
    }
    // Transfer item to player's inventory
    strcpy(player.inventory[inventoryIndex].name, player.currentRoom->items[index].name);
    strcpy(player.inventory[inventoryIndex].description, player.currentRoom->items[index].description);
    player.currentRoom->items[index].name[0] = '\0';
    player.currentRoom->items[index].description[0] = '\0';
    printf("\n%s taken!\n", item);
}

void dropItem(char input[]) {
    // Find the item to drop
    char item[20];
    sscanf(input, "%*s %s", item);
    int index = -1;
    for(int i = 0; i < maxInventory; i++) {
        if(player.inventory[i].name[0] != '\0' && strcmp(player.inventory[i].name, item) == 0) {
            index = i;
            break;
        }
    }
    // Item not found
    if(index == -1) {
        printf("\nItem not found!\n");
        return;
    }
    // Transfer item to current room
    strcpy(player.currentRoom->items[index].name, player.inventory[index].name);
    strcpy(player.currentRoom->items[index].description, player.inventory[index].description);
    player.inventory[index].name[0] = '\0';
    player.inventory[index].description[0] = '\0';
    printf("\n%s dropped!\n", item);
}

void move(char input[]) {
    // Check if door exists in that direction
    if((strncmp(input, "north", 5) == 0 && player.currentRoom->north == NULL) ||
       (strncmp(input, "south", 5) == 0 && player.currentRoom->south == NULL) ||
       (strncmp(input, "east", 4) == 0 && player.currentRoom->east == NULL) ||
       (strncmp(input, "west", 4) == 0 && player.currentRoom->west == NULL)) {
        printf("\nThere is no door in that direction!\n");
        return;
    }
    // Check if unlocked door in that direction
    if(strncmp(input, "north", 5) == 0 && player.currentRoom->north != NULL &&
       strcmp(player.currentRoom->north->name, "Room 9") == 0 && player.inventory[0].name[0] == '\0') {
        printf("\nThe door is locked!\n");
        return;
    }
    // Move to new room
    if(strncmp(input, "north", 5) == 0) player.currentRoom = player.currentRoom->north;
    else if(strncmp(input, "south", 5) == 0) player.currentRoom = player.currentRoom->south;
    else if(strncmp(input, "east", 4) == 0) player.currentRoom = player.currentRoom->east;
    else if(strncmp(input, "west", 4) == 0) player.currentRoom = player.currentRoom->west;
    printCurrentRoom();
}