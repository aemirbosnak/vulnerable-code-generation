//GEMINI-pro DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Define the player's stats
typedef struct {
    int health;
    int attack;
    int defense;
} player_stats;

// Define the monster's stats
typedef struct {
    int health;
    int attack;
    int defense;
    char *name;
} monster_stats;

// Create a new player
player_stats *create_player(int health, int attack, int defense) {
    player_stats *player = malloc(sizeof(player_stats));
    player->health = health;
    player->attack = attack;
    player->defense = defense;
    return player;
}

// Create a new monster
monster_stats *create_monster(int health, int attack, int defense, char *name) {
    monster_stats *monster = malloc(sizeof(monster_stats));
    monster->health = health;
    monster->attack = attack;
    monster->defense = defense;
    monster->name = name;
    return monster;
}

// Battle the player and the monster
void battle(player_stats *player, monster_stats *monster) {
    while (player->health > 0 && monster->health > 0) {
        // Calculate the player's damage
        int player_damage = player->attack - monster->defense;
        if (player_damage < 0) {
            player_damage = 0;
        }

        // Calculate the monster's damage
        int monster_damage = monster->attack - player->defense;
        if (monster_damage < 0) {
            monster_damage = 0;
        }

        // Deal damage to the player and the monster
        player->health -= monster_damage;
        monster->health -= player_damage;

        // Print the battle status
        printf("Player health: %d\n", player->health);
        printf("Monster health: %d\n", monster->health);
    }

    // Check if the player won or lost
    if (player->health <= 0) {
        printf("You lose!\n");
    } else {
        printf("You win!\n");
    }
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the player and the monster
    player_stats *player = create_player(100, 10, 5);
    monster_stats *monster = create_monster(100, 10, 5, "Goblin");

    // Battle the player and the monster
    battle(player, monster);

    // Free the player and the monster
    free(player);
    free(monster);

    return 0;
}