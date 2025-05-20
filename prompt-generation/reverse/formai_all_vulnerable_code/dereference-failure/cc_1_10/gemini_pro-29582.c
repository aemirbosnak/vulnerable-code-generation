//GEMINI-pro DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_DESC_LEN 100

// Character types
typedef enum {
  WARRIOR,
  MAGE,
  ROGUE
} character_type;

// Character struct
typedef struct {
  char name[MAX_NAME_LEN + 1];
  char description[MAX_DESC_LEN + 1];
  character_type type;
  int health;
  int attack;
  int defense;
} character;

// Create a new character
character *create_character(char *name, char *description, character_type type, int health, int attack, int defense) {
  character *c = malloc(sizeof(character));
  strcpy(c->name, name);
  strcpy(c->description, description);
  c->type = type;
  c->health = health;
  c->attack = attack;
  c->defense = defense;
  return c;
}

// Print character information
void print_character(character *c) {
  printf("Name: %s\n", c->name);
  printf("Description: %s\n", c->description);
  printf("Type: ");
  switch (c->type) {
    case WARRIOR:
      printf("Warrior\n");
      break;
    case MAGE:
      printf("Mage\n");
      break;
    case ROGUE:
      printf("Rogue\n");
      break;
  }
  printf("Health: %d\n", c->health);
  printf("Attack: %d\n", c->attack);
  printf("Defense: %d\n", c->defense);
}

// Battle two characters
void battle(character *c1, character *c2) {
  // Loop until one character's health reaches 0
  while (c1->health > 0 && c2->health > 0) {
    // Calculate damage dealt
    int damage1 = c1->attack - c2->defense;
    int damage2 = c2->attack - c1->defense;
    
    // If damage is negative, set it to 0
    if (damage1 < 0) {
      damage1 = 0;
    }
    if (damage2 < 0) {
      damage2 = 0;
    }
    
    // Deal damage to characters
    c1->health -= damage2;
    c2->health -= damage1;
  }
  
  // Print battle results
  if (c1->health <= 0) {
    printf("%s has been defeated!\n", c1->name);
  } else {
    printf("%s has been defeated!\n", c2->name);
  }
}

// Main function
int main() {
  // Create two characters
  character *c1 = create_character("Hero", "A brave and noble warrior", WARRIOR, 100, 20, 10);
  character *c2 = create_character("Monster", "A fearsome and deadly creature", ROGUE, 100, 15, 15);
  
  // Print character information
  print_character(c1);
  printf("\n");
  print_character(c2);
  printf("\n");
  
  // Battle the characters
  battle(c1, c2);
  
  // Free memory allocated for characters
  free(c1);
  free(c2);
  
  return 0;
}