//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
  char name[20];
  struct Room* next;
  int num;
  int has_visited;
} Room;

Room* create_room(char* name, int num) {
  Room* new_room = malloc(sizeof(Room));
  strcpy(new_room->name, name);
  new_room->num = num;
  new_room->next = NULL;
  new_room->has_visited = 0;
  return new_room;
}

void start_adventure() {
  Room* room_list = create_room("The Hallway", 1);
  room_list = create_room("The Library", 2);
  room_list = create_room("The Kitchen", 3);
  room_list = create_room("The Bedroom", 4);
  room_list = create_room("The Secret Room", 5);

  Room* current_room = room_list;

  printf("You wake up in a mysterious house. You have no memory of how you got here. You only have a map that points to five rooms:\n");
  printf("1. The Hallway\n");
  printf("2. The Library\n");
  printf("3. The Kitchen\n");
  printf("4. The Bedroom\n");
  printf("5. The Secret Room\n");

  int choice = 0;
  printf("Please enter the number of the room you want to visit: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You enter the hallway. It is dark and empty.\n");
      current_room->has_visited = 1;
      start_adventure();
      break;
    case 2:
      printf("You enter the library. There are bookshelves and a fireplace.\n");
      current_room->has_visited = 1;
      start_adventure();
      break;
    case 3:
      printf("You enter the kitchen. There is a fridge, a stove, and a table.\n");
      current_room->has_visited = 1;
      start_adventure();
      break;
    case 4:
      printf("You enter the bedroom. There is a bed, a dresser, and a mirror.\n");
      current_room->has_visited = 1;
      start_adventure();
      break;
    case 5:
      printf("You enter the secret room. It is full of treasures.\n");
      current_room->has_visited = 1;
      start_adventure();
      break;
    default:
      printf("Invalid choice.\n");
      start_adventure();
  }
}

int main() {
  start_adventure();
  return 0;
}