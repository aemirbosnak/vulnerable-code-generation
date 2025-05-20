//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 10
#define ITEM_COUNT 20
#define MONSTER_COUNT 15

typedef struct Room {
  char name[20];
  struct Room* next;
  int monsters;
  int items;
} Room;

typedef struct Item {
  char name[20];
  int value;
  struct Item* next;
} Item;

typedef struct Monster {
  char name[20];
  int health;
  struct Monster* next;
} Monster;

Room* generateRooms() {
  Room* head = NULL;
  for (int i = 0; i < ROOM_COUNT; i++) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->name[0] = 'A' + i;
    newRoom->next = head;
    head = newRoom;
  }
  return head;
}

Item* generateItems() {
  Item* head = NULL;
  for (int i = 0; i < ITEM_COUNT; i++) {
    Item* newItem = malloc(sizeof(Item));
    newItem->name[0] = 'a' + i;
    newItem->value = rand() % 100;
    newItem->next = head;
    head = newItem;
  }
  return head;
}

Monster* generateMonsters() {
  Monster* head = NULL;
  for (int i = 0; i < MONSTER_COUNT; i++) {
    Monster* newMonster = malloc(sizeof(Monster));
    newMonster->name[0] = 'm' + i;
    newMonster->health = rand() % 100;
    newMonster->next = head;
    head = newMonster;
  }
  return head;
}

int main() {
  srand(time(NULL));

  Room* rooms = generateRooms();
  Item* items = generateItems();
  Monster* monsters = generateMonsters();

  // Play the game...
}