//GEMINI-pro DATASET v1.0 Category: Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 20

typedef struct room {
  char name[MAX_NAME_LENGTH];
  struct room *north;
  struct room *south;
  struct room *east;
  struct room *west;
} room;

room *create_room(char *name) {
  room *new_room = malloc(sizeof(room));
  strcpy(new_room->name, name);
  new_room->north = NULL;
  new_room->south = NULL;
  new_room->east = NULL;
  new_room->west = NULL;
  return new_room;
}

void connect_rooms(room *room1, room *room2, char direction) {
  switch (direction) {
    case 'n':
      room1->north = room2;
      break;
    case 's':
      room1->south = room2;
      break;
    case 'e':
      room1->east = room2;
      break;
    case 'w':
      room1->west = room2;
      break;
  }
}

void print_room(room *room) {
  printf("You are in %s.\n", room->name);
  if (room->north != NULL) {
    printf("To the north is %s.\n", room->north->name);
  }
  if (room->south != NULL) {
    printf("To the south is %s.\n", room->south->name);
  }
  if (room->east != NULL) {
    printf("To the east is %s.\n", room->east->name);
  }
  if (room->west != NULL) {
    printf("To the west is %s.\n", room->west->name);
  }
}

int main() {
  room *rooms[MAX_ROOMS];
  int num_rooms = 0;

  // Create the rooms.
  rooms[num_rooms++] = create_room("Hall of Shadows");
  rooms[num_rooms++] = create_room("Chamber of Secrets");
  rooms[num_rooms++] = create_room("Throne Room");
  rooms[num_rooms++] = create_room("Armory");
  rooms[num_rooms++] = create_room("Dungeon");

  // Connect the rooms.
  connect_rooms(rooms[0], rooms[1], 'n');
  connect_rooms(rooms[1], rooms[2], 'e');
  connect_rooms(rooms[2], rooms[3], 's');
  connect_rooms(rooms[3], rooms[4], 'w');

  // Start the game.
  room *current_room = rooms[0];
  while (1) {
    print_room(current_room);
    char input[MAX_NAME_LENGTH];
    printf("> ");
    scanf("%s", input);
    if (strcmp(input, "n") == 0 && current_room->north != NULL) {
      current_room = current_room->north;
    } else if (strcmp(input, "s") == 0 && current_room->south != NULL) {
      current_room = current_room->south;
    } else if (strcmp(input, "e") == 0 && current_room->east != NULL) {
      current_room = current_room->east;
    } else if (strcmp(input, "w") == 0 && current_room->west != NULL) {
      current_room = current_room->west;
    } else {
      printf("Invalid input.\n");
    }
  }

  return 0;
}