//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10
#define MAX_ACTIONS 10

typedef struct {
    char *name;
    char *description;
    int n_exits;
    int exits[MAX_ACTIONS];
} room;

typedef struct {
    char *name;
    char *description;
} item;

typedef struct {
    char *name;
    void (*func)(void);
} action;

room rooms[MAX_ROOMS];
item items[MAX_ITEMS];
action actions[MAX_ACTIONS];

int current_room;
int inventory[MAX_ITEMS];

void print_room(void) {
    printf("%s\n", rooms[current_room].name);
    printf("%s\n", rooms[current_room].description);
}

void print_inventory(void) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i] > 0) {
            printf("%s\n", items[i].name);
        }
    }
}

void look_around(void) {
    print_room();
    print_inventory();
}

void go_north(void) {
    if (rooms[current_room].exits[0] != -1) {
        current_room = rooms[current_room].exits[0];
        print_room();
    } else {
        printf("There is no exit to the north.\n");
    }
}

void go_south(void) {
    if (rooms[current_room].exits[1] != -1) {
        current_room = rooms[current_room].exits[1];
        print_room();
    } else {
        printf("There is no exit to the south.\n");
    }
}

void go_east(void) {
    if (rooms[current_room].exits[2] != -1) {
        current_room = rooms[current_room].exits[2];
        print_room();
    } else {
        printf("There is no exit to the east.\n");
    }
}

void go_west(void) {
    if (rooms[current_room].exits[3] != -1) {
        current_room = rooms[current_room].exits[3];
        print_room();
    } else {
        printf("There is no exit to the west.\n");
    }
}

void take_item(void) {
    char item_name[MAX_ITEMS];

    printf("Which item do you want to take?\n");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            inventory[i]++;
            printf("You took the %s.\n", item_name);
            return;
        }
    }

    printf("There is no such item here.\n");
}

void drop_item(void) {
    char item_name[MAX_ITEMS];

    printf("Which item do you want to drop?\n");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            if (inventory[i] > 0) {
                inventory[i]--;
                printf("You dropped the %s.\n", item_name);
                return;
            } else {
                printf("You don't have the %s.\n", item_name);
                return;
            }
        }
    }

    printf("There is no such item in your inventory.\n");
}

void quit_game(void) {
    printf("Goodbye!\n");
    exit(0);
}

int main(void) {
    // Initialize the rooms
    strcpy(rooms[0].name, "The Foyer");
    strcpy(rooms[0].description, "You are standing in the foyer of a large house. There are doors to the north, east, and west.");
    rooms[0].n_exits = 3;
    rooms[0].exits[0] = 1;
    rooms[0].exits[1] = -1;
    rooms[0].exits[2] = 2;
    rooms[0].exits[3] = -1;

    strcpy(rooms[1].name, "The Living Room");
    strcpy(rooms[1].description, "You are standing in the living room. There is a door to the south.");
    rooms[1].n_exits = 1;
    rooms[1].exits[0] = -1;
    rooms[1].exits[1] = 0;
    rooms[1].exits[2] = -1;
    rooms[1].exits[3] = -1;

    strcpy(rooms[2].name, "The Dining Room");
    strcpy(rooms[2].description, "You are standing in the dining room. There is a door to the west.");
    rooms[2].n_exits = 1;
    rooms[2].exits[0] = -1;
    rooms[2].exits[1] = -1;
    rooms[2].exits[2] = 0;
    rooms[2].exits[3] = -1;

    // Initialize the items
    strcpy(items[0].name, "The Key");
    strcpy(items[0].description, "This is the key to the locked door.");

    strcpy(items[1].name, "The Sword");
    strcpy(items[1].description, "This is a sword that can be used to kill the dragon.");

    // Initialize the actions
    strcpy(actions[0].name, "Look around");
    actions[0].func = look_around;

    strcpy(actions[1].name, "Go north");
    actions[1].func = go_north;

    strcpy(actions[2].name, "Go south");
    actions[2].func = go_south;

    strcpy(actions[3].name, "Go east");
    actions[3].func = go_east;

    strcpy(actions[4].name, "Go west");
    actions[4].func = go_west;

    strcpy(actions[5].name, "Take item");
    actions[5].func = take_item;

    strcpy(actions[6].name, "Drop item");
    actions[6].func = drop_item;

    strcpy(actions[7].name, "Quit game");
    actions[7].func = quit_game;

    // Start the game
    current_room = 0;
    print_room();

    while (1) {
        char action_name[MAX_ACTIONS];

        printf("\nWhat do you want to do?\n");
        scanf("%s", action_name);

        for (int i = 0; i < MAX_ACTIONS; i++) {
            if (strcmp(action_name, actions[i].name) == 0) {
                actions[i].func();
                break;
            }
        }
    }

    return 0;
}