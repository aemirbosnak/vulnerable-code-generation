//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 10

typedef struct room_t {
  int num;
  char name[20];
  struct room_t *next;
} room_t;

room_t *create_room(int num, char *name) {
  room_t *new_room = malloc(sizeof(room_t));
  new_room->num = num;
  strcpy(new_room->name, name);
  new_room->next = NULL;
  return new_room;
}

void explore_room(room_t *room) {
  printf("You are in the %s.\n", room->name);
  switch (room->num) {
    case 1:
      printf("There is a giant talking fish here.\n");
      break;
    case 2:
      printf("You see a mushroom that looks like a rainbow.\n");
      break;
    case 3:
      printf("A disembodied hand reaches out from the wall.\n");
      break;
    default:
      printf("Nothing interesting happens.\n");
  }
  printf("What would you like to do? (e.g. go north, south, east, west)\n");
  char input[20];
  scanf("%s", input);
  // Implement your own logic for handling user input and exploring the room
}

int main() {
  room_t *rooms = NULL;
  rooms = create_room(1, "The Fish Bowl");
  rooms = create_room(2, "The Rainbow Mushroom");
  rooms = create_room(3, "The Disembodied Hand");

  explore_room(rooms);

  return 0;
}