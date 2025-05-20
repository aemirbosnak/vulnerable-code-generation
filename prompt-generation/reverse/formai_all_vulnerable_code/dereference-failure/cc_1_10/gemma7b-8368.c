//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_COUNT 10
#define MAX_ITEM_COUNT 5

typedef struct Room {
  char name[20];
  int items[MAX_ITEM_COUNT];
  struct Room* next;
} Room;

typedef struct Item {
  char name[20];
  int value;
  struct Item* next;
} Item;

Room* generateRooms() {
  int roomCount = rand() % MAX_ROOM_COUNT + 1;
  Room* rooms = NULL;

  for (int i = 0; i < roomCount; i++) {
    rooms = malloc(sizeof(Room));
    rooms->name[0] = 'A' + i;
    rooms->items[0] = rand() % MAX_ITEM_COUNT + 1;
    rooms->next = rooms;
  }

  return rooms;
}

Item* generateItems() {
  int itemCount = rand() % MAX_ITEM_COUNT + 1;
  Item* items = NULL;

  for (int i = 0; i < itemCount; i++) {
    items = malloc(sizeof(Item));
    items->name[0] = 'a' + i;
    items->value = rand() % 100 + 1;
    items->next = items;
  }

  return items;
}

int main() {
  Room* rooms = generateRooms();
  Item* items = generateItems();

  printf("Rooms:");
  for (Room* room = rooms; room; room = room->next) {
    printf(" %s", room->name);
  }

  printf("\nItems:");
  for (Item* item = items; item; item = item->next) {
    printf(" %s (%d)", item->name, item->value);
  }

  return 0;
}