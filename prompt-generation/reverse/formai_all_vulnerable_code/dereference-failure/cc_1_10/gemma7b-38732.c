//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5
#define MAX_ITEMS 3

typedef struct Room {
  char name[20];
  int monsters;
  int items;
  struct Room* next;
} Room;

typedef struct Monster {
  char name[20];
  int health;
  int attack;
  struct Monster* next;
} Monster;

typedef struct Item {
  char name[20];
  int uses;
  struct Item* next;
} Item;

Room* generate_room(int num) {
  Room* room = malloc(sizeof(Room));
  room->name[0] = 'A' + num;
  room->monsters = rand() % MAX_MONSTERS;
  room->items = rand() % MAX_ITEMS;
  room->next = NULL;
  return room;
}

Monster* generate_monster(int num) {
  Monster* monster = malloc(sizeof(Monster));
  monster->name[0] = 'M' + num;
  monster->health = rand() % 10 + 1;
  monster->attack = rand() % 5 + 1;
  monster->next = NULL;
  return monster;
}

Item* generate_item(int num) {
  Item* item = malloc(sizeof(Item));
  item->name[0] = 'I' + num;
  item->uses = rand() % 3 + 1;
  item->next = NULL;
  return item;
}

int main() {
  srand(time(NULL));

  Room* rooms = generate_room(1);
  for (int i = 0; i < MAX_ROOMS - 1; i++) {
    rooms->next = generate_room(i + 2);
    rooms = rooms->next;
  }

  Monster* monsters = generate_monster(1);
  for (int i = 0; i < MAX_MONSTERS - 1; i++) {
    monsters->next = generate_monster(i + 2);
    monsters = monsters->next;
  }

  Item* items = generate_item(1);
  for (int i = 0; i < MAX_ITEMS - 1; i++) {
    items->next = generate_item(i + 2);
    items = items->next;
  }

  // Play the game...
  return 0;
}