//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct room {
  char *name;
  struct room *north;
  struct room *south;
  struct room *east;
  struct room *west;
} room;

room *rooms[MAX_ROOMS];

void create_rooms() {
  for (int i = 0; i < MAX_ROOMS; i++) {
    rooms[i] = malloc(sizeof(room));
    rooms[i]->name = malloc(10);
    sprintf(rooms[i]->name, "Room %d", i);
    rooms[i]->north = NULL;
    rooms[i]->south = NULL;
    rooms[i]->east = NULL;
    rooms[i]->west = NULL;
  }

  rooms[0]->north = rooms[1];
  rooms[0]->south = rooms[2];
  rooms[0]->east = rooms[3];
  rooms[0]->west = rooms[4];

  rooms[1]->south = rooms[0];
  rooms[1]->east = rooms[5];
  rooms[1]->west = rooms[6];

  rooms[2]->north = rooms[0];
  rooms[2]->east = rooms[7];
  rooms[2]->west = rooms[8];

  rooms[3]->west = rooms[0];
  rooms[3]->east = rooms[9];

  rooms[4]->east = rooms[0];
  rooms[4]->west = rooms[5];

  rooms[5]->north = rooms[1];
  rooms[5]->east = rooms[6];
  rooms[5]->west = rooms[4];

  rooms[6]->north = rooms[1];
  rooms[6]->east = rooms[7];
  rooms[6]->west = rooms[5];

  rooms[7]->north = rooms[2];
  rooms[7]->east = rooms[8];
  rooms[7]->west = rooms[6];

  rooms[8]->north = rooms[2];
  rooms[8]->east = rooms[9];
  rooms[8]->west = rooms[7];

  rooms[9]->west = rooms[3];
  rooms[9]->east = rooms[8];
}

void free_rooms() {
  for (int i = 0; i < MAX_ROOMS; i++) {
    free(rooms[i]->name);
    free(rooms[i]);
  }
}

void print_room(room *r) {
  printf("You are in %s.\n", r->name);
  if (r->north) printf("To the north, you see %s.\n", r->north->name);
  if (r->south) printf("To the south, you see %s.\n", r->south->name);
  if (r->east) printf("To the east, you see %s.\n", r->east->name);
  if (r->west) printf("To the west, you see %s.\n", r->west->name);
}

void play_game() {
  room *current_room = rooms[0];

  while (1) {
    print_room(current_room);

    char input[10];
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "n") == 0 && current_room->north) {
      current_room = current_room->north;
    } else if (strcmp(input, "s") == 0 && current_room->south) {
      current_room = current_room->south;
    } else if (strcmp(input, "e") == 0 && current_room->east) {
      current_room = current_room->east;
    } else if (strcmp(input, "w") == 0 && current_room->west) {
      current_room = current_room->west;
    } else if (strcmp(input, "q") == 0) {
      break;
    } else {
      printf("Invalid input.\n");
    }
  }
}

int main() {
  srand(time(NULL));

  create_rooms();
  play_game();
  free_rooms();

  return 0;
}