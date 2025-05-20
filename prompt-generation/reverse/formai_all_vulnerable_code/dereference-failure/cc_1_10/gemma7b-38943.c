//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 10
#define ITEM_COUNT 20

typedef struct Room {
  char name[20];
  int x, y;
  struct Room* next;
} Room;

typedef struct Item {
  char name[20];
  int value;
  struct Item* next;
} Item;

Room* generateRooms() {
  time_t t = time(NULL);
  srand(t);

  Room* head = NULL;
  for (int i = 0; i < ROOM_COUNT; i++) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->name[0] = 'A' + i;
    newRoom->x = rand() % 10;
    newRoom->y = rand() % 10;
    newRoom->next = head;
    head = newRoom;
  }

  return head;
}

Item* generateItems() {
  time_t t = time(NULL);
  srand(t);

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

int main() {
  Room* rooms = generateRooms();
  Item* items = generateItems();

  // Play the game
  // ...

  return 0;
}