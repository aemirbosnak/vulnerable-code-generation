//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 50

// define a struct for items
struct Item {
    char *name;
    char *description;
    struct Item *next;
};

// define a struct for rooms
struct Room {
    char *name;
    char *description;
    int num_items;
    struct Item *items;
    struct Room *north;
    struct Room *east;
    struct Room *south;
    struct Room *west;
};

// function to create a new item
struct Item* new_item(char *name, char *description) {
    struct Item *item = malloc(sizeof(struct Item));
    item->name = strdup(name);
    item->description = strdup(description);
    item->next = NULL;
    return item;
}

// function to create a new room
struct Room* new_room(char *name, char *description) {
    struct Room *room = malloc(sizeof(struct Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->num_items = 0;
    room->items = NULL;
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// function to add an item to a room's list of items
void add_item_to_room(struct Room *room, struct Item *item) {
    item->next = room->items;
    room->items = item;
    room->num_items++;
}

// function to remove an item from a room's list of items
void remove_item_from_room(struct Room *room, struct Item *item) {
    struct Item *current = room->items;
    struct Item *prev = NULL;
    while(current != NULL) {
        if(current == item) {
            if(prev == NULL) {
                room->items = current->next;
            } else {
                prev->next = current->next;
            }
            room->num_items--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// function to get the name of an item in lowercase
char* get_item_name_lowercase(char *input) {
    char *name = strdup(input + 4);
    int len = strlen(name);
    for(int i=0; i<len; i++) {
        name[i] = tolower(name[i]);
    }
    return name;
}

int main() {
    // create the rooms
    struct Room *start_room = new_room("Start Room", "You are in a dimly lit room.");
    struct Room *north_room = new_room("North Room", "You are in a room with a door to the north.");
    struct Room *east_room = new_room("East Room", "You are in a room with a door to the east.");
    struct Room *south_room = new_room("South Room", "You are in a room with a door to the south.");
    struct Room *west_room = new_room("West Room", "You are in a room with a door to the west.");

    // connect the rooms
    start_room->north = north_room;
    start_room->east = east_room;
    start_room->south = south_room;
    start_room->west = west_room;
    north_room->south = start_room;
    east_room->west = start_room;
    south_room->north = start_room;
    west_room->east = start_room;

    // create the items
    struct Item *key = new_item("Key", "A small key.");
    struct Item *sword = new_item("Sword", "A rusty sword.");
    struct Item *gem = new_item("Gem", "A shining gem.");
    add_item_to_room(start_room, key);
    add_item_to_room(north_room, sword);
    add_item_to_room(west_room, gem);

    // set the current room
    struct Room *current_room = start_room;

    // game loop
    while(1) {
        // print the current room
        printf("%s\n%s\n", current_room->name, current_room->description);
        
        // print the room's items
        if(current_room->num_items > 0) {
            struct Item *item = current_room->items;
            printf("You see the following items:\n");
            while(item != NULL) {
                printf("- %s\n", item->name);
                item = item->next;
            }
        }
        
        // get user input
        char input[MAX_INPUT_SIZE];
        printf("\n> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        
        // remove the newline character from input
        int len = strlen(input);
        if(input[len-1] == '\n') {
            input[len-1] = '\0';
        }
        
        // process the input
        if(strcmp(input, "quit") == 0) {
            break;
        } else if(strcmp(input, "north") == 0) {
            if(current_room->north == NULL) {
                printf("You cannot go that way.\n");
            } else {
                current_room = current_room->north;
            }
        } else if(strcmp(input, "east") == 0) {
            if(current_room->east == NULL) {
                printf("You cannot go that way.\n");
            } else {
                current_room = current_room->east;
            }
        } else if(strcmp(input, "south") == 0) {
            if(current_room->south == NULL) {
                printf("You cannot go that way.\n");
            } else {
                current_room = current_room->south;
            }
        } else if(strcmp(input, "west") == 0) {
            if(current_room->west == NULL) {
                printf("You cannot go that way.\n");
            } else {
                current_room = current_room->west;
            }
        } else if(strncmp(input, "get ", 4) == 0) {
            char *item_name = get_item_name_lowercase(input);
            struct Item *item = current_room->items;
            while(item != NULL) {
                if(strcmp(item->name, item_name) == 0) {
                    printf("You pick up the %s.\n", item->name);
                    add_item_to_room(current_room, item);
                    remove_item_from_room(current_room, item);
                    free(item_name);
                    break;
                }
                item = item->next;
            }
            if(item == NULL) {
                printf("That item is not in this room.\n");
                free(item_name);
            }
        } else if(strncmp(input, "drop ", 5) == 0) {
            char *item_name = get_item_name_lowercase(input);
            struct Item *item = current_room->items;
            while(item != NULL) {
                if(strcmp(item->name, item_name) == 0) {
                    printf("You drop the %s.\n", item->name);
                    add_item_to_room(current_room, item);
                    remove_item_from_room(current_room, item);
                    free(item_name);
                    break;
                }
                item = item->next;
            }
            if(item == NULL) {
                printf("You do not have that item.\n");
                free(item_name);
            }
        } else {
            printf("I don't understand that command.\n");
        }
    }
    
    // free memory
    free(start_room->name);
    free(start_room->description);
    free(north_room->name);
    free(north_room->description);
    free(east_room->name);
    free(east_room->description);
    free(south_room->name);
    free(south_room->description);
    free(west_room->name);
    free(west_room->description);
    struct Item *item = start_room->items;
    while(item != NULL) {
        struct Item *next = item->next;
        free(item->name);
        free(item->description);
        free(item);
        item = next;
    }
    item = north_room->items;
    while(item != NULL) {
        struct Item *next = item->next;
        free(item->name);
        free(item->description);
        free(item);
        item = next;
    }
    item = east_room->items;
    while(item != NULL) {
        struct Item *next = item->next;
        free(item->name);
        free(item->description);
        free(item);
        item = next;
    }
    item = south_room->items;
    while(item != NULL) {
        struct Item *next = item->next;
        free(item->name);
        free(item->description);
        free(item);
        item = next;
    }
    item = west_room->items;
    while(item != NULL) {
        struct Item *next = item->next;
        free(item->name);
        free(item->description);
        free(item);
        item = next;
    }
    free(start_room);
    free(north_room);
    free(east_room);
    free(south_room);
    free(west_room);

    return 0;
}