//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct Room {
  char name[20];
  struct Room *next;
  struct Item *items;
} Room;

typedef struct Item {
  char name[20];
  int quantity;
  struct Item *next;
} Item;

Room *generateRooms(int numRooms) {
  Room *head = NULL;
  for (int i = 0; i < numRooms; i++) {
    Room *newRoom = malloc(sizeof(Room));
    newRoom->name[0] = 'a' + i;
    newRoom->next = head;
    head = newRoom;
  }
  return head;
}

Item *generateItems(int numItems) {
  Item *head = NULL;
  for (int i = 0; i < numItems; i++) {
    Item *newItem = malloc(sizeof(Item));
    newItem->name[0] = 'a' + i;
    newItem->quantity = rand() % 10;
    newItem->next = head;
    head = newItem;
  }
  return head;
}

int main() {
  srand(time(NULL));
  Room *rooms = generateRooms(MAX_ROOMS);
  Item *items = generateItems(MAX_ITEMS);

  // Explore the rooms and collect items
  // ...

  return 0;
}