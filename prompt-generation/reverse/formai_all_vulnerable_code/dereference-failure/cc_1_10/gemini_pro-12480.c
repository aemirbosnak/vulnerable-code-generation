//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player struct
typedef struct player {
    char *name;
    int health;
    int attack;
    int defense;
} player_t;

// Define the room struct
typedef struct room {
    char *name;
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room_t;

// Define the item struct
typedef struct item {
    char *name;
    char *description;
    int value;
} item_t;

// Define the game struct
typedef struct game {
    player_t *player;
    room_t *current_room;
    item_t *inventory[10];
    int inventory_size;
} game_t;

// Create a new player
player_t *create_player(char *name, int health, int attack, int defense) {
    player_t *player = malloc(sizeof(player_t));
    player->name = strdup(name);
    player->health = health;
    player->attack = attack;
    player->defense = defense;
    return player;
}

// Create a new room
room_t *create_room(char *name, char *description) {
    room_t *room = malloc(sizeof(room_t));
    room->name = strdup(name);
    room->description = strdup(description);
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// Create a new item
item_t *create_item(char *name, char *description, int value) {
    item_t *item = malloc(sizeof(item_t));
    item->name = strdup(name);
    item->description = strdup(description);
    item->value = value;
    return item;
}

// Initialize the game
game_t *init_game() {
    game_t *game = malloc(sizeof(game_t));

    // Create the player
    game->player = create_player("Player", 100, 10, 10);

    // Create the rooms
    room_t *room1 = create_room("Room 1", "This is the first room.");
    room_t *room2 = create_room("Room 2", "This is the second room.");
    room_t *room3 = create_room("Room 3", "This is the third room.");
    room_t *room4 = create_room("Room 4", "This is the fourth room.");

    // Connect the rooms
    room1->north = room2;
    room1->east = room3;
    room1->south = room4;
    room2->north = room1;
    room2->south = room3;
    room3->west = room1;
    room3->east = room4;
    room4->north = room1;
    room4->west = room3;

    // Create the items
    item_t *item1 = create_item("Sword", "A sharp sword.", 100);
    item_t *item2 = create_item("Shield", "A sturdy shield.", 50);
    item_t *item3 = create_item("Potion", "A healing potion.", 20);

    // Add the items to the game
    game->inventory[0] = item1;
    game->inventory[1] = item2;
    game->inventory[2] = item3;
    game->inventory_size = 3;

    // Set the current room
    game->current_room = room1;

    return game;
}

// Play the game
void play_game(game_t *game) {
    while (1) {
        // Print the current room
        printf("%s\n", game->current_room->description);

        // Get the player's input
        char input[100];
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Parse the input
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, " ");

        // Execute the command
        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "north") == 0) {
            if (game->current_room->north != NULL) {
                game->current_room = game->current_room->north;
            } else {
                printf("There is no door to the north.\n");
            }
        } else if (strcmp(command, "east") == 0) {
            if (game->current_room->east != NULL) {
                game->current_room = game->current_room->east;
            } else {
                printf("There is no door to the east.\n");
            }
        } else if (strcmp(command, "south") == 0) {
            if (game->current_room->south != NULL) {
                game->current_room = game->current_room->south;
            } else {
                printf("There is no door to the south.\n");
            }
        } else if (strcmp(command, "west") == 0) {
            if (game->current_room->west != NULL) {
                game->current_room = game->current_room->west;
            } else {
                printf("There is no door to the west.\n");
            }
        } else if (strcmp(command, "look") == 0) {
            printf("%s\n", game->current_room->description);
        } else if (strcmp(command, "inventory") == 0) {
            for (int i = 0; i < game->inventory_size; i++) {
                printf("%s\n", game->inventory[i]->name);
            }
        } else {
            printf("I don't understand that command.\n");
        }
    }
}

// Free the game
void free_game(game_t *game) {
    // Free the player
    free(game->player->name);
    free(game->player);

    // Free the rooms
    free(game->current_room->name);
    free(game->current_room->description);
    free(game->current_room);

    // Free the items
    for (int i = 0; i < game->inventory_size; i++) {
        free(game->inventory[i]->name);
        free(game->inventory[i]->description);
        free(game->inventory[i]);
    }

    // Free the game
    free(game);
}

int main() {
    // Initialize the game
    game_t *game = init_game();

    // Play the game
    play_game(game);

    // Free the game
    free_game(game);

    return 0;
}