//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
  int num;
  char name[20];
  struct Room *next;
} Room;

Room *create_room(int num, char *name) {
  Room *room = malloc(sizeof(Room));
  room->num = num;
  strcpy(room->name, name);
  room->next = NULL;
  return room;
}

void explore_room(Room *room) {
  printf("You are in the %s.\n", room->name);
  printf("What do you want to do? (look, go, interact)\n");
  char input[20];
  scanf("%s", input);

  if (strcmp(input, "look") == 0) {
    printf("The room is... %s.\n", room->name);
  } else if (strcmp(input, "go") == 0) {
    printf("You went %s.\n", room->next->name);
    explore_room(room->next);
  } else if (strcmp(input, "interact") == 0) {
    printf("You interacted with... %s.\n", room->name);
  } else {
    printf("Invalid input.\n");
  }
}

int main() {
  Room *start = create_room(1, "The Entrance");
  Room *room2 = create_room(2, "The Library");
  Room *room3 = create_room(3, "The Dining Hall");
  Room *room4 = create_room(4, "The Bedroom");
  room2->next = room3;
  room3->next = room4;
  start->next = room2;

  explore_room(start);

  return 0;
}