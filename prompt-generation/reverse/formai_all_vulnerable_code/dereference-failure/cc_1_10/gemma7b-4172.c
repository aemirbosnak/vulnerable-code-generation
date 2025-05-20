//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUEST_NAME_LENGTH 20
#define MAX_ROOM_NUMBER 100

typedef struct Guest {
  char name[MAX_GUEST_NAME_LENGTH];
  int roomNumber;
  struct Guest* next;
} Guest;

typedef struct Room {
  int number;
  Guest* guest;
  struct Room* next;
} Room;

Room* CreateRoom(int number);
Guest* CreateGuest(char* name, int roomNumber);

int main() {
  Room* headRoom = CreateRoom(1);
  Guest* headGuest = CreateGuest("John Doe", 1);

  headRoom->guest = headGuest;

  // Paranoia!
  headGuest->next = NULL;
  headRoom->next = NULL;

  return 0;
}

Room* CreateRoom(int number) {
  Room* newRoom = malloc(sizeof(Room));
  newRoom->number = number;
  newRoom->guest = NULL;
  newRoom->next = NULL;

  return newRoom;
}

Guest* CreateGuest(char* name, int roomNumber) {
  Guest* newGuest = malloc(sizeof(Guest));
  strcpy(newGuest->name, name);
  newGuest->roomNumber = roomNumber;
  newGuest->next = NULL;

  return newGuest;
}