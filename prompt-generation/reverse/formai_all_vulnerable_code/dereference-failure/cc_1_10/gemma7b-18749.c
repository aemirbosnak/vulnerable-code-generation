//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_ROOM_SIZE 10

typedef struct Room {
  int x, y;
  int w, h;
  struct Room* next;
} Room;

Room* generate_room(int w, int h) {
  Room* room = malloc(sizeof(Room));
  room->x = rand() % WIDTH;
  room->y = rand() % HEIGHT;
  room->w = w;
  room->h = h;
  room->next = NULL;
  return room;
}

void draw_room(Room* room) {
  for (int x = room->x; x < room->x + room->w; x++) {
    for (int y = room->y; y < room->y + room->h; y++) {
      printf("%c ", '#');
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  int num_rooms = rand() % MAX_ROOM_SIZE + 1;

  Room* rooms = NULL;
  for (int i = 0; i < num_rooms; i++) {
    rooms = generate_room(rand() % 5 + 1, rand() % 5 + 1)
      ? rooms : generate_room(rand() % 5 + 1, rand() % 5 + 1)
      ? rooms : NULL;
  }

  if (rooms) {
    draw_room(rooms);
  } else {
    printf("No rooms generated.\n");
  }

  return 0;
}