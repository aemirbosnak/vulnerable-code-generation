//GEMINI-pro DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PARANOID_LEVEL 10

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Character;

Character *create_character(char *name, int health, int attack, int defense) {
    Character *character = malloc(sizeof(Character));

    character->name = strdup(name);
    character->health = health;
    character->attack = attack;
    character->defense = defense;

    return character;
}

void free_character(Character *character) {
    free(character->name);
    free(character);
}

int main(void) {
    // Initialize the random number generator.
    srand(time(NULL));

    // Create the player character.
    Character *player = create_character("Player", 100, 10, 10);

    // Create the enemy character.
    Character *enemy = create_character("Enemy", 100, 10, 10);

    // Battle loop.
    while (player->health > 0 && enemy->health > 0) {
        // Player's turn.
        int damage = player->attack - enemy->defense;
        if (damage < 0) {
            damage = 0;
        }

        enemy->health -= damage;

        // Check if the enemy is dead.
        if (enemy->health <= 0) {
            break;
        }

        // Enemy's turn.
        damage = enemy->attack - player->defense;
        if (damage < 0) {
            damage = 0;
        }

        player->health -= damage;

        // Check if the player is dead.
        if (player->health <= 0) {
            break;
        }
    }

    // Print the results of the battle.
    if (player->health > 0) {
        printf("Player wins!\n");
    } else {
        printf("Enemy wins!\n");
    }

    // Free the memory allocated for the characters.
    free_character(player);
    free_character(enemy);

    return 0;
}