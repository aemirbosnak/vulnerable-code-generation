//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_COUNT 10
#define MAX_ITEM_COUNT 5

typedef struct Room {
  char name[20];
  int items[MAX_ITEM_COUNT];
  struct Room* nextRoom;
} Room;

typedef struct Item {
  char name[20];
  int rarity;
  struct Item* nextItem;
} Item;

Room* generateRooms() {
  int roomCount = rand() % MAX_ROOM_COUNT;
  Room* rooms = NULL;
  for (int i = 0; i < roomCount; i++) {
    rooms = malloc(sizeof(Room));
    rooms->name[0] = 'A' + i;
    rooms->items[0] = rand() % MAX_ITEM_COUNT;
    rooms->nextRoom = rooms;
  }
  return rooms;
}

Item* generateItems() {
  int itemCount = rand() % MAX_ITEM_COUNT;
  Item* items = NULL;
  for (int i = 0; i < itemCount; i++) {
    items = malloc(sizeof(Item));
    items->name[0] = 'a' + i;
    items->rarity = rand() % 10;
    items->nextItem = items;
  }
  return items;
}

int main() {
  srand(time(NULL));
  Room* rooms = generateRooms();
  Item* items = generateItems();

  printf("You are in the %s room.\n", rooms->name);
  printf("You have found the following items: ");
  for (Item* item = items; item; item = item->nextItem) {
    printf("%s ", item->name);
  }

  return 0;
}