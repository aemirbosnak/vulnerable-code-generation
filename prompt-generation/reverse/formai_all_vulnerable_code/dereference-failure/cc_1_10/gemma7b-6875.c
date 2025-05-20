//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
  char name[20];
  int room_number;
  struct Guest* next;
} Guest;

typedef struct Room {
  int number;
  int occupancy;
  struct Room* next;
} Room;

Guest* head_guest = NULL;
Room* head_room = NULL;

void add_guest(char* name, int room_number) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_number = room_number;
  new_guest->next = head_guest;
  head_guest = new_guest;
}

void add_room(int number, int occupancy) {
  Room* new_room = (Room*)malloc(sizeof(Room));
  new_room->number = number;
  new_room->occupancy = occupancy;
  new_room->next = head_room;
  head_room = new_room;
}

int main() {
  add_guest("John Doe", 1);
  add_guest("Jane Doe", 2);
  add_guest("Bob Smith", 3);
  add_room(1, 2);
  add_room(2, 1);
  add_room(3, 0);

  Guest* guest = head_guest;
  while (guest) {
    printf("Name: %s, Room Number: %d\n", guest->name, guest->room_number);
    guest = guest->next;
  }

  Room* room = head_room;
  while (room) {
    printf("Number: %d, Occupancy: %d\n", room->number, room->occupancy);
    room = room->next;
  }

  return 0;
}