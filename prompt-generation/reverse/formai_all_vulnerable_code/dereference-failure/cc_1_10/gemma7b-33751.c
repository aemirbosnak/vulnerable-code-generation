//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_COUNT 10

typedef struct Room {
  char name[20];
  struct Room *next;
  int items[5];
  int visited;
} Room;

Room *generateRooms(int roomCount) {
  srand(time(NULL));

  Room *head = NULL;
  for (int i = 0; i < roomCount; i++) {
    Room *newRoom = malloc(sizeof(Room));
    newRoom->name[0] = 'a' + i;
    newRoom->next = head;
    head = newRoom;
  }

  return head;
}

void exploreRoom(Room *room) {
  printf("You are in the %s.\n", room->name);

  for (int i = 0; i < 5; i++) {
    if (room->items[i] != -1) {
      printf("There is a %s in the room.\n", room->items[i]);
    }
  }

  room->visited = 1;
}

int main() {
  int roomCount = MAX_ROOM_COUNT;
  Room *rooms = generateRooms(roomCount);

  for (Room *room = rooms; room; room = room->next) {
    if (!room->visited) {
      exploreRoom(room);
    }
  }

  return 0;
}