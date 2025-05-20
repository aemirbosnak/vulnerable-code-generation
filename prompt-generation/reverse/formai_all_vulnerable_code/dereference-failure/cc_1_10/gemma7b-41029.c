//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 20

typedef struct Room {
  int number;
  struct Guest *guests;
  struct Room *next;
} Room;

typedef struct Guest {
  char name[20];
  int room_number;
  struct Guest *next;
} Guest;

Room *create_room(int number) {
  Room *room = (Room *)malloc(sizeof(Room));
  room->number = number;
  room->guests = NULL;
  room->next = NULL;
  return room;
}

Guest *create_guest(char *name, int room_number) {
  Guest *guest = (Guest *)malloc(sizeof(Guest));
  strcpy(guest->name, name);
  guest->room_number = room_number;
  guest->next = NULL;
  return guest;
}

void add_guest(Room *room, Guest *guest) {
  room->guests = guest;
}

void check_in(Room *room, char *name) {
  Guest *guest = create_guest(name, room->number);
  add_guest(room, guest);
}

void check_out(Room *room, char *name) {
  Guest *guest = room->guests;
  while (guest) {
    if (strcmp(guest->name, name) == 0) {
      free(guest);
      room->guests = guest->next;
      break;
    }
    guest = guest->next;
  }
}

int main() {
  Room *head = create_room(1);
  Room *tail = head;

  for (int i = 2; i <= MAX_ROOMS; i++) {
    tail = create_room(i);
    tail->next = head;
    head = tail;
  }

  check_in(head, "Alice");
  check_in(head, "Bob");
  check_out(head, "Bob");

  Guest *guest = head->guests;
  while (guest) {
    printf("Name: %s, Room number: %d\n", guest->name, guest->room_number);
    guest = guest->next;
  }

  return 0;
}