//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player's stats
typedef struct {
    char* name;
    int health;
    int attack;
    int defense;
} Player;

// Define the game world
typedef struct {
    char* name;
    char* description;
    Player* player;
} World;

// Create a new player
Player* create_player(char* name, int health, int attack, int defense) {
    Player* player = malloc(sizeof(Player));
    player->name = malloc(strlen(name) + 1);
    strcpy(player->name, name);
    player->health = health;
    player->attack = attack;
    player->defense = defense;
    return player;
}

// Create a new world
World* create_world(char* name, char* description, Player* player) {
    World* world = malloc(sizeof(World));
    world->name = malloc(strlen(name) + 1);
    strcpy(world->name, name);
    world->description = malloc(strlen(description) + 1);
    strcpy(world->description, description);
    world->player = player;
    return world;
}

// Print the player's stats
void print_player_stats(Player* player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Attack: %d\n", player->attack);
    printf("Defense: %d\n", player->defense);
}

// Print the world description
void print_world_description(World* world) {
    printf("%s\n", world->description);
}

// Handle the player's input
void handle_player_input(World* world) {
    char input[256];
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "quit") == 0) {
        printf("Goodbye!\n");
        exit(0);
    } else if (strcmp(input, "stats") == 0) {
        print_player_stats(world->player);
    } else if (strcmp(input, "look") == 0) {
        print_world_description(world);
    } else {
        printf("I don't understand that command.\n");
    }
}

// The main game loop
int main() {
    // Create the player
    Player* player = create_player("Player", 100, 10, 10);

    // Create the world
    World* world = create_world("World", "This is a world.", player);

    // Print the intro
    printf("Welcome to the game!\n");
    print_world_description(world);

    // Handle the player's input
    while (1) {
        handle_player_input(world);
    }

    return 0;
}