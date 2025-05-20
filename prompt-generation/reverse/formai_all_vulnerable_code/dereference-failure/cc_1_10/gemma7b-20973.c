//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Room {
  int number;
  char type;
  int occupancy;
  struct Room* next;
};

struct Hotel {
  struct Room* head;
  int numRooms;
  int numOccupancy;
  int availableRooms;
  struct Hotel* next;
};

void insertRoom(struct Hotel* h, int number, char type, int occupancy) {
  struct Room* newRoom = (struct Room*)malloc(sizeof(struct Room));
  newRoom->number = number;
  newRoom->type = type;
  newRoom->occupancy = occupancy;
  newRoom->next = NULL;

  if (h->head == NULL) {
    h->head = newRoom;
  } else {
    struct Room* temp = h->head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newRoom;
  }

  h->numRooms++;
  h->numOccupancy += occupancy;
  h->availableRooms--;
}

void checkIn(struct Hotel* h, int number, int occupancy) {
  struct Room* room = h->head;
  while (room) {
    if (room->number == number) {
      if (room->occupancy >= occupancy) {
        printf("Sorry, the room is full.\n");
      } else {
        room->occupancy += occupancy;
        h->numOccupancy += occupancy;
        printf("Welcome to the hotel, %d.\n", number);
      }
      break;
    }
    room = room->next;
  }

  if (room == NULL) {
    printf("Sorry, the room does not exist.\n");
  }
}

void checkOut(struct Hotel* h, int number, int occupancy) {
  struct Room* room = h->head;
  while (room) {
    if (room->number == number) {
      room->occupancy -= occupancy;
      h->numOccupancy -= occupancy;
      printf("Thank you for your stay, %d.\n", number);
      break;
    }
    room = room->next;
  }

  if (room == NULL) {
    printf("Sorry, the room does not exist.\n");
  }
}

int main() {
  struct Hotel* h = (struct Hotel*)malloc(sizeof(struct Hotel));
  h->head = NULL;
  h->numRooms = 0;
  h->numOccupancy = 0;
  h->availableRooms = MAX;

  insertRoom(h, 101, 'A', 2);
  insertRoom(h, 102, 'B', 1);
  insertRoom(h, 103, 'A', 3);

  checkOut(h, 102, 1);
  checkOut(h, 103, 2);

  checkIn(h, 104, 2);
  checkIn(h, 105, 1);

  printf("Number of rooms: %d\n", h->numRooms);
  printf("Number of occupied rooms: %d\n", h->numOccupancy);
  printf("Available rooms: %d\n", h->availableRooms);

  return 0;
}