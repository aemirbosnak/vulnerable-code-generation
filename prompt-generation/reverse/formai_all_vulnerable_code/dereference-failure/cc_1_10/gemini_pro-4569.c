//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

struct room {
  int x;
  int y;
  char *description;
};

struct room *rooms[MAX_ROOMS];

void create_room(int x, int y, char *description) {
  struct room *room = malloc(sizeof(struct room));
  room->x = x;
  room->y = y;
  room->description = description;
  rooms[x * MAX_ROOMS + y] = room;
}

void print_room(struct room *room) {
  printf("You are in %s.\n", room->description);
  printf("There are doors to the north, south, east, and west.\n");
}

void play_game() {
  struct room *room = rooms[0];

  while (1) {
    print_room(room);

    char direction;
    printf("Which direction do you want to go? (n/s/e/w): ");
    scanf(" %c", &direction);

    switch (direction) {
      case 'n':
        room = rooms[room->x * MAX_ROOMS + (room->y - 1)];
        break;
      case 's':
        room = rooms[room->x * MAX_ROOMS + (room->y + 1)];
        break;
      case 'e':
        room = rooms[(room->x + 1) * MAX_ROOMS + room->y];
        break;
      case 'w':
        room = rooms[(room->x - 1) * MAX_ROOMS + room->y];
        break;
      default:
        printf("Invalid direction.\n");
        break;
    }
  }
}

int main() {
  srand(time(NULL));

  // Create the rooms
  create_room(0, 0, "the foyer");
  create_room(1, 0, "the living room");
  create_room(2, 0, "the dining room");
  create_room(3, 0, "the kitchen");
  create_room(4, 0, "the library");
  create_room(5, 0, "the study");
  create_room(6, 0, "the master bedroom");
  create_room(7, 0, "the guest bedroom");
  create_room(8, 0, "the bathroom");
  create_room(9, 0, "the attic");

  // Play the game
  play_game();

  return 0;
}