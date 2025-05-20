//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5

void intro();
void generateEnemyTypes(char enemyTypes[]);
int* generateEnemies(int numEnemies);
void printEnemies(int* enemyHealth, char enemyType[]);
void battle(int* enemyHealth, char enemyType[], int* playerHealth);
void gameOver();

int main() {
  srand(time(NULL));
  
  intro();
  
  char enemyTypes[MAX_ENEMIES];
  generateEnemyTypes(enemyTypes);
  
  int* enemyHealth = generateEnemies(MAX_ENEMIES);
  
  int playerHealth = 100;
  
  printEnemies(enemyHealth, enemyTypes);
  
  battle(enemyHealth, enemyTypes, &playerHealth);
  
  if (playerHealth <= 0) {
    gameOver();
  } else {
    printf("Congratulations! You have defeated all the enemies and won the game!\n");
  }
  
  return 0;
}

void intro() {
  printf("Welcome to the Space Adventure game!\n");
  printf("In this game, you will be facing a number of enemies that you must defeat in order to win.\n");
  printf("You will start out with 100 health points.\n");
  printf("Good luck!\n\n");
}

void generateEnemyTypes(char enemyTypes[]) {
  for (int i = 0; i < MAX_ENEMIES; i++) {
    int randNum = rand() % 3;
    if (randNum == 0) {
      enemyTypes[i] = 'A';
    } else if (randNum == 1) {
      enemyTypes[i] = 'B';
    } else {
      enemyTypes[i] = 'C';
    }
  }
}

int* generateEnemies(int numEnemies) {
  int* enemyHealth = malloc(sizeof(int) * numEnemies);
  for (int i = 0; i < numEnemies; i++) {
    enemyHealth[i] = rand() % 100 + 1;
  }
  return enemyHealth;
}

void printEnemies(int* enemyHealth, char enemyType[]) {
  printf("Here are the enemies you are facing:\n\n");
  for (int i = 0; i < MAX_ENEMIES; i++) {
    printf("Enemy %d: Type %c, health %d\n", i+1, enemyType[i], enemyHealth[i]);
  }
  printf("\n");
}

void battle(int* enemyHealth, char enemyType[], int* playerHealth) {
  int numEnemiesDefeated = 0;
  while (numEnemiesDefeated < MAX_ENEMIES && *playerHealth > 0) {
    printf("You are now facing enemy %d, a type %c.\n", numEnemiesDefeated+1, enemyType[numEnemiesDefeated]);
    printf("You have %d health points remaining.\n", *playerHealth);
    printf("The enemy has %d health points.\n\n", enemyHealth[numEnemiesDefeated]);
    
    // simulate battle
    while (*playerHealth > 0 && enemyHealth[numEnemiesDefeated] > 0) {
      int randNum = rand() % 2;
      if (randNum == 0) {
        printf("You attack the enemy and deal 10 damage!\n");
        enemyHealth[numEnemiesDefeated] -= 10;
      } else {
        printf("The enemy attacks you and deals 10 damage!\n");
        *playerHealth -= 10;
      }
      printf("You have %d health points remaining.\n", *playerHealth);
      printf("The enemy has %d health points.\n\n", enemyHealth[numEnemiesDefeated]);
    }
    
    if (enemyHealth[numEnemiesDefeated] <= 0) {
      numEnemiesDefeated++;
      printf("You have defeated the enemy!\n\n");
    }
  }
}

void gameOver() {
  printf("Game over! Better luck next time.\n");
}