//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char *name;
    char *description;
    int num_exits;
    int exits[4]; // N, E, S, W
    int num_items;
    int items[MAX_ITEMS];
} Room;

typedef struct {
    char *name;
    char *description;
} Item;

Room rooms[MAX_ROOMS];
Item items[MAX_ITEMS];
int num_rooms = 0;
int num_items = 0;

void create_room(char *name, char *description) {
    rooms[num_rooms].name = malloc(strlen(name) + 1);
    strcpy(rooms[num_rooms].name, name);

    rooms[num_rooms].description = malloc(strlen(description) + 1);
    strcpy(rooms[num_rooms].description, description);

    rooms[num_rooms].num_exits = 0;
    memset(rooms[num_rooms].exits, -1, sizeof(rooms[num_rooms].exits));

    rooms[num_rooms].num_items = 0;
    memset(rooms[num_rooms].items, -1, sizeof(rooms[num_rooms].items));

    num_rooms++;
}

void create_item(char *name, char *description) {
    items[num_items].name = malloc(strlen(name) + 1);
    strcpy(items[num_items].name, name);

    items[num_items].description = malloc(strlen(description) + 1);
    strcpy(items[num_items].description, description);

    num_items++;
}

void link_rooms(int room1, int room2, int direction) {
    rooms[room1].exits[direction] = room2;
    rooms[room2].exits[direction ^ 2] = room1;
}

void place_item(int room, int item) {
    rooms[room].items[rooms[room].num_items++] = item;
}

void print_room(int room) {
    printf("%s\n", rooms[room].name);
    printf("%s\n", rooms[room].description);

    if (rooms[room].num_exits > 0) {
        printf("Exits:\n");
        for (int i = 0; i < 4; i++) {
            if (rooms[room].exits[i] != -1) {
                printf("  %s\n", rooms[rooms[room].exits[i]].name);
            }
        }
    }

    if (rooms[room].num_items > 0) {
        printf("Items:\n");
        for (int i = 0; i < rooms[room].num_items; i++) {
            printf("  %s\n", items[rooms[room].items[i]].name);
        }
    }
}

int get_room_index(char *name) {
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

int get_item_index(char *name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    // Create rooms
    create_room("Entrance", "You are standing in a large, open room. The walls are made of rough-hewn stone, and the floor is covered in dirt.");
    create_room("North Room", "You are in a small, square room. The walls are covered in tapestries, and the floor is carpeted.");
    create_room("East Room", "You are in a long, narrow room. The walls are lined with shelves, and the floor is covered in books.");
    create_room("South Room", "You are in a large, open room. The walls are made of white marble, and the floor is covered in a mosaic tile.");
    create_room("West Room", "You are in a small, dark room. The walls are covered in soot, and the floor is covered in ashes.");

    // Link rooms
    link_rooms(0, 1, 0);
    link_rooms(0, 2, 1);
    link_rooms(0, 3, 2);
    link_rooms(0, 4, 3);

    // Place items
    create_item("Sword", "A sharp, metal sword.");
    place_item(1, 0);

    create_item("Key", "A small, golden key.");
    place_item(2, 1);

    create_item("Book", "A large, leather-bound book.");
    place_item(3, 2);

    // Main game loop
    int current_room = 0;
    char input[MAX_NAME_LENGTH];

    while (true) {
        print_room(current_room);

        printf("> ");
        fgets(input, MAX_NAME_LENGTH, stdin);
        input[strlen(input) - 1] = '\0'; // Remove newline

        if (strcmp(input, "north") == 0) {
            if (rooms[current_room].exits[0] != -1) {
                current_room = rooms[current_room].exits[0];
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(input, "east") == 0) {
            if (rooms[current_room].exits[1] != -1) {
                current_room = rooms[current_room].exits[1];
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (rooms[current_room].exits[2] != -1) {
                current_room = rooms[current_room].exits[2];
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(input, "west") == 0) {
            if (rooms[current_room].exits[3] != -1) {
                current_room = rooms[current_room].exits[3];
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(input, "examine") == 0) {
            printf("What do you want to examine?\n");
            fgets(input, MAX_NAME_LENGTH, stdin);
            input[strlen(input) - 1] = '\0'; // Remove newline

            int item_index = get_item_index(input);
            if (item_index != -1) {
                printf("%s\n", items[item_index].description);
            } else {
                printf("You cannot examine that.\n");
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("I don't understand that command.\n");
        }
    }

    return 0;
}