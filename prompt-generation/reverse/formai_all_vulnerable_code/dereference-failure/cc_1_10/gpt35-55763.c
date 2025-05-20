//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_DESCRIPTION_LENGTH 1024
#define MAX_ITEMS 5
#define MAX_ITEM_NAME_LENGTH 50

struct Item {
    char name[MAX_ITEM_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int is_picked_up;
};

struct Room {
    char name[MAX_ITEM_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int visited;
    int is_exit;
    struct Item items[MAX_ITEMS];
    int num_items;
    struct Room* exits[4];
};

// Function prototypes
struct Room* create_room(char*, char*, int);
void connect_rooms(struct Room*, struct Room*, char);
void print_room_description(struct Room*);
void print_item_description(struct Item*);
void print_inventory(struct Item*, int);
void pick_up_item(struct Room*, struct Item*, int*);
void drop_item(struct Room*, struct Item*, int*);
int is_game_over(struct Room*);
void play_game(struct Room*);

int main() {
    srand(time(NULL));

    // Create rooms
    struct Room* hall = create_room("Great Hall", "You are in a spooky great hall with a large chandelier and a long dining table.", 0);
    struct Room* library = create_room("Library", "The library is dark and dusty, with many shelves of books.", 0);
    struct Room* kitchen = create_room("Kitchen", "The kitchen is abandoned and it looks like no one has cooked in years.", 0);
    struct Room* bedroom = create_room("Bedroom", "The bedroom is filled with old furniture and cobwebs hang from the ceiling.", 0);
    struct Room* bathroom = create_room("Bathroom", "The bathroom is creepy and there is a bath with a shower in the corner.", 0);
    struct Room* secret_room = create_room("Secret Room", "You have stumbled upon a secret room! It is damp and moldy with a single candle on a table.", 0);
    struct Room* backyard = create_room("Backyard", "The backyard is gloomy with an overgrown garden and a rusty swing.", 0);
    struct Room* garage = create_room("Garage", "The garage is filled with cobwebs and old tools.", 0);
    struct Room* attic = create_room("Attic", "The attic is pitch black and you can barely see a thing. You feel something breathing down your neck and you quickly exit the room.", 0);
    struct Room* exit = create_room("Exit", "You have found the exit and escaped from the haunted house. Congrats!", 1);

    // Connect rooms
    connect_rooms(hall, library, 's');
    connect_rooms(hall, kitchen, 'w');
    connect_rooms(hall, bedroom, 'n');
    connect_rooms(hall, bathroom, 'e');
    connect_rooms(hall, secret_room, 'u');
    connect_rooms(secret_room, garage, 'd');
    connect_rooms(backyard, exit, 'n');
    connect_rooms(kitchen, backyard, 'n');
    connect_rooms(bedroom, attic, 'u');
    connect_rooms(attic, exit, 'd');

    // Add items to rooms
    struct Item book = {"Book", "A dusty old book that looks like it has been untouched for many years.", 0};
    struct Item key = {"Key", "A rusty old key that could be used to open something.", 0};
    hall->items[0] = book;
    hall->items[1] = key;
    hall->num_items = 2;

    // Begin game
    play_game(hall);

    return 0;
}

/**
 * Create a new room with a given name and description
 */
struct Room* create_room(char* name, char* description, int is_exit) {
    struct Room* room = malloc(sizeof(struct Room));
    strcpy(room->name, name);
    strcpy(room->description, description);
    room->visited = 0;
    room->is_exit = is_exit;
    room->num_items = 0;
    return room;
}

/**
 * Connect two rooms together in a given direction
 */
void connect_rooms(struct Room* room1, struct Room* room2, char direction) {
    switch(toupper(direction)) {
        case 'N':
            room1->exits[0] = room2;
            room2->exits[2] = room1;
            break;
        case 'S':
            room1->exits[2] = room2;
            room2->exits[0] = room1;
            break;
        case 'E':
            room1->exits[1] = room2;
            room2->exits[3] = room1;
            break;
        case 'W':
            room1->exits[3] = room2;
            room2->exits[1] = room1;
            break;
        case 'U':
            room1->exits[4] = room2;
            room2->exits[5] = room1;
            break;
        case 'D':
            room1->exits[5] = room2;
            room2->exits[4] = room1;
            break;
        default:
            printf("Invalid direction %c\n", direction);
            break;
    }
}

/**
 * Print the description of a given room, including its name, description, and items
 */
void print_room_description(struct Room* room) {
    printf("You are in the %s.\n%s\n", room->name, room->description);
    if(room->num_items == 0) {
        printf("There are no items in this room.\n");
    } else {
        printf("There are %d items in this room:\n", room->num_items);
        for(int i = 0; i < room->num_items; i++) {
            printf("    %d. %s\n", i+1, room->items[i].name);
        }
    }
}

/**
 * Print the description of a given item, including its name and description
 */
void print_item_description(struct Item* item) {
    printf("%s: %s\n", item->name, item->description);
}

/**
 * Print the inventory of the player, including all picked up items
 */
void print_inventory(struct Item* inventory, int num_items) {
    if(num_items == 0) {
        printf("You have no items in your inventory.\n");
    } else {
        printf("You have the following items in your inventory:\n");
        for(int i = 0; i < num_items; i++) {
            printf("    %d. %s\n", i+1, inventory[i].name);
        }
    }
}

/**
 * Allow the player to pick up an item from a room, if it exists
 * Update inventory array and number of items accordingly
 */
void pick_up_item(struct Room* room, struct Item* inventory, int* num_items) {
    int item_index;
    if(room->num_items == 0) {
        printf("There are no items in this room to pick up.\n");
        return;
    } else {
        printf("Which item would you like to pick up?\n");
        for(int i = 0; i < room->num_items; i++) {
            printf("    %d. %s\n", i+1, room->items[i].name);
        }
        scanf("%d", &item_index);
        item_index--;
        if(item_index < 0 || item_index >= room->num_items) {
            printf("Invalid input. Please try again.\n");
            return;
        } else {
            struct Item picked_up_item = room->items[item_index];
            if(picked_up_item.is_picked_up == 1) {
                printf("That item has already been picked up.\n");
                return;
            } else {
                inventory[*num_items] = picked_up_item;
                (*num_items)++;
                picked_up_item.is_picked_up = 1;
                printf("You have picked up the %s.\n", picked_up_item.name);
            }
        }
    }
}

/**
 * Allow the player to drop an item from their inventory into a room
 * Update inventory array and number of items accordingly
 */
void drop_item(struct Room* room, struct Item* inventory, int* num_items) {
    int item_index;
    if(*num_items == 0) {
        printf("You have no items in your inventory to drop.\n");
        return;
    } else {
        printf("Which item would you like to drop?\n");
        for(int i = 0; i < *num_items; i++) {
            printf("    %d. %s\n", i+1, inventory[i].name);
        }
        scanf("%d", &item_index);
        item_index--;
        if(item_index < 0 || item_index >= *num_items) {
            printf("Invalid input. Please try again.\n");
            return;
        } else {
            room->items[room->num_items] = inventory[item_index];
            room->num_items++;
            inventory[item_index].is_picked_up = 0;
            for(int i = item_index; i < *num_items-1; i++) {
                inventory[i] = inventory[i+1];
            }
            (*num_items)--;
            printf("You have dropped the %s.\n", room->items[room->num_items-1].name);
        }
    }
}

/**
 * Check if the game is over (player has escaped or died)
 */
int is_game_over(struct Room* current_room) {
    if(current_room->is_exit == 1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Play the game
 */
void play_game(struct Room* starting_room) {
    struct Room* current_room = starting_room;
    int inventory_size = 0;
    struct Item inventory[MAX_ITEMS];

    printf("Welcome to the Haunted House Simulator! Your goal is to escape from the house by finding and using the right items.\n");

    while(!is_game_over(current_room)) {
        print_room_description(current_room);
        if(current_room->visited == 0) {
            current_room->visited = 1;
            printf("This is your first time in this room.\n");
        }

        printf("What would you like to do?\n");
        printf("    1. Pick up an item\n");
        printf("    2. Drop an item\n");
        printf("    3. Check inventory\n");
        printf("    4. Move to another room\n");
        printf("Enter a number: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Pick up item
                pick_up_item(current_room, inventory, &inventory_size);
                break;
            case 2: // Drop item
                drop_item(current_room, inventory, &inventory_size);
                break;
            case 3: // Check inventory
                print_inventory(inventory, inventory_size);
                break;
            case 4: // Move to another room
                printf("Which direction would you like to go?\n");
                printf("    1. North\n");
                printf("    2. South\n");
                printf("    3. East\n");
                printf("    4. West\n");
                printf("    5. Up\n");
                printf("    6. Down\n");
                printf("Enter a number: ");
                int direction;
                scanf("%d", &direction);
                switch(direction) {
                    case 1: // North
                        if(current_room->exits[0] != NULL) {
                            current_room = current_room->exits[0];
                        } else {
                            printf("There is no exit in that direction.\n");
                        }
                        break;
                    case 2: // South
                        if(current_room->exits[2] != NULL) {
                            current_room = current_room->exits[2];
                        } else {
                            printf("There is no exit in that direction.\n");
                        }
                        break;
                    case 3: // East
                        if(current_room->exits[1] != NULL) {
                            current_room = current_room->exits[1];
                        } else {
                            printf("There is no exit in that direction.\n");
                        }
                        break;
                    case 4: // West
                        if(current_room->exits[3] != NULL) {
                            current_room = current_room->exits[3];
                        } else {
                            printf("There is no exit in that direction.\n");
                        }
                        break;
                    case 5: // Up
                        if(current_room->exits[4] != NULL) {
                            current_room = current_room->exits[4];
                        } else {
                            printf("There is no exit in that direction.\n");
                        }
                        break;
                    case 6: // Down
                        if(current_room->exits[5] != NULL) {
                            current_room = current_room->exits[5];
                        } else {
                            printf("There is no exit in that direction.\n");
                        }
                        break;
                    default:
                        printf("Invalid direction choice.\n");
                        break;
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    printf("%s", current_room->description);
}