//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct Room {
  int number;
  char status;
  struct Room* next;
} Room;

Room* createRoom(int number) {
  Room* newRoom = (Room*)malloc(sizeof(Room));
  newRoom->number = number;
  newRoom->status = 'O';
  newRoom->next = NULL;

  return newRoom;
}

void addRoom(Room* head, int number) {
  Room* newRoom = createRoom(number);

  if (head == NULL) {
    head = newRoom;
  } else {
    head->next = newRoom;
  }

  head = newRoom;
}

void showRooms(Room* head) {
  while (head) {
    printf("Room number: %d, Status: %c\n", head->number, head->status);
    head = head->next;
  }
}

int main() {
  Room* head = NULL;

  addRoom(head, 101);
  addRoom(head, 102);
  addRoom(head, 103);
  addRoom(head, 104);

  showRooms(head);

  return 0;
}