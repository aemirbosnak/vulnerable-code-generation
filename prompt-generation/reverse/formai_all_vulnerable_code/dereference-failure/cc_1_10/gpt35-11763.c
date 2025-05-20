//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ROOMS 20
#define MAX_ITEMS 20

// Room structure
typedef struct Room {
    char *name;
    char *description;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

// Item structure
typedef struct Item {
    char *name;
    char *description;
    Room *location;
} Item;

// Function prototypes
void initializeRooms();
void initializeItems();
void printLocation();
void listInventory();
void pickupItem(char *itemName);
void dropItem(char *itemName);
void go(char *direction);
void unlock(char *direction);
void help();
void quit();

// Global variables
Room *currentLocation;
Item *inventory[MAX_ITEMS];
int numItems = 0;
Room *rooms[MAX_ROOMS];
int numRooms = 0;
Item *items[MAX_ITEMS];
int numTotalItems = 0;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game
    initializeRooms();
    initializeItems();
    currentLocation = rooms[rand() % numRooms];

    // Welcome message
    printf("*** Welcome to the Text-Based Adventure Game! ***\n\n");
    printf("You find yourself in a %s.\n\n", currentLocation->name);

    // Game loop
    while (1) {
        // Print current location and prompt for input
        printLocation();
        printf("\nWhat would you like to do?\n> ");
        char input[100];
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Tokenize input
        const char delim[2] = " ";
        char *token = strtok(input, delim);

        // Process input
        if (token != NULL) {
            if (strcmp(token, "go") == 0) {
                // Move to another room
                token = strtok(NULL, delim);

                if (token != NULL) {
                    go(token);
                } else {
                    printf("Go where?\n");
                }
            } else if (strcmp(token, "pickup") == 0) {
                // Pick up an item
                token = strtok(NULL, delim);

                if (token != NULL) {
                    pickupItem(token);
                } else {
                    printf("Pick up what?\n");
                }
            } else if (strcmp(token, "drop") == 0) {
                // Drop an item
                token = strtok(NULL, delim);

                if (token != NULL) {
                    dropItem(token);
                } else {
                    printf("Drop what?\n");
                }
            } else if (strcmp(token, "unlock") == 0) {
                // Unlock a door
                token = strtok(NULL, delim);

                if (token != NULL) {
                    unlock(token);
                } else {
                    printf("Unlock what?\n");
                }
            } else if (strcmp(token, "inventory") == 0) {
                // List inventory
                listInventory();
            } else if (strcmp(token, "help") == 0) {
                // Display help message
                help();
            } else if (strcmp(token, "quit") == 0) {
                // Quit the game
                quit();
            } else {
                printf("I don't understand that.\n");
            }
        }
    }

    return 0;
}

void initializeRooms() {
    // Room 1
    Room *room1 = malloc(sizeof(Room));
    room1->name = "dank cellar";
    room1->description = "You are in a damp, musty cellar. You can see a dim light coming from the north.";
    room1->north = NULL;
    room1->south = NULL;
    room1->east = NULL;
    room1->west = NULL;
    rooms[numRooms++] = room1;

    // Room 2
    Room *room2 = malloc(sizeof(Room));
    room2->name = "spooky hallway";
    room2->description = "You are in a dark hallway. You can see doors to the north, south, and east. The west end of the hallway is blocked by rubble.";
    room2->north = NULL;
    room2->south = NULL;
    room2->east = NULL;
    room2->west = NULL;
    rooms[numRooms++] = room2;

    // Room 3
    Room *room3 = malloc(sizeof(Room));
    room3->name = "creaky attic";
    room3->description = "You are in a dusty attic. You can see a small window to the south.";
    room3->north = NULL;
    room3->south = NULL;
    room3->east = NULL;
    room3->west = NULL;
    rooms[numRooms++] = room3;

    // Connect rooms
    room1->north = room2;
    room2->south = room1;
    room2->north = room3;
    room3->south = room2;
}

void initializeItems() {
    // Item 1
    Item *item1 = malloc(sizeof(Item));
    item1->name = "key";
    item1->description = "A small key with a tag that reads 'front door'.";
    item1->location = rooms[rand() % numRooms];
    items[numTotalItems++] = item1;

    // Item 2
    Item *item2 = malloc(sizeof(Item));
    item2->name = "lantern";
    item2->description = "An old-fashioned lantern with a dim light. It seems to have some oil left in it.";
    item2->location = rooms[rand() % numRooms];
    items[numTotalItems++] = item2;

    // Item 3
    Item *item3 = malloc(sizeof(Item));
    item3->name = "crowbar";
    item3->description = "A heavy metal crowbar. It looks like it could be used to pry open doors or break things.";
    item3->location = rooms[rand() % numRooms];
    items[numTotalItems++] = item3;
}

void printLocation() {
    printf("\nYou are in a %s.\n", currentLocation->name);
    printf("%s\n", currentLocation->description);

    // List items in the room
    int numItemsInRoom = 0;

    for (int i = 0; i < numTotalItems; i++) {
        if (items[i]->location == currentLocation) {
            numItemsInRoom++;

            if (numItemsInRoom == 1) {
                printf("You see the following items:\n");
            }

            printf("- %s\n", items[i]->name);
        }
    }

    // List possible exits
    printf("\nPossible exits are:");

    if (currentLocation->north != NULL) {
        printf(" north");
    }

    if (currentLocation->south != NULL) {
        printf(" south");
    }

    if (currentLocation->east != NULL) {
        printf(" east");
    }

    if (currentLocation->west != NULL) {
        printf(" west");
    }

    printf("\n");
}

void listInventory() {
    if (numItems == 0) {
        printf("You don't have any items.\n");
    } else {
        printf("You are carrying the following items:\n");

        for (int i = 0; i < numItems; i++) {
            printf("- %s\n", inventory[i]->name);
        }
    }
}

void pickupItem(char *itemName) {
    // Find item in current location
    Item *item = NULL;
    int itemIndex = -1;

    for (int i = 0; i < numTotalItems; i++) {
        if (items[i]->location == currentLocation && strcmp(itemName, items[i]->name) == 0) {
            item = items[i];
            itemIndex = i;
            break;
        }
    }

    // Pick up item
    if (item == NULL) {
        printf("I don't see a %s here.\n", itemName);
    } else {
        if (numItems == MAX_ITEMS) {
            printf("Your inventory is full.\n");
        } else {
            items[itemIndex]->location = NULL;
            inventory[numItems++] = item;
            printf("You picked up the %s.\n", itemName);
        }
    }
}

void dropItem(char *itemName) {
    // Find item in inventory
    Item *item = NULL;
    int itemIndex = -1;

    for (int i = 0; i < numItems; i++) {
        if (strcmp(itemName, inventory[i]->name) == 0) {
            item = inventory[i];
            itemIndex = i;
            break;
        }
    }

    // Drop item
    if (item == NULL) {
        printf("You don't have a %s.\n", itemName);
    } else {
        item->location = currentLocation;
        inventory[itemIndex] = inventory[numItems - 1];
        inventory[numItems - 1] = NULL;
        numItems--;
        printf("You dropped the %s.\n", itemName);
    }
}

void go(char *direction) {
    // Move to another location
    Room *newLocation = NULL;

    if (strcmp(direction, "north") == 0 && currentLocation->north != NULL) {
        newLocation = currentLocation->north;
    } else if (strcmp(direction, "south") == 0 && currentLocation->south != NULL) {
        newLocation = currentLocation->south;
    } else if (strcmp(direction, "east") == 0 && currentLocation->east != NULL) {
        newLocation = currentLocation->east;
    } else if (strcmp(direction, "west") == 0 && currentLocation->west != NULL) {
        newLocation = currentLocation->west;
    } else {
        printf("You can't go that way.\n");
        return;
    }

    currentLocation = newLocation;
    printf("You move to the %s.\n", direction);

    // Check if there are any items in the new location
    for (int i = 0; i < numTotalItems; i++) {
        if (items[i]->location == currentLocation) {
            printf("You see a %s.\n", items[i]->name);
        }
    }
}

void unlock(char *direction) {
    // Check if player has the key
    int hasKey = 0;

    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i]->name, "key") == 0) {
            hasKey = 1;
            break;
        }
    }

    if (!hasKey) {
        printf("You don't have a key.\n");
        return;
    }

    // Unlock the door
    if (strcmp(direction, "north") == 0 && currentLocation->north != NULL) {
        currentLocation->north->south = currentLocation;
        printf("You unlocked the door to the north.\n");
    } else if (strcmp(direction, "south") == 0 && currentLocation->south != NULL) {
        currentLocation->south->north = currentLocation;
        printf("You unlocked the door to the south.\n");
    } else if (strcmp(direction, "east") == 0 && currentLocation->east != NULL) {
        currentLocation->east->west = currentLocation;
        printf("You unlocked the door to the east.\n");
    } else if (strcmp(direction, "west") == 0 && currentLocation->west != NULL) {
        currentLocation->west->east = currentLocation;
        printf("You unlocked the door to the west.\n");
    } else {
        printf("There is no door to unlock in that direction.\n");
    }
}

void help() {
    printf("Available commands:\n");
    printf("- go [ north | south | east | west ]\n");
    printf("- pickup [ item ]\n");
    printf("- drop [ item ]\n");
    printf("- unlock [ north | south | east | west ]\n");
    printf("- inventory\n");
    printf("- help\n");
    printf("- quit\n");
}

void quit() {
    printf("Goodbye!\n");
    exit(0);
}