//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
  char name[50];
  int room_no;
  struct Guest* next;
} Guest;

typedef struct Room {
  int room_no;
  int occupancy;
  struct Room* next;
} Room;

Guest* insert_guest(Guest* head, char* name, int room_no) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_no = room_no;
  new_guest->next = NULL;

  if (head == NULL) {
    head = new_guest;
  } else {
    Guest* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_guest;
  }

  return head;
}

Room* insert_room(Room* head, int room_no, int occupancy) {
  Room* new_room = (Room*)malloc(sizeof(Room));
  new_room->room_no = room_no;
  new_room->occupancy = occupancy;
  new_room->next = NULL;

  if (head == NULL) {
    head = new_room;
  } else {
    Room* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_room;
  }

  return head;
}

int main() {
  Guest* head_guest = NULL;
  Room* head_room = NULL;

  insert_guest(head_guest, "John Doe", 101);
  insert_guest(head_guest, "Jane Doe", 102);
  insert_guest(head_guest, "Peter Pan", 103);

  insert_room(head_room, 101, 2);
  insert_room(head_room, 102, 1);
  insert_room(head_room, 103, 0);

  Guest* current_guest = head_guest;
  while (current_guest) {
    printf("Name: %s, Room No: %d\n", current_guest->name, current_guest->room_no);
    current_guest = current_guest->next;
  }

  Room* current_room = head_room;
  while (current_room) {
    printf("Room No: %d, Occupancy: %d\n", current_room->room_no, current_room->occupancy);
    current_room = current_room->next;
  }

  return 0;
}