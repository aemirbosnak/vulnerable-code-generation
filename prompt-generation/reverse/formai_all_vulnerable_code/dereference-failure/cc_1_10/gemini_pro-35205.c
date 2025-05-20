//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define the player's stats
typedef struct {
    int health;
    int attack;
    int defense;
} Player;

// Define the game world
typedef struct {
    char *name;
    char *description;
    Player *player;
} World;

// Create a new player
Player *new_player() {
    Player *player = malloc(sizeof(Player));
    player->health = 100;
    player->attack = 10;
    player->defense = 10;
    return player;
}

// Create a new world
World *new_world() {
    World *world = malloc(sizeof(World));
    world->name = "The Forest";
    world->description = "A dark and mysterious forest, filled with all sorts of creatures.";
    world->player = new_player();
    return world;
}

// Print the game world
void print_world(World *world) {
    printf("%s\n", world->name);
    printf("%s\n", world->description);
    printf("Player:\n");
    printf("  Health: %d\n", world->player->health);
    printf("  Attack: %d\n", world->player->attack);
    printf("  Defense: %d\n", world->player->defense);
}

// Handle player input
void handle_input(World *world) {
    char input[256];
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "quit") == 0) {
        exit(0);
    } else if (strcmp(input, "look") == 0) {
        print_world(world);
    } else if (strcmp(input, "go north") == 0) {
        // TODO: Implement movement
    } else if (strcmp(input, "go south") == 0) {
        // TODO: Implement movement
    } else if (strcmp(input, "go east") == 0) {
        // TODO: Implement movement
    } else if (strcmp(input, "go west") == 0) {
        // TODO: Implement movement
    } else {
        printf("Invalid command.\n");
    }
}

// Main game loop
int main() {
    World *world = new_world();

    while (1) {
        print_world(world);
        handle_input(world);
    }

    return 0;
}