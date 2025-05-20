//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY 5
#define PLAYER_HEALTH 100

typedef struct Enemy {
  int health;
  int attack;
  char name[20];
} Enemy;

void initializeEnemies(Enemy **enemies);
void battle(Enemy *enemy, int playerHealth);

int main() {
  Enemy **enemies = NULL;
  int playerHealth = PLAYER_HEALTH;
  int enemyIndex = 0;

  initializeEnemies(&enemies);

  while (playerHealth > 0 && enemies[enemyIndex] != NULL) {
    battle(enemies[enemyIndex], playerHealth);
    enemyIndex++;
  }

  if (playerHealth <= 0) {
    printf("You have perished in the battle!\n");
  } else {
    printf("You have won the battle!\n");
  }

  return 0;
}

void initializeEnemies(Enemy **enemies) {
  *enemies = malloc(MAX_ENEMY * sizeof(Enemy));

  for (int i = 0; i < MAX_ENEMY; i++) {
    enemies[i] = malloc(sizeof(Enemy));
    enemies[i]->health = 50 + i * 20;
    enemies[i]->attack = 10 + i;
    strcpy(enemies[i]->name, "Goblin");
  }
}

void battle(Enemy *enemy, int playerHealth) {
  printf("You have encountered a %s.\n", enemy->name);

  while (enemy->health > 0 && playerHealth > 0) {
    int damage = rand() % enemy->attack;
    playerHealth -= damage;

    printf("%s has attacked you for %d damage.\n", enemy->name, damage);

    if (playerHealth <= 0) {
      printf("You have perished in the battle!\n");
      break;
    }

    damage = rand() % playerHealth;
    enemy->health -= damage;

    printf("You have attacked %s for %d damage.\n", enemy->name, damage);
  }

  if (enemy->health <= 0) {
    printf("You have slain the %s.\n", enemy->name);
  }
}