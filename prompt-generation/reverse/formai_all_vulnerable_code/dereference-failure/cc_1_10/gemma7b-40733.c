//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_COUNT 10
#define MAX_ITEM_COUNT 5

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

Room* generateRooms(int roomCount) {
  Room* head = NULL;
  for (int i = 0; i < roomCount; i++) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, "Room ");
    newRoom->x = rand() % 10;
    newRoom->y = rand() % 10;
    newRoom->next = head;
    head = newRoom;
  }
  return head;
}

Item* generateItems(int itemCount) {
  Item* head = NULL;
  for (int i = 0; i < itemCount; i++) {
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, "Item ");
    newItem->value = rand() % 100;
    newItem->next = head;
    head = newItem;
  }
  return head;
}

int main() {
  srand(time(NULL));

  int roomCount = rand() % MAX_ROOM_COUNT;
  Room* rooms = generateRooms(roomCount);

  int itemCount = rand() % MAX_ITEM_COUNT;
  Item* items = generateItems(itemCount);

  // Play the game
  // ...

  return 0;
}