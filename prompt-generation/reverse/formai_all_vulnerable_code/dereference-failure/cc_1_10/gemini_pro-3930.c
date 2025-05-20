//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct {
  int x;
  int y;
} Room;

typedef struct {
  char *name;
  char *description;
} Item;

Room rooms[MAX_ROOMS];
Item items[MAX_ITEMS];

int numRooms = 0;
int numItems = 0;

void generateRooms() {
  for (int i = 0; i < MAX_ROOMS; i++) {
    rooms[i].x = rand() % 10;
    rooms[i].y = rand() % 10;
  }
}

void generateItems() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    items[i].name = malloc(10);
    items[i].description = malloc(20);
    sprintf(items[i].name, "Item %d", i);
    sprintf(items[i].description, "This is item %d.", i);
  }
}

void printRooms() {
  for (int i = 0; i < numRooms; i++) {
    printf("Room %d: (%d, %d)\n", i, rooms[i].x, rooms[i].y);
  }
}

void printItems() {
  for (int i = 0; i < numItems; i++) {
    printf("Item %d: %s - %s\n", i, items[i].name, items[i].description);
  }
}

int main() {
  srand(time(NULL));

  generateRooms();
  generateItems();

  printRooms();
  printItems();

  return 0;
}