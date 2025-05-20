//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 3
#define MAX_INPUT 50

typedef struct {
    char* name;
    char* description;
    int price;
} Item;

typedef struct {
    char* name;
    char* description;
    Item* items[MAX_ITEMS];
    int num_items;
} Room;

int play_game();
void print_menu(char* room_name);
void print_room(Room* room);
int update_inventory(Item* item);
void print_inventory();
int process_input(char* input, Room* current_room);
void do_help();
void do_look(Room* current_room);
void do_take(char* item_name, Room* current_room);
void do_drop(char* item_name, Room* current_room);
void do_exit();

Item* create_item(char* name, char* description, int price);
Room* create_room(char* name, char* description);
void add_item_to_room(Room* room, Item* item);

Item* inventory[MAX_ITEMS];
int num_items = 0;
Room* current_room;

int main() {
    return play_game();
}

int play_game() {
    Item* key = create_item("key", "A small key that looks like it might unlock a door", 5);
    Item* sword = create_item("sword", "A rusty sword that barely looks sharp enough to cut a tomato", 10);
    Item* apple = create_item("apple", "A juicy red apple that looks delicious", 2);
    
    Room* kitchen = create_room("Kitchen", "A dirty kitchen with pots and pans scattered everywhere.");
    add_item_to_room(kitchen, key);
    add_item_to_room(kitchen, apple);
    
    Room* bedroom = create_room("Bedroom", "A dark bedroom with a bed in the center.");
    add_item_to_room(bedroom, sword);
    
    Room* living_room = create_room("Living Room", "A cozy living room with a comfortable couch.");
    
    kitchen->items[1] = apple; // Fix bug from create_room
    
    kitchen->num_items = 2;
    bedroom->num_items = 1;
    
    kitchen->items[1] = apple; // Fix bug from create_room
    
    current_room = kitchen;
    
    printf("Welcome to Adventure Game!\n");
    do_help();
    
    while(1) {
        char input[MAX_INPUT];
        print_menu(current_room->name);
        printf("> ");
        fgets(input, MAX_INPUT, stdin);
        // Remove newline character from end of input
        input[strcspn(input, "\n")] = '\0';
        if(process_input(input, current_room) == 0) {
            break;
        }
    }
    
    printf("Thanks for playing Adventure Game!\n");
    
    return 0;
}

void print_menu(char* room_name) {
    printf("You are in the %s\n", room_name);
    printf("Commands: help, look, take <item>, drop <item>, inventory, exit\n");
}

void print_room(Room* room) {
    printf("%s\n", room->description);
    printf("Items:\n");
    for(int i = 0; i < room->num_items; i++) {
        printf("%d. %s (%d gold)\n", i + 1, room->items[i]->name, room->items[i]->price);
    }
}

int update_inventory(Item* item) {
    if(num_items >= MAX_ITEMS) {
        printf("Your inventory is full.\n");
        return 0;
    }
    inventory[num_items++] = item;
    printf("You take the %s.\n", item->name);
    return 1;
}

void print_inventory() {
    printf("Inventory:");
    if(num_items == 0) {
        printf(" your inventory is empty.\n");
        return;
    }
    printf("\n");
    for(int i = 0; i < num_items; i++) {
        printf("%d. %s (%d gold)\n", i + 1, inventory[i]->name, inventory[i]->price);
    }
}

int process_input(char* input, Room* current_room) {
    // Convert input to lowercase
    for(int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }
    
    if(strcmp(input, "help") == 0) {
        do_help();
    }
    else if(strcmp(input, "look") == 0) {
        do_look(current_room);
    }
    else if(strncmp(input, "take ", 5) == 0) {
        char item_name[MAX_INPUT];
        sscanf(input, "take %s", item_name);
        do_take(item_name, current_room);
    }
    else if(strncmp(input, "drop ", 5) == 0) {
        char item_name[MAX_INPUT];
        sscanf(input, "drop %s", item_name);
        do_drop(item_name, current_room);
    }
    else if(strcmp(input, "inventory") == 0) {
        print_inventory();
    }
    else if(strcmp(input, "exit") == 0) {
        do_exit();
        return 0;
    }
    else {
        printf("Invalid command. Type 'help' for a list of commands.\n");
    }
    return 1;
}

void do_help() {
    printf("Commands: help, look, take <item>, drop <item>, inventory, exit\n");
}

void do_look(Room* current_room) {
    print_room(current_room);
}

void do_take(char* item_name, Room* current_room) {
    for(int i = 0; i < current_room->num_items; i++) {
        if(strcmp(current_room->items[i]->name, item_name) == 0) {
            if(update_inventory(current_room->items[i])) {
                for(int j = i; j < current_room->num_items - 1; j++) {
                    current_room->items[j] = current_room->items[j + 1];
                }
                current_room->num_items--;
                return;
            }
        }
    }
    printf("There is no %s to take.\n", item_name);
}

void do_drop(char* item_name, Room* current_room) {
    for(int i = 0; i < num_items; i++) {
        if(strcmp(inventory[i]->name, item_name) == 0) {
            current_room->items[current_room->num_items++] = inventory[i];
            printf("You drop the %s.\n", item_name);
            for(int j = i; j < num_items - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_items--;
            return;
        }
    }
    printf("You don't have a %s in your inventory.\n", item_name);
}

void do_exit() {
    printf("Are you sure you want to quit? (y/n)\n");
    char input[MAX_INPUT];
    fgets(input, MAX_INPUT, stdin);
    if(tolower(input[0]) == 'y') {
        printf("Goodbye!\n");
        exit(0);
    }
}

Item* create_item(char* name, char* description, int price) {
    Item* item = malloc(sizeof(Item));
    item->name = name;
    item->description = description;
    item->price = price;
    return item;
}

Room* create_room(char* name, char* description) {
    Room* room = malloc(sizeof(Room));
    room->name = name;
    room->description = description;
    room->num_items = 0;
    return room;
}

void add_item_to_room(Room* room, Item* item) {
    room->items[room->num_items++] = item;
}