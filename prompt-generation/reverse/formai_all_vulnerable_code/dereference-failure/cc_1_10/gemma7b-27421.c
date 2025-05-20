//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 5

typedef struct Room {
  char name[20];
  struct Room* next;
} Room;

void create_room(char* name) {
  Room* new_room = malloc(sizeof(Room));
  strcpy(new_room->name, name);
  new_room->next = NULL;
}

void connect_rooms(Room* room1, Room* room2) {
  room1->next = room2;
}

int main() {
  Room* rooms = NULL;
  create_room("The Kitchen");
  create_room("The Living Room");
  create_room("The Bedroom");
  create_room("The Dining Room");
  create_room("The Bathroom");

  connect_rooms(rooms, rooms->next);
  connect_rooms(rooms->next, rooms->next->next);
  connect_rooms(rooms->next->next, rooms->next->next->next);
  connect_rooms(rooms->next->next->next, rooms->next->next->next->next);

  char command[20];
  printf("Enter a command: ");
  scanf("%s", command);

  switch (command[0]) {
    case 'n':
      printf("You are now in the %s.\n", rooms->next->name);
      break;
    case 's':
      printf("You are now in the %s.\n", rooms->name);
      break;
    case 'w':
      printf("You are now in the %s.\n", rooms->next->next->name);
      break;
    case 'e':
      printf("You are now in the %s.\n", rooms->next->next->next->name);
      break;
    default:
      printf("Invalid command.\n");
  }

  return 0;
}