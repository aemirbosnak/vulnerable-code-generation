//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define ROOM_COUNT 10

typedef struct Room {
  int x, y;
  int width, height;
  struct Room* next;
} Room;

Room* createRoom(int x, int y, int w, int h) {
  Room* room = malloc(sizeof(Room));
  room->x = x;
  room->y = y;
  room->width = w;
  room->height = h;
  room->next = NULL;
  return room;
}

void generateMap() {
  // Create a list of rooms
  Room* head = createRoom(0, 0, 5, 5);
  for (int i = 1; i < ROOM_COUNT; i++) {
    head = createRoom(rand() % MAP_SIZE, rand() % MAP_SIZE, rand() % 3 + 1, rand() % 3 + 1);
    head->next = head;
  }

  // Print the map
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      Room* room = head;
      while (room) {
        if (x >= room->x && x < room->x + room->width && y >= room->y && y < room->y + room->height) {
          printf("R");
        } else {
          printf(".");
        }
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  generateMap();

  return 0;
}