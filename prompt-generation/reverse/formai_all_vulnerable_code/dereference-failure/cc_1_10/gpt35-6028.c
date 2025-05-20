//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constants
#define MAX_ROOMS 5
#define MAX_ITEMS 5
#define MAX_COMMAND_LENGTH 20

// Structs
typedef struct Room Room;
typedef struct Item Item;
struct Room {
    char* name;
    char* description;
    Item* items[MAX_ITEMS];
    int num_items;
    Room* north;
    Room* south;
    Room* east;
    Room* west;
};
struct Item {
    char* name;
    char* description;
    bool taken;
};

// Function prototypes
void print_intro();
void print_help();
void print_room(Room* current_room);
Room* create_room(char* name, char* description);
Item* create_item(char* name, char* description);
void add_item(Room* room, Item* item);
Item* remove_item(Room* room, char* item_name);
void move(Room** current_room, char* direction);
bool take_item(Room* current_room, char* item_name);
bool drop_item(Room* current_room, char* item_name);
void print_inventory();

// Global variables
Room* rooms[MAX_ROOMS];
int num_rooms = 0;
Item* inventory[MAX_ITEMS];
int num_inventory = 0;

// Main function
int main() {
    // Create rooms and items
    rooms[0] = create_room("Bridge", "You are on the bridge of your spaceship.");
    rooms[1] = create_room("Cargo Bay", "You are in the cargo bay of your spaceship.");
    rooms[2] = create_room("Engine Room", "You are in the engine room of your spaceship.");
    rooms[3] = create_room("Med Bay", "You are in the med bay of your spaceship.");
    rooms[4] = create_room("Captain's Quarters", "You are in the captain's quarters of your spaceship.");
    add_item(rooms[0], create_item("Blaster", "A powerful weapon."));
    add_item(rooms[1], create_item("Alien Artifact", "A mysterious artifact."));
    add_item(rooms[2], create_item("Wrench", "A useful tool."));
    add_item(rooms[3], create_item("Med Kit", "A kit containing medical supplies."));
    add_item(rooms[4], create_item("Log Book", "Contains important information."));

    // Set room connections
    rooms[0]->north = rooms[1];
    rooms[1]->south = rooms[0];
    rooms[1]->north = rooms[2];
    rooms[1]->east = rooms[4];
    rooms[2]->south = rooms[1];
    rooms[2]->east = rooms[3];
    rooms[3]->west = rooms[2];
    rooms[4]->west = rooms[1];

    // Play game
    print_intro();
    Room* current_room = rooms[0];
    while (true) {
        print_room(current_room);
        printf("> ");
        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);
        if (strcmp(command, "help") == 0) {
            print_help();
        } else if (strcmp(command, "north") == 0) {
            move(&current_room, "north");
        } else if (strcmp(command, "south") == 0) {
            move(&current_room, "south");
        } else if (strcmp(command, "east") == 0) {
            move(&current_room, "east");
        } else if (strcmp(command, "west") == 0) {
            move(&current_room, "west");
        } else if (strcmp(command, "take") == 0) {
            char item_name[MAX_COMMAND_LENGTH];
            scanf("%s", item_name);
            if (!take_item(current_room, item_name)) {
                printf("There is no %s in this room.\n", item_name);
            }
        } else if (strcmp(command, "drop") == 0) {
            char item_name[MAX_COMMAND_LENGTH];
            scanf("%s", item_name);
            if (!drop_item(current_room, item_name)) {
                printf("You are not carrying a %s.\n", item_name);
            }
        } else if (strcmp(command, "inventory") == 0) {
            print_inventory();
        } else if (strcmp(command, "quit") == 0) {
            printf("Game over!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    // Free memory
    for (int i = 0; i < MAX_ROOMS; i++) {
        free(rooms[i]->name);
        free(rooms[i]->description);
        for (int j = 0; j < rooms[i]->num_items; j++) {
            free(rooms[i]->items[j]->name);
            free(rooms[i]->items[j]->description);
            free(rooms[i]->items[j]);
        }
        free(rooms[i]);
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
        free(inventory[i]->name);
        free(inventory[i]->description);
        free(inventory[i]);
    }
}

// Function definitions
void print_intro() {
    printf("Welcome to the Space Adventure game!\n");
    printf("You are the captain of a spaceship on a mission to explore the galaxy.\n");
    printf("You find yourself on the bridge of your spaceship.\n");
    printf("Type 'help' for a list of available commands.\n\n");
}

void print_help() {
    printf("Available commands:\n");
    printf("  help             - Print this help message\n");
    printf("  north/south/east/west - Move in a particular direction\n");
    printf("  take [item]      - Take an item from the room\n");
    printf("  drop [item]      - Drop an item from your inventory\n");
    printf("  inventory        - Print your inventory\n");
    printf("  quit             - Quit the game\n\n");
}

void print_room(Room* current_room) {
    printf("%s\n", current_room->name);
    printf("%s\n", current_room->description);
    printf("Items in the room:\n");
    for (int i = 0; i < current_room->num_items; i++) {
        printf("  %s\n", current_room->items[i]->name);
    }
    printf("\n");
}

Room* create_room(char* name, char* description) {
    Room* room = malloc(sizeof(Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->num_items = 0;
    return room;
}

Item* create_item(char* name, char* description) {
    Item* item = malloc(sizeof(Item));
    item->name = strdup(name);
    item->description = strdup(description);
    item->taken = false;
    return item;
}

void add_item(Room* room, Item* item) {
    if (room->num_items < MAX_ITEMS) {
        room->items[room->num_items] = item;
        room->num_items++;
    }
}

Item* remove_item(Room* room, char* item_name) {
    for (int i = 0; i < room->num_items; i++) {
        Item* item = room->items[i];
        if (strcmp(item->name, item_name) == 0) {
            for (int j = i; j < room->num_items - 1; j++) {
                room->items[j] = room->items[j+1];
            }
            room->num_items--;
            return item;
        }
    }
    return NULL;
}

void move(Room** current_room, char* direction) {
    if (strcmp(direction, "north") == 0) {
        if ((*current_room)->north != NULL) {
            *current_room = (*current_room)->north;
        } else {
            printf("There is no room to the north.\n");
        }
    } else if (strcmp(direction, "south") == 0) {
        if ((*current_room)->south != NULL) {
            *current_room = (*current_room)->south;
        } else {
            printf("There is no room to the south.\n");
        }
    } else if (strcmp(direction, "east") == 0) {
        if ((*current_room)->east != NULL) {
            *current_room = (*current_room)->east;
        } else {
            printf("There is no room to the east.\n");
        }
    } else if (strcmp(direction, "west") == 0) {
        if ((*current_room)->west != NULL) {
            *current_room = (*current_room)->west;
        } else {
            printf("There is no room to the west.\n");
        }
    }
}

bool take_item(Room* current_room, char* item_name) {
    Item* item = remove_item(current_room, item_name);
    if (item != NULL) {
        if (num_inventory < MAX_ITEMS) {
            inventory[num_inventory] = item;
            num_inventory++;
            printf("You take the %s.\n", item_name);
            return true;
        } else {
            printf("You cannot carry any more items.\n");
            add_item(current_room, item);
            return false;
        }
    } else {
        return false;
    }
}

bool drop_item(Room* current_room, char* item_name) {
    for (int i = 0; i < num_inventory; i++) {
        Item* item = inventory[i];
        if (strcmp(item->name, item_name) == 0) {
            for (int j = i; j < num_inventory - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            num_inventory--;
            add_item(current_room, item);
            printf("You drop the %s.\n", item_name);
            return true;
        }
    }
    return false;
}

void print_inventory() {
    printf("Your inventory:\n");
    if (num_inventory == 0) {
        printf("  (empty)\n");
    } else {
        for (int i = 0; i < num_inventory; i++) {
            printf("  %s\n", inventory[i]->name);
        }
    }
    printf("\n");
}