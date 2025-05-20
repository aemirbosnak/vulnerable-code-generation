//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_COUNT 10
#define MAX_ITEM_COUNT 5

typedef struct Room {
  char name[20];
  struct Room* next;
  int items[MAX_ITEM_COUNT];
} Room;

typedef struct Item {
  char name[20];
  int value;
} Item;

Room* generateRooms(int roomCount) {
  Room* head = NULL;
  for (int i = 0; i < roomCount; i++) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->name[0] = 'A' + i;
    newRoom->next = head;
    head = newRoom;
  }

  return head;
}

Item* generateItems(int itemCount) {
  Item* items = malloc(sizeof(Item) * itemCount);
  for (int i = 0; i < itemCount; i++) {
    items[i].name[0] = 'a' + i;
    items[i].value = rand() % 100;
  }

  return items;
}

int main() {
  srand(time(NULL));

  int roomCount = rand() % MAX_ROOM_COUNT;
  Room* rooms = generateRooms(roomCount);

  int itemCount = rand() % MAX_ITEM_COUNT;
  Item* items = generateItems(itemCount);

  // Traverse the rooms and items
  for (Room* room = rooms; room; room = room->next) {
    printf("Room: %s\n", room->name);
    for (int i = 0; i < itemCount; i++) {
      if (room->items[i] != NULL) {
        printf("Item: %s, Value: %d\n", items[i].name, items[i].value);
      }
    }
  }

  return 0;
}