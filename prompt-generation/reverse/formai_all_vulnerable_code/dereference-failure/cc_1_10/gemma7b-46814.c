//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
  char name[50];
  int room_number;
  struct Guest* next;
} Guest;

typedef struct Room {
  int number;
  char status;
  struct Room* next;
} Room;

Guest* insertGuest(Guest* head, char* name, int room_number) {
  Guest* newGuest = malloc(sizeof(Guest));
  strcpy(newGuest->name, name);
  newGuest->room_number = room_number;
  newGuest->next = NULL;

  if (head == NULL) {
    head = newGuest;
  } else {
    Guest* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newGuest;
  }

  return head;
}

Room* insertRoom(Room* head, int number, char status) {
  Room* newRoom = malloc(sizeof(Room));
  newRoom->number = number;
  newRoom->status = status;
  newRoom->next = NULL;

  if (head == NULL) {
    head = newRoom;
  } else {
    Room* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newRoom;
  }

  return head;
}

void printGuests(Guest* head) {
  Guest* current = head;
  while (current) {
    printf("Name: %s, Room Number: %d\n", current->name, current->room_number);
    current = current->next;
  }
}

void printRooms(Room* head) {
  Room* current = head;
  while (current) {
    printf("Number: %d, Status: %c\n", current->number, current->status);
    current = current->next;
  }
}

int main() {
  Guest* guests = NULL;
  Room* rooms = NULL;

  insertGuest(guests, "John Doe", 1);
  insertGuest(guests, "Jane Doe", 2);
  insertGuest(guests, "Peter Pan", 3);

  insertRoom(rooms, 1, 'O');
  insertRoom(rooms, 2, 'A');
  insertRoom(rooms, 3, 'B');

  printGuests(guests);
  printRooms(rooms);

  return 0;
}