//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player's starting stats
#define MAX_HEALTH 100
#define MAX_ATTACK 10
#define MAX_DEFENSE 10

// Define the game's map
#define NUM_ROOMS 5
char *room_descriptions[NUM_ROOMS] = {
    "You are in a dark and musty room. The only light comes from a flickering candle on a nearby table.",
    "You are in a spacious chamber, adorned with tapestries and fine furniture. A large window overlooks a beautiful garden.",
    "You are in a narrow corridor, lined with torches that cast eerie shadows on the walls.",
    "You are in a small, windowless room. The air is thick with the smell of incense.",
    "You are in a large, open field. The sun is shining brightly overhead."
};

// Define the game's enemies
#define NUM_ENEMIES 3
char *enemy_names[NUM_ENEMIES] = {"Goblin", "Orc", "Dragon"};
int enemy_health[NUM_ENEMIES] = {10, 20, 50};
int enemy_attack[NUM_ENEMIES] = {5, 10, 20};
int enemy_defense[NUM_ENEMIES] = {2, 4, 8};

// Define the player's inventory
#define MAX_ITEMS 5
char *item_names[MAX_ITEMS] = {"Sword", "Shield", "Potion", "Key", "Gold"};

// Define the game's state
int player_health = MAX_HEALTH;
int player_attack = MAX_ATTACK;
int player_defense = MAX_DEFENSE;
int player_room = 0;
int player_inventory[MAX_ITEMS] = {0};

// Define the game's functions
void print_room_description();
void print_enemy_description();
void combat();
void loot_room();
void print_inventory();
void game_over();

int main() {
    // Print the welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to defeat the evil dragon.\n");
    printf("Along the way, you will encounter many challenges, but with courage and determination, you will succeed.\n");

    // Print the room description
    print_room_description();

    // Main game loop
    while (player_health > 0) {
        // Get the player's input
        char input[256];
        printf("> ");
        fgets(input, 256, stdin);

        // Parse the player's input
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, " ");

        // Execute the player's command
        if (strcmp(command, "go") == 0) {
            // Move to the specified room
            int room = atoi(argument);
            if (room >= 0 && room < NUM_ROOMS) {
                player_room = room;
                print_room_description();
            } else {
                printf("Invalid room number.\n");
            }
        } else if (strcmp(command, "attack") == 0) {
            // Attack the enemy
            combat();
        } else if (strcmp(command, "loot") == 0) {
            // Loot the room
            loot_room();
        } else if (strcmp(command, "inventory") == 0) {
            // Print the player's inventory
            print_inventory();
        } else if (strcmp(command, "quit") == 0) {
            // Quit the game
            break;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    // Game over
    game_over();

    return 0;
}

void print_room_description() {
    // Print the room description
    printf("%s\n", room_descriptions[player_room]);

    // Print the enemy description
    if (player_room != 4) {
        print_enemy_description();
    }
}

void print_enemy_description() {
    // Print the enemy description
    printf("You encounter a %s.\n", enemy_names[player_room]);
    printf("The %s has %d health, %d attack, and %d defense.\n", enemy_names[player_room], enemy_health[player_room], enemy_attack[player_room], enemy_defense[player_room]);
}

void combat() {
    // Calculate the player's damage
    int damage = player_attack - enemy_defense[player_room];
    if (damage < 0) {
        damage = 0;
    }

    // Calculate the enemy's damage
    damage = enemy_attack[player_room] - player_defense;
    if (damage < 0) {
        damage = 0;
    }

    // Apply the damage to the player and enemy
    player_health -= damage;
    enemy_health[player_room] -= damage;

    // Print the combat results
    printf("You attack the %s for %d damage.\n", enemy_names[player_room], damage);
    printf("The %s attacks you for %d damage.\n", enemy_names[player_room], damage);

    // Check if the player or enemy is dead
    if (player_health <= 0) {
        game_over();
    } else if (enemy_health[player_room] <= 0) {
        printf("You have defeated the %s!\n", enemy_names[player_room]);

        // Loot the room
        loot_room();

        // Move to the next room
        player_room++;
        print_room_description();
    }
}

void loot_room() {
    // Add a random item to the player's inventory
    int item = rand() % MAX_ITEMS;
    player_inventory[item]++;

    // Print the loot message
    printf("You have looted a %s.\n", item_names[item]);
}

void print_inventory() {
    // Print the player's inventory
    printf("Your inventory:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (player_inventory[i] > 0) {
            printf("%s: %d\n", item_names[i], player_inventory[i]);
        }
    }
}

void game_over() {
    // Print the game over message
    printf("Game over.\n");
    printf("You have died.\n");
}