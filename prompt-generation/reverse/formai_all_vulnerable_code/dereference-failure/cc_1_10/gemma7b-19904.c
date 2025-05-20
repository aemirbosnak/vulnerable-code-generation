//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

struct room {
  char name[20];
  int number;
  struct guest *guest;
  struct room *next;
};

struct guest {
  char name[20];
  int room_number;
  struct guest *next;
};

struct room *create_room(char *name, int number)
{
  struct room *new_room = malloc(sizeof(struct room));
  strcpy(new_room->name, name);
  new_room->number = number;
  new_room->guest = NULL;
  new_room->next = NULL;

  return new_room;
}

struct guest *create_guest(char *name, int room_number)
{
  struct guest *new_guest = malloc(sizeof(struct guest));
  strcpy(new_guest->name, name);
  new_guest->room_number = room_number;
  new_guest->next = NULL;

  return new_guest;
}

void check_in(struct room *room, struct guest *guest)
{
  room->guest = guest;
  guest->room_number = room->number;
}

void check_out(struct room *room)
{
  room->guest = NULL;
}

int main()
{
  struct room *head = create_room("Suite 1", 1);
  struct guest *guest = create_guest("John Doe", 1);
  check_in(head, guest);

  struct room *second = create_room("Deluxe Room", 2);
  struct guest *guest2 = create_guest("Jane Doe", 2);
  check_in(second, guest2);

  check_out(head);

  printf("Guest name: %s, room number: %d\n", guest->name, guest->room_number);
  printf("Guest name: %s, room number: %d\n", guest2->name, guest2->room_number);

  return 0;
}