//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

typedef struct Guest {
  char name[50];
  int room_no;
  struct Guest *next;
} Guest;

typedef struct Room {
  int room_no;
  int occupancy;
  struct Room *next;
} Room;

Guest *head_guest = NULL;
Room *head_room = NULL;

void add_guest(char *name, int room_no) {
  Guest *new_guest = (Guest *)malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_no = room_no;
  new_guest->next = NULL;

  if (head_guest == NULL) {
    head_guest = new_guest;
  } else {
    head_guest->next = new_guest;
  }
}

void add_room(int room_no, int occupancy) {
  Room *new_room = (Room *)malloc(sizeof(Room));
  new_room->room_no = room_no;
  new_room->occupancy = occupancy;
  new_room->next = NULL;

  if (head_room == NULL) {
    head_room = new_room;
  } else {
    head_room->next = new_room;
  }
}

void check_room_occupancy(int room_no) {
  Room *current_room = head_room;

  while (current_room) {
    if (current_room->room_no == room_no) {
      printf("Room %d is %s.\n", room_no, current_room->occupancy ? "occupied" : "available");
      return;
    }
    current_room = current_room->next;
  }

  printf("Room %d does not exist.\n", room_no);
}

int main() {
  add_guest("John Doe", 1);
  add_guest("Jane Doe", 2);
  add_room(1, 2);
  add_room(2, 1);

  check_room_occupancy(1);
  check_room_occupancy(2);
  check_room_occupancy(3);

  return 0;
}