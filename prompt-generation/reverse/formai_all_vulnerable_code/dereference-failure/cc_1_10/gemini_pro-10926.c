//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int health;
  int attack;
  int defense;
} Character;

typedef struct {
  char *name;
  int value;
  Character *owner;
} Item;

typedef struct {
  Character *characters[4];
  Item *items[4];
  int num_characters;
  int num_items;
} Party;

Party party;

void init_party() {
  party.num_characters = 0;
  party.num_items = 0;

  Character *hero = malloc(sizeof(Character));
  hero->name = "Hero";
  hero->health = 100;
  hero->attack = 10;
  hero->defense = 10;
  party.characters[party.num_characters++] = hero;

  Character *mage = malloc(sizeof(Character));
  mage->name = "Mage";
  mage->health = 50;
  mage->attack = 15;
  mage->defense = 5;
  party.characters[party.num_characters++] = mage;

  Character *rogue = malloc(sizeof(Character));
  rogue->name = "Rogue";
  rogue->health = 75;
  rogue->attack = 12;
  rogue->defense = 10;
  party.characters[party.num_characters++] = rogue;
}

void print_party() {
  printf("Party:\n");
  for (int i = 0; i < party.num_characters; i++) {
    printf("  %s (health: %d, attack: %d, defense: %d)\n",
           party.characters[i]->name, party.characters[i]->health,
           party.characters[i]->attack, party.characters[i]->defense);
  }
}

int main() {
  init_party();
  print_party();
  return 0;
}