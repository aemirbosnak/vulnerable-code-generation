//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room {
  int number;
  char type;
  int available;
  struct Room* next;
} Room;

// Define a function to insert a room into the linked list
void insertRoom(Room* head, int number, char type, int available) {
  Room* newRoom = malloc(sizeof(Room));
  newRoom->number = number;
  newRoom->type = type;
  newRoom->available = available;
  newRoom->next = NULL;

  if (head == NULL) {
    head = newRoom;
  } else {
    newRoom->next = head;
    head = newRoom;
  }
}

// Define a function to find a room by number
Room* findRoom(Room* head, int number) {
  while (head) {
    if (head->number == number) {
      return head;
    } else {
      head = head->next;
    }
  }

  return NULL;
}

// Define a function to check if a room is available
int isRoomAvailable(Room* head, int number) {
  Room* room = findRoom(head, number);

  if (room) {
    return room->available;
  } else {
    return 0;
  }
}

int main() {
  // Create a linked list of rooms
  Room* head = NULL;

  // Insert some rooms
  insertRoom(head, 101, 'A', 1);
  insertRoom(head, 102, 'B', 0);
  insertRoom(head, 103, 'A', 1);

  // Check if room 102 is available
  if (isRoomAvailable(head, 102)) {
    printf("Room 102 is available.\n");
  } else {
    printf("Room 102 is not available.\n");
  }

  // Check if room 103 is available
  if (isRoomAvailable(head, 103)) {
    printf("Room 103 is available.\n");
  } else {
    printf("Room 103 is not available.\n");
  }

  return 0;
}