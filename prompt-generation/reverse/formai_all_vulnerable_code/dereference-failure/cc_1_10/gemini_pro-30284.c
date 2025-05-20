//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char* name;
	int health;
	int attack;
	int defense;
} Creature;

void createCreature(Creature* creature, char* name, int health, int attack, int defense) {
	creature->name = malloc(strlen(name) + 1);
	strcpy(creature->name, name);
	creature->health = health;
	creature->attack = attack;
	creature->defense = defense;
}

void destroyCreature(Creature* creature) {
	free(creature->name);
	free(creature);
}

void printCreature(Creature* creature) {
	printf("Name: %s\n", creature->name);
	printf("Health: %d\n", creature->health);
	printf("Attack: %d\n", creature->attack);
	printf("Defense: %d\n", creature->defense);
}

int main() {
	// Create the player character
	Creature* player = malloc(sizeof(Creature));
	createCreature(player, "Player", 100, 10, 5);

	// Create the enemy
	Creature* enemy = malloc(sizeof(Creature));
	createCreature(enemy, "Enemy", 100, 10, 5);

	// Battle loop
	while(player->health > 0 && enemy->health > 0) {
		// Player's turn
		int choice;
		printf("1. Attack\n2. Defend\n");
		scanf("%d", &choice);

		if(choice == 1) {
			// Player attacks
			int damage = player->attack - enemy->defense;
			if(damage < 0) {
				damage = 0;
			}
			enemy->health -= damage;
			printf("You deal %d damage to the enemy.\n", damage);
		} else if(choice == 2) {
			// Player defends
			player->defense += 2;
			printf("You gain 2 defense.\n");
		} else {
			printf("Invalid choice.\n");
		}

		// Enemy's turn
		int enemyChoice = rand() % 2 + 1;

		if(enemyChoice == 1) {
			// Enemy attacks
			int damage = enemy->attack - player->defense;
			if(damage < 0) {
				damage = 0;
			}
			player->health -= damage;
			printf("The enemy deals %d damage to you.\n", damage);
		} else if(enemyChoice == 2) {
			// Enemy defends
			enemy->defense += 2;
			printf("The enemy gains 2 defense.\n");
		}
	}

	// Check who won
	if(player->health <= 0) {
		printf("You lose!\n");
	} else {
		printf("You win!\n");
	}

	// Destroy the creatures
	destroyCreature(player);
	destroyCreature(enemy);

	return 0;
}