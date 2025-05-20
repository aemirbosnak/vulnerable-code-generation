//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_GUESTS 2

typedef struct Room {
  int number;
  int guests;
  struct Room *next;
} Room;

typedef struct Guest {
  char name[20];
  int room_number;
  struct Guest *next;
} Guest;

Room *insertRoom(Room *head) {
  Room *newRoom = (Room *)malloc(sizeof(Room));
  newRoom->number = MAX_ROOMS + 1;
  newRoom->guests = MAX_GUESTS;
  newRoom->next = NULL;

  if (head == NULL) {
    head = newRoom;
  } else {
    head->next = newRoom;
  }

  return head;
}

Guest *insertGuest(Guest *head, Room *room) {
  Guest *newGuest = (Guest *)malloc(sizeof(Guest));
  newGuest->name[0] = '\0';
  newGuest->room_number = room->number;
  newGuest->next = NULL;

  if (head == NULL) {
    head = newGuest;
  } else {
    head->next = newGuest;
  }

  return head;
}

void printRooms(Room *head) {
  while (head) {
    printf("Room number: %d, guests: %d\n", head->number, head->guests);
    head = head->next;
  }
}

void printGuests(Guest *head) {
  while (head) {
    printf("Guest name: %s, room number: %d\n", head->name, head->room_number);
    head = head->next;
  }
}

int main() {
  Room *rooms = NULL;
  Guest *guests = NULL;

  rooms = insertRoom(rooms);
  insertRoom(rooms);
  insertRoom(rooms);

  guests = insertGuest(guests, rooms);
  insertGuest(guests, rooms);
  insertGuest(guests, rooms);

  printRooms(rooms);
  printGuests(guests);

  return 0;
}