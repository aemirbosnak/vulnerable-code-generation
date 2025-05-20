//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct Room {
  int x, y;
  char **map;
  struct Room* next;
} Room;

Room* generate_room(int x, int y) {
  Room* room = malloc(sizeof(Room));
  room->x = x;
  room->y = y;
  room->map = malloc(5 * x * y);
  for (int i = 0; i < 5 * x * y; i++) {
    room->map[i] = '#';
  }
  return room;
}

void print_room(Room* room) {
  for (int y = 0; y < room->y; y++) {
    for (int x = 0; x < room->x; x++) {
      printf("%c ", room->map[x + room->x * y]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  // Generate a list of rooms
  Room* head = generate_room(5, 5);
  Room* current = head;

  // Print the first room
  print_room(current);

  // Go to the next room
  current = current->next = generate_room(6, 6);

  // Print the second room
  print_room(current);

  return 0;
}