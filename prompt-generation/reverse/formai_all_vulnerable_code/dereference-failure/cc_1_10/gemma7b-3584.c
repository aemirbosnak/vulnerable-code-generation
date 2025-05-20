//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
  char name[50];
  int room_no;
  struct Guest *next;
} Guest;

typedef struct Room {
  int no;
  Guest *guest;
  struct Room *next;
} Room;

Guest *head_guest = NULL;
Room *head_room = NULL;

void create_guest(char *name, int room_no) {
  Guest *new_guest = (Guest *)malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_no = room_no;
  new_guest->next = NULL;

  if (head_guest == NULL) {
    head_guest = new_guest;
  } else {
    head_guest->next = new_guest;
    head_guest = new_guest;
  }
}

void create_room(int no) {
  Room *new_room = (Room *)malloc(sizeof(Room));
  new_room->no = no;
  new_room->guest = NULL;
  new_room->next = NULL;

  if (head_room == NULL) {
    head_room = new_room;
  } else {
    head_room->next = new_room;
    head_room = new_room;
  }
}

void check_in(char *name, int room_no) {
  Guest *guest = head_guest;
  Room *room = head_room;

  while (guest) {
    if (strcmp(guest->name, name) == 0) {
      while (room) {
        if (room->no == room_no) {
          room->guest = guest;
          break;
        }
        room = room->next;
      }
      break;
    }
    guest = guest->next;
  }

  if (room == NULL) {
    printf("Error: Room not found.\n");
  } else {
    printf("Welcome, %s, to room %d.\n", name, room_no);
  }
}

void check_out(char *name) {
  Guest *guest = head_guest;

  while (guest) {
    if (strcmp(guest->name, name) == 0) {
      guest->room_no = -1;
      printf("Goodbye, %s.\n", name);
      break;
    }
    guest = guest->next;
  }

  if (guest == NULL) {
    printf("Error: Guest not found.\n");
  }
}

int main() {
  create_guest("John Doe", 1);
  create_guest("Jane Doe", 2);
  create_room(1);
  create_room(2);

  check_in("John Doe", 1);
  check_out("Jane Doe");

  return 0;
}