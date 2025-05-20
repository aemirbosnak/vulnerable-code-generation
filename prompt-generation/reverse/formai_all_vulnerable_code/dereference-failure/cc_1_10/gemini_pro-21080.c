//GEMINI-pro DATASET v1.0 Category: Educational ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's stats
struct Player {
    char name[20];
    int health;
    int attack;
    int defense;
};

// Define the enemy's stats
struct Enemy {
    char name[20];
    int health;
    int attack;
    int defense;
};

// Create a new player
struct Player *create_player() {
    struct Player *player = malloc(sizeof(struct Player));

    // Get the player's name
    printf("Enter your name: ");
    scanf("%s", player->name);

    // Set the player's stats
    player->health = 100;
    player->attack = 10;
    player->defense = 5;

    return player;
}

// Create a new enemy
struct Enemy *create_enemy() {
    struct Enemy *enemy = malloc(sizeof(struct Enemy));

    // Set the enemy's name
    strcpy(enemy->name, "goblin");

    // Set the enemy's stats
    enemy->health = 100;
    enemy->attack = 10;
    enemy->defense = 5;

    return enemy;
}

// Battle the player and the enemy
void battle(struct Player *player, struct Enemy *enemy) {
    while (player->health > 0 && enemy->health > 0) {
        // The player attacks the enemy
        int damage = player->attack - enemy->defense;
        if (damage < 0) {
            damage = 0;
        }
        enemy->health -= damage;

        // The enemy attacks the player
        damage = enemy->attack - player->defense;
        if (damage < 0) {
            damage = 0;
        }
        player->health -= damage;

        // Print the player's and enemy's health
        printf("Player health: %d\n", player->health);
        printf("Enemy health: %d\n", enemy->health);
    }

    // Check who won the battle
    if (player->health <= 0) {
        printf("You lose!\n");
    } else {
        printf("You win!\n");
    }
}

// Free the player and enemy memory
void free_player(struct Player *player) {
    free(player);
}

void free_enemy(struct Enemy *enemy) {
    free(enemy);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the player and enemy
    struct Player *player = create_player();
    struct Enemy *enemy = create_enemy();

    // Battle the player and the enemy
    battle(player, enemy);

    // Free the player and enemy memory
    free_player(player);
    free_enemy(enemy);

    return 0;
}