//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define ROOM_NO_MAX 10

typedef struct Room {
  int roomNo;
  char status;
  struct Guest *guest;
} Room;

typedef struct Guest {
  char name[20];
  int noRooms;
  struct Room **rooms;
} Guest;

Room **createRoom(int roomNo) {
  Room **room = (Room **)malloc(sizeof(Room *) * ROOM_NO_MAX);
  for (int i = 0; i < ROOM_NO_MAX; i++) {
    if (room[i] == NULL) {
      room[i] = (Room *)malloc(sizeof(Room));
      room[i]->roomNo = roomNo;
      room[i]->status = 'O';
      room[i]->guest = NULL;
      return room;
    }
  }
  return NULL;
}

Guest *createGuest(char *name) {
  Guest **guest = (Guest **)malloc(sizeof(Guest *) * ROOM_NO_MAX);
  for (int i = 0; i < ROOM_NO_MAX; i++) {
    if (guest[i] == NULL) {
      guest[i] = (Guest *)malloc(sizeof(Guest));
      strcpy(guest[i]->name, name);
      guest[i]->noRooms = 0;
      guest[i]->rooms = NULL;
      return guest;
    }
  }
  return NULL;
}

int main() {
  Room **rooms = createRoom(1);
  Guest **guests = createGuest("John Doe");

  rooms[0]->guest = guests[0];
  guests[0]->rooms = rooms[0];

  printf("Guest name: %s\n", guests[0]->name);
  printf("Room number: %d\n", rooms[0]->roomNo);

  return 0;
}