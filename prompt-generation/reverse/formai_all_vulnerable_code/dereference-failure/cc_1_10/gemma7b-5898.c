//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct Room {
  int num;
  char name[20];
  struct Room* next;
} Room;

typedef struct Item {
  int num;
  char name[20];
  struct Item* next;
} Item;

Room* generateRooms(int numRooms) {
  Room* head = NULL;
  for (int i = 0; i < numRooms; i++) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->num = i + 1;
    sprintf(newRoom->name, "Room %d", i + 1);
    newRoom->next = head;
    head = newRoom;
  }
  return head;
}

Item* generateItems(int numItems) {
  Item* head = NULL;
  for (int i = 0; i < numItems; i++) {
    Item* newItem = malloc(sizeof(Item));
    newItem->num = i + 1;
    sprintf(newItem->name, "Item %d", i + 1);
    newItem->next = head;
    head = newItem;
  }
  return head;
}

int main() {
  Room* rooms = generateRooms(MAX_ROOMS);
  Item* items = generateItems(MAX_ITEMS);

  // Play the game here

  return 0;
}