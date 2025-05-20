//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room definitions
#define ROOM_START 1
#define ROOM_LIBRARY 2
#define ROOM_STUDY 3
#define ROOM_HALL 4
#define ROOM_KITCHEN 5
#define ROOM_DINING 6
#define ROOM_END 7

// Item definitions
#define ITEM_NOTE 1
#define ITEM_KEY 2
#define ITEM_PIPE 3

// State definitions
#define STATE_NORMAL 0
#define STATE_INVENTORY 1
#define STATE_EXAMINE 2

// Global variables
int current_room;
int inventory[10];
int state;
char input[100];

// Room data
struct room {
    int id;
    char *name;
    char *description;
    int north;
    int east;
    int south;
    int west;
    int items[10];
};

// Item data
struct item {
    int id;
    char *name;
    char *description;
};

// Room data
struct room rooms[] = {
    { ROOM_START, "Start", "You are standing in the entrance hall of a large Victorian house.", 0, ROOM_LIBRARY, 0, 0, {} },
    { ROOM_LIBRARY, "Library", "The library is a large and comfortable room, with bookshelves lining the walls.", ROOM_START, ROOM_STUDY, 0, 0, {} },
    { ROOM_STUDY, "Study", "The study is a small and tidy room, with a desk and chair in the center.", 0, 0, ROOM_LIBRARY, 0, {} },
    { ROOM_HALL, "Hall", "The hall is a long and narrow passageway, with doors leading to the other rooms.", ROOM_STUDY, ROOM_KITCHEN, 0, ROOM_DINING, {} },
    { ROOM_KITCHEN, "Kitchen", "The kitchen is a large and well-equipped room, with a stove, oven, and refrigerator.", 0, ROOM_DINING, 0, ROOM_HALL, {} },
    { ROOM_DINING, "Dining Room", "The dining room is a large and elegant room, with a long table and chairs.", ROOM_HALL, 0, 0, ROOM_KITCHEN, {} },
    { ROOM_END, "End", "You have reached the end of the game.", 0, 0, 0, 0, {} }
};

// Item data
struct item items[] = {
    { ITEM_NOTE, "Note", "A crumpled note that reads, 'Meet me in the study at midnight.'" },
    { ITEM_KEY, "Key", "A small brass key." },
    { ITEM_PIPE, "Pipe", "A long and curved smoking pipe." }
};

// Initialize game state
void init_game() {
    current_room = ROOM_START;
    inventory[0] = 0;
    state = STATE_NORMAL;
}

// Print the current room description
void print_room_description() {
    struct room *room = &rooms[current_room - 1];
    printf("%s\n", room->description);
}

// Print the list of available commands
void print_commands() {
    printf("Commands:\n");
    printf("  go <direction>\n");
    printf("  examine <object>\n");
    printf("  inventory\n");
    printf("  quit\n");
}

// Handle input
void handle_input() {
    // Get input from the user
    printf("> ");
    fgets(input, 100, stdin);

    // Parse the input
    char *command = strtok(input, " ");
    char *argument = strtok(NULL, " ");

    // Execute the command
    if (strcmp(command, "go") == 0) {
        if (strcmp(argument, "north") == 0) {
            current_room = rooms[current_room - 1].north;
            print_room_description();
        } else if (strcmp(argument, "east") == 0) {
            current_room = rooms[current_room - 1].east;
            print_room_description();
        } else if (strcmp(argument, "south") == 0) {
            current_room = rooms[current_room - 1].south;
            print_room_description();
        } else if (strcmp(argument, "west") == 0) {
            current_room = rooms[current_room - 1].west;
            print_room_description();
        } else {
            printf("Invalid direction.\n");
        }
    } else if (strcmp(command, "examine") == 0) {
        struct room *room = &rooms[current_room - 1];
        int i;

        for (i = 0; i < 10; i++) {
            if (room->items[i] != 0) {
                struct item *item = &items[room->items[i] - 1];
                printf("%s: %s\n", item->name, item->description);
            }
        }

        state = STATE_EXAMINE;
    } else if (strcmp(command, "inventory") == 0) {
        int i;

        for (i = 0; i < 10; i++) {
            if (inventory[i] != 0) {
                struct item *item = &items[inventory[i] - 1];
                printf("%s: %s\n", item->name, item->description);
            }
        }

        state = STATE_INVENTORY;
    } else if (strcmp(command, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid command.\n");
    }
}

// Main game loop
int main() {
    // Initialize the game
    init_game();

    // Print the welcome message
    printf("Welcome to Sherlock Holmes: The Case of the Missing Will.\n");
    printf("You are a world-renowned detective, and you have been called to investigate the disappearance of a wealthy man's will.\n");
    printf("You must search for clues and solve puzzles in order to find the will and bring the thief to justice.\n");

    // Print the room description
    print_room_description();

    // Print the list of commands
    print_commands();

    // Main game loop
    while (1) {
        // Handle input
        handle_input();
    }

    return 0;
}