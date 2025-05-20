//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Items 5

typedef struct Room {
  int x, y;
  char name[20];
  struct Room* next;
} Room;

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

Room** generateRooms(int numRooms) {
  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->x = rand() % 10;
    rooms[i]->y = rand() % 10;
    rooms[i]->name[0] = 'A' + i;
    rooms[i]->next = NULL;
  }
  return rooms;
}

Item** generateItems(int numItems) {
  Item** items = malloc(numItems * sizeof(Item*));
  for (int i = 0; i < numItems; i++) {
    items[i] = malloc(sizeof(Item));
    items[i]->name[0] = 'a' + i;
    items[i]->quantity = rand() % 5;
    items[i]->next = NULL;
  }
  return items;
}

int main() {
  srand(time(NULL));

  int numRooms = rand() % MAX_Rooms;
  Room** rooms = generateRooms(numRooms);

  int numItems = rand() % MAX_Items;
  Item** items = generateItems(numItems);

  // Play the game...
  for (int i = 0; i < numRooms; i++) {
    printf("Room %c: (%d, %d)\n", rooms[i]->name[0], rooms[i]->x, rooms[i]->y);
  }

  for (int i = 0; i < numItems; i++) {
    printf("Item %c: %d\n", items[i]->name[0], items[i]->quantity);
  }

  return 0;
}