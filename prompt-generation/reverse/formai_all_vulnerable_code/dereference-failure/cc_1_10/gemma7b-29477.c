//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define ROOM_COUNT 10

typedef struct Room {
  int x, y;
  int type;
  struct Room* next;
} Room;

Room* generateRooms() {
  time_t seed = time(NULL);
  srand(seed);

  Room* head = NULL;
  for (int i = 0; i < ROOM_COUNT; i++) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->x = rand() % MAP_SIZE;
    newRoom->y = rand() % MAP_SIZE;
    newRoom->type = rand() % 3;
    newRoom->next = head;
    head = newRoom;
  }

  return head;
}

void drawMap(Room* room) {
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      if (room->x == x && room->y == y) {
        printf("R");
      } else if (rand() % 2 == 0) {
        printf("W");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  Room* rooms = generateRooms();
  drawMap(rooms);

  return 0;
}