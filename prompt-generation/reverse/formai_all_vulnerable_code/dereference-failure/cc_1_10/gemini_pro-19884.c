//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10

struct Room {
    char* name;
    char* description;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
    struct Item* items;
};

struct Item {
    char* name;
    char* description;
};

struct Player {
    struct Room* current_room;
    struct Item* inventory[MAX_ITEMS];
};

struct Game {
    struct Room* rooms[MAX_ROOMS];
    struct Item* items[MAX_ITEMS];
};

struct Game* create_game() {
    struct Game* game = malloc(sizeof(struct Game));
    return game;
}

void destroy_game(struct Game* game) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (game->rooms[i] != NULL) {
            free(game->rooms[i]);
        }
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (game->items[i] != NULL) {
            free(game->items[i]);
        }
    }
    free(game);
}

struct Room* create_room(char* name, char* description) {
    struct Room* room = malloc(sizeof(struct Room));
    room->name = strdup(name);
    room->description = strdup(description);
    return room;
}

void destroy_room(struct Room* room) {
    free(room->name);
    free(room->description);
    free(room);
}

struct Item* create_item(char* name, char* description) {
    struct Item* item = malloc(sizeof(struct Item));
    item->name = strdup(name);
    item->description = strdup(description);
    return item;
}

void destroy_item(struct Item* item) {
    free(item->name);
    free(item->description);
    free(item);
}

struct Player* create_player(struct Room* starting_room) {
    struct Player* player = malloc(sizeof(struct Player));
    player->current_room = starting_room;
    return player;
}

void destroy_player(struct Player* player) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (player->inventory[i] != NULL) {
            destroy_item(player->inventory[i]);
        }
    }
    free(player);
}

void print_room_description(struct Room* room) {
    printf("%s\n", room->description);
}

void print_room_exits(struct Room* room) {
    if (room->north != NULL) {
        printf("North: %s\n", room->north->name);
    }
    if (room->south != NULL) {
        printf("South: %s\n", room->south->name);
    }
    if (room->east != NULL) {
        printf("East: %s\n", room->east->name);
    }
    if (room->west != NULL) {
        printf("West: %s\n", room->west->name);
    }
}

void print_player_inventory(struct Player* player) {
    printf("Inventory:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (player->inventory[i] != NULL) {
            printf("%s\n", player->inventory[i]->name);
        }
    }
}

void process_command(struct Player* player, char* command) {
    if (strcmp(command, "north") == 0) {
        if (player->current_room->north != NULL) {
            player->current_room = player->current_room->north;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(command, "south") == 0) {
        if (player->current_room->south != NULL) {
            player->current_room = player->current_room->south;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(command, "east") == 0) {
        if (player->current_room->east != NULL) {
            player->current_room = player->current_room->east;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(command, "west") == 0) {
        if (player->current_room->west != NULL) {
            player->current_room = player->current_room->west;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(command, "look") == 0) {
        print_room_description(player->current_room);
        print_room_exits(player->current_room);
    } else if (strcmp(command, "inventory") == 0) {
        print_player_inventory(player);
    } else {
        printf("I do not understand that command.\n");
    }
}

int main() {
    struct Game* game = create_game();

    struct Room* room1 = create_room("Room 1", "This is the first room.");
    struct Room* room2 = create_room("Room 2", "This is the second room.");
    struct Room* room3 = create_room("Room 3", "This is the third room.");
    struct Room* room4 = create_room("Room 4", "This is the fourth room.");

    game->rooms[0] = room1;
    game->rooms[1] = room2;
    game->rooms[2] = room3;
    game->rooms[3] = room4;

    room1->north = room2;
    room2->south = room1;
    room2->east = room3;
    room3->west = room2;
    room3->east = room4;
    room4->west = room3;

    struct Item* item1 = create_item("Item 1", "This is the first item.");
    struct Item* item2 = create_item("Item 2", "This is the second item.");
    struct Item* item3 = create_item("Item 3", "This is the third item.");

    game->items[0] = item1;
    game->items[1] = item2;
    game->items[2] = item3;

    room1->items = item1;
    room2->items = item2;
    room3->items = item3;

    struct Player* player = create_player(room1);

    char command[80];

    while (1) {
        print_room_description(player->current_room);
        print_room_exits(player->current_room);
        printf("> ");
        scanf("%s", command);
        process_command(player, command);
    }

    destroy_player(player);
    destroy_game(game);

    return 0;
}