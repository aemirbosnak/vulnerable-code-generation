//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

#define MAX_ROOM_SIZE 10

typedef struct Room {
  int x, y;
  int w, h;
  struct Room* next;
} Room;

Room* generate_map() {
  Room* head = NULL;
  int i, j;

  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      int r_w = rand() % MAX_ROOM_SIZE;
      int r_h = rand() % MAX_ROOM_SIZE;

      Room* new_room = malloc(sizeof(Room));
      new_room->x = i;
      new_room->y = j;
      new_room->w = r_w;
      new_room->h = r_h;
      new_room->next = head;
      head = new_room;
    }
  }

  return head;
}

void print_map(Room* room) {
  while (room) {
    for (int y = room->y; y < room->y + room->h; y++) {
      for (int x = room->x; x < room->x + room->w; x++) {
        printf("%c ", 'A' + x + y);
      }
      printf("\n");
    }
    room = room->next;
  }
}

int main() {
  Room* map = generate_map();
  print_map(map);

  return 0;
}