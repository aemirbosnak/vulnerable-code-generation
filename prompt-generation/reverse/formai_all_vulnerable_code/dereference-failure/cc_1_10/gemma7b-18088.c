//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 10

typedef struct Room {
  char name[20];
  struct Room* next;
  int has_visited;
  int items_taken;
} Room;

Room* create_room(char* name) {
  Room* new_room = malloc(sizeof(Room));
  strcpy(new_room->name, name);
  new_room->next = NULL;
  new_room->has_visited = 0;
  new_room->items_taken = 0;
  return new_room;
}

void explore(Room* current_room) {
  printf("\nYou are in the %s.\n", current_room->name);

  if (current_room->has_visited == 0) {
    current_room->has_visited = 1;

    switch (current_room->name[0]) {
      case 'a':
        printf("There is a golden key on the table.\n");
        break;
      case 'b':
        printf("There is a silver key on the floor.\n");
        break;
      case 'c':
        printf("There is a bronze key on the wall.\n");
        break;
    }
  } else {
    printf("You have already explored this room.\n");
  }
}

int main() {
  Room* rooms = create_room("The Hall");
  rooms = create_room("The Kitchen");
  rooms = create_room("The Bedroom");

  explore(rooms);

  return 0;
}