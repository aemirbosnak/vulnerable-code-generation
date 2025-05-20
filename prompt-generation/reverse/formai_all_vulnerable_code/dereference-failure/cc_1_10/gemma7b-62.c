//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_SIZE 10
#define MAX_ITEMS_PER_ROOM 5

typedef struct room_t {
  char **walls;
  struct room_t **next_rooms;
  int items[MAX_ITEMS_PER_ROOM];
  int num_items;
  int x, y;
} room_t;

room_t *generate_room(int x, int y) {
  room_t *room = malloc(sizeof(room_t));
  room->walls = malloc(4 * sizeof(char *));
  for (int i = 0; i < 4; i++) {
    room->walls[i] = malloc(MAX_ROOM_SIZE * sizeof(char));
  }

  room->next_rooms = NULL;
  room->num_items = 0;
  room->x = x;
  room->y = y;

  return room;
}

void place_items(room_t *room) {
  for (int i = 0; i < room->num_items; i++) {
    room->items[i] = rand() % MAX_ITEMS_PER_ROOM;
  }
}

void traverse_room(room_t *room) {
  printf("You are in room (%d, %d).\n", room->x, room->y);

  for (int i = 0; i < room->num_items; i++) {
    printf("Item: %d\n", room->items[i]);
  }

  if (room->next_rooms) {
    traverse_room(room->next_rooms[0]);
  }
}

int main() {
  srand(time(NULL));

  room_t *start_room = generate_room(0, 0);
  place_items(start_room);
  traverse_room(start_room);

  return 0;
}