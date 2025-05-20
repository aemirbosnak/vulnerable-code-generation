//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Game states
enum GameState {
    START,
    PLAYING,
    END
};

// Player data
struct Player {
    char *name;
    int health;
    int energy;
    int inventory[10];
};

// Room data
struct Room {
    char *name;
    char *description;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
    int locked;
};

// Item data
struct Item {
    char *name;
    char *description;
    int useCount;
};

// Game data
struct Game {
    enum GameState state;
    struct Player player;
    struct Room *currentRoom;
    struct Item *items[10];
};

// Function prototypes
struct Game *initGame();
void playGame(struct Game *game);
void cleanupGame(struct Game *game);

// Main game loop
int main() {
    // Initialize the game
    struct Game *game = initGame();

    // Play the game
    playGame(game);

    // Cleanup the game
    cleanupGame(game);

    return 0;
}

// Initialize the game
struct Game *initGame() {
    // Allocate memory for the game
    struct Game *game = malloc(sizeof(struct Game));

    // Set the game state to START
    game->state = START;

    // Create the player
    game->player.name = "Player";
    game->player.health = 100;
    game->player.energy = 100;
    for (int i = 0; i < 10; i++) {
        game->player.inventory[i] = -1;
    }

    // Create the rooms
    struct Room *room1 = malloc(sizeof(struct Room));
    room1->name = "Room 1";
    room1->description = "This is the first room.";
    room1->north = NULL;
    room1->south = NULL;
    room1->east = NULL;
    room1->west = NULL;
    room1->locked = 0;

    struct Room *room2 = malloc(sizeof(struct Room));
    room2->name = "Room 2";
    room2->description = "This is the second room.";
    room2->north = NULL;
    room2->south = NULL;
    room2->east = NULL;
    room2->west = NULL;
    room2->locked = 0;

    struct Room *room3 = malloc(sizeof(struct Room));
    room3->name = "Room 3";
    room3->description = "This is the third room.";
    room3->north = NULL;
    room3->south = NULL;
    room3->east = NULL;
    room3->west = NULL;
    room3->locked = 0;

    // Set the current room
    game->currentRoom = room1;

    // Create the items
    struct Item *item1 = malloc(sizeof(struct Item));
    item1->name = "Item 1";
    item1->description = "This is the first item.";
    item1->useCount = 0;

    struct Item *item2 = malloc(sizeof(struct Item));
    item2->name = "Item 2";
    item2->description = "This is the second item.";
    item2->useCount = 0;

    struct Item *item3 = malloc(sizeof(struct Item));
    item3->name = "Item 3";
    item3->description = "This is the third item.";
    item3->useCount = 0;

    // Add the items to the game
    game->items[0] = item1;
    game->items[1] = item2;
    game->items[2] = item3;

    // Return the game
    return game;
}

// Play the game
void playGame(struct Game *game) {
    // While the game is in the PLAYING state
    while (game->state == PLAYING) {
        // Print the current room description
        printf("%s\n", game->currentRoom->description);

        // Print the available exits
        if (game->currentRoom->north != NULL) {
            printf("North: %s\n", game->currentRoom->north->name);
        }
        if (game->currentRoom->south != NULL) {
            printf("South: %s\n", game->currentRoom->south->name);
        }
        if (game->currentRoom->east != NULL) {
            printf("East: %s\n", game->currentRoom->east->name);
        }
        if (game->currentRoom->west != NULL) {
            printf("West: %s\n", game->currentRoom->west->name);
        }

        // Get the player's input
        char input[100];
        scanf("%s", input);

        // Parse the player's input
        if (strcmp(input, "north") == 0) {
            if (game->currentRoom->north != NULL) {
                game->currentRoom = game->currentRoom->north;
            }
        } else if (strcmp(input, "south") == 0) {
            if (game->currentRoom->south != NULL) {
                game->currentRoom = game->currentRoom->south;
            }
        } else if (strcmp(input, "east") == 0) {
            if (game->currentRoom->east != NULL) {
                game->currentRoom = game->currentRoom->east;
            }
        } else if (strcmp(input, "west") == 0) {
            if (game->currentRoom->west != NULL) {
                game->currentRoom = game->currentRoom->west;
            }
        } else if (strcmp(input, "quit") == 0) {
            game->state = END;
        }
    }
}

// Cleanup the game
void cleanupGame(struct Game *game) {
    // Free the player
    free(game->player.name);

    // Free the rooms
    free(game->currentRoom);

    // Free the items
    for (int i = 0; i < 10; i++) {
        free(game->items[i]);
    }

    // Free the game
    free(game);
}